# Multi-agent partition map — wave 19 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1347** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W19-A | `0x00424890`, `0x004f9030` |
| W19-B | `0x004540b0`, `0x005739b0` |
| W19-C | `0x004e2e80`, `0x00946c00` |
| W19-D | `0x00419ad0`, `0x0076cef0` |
| W19-E | `0x004bc180`, `0x00620480` |
| W19-F | `0x0059c000`, `0x004ce5f0` |
| W19-G | `0x006061e0`, `0x00512070` |
| W19-H | `0x00513e30`, `0x00513580` |
| W19-I | `0x0051cb40`, `0x008a81a0` |
| W19-J | `0x00533220`, `0x00569320` |
| W19-K | `0x00568b70`, `0x00538190` |
| W19-L | `0x0053b8c0`, `0x0054eb20` |
| W19-M | `0x006cad80`, `0x00561320` |
| W19-N | `0x00514ff0`, `0x005a2850` |
| W19-O | `0x006078e0`, `0x00507290` |
| W19-P | `0x0063a700`, `0x0071bdd0` |
| W19-Q | `0x0071b5a0`, `0x00439870` |
| W19-R | `0x00745d70`, `0x0076a900` |
| W19-S | `0x00439a80`, `0x007b6e8d` |
| W19-T | `0x00580a20`, `0x00931440` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
