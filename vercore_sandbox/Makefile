TOP=vercore_top
ROOT:=$(abspath .)
RTL_DIR=rtl
TB_DIR=tb
TEST_DIR=tests
BUILD_DIR=build

RISCV_PREFIX=riscv64-unknown-elf
CC=$(RISCV_PREFIX)-gcc
OBJCOPY=$(RISCV_PREFIX)-objcopy

ARCH_FLAGS=-march=rv32im -mabi=ilp32
CFLAGS_BARE=-nostdlib -nostartfiles -ffreestanding -O0 -g

RTL_SRCS=$(ROOT)/$(RTL_DIR)/vercore_top.v \
         $(ROOT)/$(RTL_DIR)/vercore_controller.v \
         $(ROOT)/$(RTL_DIR)/vercore_pipeline_regs.v \
         $(ROOT)/$(RTL_DIR)/vercore_regfile.v \
         $(ROOT)/$(RTL_DIR)/vercore_alu.v

TB_CPP=$(ROOT)/$(TB_DIR)/tb_vercore.cpp

ELF=$(BUILD_DIR)/test_basic.elf
BIN=$(BUILD_DIR)/test_basic.bin
HEX=$(BUILD_DIR)/test_basic.hex
SIM_BIN=$(BUILD_DIR)/sim_vercore

.PHONY: all clean test rtl spike compare

all: test

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(ELF): $(TEST_DIR)/test_basic.S $(TEST_DIR)/link.ld | $(BUILD_DIR)
	$(CC) $(ARCH_FLAGS) $(CFLAGS_BARE) -T $(TEST_DIR)/link.ld -Wl,-Map,$(BUILD_DIR)/test_basic.map -o $@ $<

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(BIN)
	python3 -c "import pathlib;b=pathlib.Path('$(BIN)').read_bytes();print('\n'.join(f'{x:02x}' for x in b), end='')" > $@

$(SIM_BIN): $(RTL_SRCS) $(TB_CPP) | $(BUILD_DIR)
	verilator -Wall --cc --exe --build -o sim_vercore --Mdir $(BUILD_DIR)/obj_dir \
		--top-module $(TOP) $(RTL_SRCS) $(TB_CPP)
	cp $(BUILD_DIR)/obj_dir/sim_vercore $(SIM_BIN)

rtl: $(SIM_BIN) $(BIN)
	cd $(BUILD_DIR) && ./sim_vercore test_basic.bin
	cp $(BUILD_DIR)/rtl_trace.log ./rtl_trace.log

spike: $(ELF)
	timeout 3s spike -l --log-commits --isa=rv32im --pc=0x80000000 $(ELF) 2> spike_trace.log || true

compare: rtl spike
	python3 compare_trace.py rtl_trace.log spike_trace.log

test: compare

clean:
	rm -rf $(BUILD_DIR) rtl_trace.log spike_trace.log
