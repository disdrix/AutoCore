# Multi-agent partition map — wave 36 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **2027** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W36-A | `0x004449b0`, `0x00437b00` |
| W36-B | `0x0046c1b0`, `0x0046bf90` |
| W36-C | `0x00444a40`, `0x00437c90` |
| W36-D | `0x005e2670`, `0x00971030` |
| W36-E | `0x0075d610`, `0x00971a20` |
| W36-F | `0x005575c0`, `0x005c6ad0` |
| W36-G | `0x0044fe10`, `0x0073cb70` |
| W36-H | `0x00748960`, `0x0099e6c0` |
| W36-I | `0x0099f450`, `0x00457720` |
| W36-J | `0x00731130`, `0x007300c0` |
| W36-K | `0x0098fd80`, `0x0098df00` |
| W36-L | `0x007647c0`, `0x0045cce0` |
| W36-M | `0x00459750`, `0x0046a260` |
| W36-N | `0x00461720`, `0x00965ab0` |
| W36-O | `0x00460f90`, `0x00460d70` |
| W36-P | `0x00466df0`, `0x0046a350` |
| W36-Q | `0x00469e20`, `0x004a6820` |
| W36-R | `0x004a6b50`, `0x004a74f0` |
| W36-S | `0x004a7aa0`, `0x004a7a70` |
| W36-T | `0x004a68a0`, `0x004a68d0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w36X-report.md`.
