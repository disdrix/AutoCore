# Partition map — WQ-007 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | **WQ-007** missions-progression (priority 96) |
| Dual start | **2193** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | Highest-priority non-deferred WQ; entry managers dualed; residual undualed callees on dialog/journal/complete/give call chains |

## Ownership (2 VAs each)

| Agent | VAs | Role hint |
|-------|-----|-----------|
| WQ7R-A | `0x008ac7a0`, `0x008aaf60` | Mission dialog path (HandleButton consumers) |
| WQ7R-B | `0x008ac110`, `0x008aa610` | Mission UI helper chain |
| WQ7R-C | `0x008aab00`, `0x008aa560` | Mission dialog chrome helpers |
| WQ7R-D | `0x005465c0`, `0x00411180` | Mission string/state helpers |
| WQ7R-E | `0x00829ec0`, `0x0040b6d0` | Journal/UI + vector helper |
| WQ7R-F | `0x00521800`, `0x00521900` | Mission name/format helpers (callee of 005465c0) |
| WQ7R-G | `0x007f5120`, `0x007f9160` | UI window helpers (callee of 008aab00) |
| WQ7R-H | `0x0060d630`, `0x006508d0` | Callers of GiveMission / CompleteObjective residual |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + reconstructed-exact + function record.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. No parent ledger edits.
5. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq7rX-report.md`.
6. Prefer mission-domain names with string/RTTI evidence; else `_Inferred`.

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
