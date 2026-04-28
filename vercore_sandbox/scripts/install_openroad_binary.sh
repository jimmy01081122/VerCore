#!/usr/bin/env bash
set -euo pipefail

TMP_DIR="${TMP_DIR:-/tmp/openroad_bin}"
REG_NAME="${REG_NAME:-Cursor Agent}"
REG_EMAIL="${REG_EMAIL:-agent@example.com}"
REG_COMPANY="${REG_COMPANY:-OpenSource}"
mkdir -p "${TMP_DIR}"
COOKIE_JAR="${TMP_DIR}/vaultlink.cookies"

echo "[install_openroad_binary] Querying latest OpenROAD release..."
ASSET_URL="$(python3 - <<'PY'
import json
import urllib.request

api = "https://api.github.com/repos/Precision-Innovations/OpenROAD/releases?per_page=100"
with urllib.request.urlopen(api) as r:
    releases = json.load(r)

candidates = []
for rel in releases:
    for a in rel.get("assets", []):
        name = a.get("name", "")
        dl = a.get("browser_download_url", "")
        if name.endswith(".deb") and "amd64" in name and ("ubuntu-22.04" in name or "ubuntu22.04" in name):
            candidates.append(dl)
    if candidates:
        break

if not candidates:
    for rel in releases:
        for a in rel.get("assets", []):
            name = a.get("name", "")
            dl = a.get("browser_download_url", "")
            if name.endswith(".deb") and "amd64" in name:
                candidates.append(dl)
        if candidates:
            break

if not candidates:
    raise SystemExit("No suitable OpenROAD .deb asset found in Precision-Innovations/OpenROAD releases")

print(candidates[0])
PY
)"

DEB_PATH="${TMP_DIR}/openroad_latest.deb"
echo "[install_openroad_binary] Downloading ${ASSET_URL}"
curl -L -c "${COOKIE_JAR}" -b "${COOKIE_JAR}" "${ASSET_URL}" -o "${DEB_PATH}"

echo "[install_openroad_binary] Installing .deb package..."
dpkg -i "${DEB_PATH}" || (apt-get update && apt-get install -fy && dpkg -i "${DEB_PATH}")

echo "[install_openroad_binary] Verifying openroad in PATH..."
command -v openroad
openroad -version || true
