# Multi-agent partition map — wave 22 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1467** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W22-A | `0x005d0d60`, `0x004cef70` |
| W22-B | `0x00568200`, `0x00518940` |
| W22-C | `0x00571e10`, `0x0044b5c0` |
| W22-D | `0x008a0e10`, `0x0042b450` |
| W22-E | `0x00430b60`, `0x005690a0` |
| W22-F | `0x007fd970`, `0x00792490` |
| W22-G | `0x004048c0`, `0x00404510` |
| W22-H | `0x004047a0`, `0x005911b0` |
| W22-I | `0x004068f0`, `0x005da0a0` |
| W22-J | `0x005dac00`, `0x004c7bd0` |
| W22-K | `0x0084b890`, `0x00419bd0` |
| W22-L | `0x0099a8e0`, `0x00419e20` |
| W22-M | `0x0041a8e0`, `0x004220c0` |
| W22-N | `0x00421677`, `0x006374f0` |
| W22-O | `0x004313d0`, `0x00434dd0` |
| W22-P | `0x00434b30`, `0x00432cb0` |
| W22-Q | `0x004323e0`, `0x007689e0` |
| W22-R | `0x00436900`, `0x004e7450` |
| W22-S | `0x00442b00`, `0x0044adc0` |
| W22-T | `0x004651d0`, `0x0040c7c0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean (use `uint32_t` or scaffold note).
