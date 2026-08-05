# Multi-agent partition map — wave 30 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1787** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W30-A | `0x0043d990`, `0x0043ea60` |
| W30-B | `0x0043e5b0`, `0x0040d980` |
| W30-C | `0x0043df70`, `0x0075dae0` |
| W30-D | `0x0043c4f0`, `0x007b75b0` |
| W30-E | `0x009668a0`, `0x00457c60` |
| W30-F | `0x004cda90`, `0x0051b8a0` |
| W30-G | `0x004bcd40`, `0x004bcce0` |
| W30-H | `0x00565950`, `0x00518370` |
| W30-I | `0x005305b0`, `0x006291e0` |
| W30-J | `0x006295f0`, `0x005614f0` |
| W30-K | `0x0094bed0`, `0x005d49e0` |
| W30-L | `0x005e15a0`, `0x005e18d0` |
| W30-M | `0x005aed20`, `0x005accf0` |
| W30-N | `0x008c2f50`, `0x005b44d0` |
| W30-O | `0x005b3f60`, `0x005b4260` |
| W30-P | `0x0040d5b0`, `0x004be2a0` |
| W30-Q | `0x00494170`, `0x004941b0` |
| W30-R | `0x005be310`, `0x004b0bd0` |
| W30-S | `0x005bbc50`, `0x005cd220` |
| W30-T | `0x004c8970`, `0x005d6c10` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w30X-report.md`.
