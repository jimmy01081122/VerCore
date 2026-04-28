# Excluded Large Files

The following large prebuilt tool binaries and runtime libraries were intentionally excluded from the repository and added to `.gitignore` to avoid exceeding GitHub file size limits.

Files excluded (from last push attempt):

- vercore_sandbox/tools/openroad/usr/bin/openroad (79.83 MB)
- vercore_sandbox/tools/oss-cad-suite/lib/libLLVM-14.so.1 (104.34 MB)
- vercore_sandbox/tools/oss-cad-suite/lib/libLLVM-15.so.1 (111.46 MB)
- vercore_sandbox/tools/oss-cad-suite/libexec/nextpnr-ecp5 (107.18 MB)
- vercore_sandbox/tools/oss-cad-suite/libexec/nextpnr-ice40 (225.30 MB)
- vercore_sandbox/tools/oss-cad-suite/libexec/nextpnr-machxo2 (140.41 MB)
- vercore_sandbox/tools/oss-cad-suite/libexec/surfer (65.69 MB)
- vercore_sandbox/tools/oss-cad-suite/share/nextpnr/himbaechel/gowin/chipdb-GW5AST-138C.bin (60.96 MB)

Reason: GitHub rejects files >100 MB and warns over ~50 MB; these are prebuilt runtime/tool binaries. Keep them out of git history; provide installation instructions or use Git LFS if you need to store them.

Suggested actions:

- Keep tool binaries outside the repo, or host them separately (release assets, cloud storage, or use Git LFS).
- Document installation/setup steps for contributors in `README.md`.

Generated: April 29, 2026
