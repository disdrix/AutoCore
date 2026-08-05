# Multi-agent partition map — wave 23 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1507** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W23-A | `0x00437150`, `0x00433280` |
| W23-B | `0x004076a0`, `0x005681a0` |
| W23-C | `0x0042139b`, `0x00432580` |
| W23-D | `0x00826860`, `0x00419880` |
| W23-E | `0x0043fe60`, `0x00943b80` |
| W23-F | `0x004a7580`, `0x00541aa0` |
| W23-G | `0x005d9af0`, `0x005c74e0` |
| W23-H | `0x004b7150`, `0x00595230` |
| W23-I | `0x004baa30`, `0x00979290` |
| W23-J | `0x005cc7c0`, `0x00845360` |
| W23-K | `0x005c82a0`, `0x004c4dd0` |
| W23-L | `0x00561910`, `0x004e7d30` |
| W23-M | `0x004de760`, `0x004e7420` |
| W23-N | `0x00851630`, `0x00859bc0` |
| W23-O | `0x004e8590`, `0x00916090` |
| W23-P | `0x0055df40`, `0x00509940` |
| W23-Q | `0x004ff850`, `0x00508630` |
| W23-R | `0x005cc460`, `0x00578550` |
| W23-S | `0x00578830`, `0x005b3210` |
| W23-T | `0x00650d30`, `0x004e1830` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
