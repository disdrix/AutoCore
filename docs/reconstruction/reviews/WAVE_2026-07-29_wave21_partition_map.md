# Multi-agent partition map — wave 21 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1427** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W21-A | `0x00508390`, `0x00512d10` |
| W21-B | `0x0050846f`, `0x00572360` |
| W21-C | `0x00578b30`, `0x0077d960` |
| W21-D | `0x00508c50`, `0x0051e3d0` |
| W21-E | `0x0051b5f0`, `0x005210b0` |
| W21-F | `0x008a2020`, `0x004c9aa0` |
| W21-G | `0x00569560`, `0x00799820` |
| W21-H | `0x004c2f20`, `0x005021d0` |
| W21-I | `0x004cf080`, `0x0079a110` |
| W21-J | `0x0074e910`, `0x0059d890` |
| W21-K | `0x005a2410`, `0x006380a0` |
| W21-L | `0x00414c20`, `0x007a41f0` |
| W21-M | `0x00480970`, `0x00724870` |
| W21-N | `0x00745ea0`, `0x0044e8c0` |
| W21-O | `0x0074c9c0`, `0x0044e100` |
| W21-P | `0x004309c0`, `0x007f72e0` |
| W21-Q | `0x0092fd00`, `0x008af180` |
| W21-R | `0x008a16b0`, `0x00871690` |
| W21-S | `0x00871150`, `0x0089a260` |
| W21-T | `0x008a0210`, `0x008aa320` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
