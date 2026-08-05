# Multi-agent partition map — wave 35 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1987** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory`; no `disassemble_bytes`; no Launcher |

## High-mention nested callees (missing dual)

| Agent | VAs |
|-------|-----|
| W35-A | `0x0043e630`, `0x004ed310` |
| W35-B | `0x0043c460`, `0x0075d470` |
| W35-C | `0x0074d750`, `0x004397f0` |
| W35-D | `0x00438c40`, `0x00438ca0` |
| W35-E | `0x0044fee0`, `0x0073c810` |
| W35-F | `0x0098fef0`, `0x00542e20` |
| W35-G | `0x0096f530`, `0x005b43b0` |
| W35-H | `0x00754ee0`, `0x00444850` |
| W35-I | `0x007543b0`, `0x0075d8e0` |
| W35-J | `0x00964d00`, `0x004447e0` |
| W35-K | `0x00754480`, `0x0045f360` |
| W35-L | `0x0045f150`, `0x0046a240` |
| W35-M | `0x0045efe0`, `0x0045c4b0` |
| W35-N | `0x00461ac0`, `0x004620b0` |
| W35-O | `0x00461c90`, `0x00461780` |
| W35-P | `0x00461b80`, `0x00461ef0` |
| W35-Q | `0x004611e0`, `0x004612d0` |
| W35-R | `0x0075f7f0`, `0x0074e380` |
| W35-S | `0x0096eec0`, `0x00996bc0` |
| W35-T | `0x004673b0`, `0x00467320` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md`.
4. No parent ledger edits. No invented product names without evidence.
5. Avoid bare `undefined4` in clean.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w35X-report.md`.
