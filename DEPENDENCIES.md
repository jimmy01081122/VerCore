# VerCore Dependencies & Tool Installation Guide

This document lists all required tools, their versions, installation methods, and disk space requirements.

## 🚨 CRITICAL: Large Files NOT Included in Repository

**Total excluded size: ~5-8 GB**

The following are intentionally excluded from this repository because they are:
1. Large (often >1GB each)
2. Platform-specific
3. Easily installable via package managers or scripts
4. Auto-generated during build

### Excluded Tools & Build Artifacts

| Item | Size | Why Excluded | Installation |
|------|------|-------------|--------------|
| Verilator (binary) | 300-500 MB | Large compiled binary | `apt-get install verilator` |
| Yosys (binary) | 100-200 MB | Large compiled binary | `apt-get install yosys` |
| OpenROAD (binary) | 500 MB - 1 GB | Large; use prebuilt | See installation script |
| RISC-V GCC toolchain | 1-2 GB | Large; pre-compiled available | `apt-get install gcc-riscv64-unknown-elf` |
| Spike (binary) | 50-100 MB | Large; easy to build | Build from source or apt |
| LLVM/Clang (if used) | 2-5 GB | Optional; rarely needed | Build separately if needed |
| Various .deb packages | - | Package format | Install via apt-get |
| `vercore_sandbox/tools/` | ~3-4 GB | Prebuilt tool collection | Use `.sh` scripts in `scripts/` |

---

## 🔧 Installation Methods

### Option 1: Using Dev Container (Recommended)

**Advantages**: 
- All dependencies pre-installed
- Reproducible environment
- No system pollution

**Requirements**:
- Docker & Docker Compose
- VS Code + Dev Containers extension

**Steps**:
```bash
git clone git@github.com:jimmy01081122/VerCore.git
cd VerCore
# Open in VS Code and select "Reopen in Container"
# All tools will be installed automatically via Dockerfile
```

**Time**: ~15-30 minutes (first build), subsequent opens are instant

---

### Option 2: Manual Installation (Linux - Ubuntu 22.04)

#### 2.1 Core Build Tools

```bash
sudo apt-get update
sudo apt-get install -y build-essential git pkg-config
```

#### 2.2 Verilator (RTL Simulation & Linting)

```bash
# Version: 5.0 or later
sudo apt-get install -y verilator

# Verify installation
verilator --version
```

**Disk Space**: ~300-500 MB

#### 2.3 Yosys (Logic Synthesis)

```bash
# Version: 0.30 or later
sudo apt-get install -y yosys

# Verify installation
yosys -version
```

**Disk Space**: ~100-200 MB

#### 2.4 RISC-V GNU Toolchain (Cross-Compiler)

```bash
# For baremetal/embedded (riscv64-unknown-elf)
sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf

# For Linux target (riscv64-linux-gnu) - optional
sudo apt-get install -y gcc-riscv64-linux-gnu

# Verify installation
riscv64-unknown-elf-gcc --version
riscv64-unknown-elf-objcopy --version
```

**Disk Space**: ~1-2 GB

#### 2.5 Spike RISC-V ISA Simulator

```bash
# Method 1: From package (if available)
sudo apt-get install -y spike

# Method 2: Build from source (recommended for latest)
bash vercore_sandbox/scripts/install_spike.sh

# Verify installation
spike --version
```

**Disk Space**: ~50-100 MB (binary)

#### 2.6 Python Dependencies

```bash
# Python 3.8+
sudo apt-get install -y python3 python3-pip

# Required Python packages
pip3 install --user pathlib

# Optional but useful
pip3 install --user pyyaml
```

#### 2.7 OpenROAD Physical Design Tools

**Option A: From Ubuntu Packages**
```bash
# If available in your Ubuntu version
sudo apt-get install -y openroad
```

**Option B: Use Prebuilt Binary (Recommended)**
```bash
bash vercore_sandbox/scripts/install_openroad_binary.sh
```

**Option C: Build from Source** ⚠️ WARNING
```bash
# NOT RECOMMENDED - Takes 2-4 hours and requires ~10GB disk
# Only do this if prebuilt binaries unavailable
cd /tmp
git clone --recursive https://github.com/The-OpenROAD-Project/OpenROAD.git
cd OpenROAD
./etc/Build.md  # Follow build instructions
```

**Disk Space**: ~500 MB - 1 GB (binary), 5+ GB (source build)

---

## 📋 Dependency Matrix

### Minimum Installation (RTL Verification Only)

| Tool | Min Version | Disk | Time | Command |
|------|------------|------|------|---------|
| Verilator | 5.0 | 400 MB | 2 min | `apt-get install verilator` |
| RISC-V GCC | 10.2 | 1.5 GB | 5 min | `apt-get install gcc-riscv64-unknown-elf` |
| Python | 3.8 | 200 MB | 2 min | `apt-get install python3` |
| **Total** | - | **2.1 GB** | **~10 min** | - |

### Standard Installation (RTL + Simulation)

