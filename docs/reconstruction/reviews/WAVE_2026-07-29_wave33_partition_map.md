# Multi-agent partition map — wave 33 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1907** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W33-A | `0x0040d6d0`, `0x0040d870` |
| W33-B | `0x00423d60`, `0x004646e0` |
| W33-C | `0x0076adc0`, `0x0076b3f0` |
| W33-D | `0x004301f0`, `0x00431ae0` |
| W33-E | `0x00984340`, `0x00984c70` |
| W33-F | `0x00416490`, `0x00416410` |
| W33-G | `0x0046a2c0`, `0x00430390` |
| W33-H | `0x00431aa0`, `0x00431430` |
| W33-I | `0x00431450`, `0x00431480` |
| W33-J | `0x00469c50`, `0x0043ec50` |
| W33-K | `0x0043e910`, `0x0043ebb0` |
| W33-L | `0x0043d940`, `0x0044e4f0` |
| W33-M | `0x00971700`, `0x0043e8f0` |
| W33-N | `0x00970b20`, `0x00970b60` |
| W33-O | `0x0075d3c0`, `0x00970e50` |
| W33-P | `0x00985390`, `0x0076b190` |
| W33-Q | `0x00984d30`, `0x00984910` |
| W33-R | `0x00497c80`, `0x00986070` |
| W33-S | `0x00442c80`, `0x004c2080` |
| W33-T | `0x0055cc50`, `0x005b39a0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w33X-report.md`.
