#!/usr/bin/env bash
set -euo pipefail

SPIKE_SRC_DIR="${SPIKE_SRC_DIR:-/tmp/riscv-isa-sim}"
PREFIX="${PREFIX:-/usr/local}"
JOBS="${JOBS:-$(nproc)}"

echo "[install_spike] Installing build dependencies..."
apt-get update
apt-get install -y git autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev device-tree-compiler

echo "[install_spike] Cloning/updating riscv-isa-sim..."
if [ -d "${SPIKE_SRC_DIR}/.git" ]; then
    git -C "${SPIKE_SRC_DIR}" pull --ff-only
else
    rm -rf "${SPIKE_SRC_DIR}"
    git clone https://github.com/riscv-software-src/riscv-isa-sim.git "${SPIKE_SRC_DIR}"
fi

echo "[install_spike] Building spike..."
cd "${SPIKE_SRC_DIR}"
mkdir -p build
cd build
../configure --prefix="${PREFIX}"
make -j"${JOBS}"
make install

echo "[install_spike] Installed spike to ${PREFIX}/bin"
command -v spike
spike --version || true
