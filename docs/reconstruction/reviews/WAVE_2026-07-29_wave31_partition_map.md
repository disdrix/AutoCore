# Multi-agent partition map — wave 31 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1827** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W31-A | `0x0040d630`, `0x0040d820` |
| W31-B | `0x004bf740`, `0x0074b580` |
| W31-C | `0x00763f60`, `0x00494700` |
| W31-D | `0x00494530`, `0x00497a30` |
| W31-E | `0x0040d590`, `0x00969830` |
| W31-F | `0x00754280`, `0x00989ef0` |
| W31-G | `0x00423be0`, `0x00983940` |
| W31-H | `0x00984ee0`, `0x00948bd0` |
| W31-I | `0x0043d670`, `0x0043e3d0` |
| W31-J | `0x0043e970`, `0x0043e9e0` |
| W31-K | `0x00971640`, `0x00971900` |
| W31-L | `0x005b7db0`, `0x004ac100` |
| W31-M | `0x004bcca0`, `0x004bcc60` |
| W31-N | `0x004bbeb0`, `0x004cb4b0` |
| W31-O | `0x0075ceb0`, `0x0075b3b0` |
| W31-P | `0x00492dd0`, `0x0048fc90` |
| W31-Q | `0x0074e200`, `0x00948530` |
| W31-R | `0x0051d0e0`, `0x0051bf10` |
| W31-S | `0x0051bc90`, `0x00530670` |
| W31-T | `0x0094e530`, `0x005825d0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w31X-report.md`.
