# Multi-agent partition map — wave 27 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1667** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W27-A | `0x0090f490`, `0x008335a0` |
| W27-B | `0x00433c60`, `0x0043ce90` |
| W27-C | `0x0043c8c0`, `0x0043cec0` |
| W27-D | `0x004ba0a0`, `0x005bb5e0` |
| W27-E | `0x004b0f80`, `0x004b2b90` |
| W27-F | `0x004b18f0`, `0x00626890` |
| W27-G | `0x004c4440`, `0x004c4620` |
| W27-H | `0x005f4380`, `0x004c9120` |
| W27-I | `0x004c9430`, `0x005d7ca0` |
| W27-J | `0x005d6870`, `0x005d1d20` |
| W27-K | `0x004e3610`, `0x00497360` |
| W27-L | `0x004bd1b0`, `0x004bbfb0` |
| W27-M | `0x00515520`, `0x006297e0` |
| W27-N | `0x006caaa0`, `0x0055f4c0` |
| W27-O | `0x00560f30`, `0x00560f70` |
| W27-P | `0x00561370`, `0x0044a8c0` |
| W27-Q | `0x004e4130`, `0x00539210` |
| W27-R | `0x005399f0`, `0x00567450` |
| W27-S | `0x00573250`, `0x00573510` |
| W27-T | `0x005ae4e0`, `0x005ae990` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
6. Write agent report: `docs/agents/task-dual-ab-<va1>-<va2>-w27X-report.md`.
