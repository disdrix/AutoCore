# Multi-agent partition map — wave 26 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1627** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W26-A | `0x0040d3f0`, `0x00416260` |
| W26-B | `0x0076e5e0`, `0x00433c00` |
| W26-C | `0x00433ba0`, `0x0077d440` |
| W26-D | `0x007a4400`, `0x0055fbf0` |
| W26-E | `0x0055fa40`, `0x0053dbb0` |
| W26-F | `0x004c4880`, `0x005f44c0` |
| W26-G | `0x0043c730`, `0x004b6a80` |
| W26-H | `0x004b7330`, `0x004b4620` |
| W26-I | `0x005bc120`, `0x004bcc40` |
| W26-J | `0x004d64d0`, `0x004bbc70` |
| W26-K | `0x00584330`, `0x0058e270` |
| W26-L | `0x0058e300`, `0x008120d0` |
| W26-M | `0x00811e00`, `0x0096f660` |
| W26-N | `0x00585e00`, `0x00540890` |
| W26-O | `0x004cbd50`, `0x005cedf0` |
| W26-P | `0x00604e30`, `0x0051db60` |
| W26-Q | `0x00573170`, `0x00418c10` |
| W26-R | `0x00829ce0`, `0x005a2470` |
| W26-S | `0x0093d880`, `0x005360f0` |
| W26-T | `0x0060b410`, `0x0060b440` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
6. Write agent report: `docs/agents/task-dual-ab-<va1>-<va2>-w26X-report.md`.
