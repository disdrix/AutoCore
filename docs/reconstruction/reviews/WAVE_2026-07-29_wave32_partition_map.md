# Multi-agent partition map — wave 32 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1867** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W32-A | `0x009694e0`, `0x00430310` |
| W32-B | `0x004306b0`, `0x0040d7c0` |
| W32-C | `0x0040d700`, `0x0040d890` |
| W32-D | `0x00423cf0`, `0x009839b0` |
| W32-E | `0x00469db0`, `0x00985010` |
| W32-F | `0x0043d420`, `0x0043e080` |
| W32-G | `0x0043e4b0`, `0x0044e1c0` |
| W32-H | `0x004b88e0`, `0x004f1ff0` |
| W32-I | `0x005441d0`, `0x00556b10` |
| W32-J | `0x00971280`, `0x009717a0` |
| W32-K | `0x00971820`, `0x00972140` |
| W32-L | `0x004f2540`, `0x00744360` |
| W32-M | `0x0043ece0`, `0x0043ea50` |
| W32-N | `0x0043ecf0`, `0x0043e7f0` |
| W32-O | `0x0075de80`, `0x007560d0` |
| W32-P | `0x004933f0`, `0x00497920` |
| W32-Q | `0x0048f2d0`, `0x00756320` |
| W32-R | `0x0048f370`, `0x0048ed00` |
| W32-S | `0x005769c0`, `0x00576860` |
| W32-T | `0x00576ed0`, `0x005b35a0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w32X-report.md`.
