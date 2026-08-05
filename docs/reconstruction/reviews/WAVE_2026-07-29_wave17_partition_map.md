# Multi-agent partition map — wave 17 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1267** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## Nested high-mention callees (missing dual)

| Agent | VAs |
|-------|-----|
| W17-A | `0x004e23d0`, `0x008aec40` |
| W17-B | `0x004e88e0`, `0x0060b870` |
| W17-C | `0x00925820`, `0x0067b0a0` |
| W17-D | `0x00769e40`, `0x00404d70` |
| W17-E | `0x005134e0`, `0x004fabc0` |
| W17-F | `0x0087b500`, `0x0076d1b0` |
| W17-G | `0x00767fd0`, `0x00798bb0` |
| W17-H | `0x00944d50`, `0x0090dd50` |
| W17-I | `0x007b6a20`, `0x004c4140` |
| W17-J | `0x004d0e90`, `0x004ce940` |
| W17-K | `0x005ffc20`, `0x00538120` |
| W17-L | `0x00767120`, `0x007b6420` |
| W17-M | `0x007b66c0`, `0x007fc360` |
| W17-N | `0x00826780`, `0x006a3d60` |
| W17-O | `0x004e96e0`, `0x004c4070` |
| W17-P | `0x0056f570`, `0x00636370` |
| W17-Q | `0x005d20b0`, `0x00637da0` |
| W17-R | `0x00767070`, `0x004368b0` |
| W17-S | `0x00780730`, `0x00786280` |
| W17-T | `0x004bb010`, `0x00944b20` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
