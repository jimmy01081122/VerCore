# VerCore

VerCore is a 5-stage, in-order, single-issue RISC-V RV32I CPU core with the ZMMUL extension (multiply instructions). This repository contains RTL (Verilog-2001), Verilator-based testbenches, assembly tests, and OpenROAD flow configuration for ASAP7 physical design.

## Project structure

- `vercore_sandbox/rtl/` - Verilog-2001 RTL sources (top-level and submodules)
- `vercore_sandbox/tests/` - Assembly tests and linker script
- `vercore_sandbox/tb/` - Verilator C++ testbench
- `vercore_sandbox/Makefile` - Build and simulation helpers
- `vercore_sandbox/compare_trace.py` - Trace comparison utility
- `vercore_sandbox/OpenROAD-flow-scripts/` - OpenROAD flow scripts and ASAP7 design config
- `design_journal.md` - Design notes, checkpoints, and verification logs

## Quick verification (software-only)

Requirements (host):
- Verilator
- Spike (riscv ISA simulator)
- riscv64-unknown-elf toolchain (gcc, objcopy)

To run the Verilator RTL simulation and compare with Spike (from `vercore_sandbox`):

```bash
# build simulator
make sim_vercore

# build and run a single test (example: test_basic)
make BUILD_DIR=build test_basic

# or run the provided test runner (if toolchain & spike available)
bash run_tests.sh
```

If Spike or the riscv toolchain are not available in your environment, see `vercore_sandbox/scripts/` for helper installers.

## Physical design (ASAP7 / OpenROAD)

Design scripts and SDC constraints are under:

`vercore_sandbox/OpenROAD-flow-scripts/designs/asap7/vercore/`

The initial target clock period is 1.0 ns (1 GHz). Input and output delay constraints are applied per the project requirements.

## How to contribute

- Open issues and PRs against the repository
- Follow Verilog-2001 style and avoid SystemVerilog constructs
- Run `verilator --lint-only` to check RTL before proposing changes

## Contact

Maintainer: Jimmy

---

(Automatically generated README)