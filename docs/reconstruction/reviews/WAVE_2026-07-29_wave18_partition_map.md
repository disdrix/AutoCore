# Multi-agent partition map — wave 18 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1307** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W18-A | `0x00435df0`, `0x005081f0` |
| W18-B | `0x004024d0`, `0x008073b0` |
| W18-C | `0x005828b0`, `0x0054b480` |
| W18-D | `0x00421aa0`, `0x00423b10` |
| W18-E | `0x00436650`, `0x0043f210` |
| W18-F | `0x007252d0`, `0x004ba310` |
| W18-G | `0x0076cf00`, `0x00720670` |
| W18-H | `0x004c41c0`, `0x0094a6a0` |
| W18-I | `0x00606180`, `0x0052c780` |
| W18-J | `0x00536740`, `0x00538200` |
| W18-K | `0x0060c010`, `0x004248c0` |
| W18-L | `0x009210e0`, `0x006173a0` |
| W18-M | `0x007227e0`, `0x0040d9c0` |
| W18-N | `0x00437050`, `0x0076c270` |
| W18-O | `0x00480ca0`, `0x00862860` |
| W18-P | `0x0076f970`, `0x00419b80` |
| W18-Q | `0x00435f30`, `0x004507a0` |
| W18-R | `0x00725a70`, `0x00521310` |
| W18-S | `0x00439770`, `0x00615020` |
| W18-T | `0x004bb1c0`, `0x004cf120` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
