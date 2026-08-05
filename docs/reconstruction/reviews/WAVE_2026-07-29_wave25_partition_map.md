# Multi-agent partition map — wave 25 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1587** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W25-A | `0x00535ed0`, `0x0058dc30` |
| W25-B | `0x0091b1c0`, `0x0091ce80` |
| W25-C | `0x004bcbf0`, `0x00421240` |
| W25-D | `0x004c8110`, `0x00583f10` |
| W25-E | `0x005252f0`, `0x004f4f00` |
| W25-F | `0x0051bfb0`, `0x0051ba40` |
| W25-G | `0x0051c1c0`, `0x00829ac0` |
| W25-H | `0x0053e510`, `0x0053b900` |
| W25-I | `0x0051f510`, `0x009c3de0` |
| W25-J | `0x0051aed0`, `0x005d7f70` |
| W25-K | `0x0063f400`, `0x005d9ea0` |
| W25-L | `0x0063f5b0`, `0x0056a680` |
| W25-M | `0x005ffc90`, `0x004cbfc0` |
| W25-N | `0x00614dc0`, `0x0096ef70` |
| W25-O | `0x0065eb10`, `0x0067b070` |
| W25-P | `0x0067b0e0`, `0x00718250` |
| W25-Q | `0x0071b430`, `0x00727440` |
| W25-R | `0x0043c5f0`, `0x00767600` |
| W25-S | `0x00767840`, `0x00769b70` |
| W25-T | `0x0040d450`, `0x0077d520` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
