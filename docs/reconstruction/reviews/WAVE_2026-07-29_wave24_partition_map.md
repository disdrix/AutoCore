# Multi-agent partition map — wave 24 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1547** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W24-A | `0x004321b0`, `0x005829d0` |
| W24-B | `0x00422880`, `0x00560e90` |
| W24-C | `0x004b8ed0`, `0x004b1100` |
| W24-D | `0x009168d0`, `0x004b7030` |
| W24-E | `0x005d4830`, `0x00406840` |
| W24-F | `0x00421362`, `0x004d8a10` |
| W24-G | `0x00512460`, `0x00516be0` |
| W24-H | `0x00518ca0`, `0x0051d150` |
| W24-I | `0x005ae220`, `0x00827670` |
| W24-J | `0x008283a0`, `0x00829b20` |
| W24-K | `0x0082a050`, `0x00535c60` |
| W24-L | `0x0060bb80`, `0x00539150` |
| W24-M | `0x0053b920`, `0x0059c8a0` |
| W24-N | `0x00540090`, `0x00541e70` |
| W24-O | `0x004e22d0`, `0x006753b0` |
| W24-P | `0x0062a410`, `0x00628f10` |
| W24-Q | `0x004f4eb0`, `0x00814400` |
| W24-R | `0x0056ff00`, `0x0074ed90` |
| W24-S | `0x0074ee40`, `0x0040b020` |
| W24-T | `0x00925670`, `0x0058da00` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
