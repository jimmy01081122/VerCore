#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
OR_BIN="${ROOT_DIR}/tools/openroad/usr/bin/openroad"
OR_LIB="${ROOT_DIR}/tools/openroad/opt/or-tools/lib"
TCLRL_LIB="${ROOT_DIR}/tools/runtime_libs/tclreadline/usr/lib/x86_64-linux-gnu"
QT_LIB="${ROOT_DIR}/tools/runtime_libs/qt/usr/lib/x86_64-linux-gnu"

if [[ ! -x "${OR_BIN}" ]]; then
    echo "OpenROAD binary not found: ${OR_BIN}" >&2
    exit 1
fi

export LD_LIBRARY_PATH="${OR_LIB}:${TCLRL_LIB}:${QT_LIB}:${LD_LIBRARY_PATH:-}"
exec "${OR_BIN}" "$@"
