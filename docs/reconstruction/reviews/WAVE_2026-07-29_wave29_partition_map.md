# Multi-agent partition map — wave 29 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1747** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W29-A | `0x0043cb00`, `0x0043c660` |
| W29-B | `0x0043ce10`, `0x0043c830` |
| W29-C | `0x00436860`, `0x00423e00` |
| W29-D | `0x007b65d0`, `0x0043c2e0` |
| W29-E | `0x005ae050`, `0x00572ab0` |
| W29-F | `0x005b8000`, `0x004975e0` |
| W29-G | `0x00496f70`, `0x00518ec0` |
| W29-H | `0x00575440`, `0x00575c00` |
| W29-I | `0x00973590`, `0x005b36f0` |
| W29-J | `0x005e1fc0`, `0x008e4430` |
| W29-K | `0x004bc840`, `0x004bc7a0` |
| W29-L | `0x005ccff0`, `0x004e2940` |
| W29-M | `0x004e7350`, `0x00567860` |
| W29-N | `0x00516930`, `0x00517250` |
| W29-O | `0x00581500`, `0x00626530` |
| W29-P | `0x00626210`, `0x006261e0` |
| W29-Q | `0x0053af20`, `0x006cac60` |
| W29-R | `0x00634450`, `0x0055ff20` |
| W29-S | `0x00560020`, `0x00560750` |
| W29-T | `0x0055e760`, `0x005617c0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w29X-report.md`.
