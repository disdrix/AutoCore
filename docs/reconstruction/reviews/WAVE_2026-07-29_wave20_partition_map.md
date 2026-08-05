# Multi-agent partition map — wave 20 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1387** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W20-A | `0x00512060`, `0x0094b520` |
| W20-B | `0x0054de50`, `0x00560a30` |
| W20-C | `0x00606ff0`, `0x00424830` |
| W20-D | `0x00439810`, `0x006082e0` |
| W20-E | `0x00449dc0`, `0x0096de80` |
| W20-F | `0x008a8770`, `0x008be900` |
| W20-G | `0x00418130`, `0x00404130` |
| W20-H | `0x004e24d0`, `0x0056c0a0` |
| W20-I | `0x00542790`, `0x005408f0` |
| W20-J | `0x00422830`, `0x0042b980` |
| W20-K | `0x0077daf0`, `0x0098ae80` |
| W20-L | `0x0098acc0`, `0x00401a40` |
| W20-M | `0x006759b0`, `0x0058e370` |
| W20-N | `0x004ba770`, `0x006170b0` |
| W20-O | `0x004c3ac0`, `0x00514390` |
| W20-P | `0x005995a0`, `0x004e15a0` |
| W20-Q | `0x0058c850`, `0x00921f70` |
| W20-R | `0x00508c00`, `0x0050843d` |
| W20-S | `0x00572730`, `0x00604db0` |
| W20-T | `0x00517400`, `0x0052db50` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