| Tool | Min Version | Disk | Time | Command |
|------|------------|------|------|---------|
| Verilator | 5.0 | 400 MB | 2 min | `apt-get install verilator` |
| Yosys | 0.30 | 200 MB | 2 min | `apt-get install yosys` |
| RISC-V GCC | 10.2 | 1.5 GB | 5 min | `apt-get install gcc-riscv64-unknown-elf` |
| Spike | Latest | 100 MB | 10 min | `install_spike.sh` |
| Python | 3.8 | 200 MB | 2 min | `apt-get install python3` |
| **Total** | - | **2.4 GB** | **~25 min** | - |

### Full Installation (RTL + Simulation + Physical Design)

| Tool | Min Version | Disk | Time | Command |
|------|------------|------|------|---------|
| Verilator | 5.0 | 400 MB | 2 min | `apt-get install verilator` |
| Yosys | 0.30 | 200 MB | 2 min | `apt-get install yosys` |
| OpenROAD | Latest | 750 MB | 5 min | `install_openroad_binary.sh` |
| RISC-V GCC | 10.2 | 1.5 GB | 5 min | `apt-get install gcc-riscv64-unknown-elf` |
| Spike | Latest | 100 MB | 10 min | `install_spike.sh` |
| Python | 3.8 | 200 MB | 2 min | `apt-get install python3` |
| **Total** | - | **3.15 GB** | **~30 min** | - |

---

## 🔗 Installation Scripts

Pre-built installation scripts are provided in `vercore_sandbox/scripts/`:

```bash
# Install Spike from source
bash vercore_sandbox/scripts/install_spike.sh

# Install OpenROAD prebuilt binary
bash vercore_sandbox/scripts/install_openroad_binary.sh

# Install Yosys prebuilt binary
bash vercore_sandbox/scripts/install_yosys_binary.sh
```

---

## ⚙️ Environment Setup

After installation, verify all tools are in your PATH:

```bash
# Add to ~/.bashrc if needed
export PATH="/usr/local/bin:$PATH"

# Verify each tool
verilator --version
yosys -version
riscv64-unknown-elf-gcc --version
spike --version
openroad -version  # May not show version, but should run
```

---

## 📊 Disk Space Summary

| Category | Space Required |
|----------|-----------------|
| **Repository (source code only)** | ~100 MB |
| **Minimal tools** | ~2.1 GB |
| **Standard tools** | ~2.4 GB |
| **Full tools** | ~3.15 GB |
| **With build artifacts** | ~5-8 GB (after running flows) |

**Total for development**: ~5-10 GB recommended

---

## 🆘 Troubleshooting

### Issue: `verilator: command not found`

**Solution**:
```bash
sudo apt-get install -y verilator
# OR check PATH:
which verilator
# If not found but installed, add to PATH in ~/.bashrc
```

### Issue: `riscv64-unknown-elf-gcc: command not found`

**Solution**:
```bash
sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf
# Verify:
riscv64-unknown-elf-gcc --version
```

### Issue: `spike: command not found`

**Solution**:
```bash
# Method 1: Install from repo (if available)
sudo apt-get install -y spike

# Method 2: Build from source
bash vercore_sandbox/scripts/install_spike.sh
```

### Issue: OpenROAD fails to start

**Solution**:
```bash
# Try prebuilt binary:
bash vercore_sandbox/scripts/install_openroad_binary.sh

# Verify installation:
$OPENROAD_HOME/bin/openroad -version
```

### Issue: Build fails with "file not found"

**Solutions**:
1. Check PATH: `echo $PATH`
2. Run tool verification: `make -C vercore_sandbox verify-tools`
3. Reinstall missing tool

---

## 📝 Version Compatibility

| Tool | Min Version | Max Version | Tested With |
|------|------------|-------------|------------|
| Verilator | 5.0 | Latest | 5.024 |
| Yosys | 0.30 | Latest | 0.38+ |
| OpenROAD | 2.0 | Latest | Latest nightly |
| RISC-V GCC | 10.2 | 13.1 | 12.2 |
| Spike | Latest | Latest | Latest from source |
| Python | 3.8 | 3.11+ | 3.10 |

---

## 🔄 Updating Tools

```bash
# Update package manager
sudo apt-get update && sudo apt-get upgrade -y

# Update specific tools
sudo apt-get install --only-upgrade verilator yosys gcc-riscv64-unknown-elf

# Rebuild Spike to latest
bash vercore_sandbox/scripts/install_spike.sh --force
```

---

## 📚 References

- [Verilator Documentation](https://verilator.org/guide/)
- [Yosys Manual](https://yosys.readthedocs.io/)
- [OpenROAD Documentation](https://openroad.readthedocs.io/)
- [RISC-V GNU Toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain)
- [Spike ISA Simulator](https://github.com/riscv-software-src/riscv-isa-sim)

---

**Last Updated**: April 28, 2026
**For**: VerCore RISC-V CPU Core Design
**Repository**: git@github.com:jimmy01081122/VerCore.git
