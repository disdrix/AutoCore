# Multi-agent partition map — wave 28 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1707** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W28-A | `0x0043d390`, `0x00433ca0` |
| W28-B | `0x0043cf40`, `0x0043c9b0` |
| W28-C | `0x0043d300`, `0x0043c550` |
| W28-D | `0x0043c7e0`, `0x0043cef0` |
| W28-E | `0x004b2910`, `0x00973820` |
| W28-F | `0x00973690`, `0x00578270` |
| W28-G | `0x0051f890`, `0x006264e0` |
| W28-H | `0x005179e0`, `0x00514d80` |
| W28-I | `0x005bc3c0`, `0x005be2b0` |
| W28-J | `0x004bcf90`, `0x004bce90` |
| W28-K | `0x005d6b80`, `0x005d7de0` |
| W28-L | `0x004c3c80`, `0x005cc450` |
| W28-M | `0x004970b0`, `0x00575350` |
| W28-N | `0x005b3b20`, `0x005ae0b0` |
| W28-O | `0x005adfa0`, `0x00418bf0` |
| W28-P | `0x004e5120`, `0x0053a1a0` |
| W28-Q | `0x0053a8e0`, `0x006cad30` |
| W28-R | `0x0055f520`, `0x0055f590` |
| W28-S | `0x00629d90`, `0x0053a260` |
| W28-T | `0x0046c6c0`, `0x00573810` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w28X-report.md`.
