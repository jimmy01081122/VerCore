#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Vvercore_top.h"
#include "verilated.h"

static const uint32_t MEM_SIZE_BYTES = 1u << 20;  // 1 MiB
static const uint32_t EBREAK_INSN = 0x00100073u;
static const uint32_t MEM_BASE_ADDR = 0x80000000u;

static uint32_t load_u32(const std::vector<uint8_t>& mem, uint32_t addr) {
    if (addr < MEM_BASE_ADDR) {
        return 0;
    }
    uint32_t off = addr - MEM_BASE_ADDR;
    if (off + 3 >= mem.size()) {
        return 0;
    }
    return static_cast<uint32_t>(mem[off]) |
           (static_cast<uint32_t>(mem[off + 1]) << 8) |
           (static_cast<uint32_t>(mem[off + 2]) << 16) |
           (static_cast<uint32_t>(mem[off + 3]) << 24);
}

static void store_masked(std::vector<uint8_t>& mem, uint32_t addr, uint32_t data, uint8_t size) {
    if (addr < MEM_BASE_ADDR) {
        return;
    }
    uint32_t off = addr - MEM_BASE_ADDR;
    if (off >= mem.size()) {
        return;
    }
    if (size == 0) {
        mem[off] = static_cast<uint8_t>(data & 0xffu);
    } else if (size == 1) {
        if (off + 1 < mem.size()) {
            mem[off] = static_cast<uint8_t>(data & 0xffu);
            mem[off + 1] = static_cast<uint8_t>((data >> 8) & 0xffu);
        }
    } else {
        if (off + 3 < mem.size()) {
            mem[off] = static_cast<uint8_t>(data & 0xffu);
            mem[off + 1] = static_cast<uint8_t>((data >> 8) & 0xffu);
            mem[off + 2] = static_cast<uint8_t>((data >> 16) & 0xffu);
            mem[off + 3] = static_cast<uint8_t>((data >> 24) & 0xffu);
        }
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <program.bin> [max_cycles] [mem_latency]\n";
        return 1;
    }

    const std::string bin_path = argv[1];
    const uint64_t max_cycles = (argc >= 3) ? std::strtoull(argv[2], nullptr, 0) : 20000ULL;
    uint32_t mem_latency = (argc >= 4) ? static_cast<uint32_t>(std::strtoul(argv[3], nullptr, 0)) : 1u;
    if (mem_latency == 0u) {
        mem_latency = 1u;
    }

    std::vector<uint8_t> mem(MEM_SIZE_BYTES, 0);
    {
        std::ifstream bin(bin_path, std::ios::binary);
        if (!bin.is_open()) {
            std::cerr << "Failed to open binary: " << bin_path << "\n";
            return 1;
        }
        bin.read(reinterpret_cast<char*>(mem.data()), static_cast<std::streamsize>(mem.size()));
    }

    std::ofstream trace("rtl_trace.log");
    if (!trace.is_open()) {
        std::cerr << "Failed to open rtl_trace.log\n";
        return 1;
    }

    Vvercore_top* dut = new Vvercore_top;
    dut->clk = 0;
    dut->rst_n = 0;
    dut->icache_rdata = 0;
    dut->icache_valid = 0;
    dut->dcache_rdata = 0;
    dut->dcache_ready = 0;

    bool icache_pending = false;
    uint32_t icache_addr_pending = 0;
    uint32_t icache_countdown = 0;
    bool dcache_pending = false;
    bool dcache_we_pending = false;
    uint8_t dcache_size_pending = 0;
    uint32_t dcache_addr_pending = 0;
    uint32_t dcache_wdata_pending = 0;
    uint32_t dcache_countdown = 0;

    uint64_t cycle = 0;
    uint64_t retired = 0;
    bool done = false;

    while (!done && cycle < max_cycles) {
        // Drive memory responses (1-cycle response latency).
        if (icache_pending && (icache_countdown <= 1u)) {
            dut->icache_rdata = load_u32(mem, icache_addr_pending);
            dut->icache_valid = 1;
            icache_pending = false;
            icache_countdown = 0;
        } else {
            dut->icache_rdata = 0;
            dut->icache_valid = 0;
            if (icache_pending) {
                icache_countdown--;
            }
        }

        if (dcache_pending && (dcache_countdown <= 1u)) {
            if (dcache_we_pending) {
                store_masked(mem, dcache_addr_pending, dcache_wdata_pending, dcache_size_pending);
            } else {
                dut->dcache_rdata = load_u32(mem, dcache_addr_pending & ~0x3u);
            }
            dut->dcache_ready = 1;
            dcache_pending = false;
            dcache_countdown = 0;
        } else {
            dut->dcache_rdata = 0;
            dut->dcache_ready = 0;
            if (dcache_pending) {
                dcache_countdown--;
            }
        }

        dut->clk = 0;
        dut->eval();

        dut->clk = 1;
        dut->eval();

        if (cycle == 4) {
            dut->rst_n = 1;
        }

        if (dut->dbg_retire_valid) {
            retired++;
            trace << "pc=0x" << std::hex << std::setw(8) << std::setfill('0') << dut->dbg_retire_pc
                  << " instr=0x" << std::hex << std::setw(8) << std::setfill('0') << dut->dbg_retire_instr;
            if (dut->dbg_retire_rd_we) {
                trace << " rd=x" << std::dec << static_cast<unsigned>(dut->dbg_retire_rd_addr)
                      << " data=0x" << std::hex << std::setw(8) << std::setfill('0') << dut->dbg_retire_rd_data;
            }
            trace << "\n";

            if (dut->dbg_retire_instr == EBREAK_INSN) {
                done = true;
            }
        }

        if (!icache_pending && (dut->icache_req != 0)) {
            icache_pending = true;
            icache_addr_pending = dut->icache_addr;
            icache_countdown = mem_latency;
        }

        if (!dcache_pending && (dut->dcache_req != 0)) {
            dcache_pending = true;
            dcache_we_pending = (dut->dcache_we != 0);
            dcache_size_pending = static_cast<uint8_t>(dut->dcache_size & 0x3u);
            dcache_addr_pending = dut->dcache_addr;
            dcache_wdata_pending = dut->dcache_wdata;
            dcache_countdown = mem_latency;
        }

        cycle++;
    }

    trace << "# cycles=" << cycle << " retired=" << retired << "\n";
    trace.close();

    delete dut;

    if (!done) {
        std::cerr << "Simulation did not retire EBREAK before max cycles.\n";
        return 2;
    }

    return 0;
}
