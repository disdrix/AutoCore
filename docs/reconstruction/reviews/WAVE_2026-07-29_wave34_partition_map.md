# Multi-agent partition map — wave 34 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1947** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W34-A | `0x0076ba10`, `0x005b7250` |
| W34-B | `0x006874b0`, `0x009698a0` |
| W34-C | `0x00750260`, `0x00416510` |
| W34-D | `0x0044a0d0`, `0x00436ef0` |
| W34-E | `0x0043bdf0`, `0x00457ac0` |
| W34-F | `0x00463bd0`, `0x0043fdf0` |
| W34-G | `0x004438c0`, `0x00457b30` |
| W34-H | `0x004642d0`, `0x00431700` |
| W34-I | `0x009841d0`, `0x004a1770` |
| W34-J | `0x0099bba0`, `0x009697a0` |
| W34-K | `0x00444810`, `0x00754320` |
| W34-L | `0x00431790`, `0x0043df90` |
| W34-M | `0x0043d650`, `0x004c0640` |
| W34-N | `0x004c0a90`, `0x004c1cb0` |
| W34-O | `0x004c1960`, `0x004501d0` |
| W34-P | `0x0045cd30`, `0x004617a0` |
| W34-Q | `0x00466ea0`, `0x00469f50` |
| W34-R | `0x004a7ad0`, `0x0055be00` |
| W34-S | `0x0068a1d0`, `0x00469d10` |
| W34-T | `0x0078caf0`, `0x0048eb10` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w34X-report.md`.
