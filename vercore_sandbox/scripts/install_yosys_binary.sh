#!/usr/bin/env bash
set -euo pipefail

TMP_DIR="${TMP_DIR:-/tmp/oss_cad_suite}"
INSTALL_DIR="${INSTALL_DIR:-/opt/oss-cad-suite}"

mkdir -p "${TMP_DIR}"

ASSET_URL="$(python3 - <<'PY'
import json
import urllib.request

u = "https://api.github.com/repos/YosysHQ/oss-cad-suite-build/releases/latest"
with urllib.request.urlopen(u) as r:
    data = json.load(r)

for a in data.get("assets", []):
    name = a.get("name", "")
    if "linux-x64" in name and (name.endswith(".tgz") or name.endswith(".tar.gz")):
        print(a.get("browser_download_url", ""))
        raise SystemExit(0)

raise SystemExit("No linux-x64 oss-cad-suite asset found")
PY
)"

ARCHIVE_PATH="${TMP_DIR}/oss-cad-suite.tgz"
echo "[install_yosys_binary] Downloading ${ASSET_URL}"
curl -L "${ASSET_URL}" -o "${ARCHIVE_PATH}"

echo "[install_yosys_binary] Extracting to ${INSTALL_DIR}"
rm -rf "${INSTALL_DIR}"
mkdir -p "${INSTALL_DIR}"
tar -xzf "${ARCHIVE_PATH}" -C /opt

if [ ! -x "${INSTALL_DIR}/bin/yosys" ]; then
    echo "ERROR: ${INSTALL_DIR}/bin/yosys not found"
    exit 1
fi

ln -sf "${INSTALL_DIR}/bin/yosys" /usr/local/bin/yosys
ln -sf "${INSTALL_DIR}/bin/abc" /usr/local/bin/abc || true

echo "[install_yosys_binary] Installed yosys:"
/usr/local/bin/yosys -V
