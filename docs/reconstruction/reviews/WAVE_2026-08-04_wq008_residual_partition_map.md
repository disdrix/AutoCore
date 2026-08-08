# Partition map — WQ-008 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | **WQ-008** inventory-transfer (priority 94) |
| Dual start | **2209** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | Highest remaining non-deferred WQ after WQ-007 residual; entry grab/drop/equip dualed; expand undualed nested callees mentioned by dualed HP inventory artifacts |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ8R-A | `0x005718a0`, `0x00588290` |
| WQ8R-B | `0x00531570`, `0x005316c0` |
| WQ8R-C | `0x00570af0`, `0x005715d0` |
| WQ8R-D | `0x00829190`, `0x00571d80` |
| WQ8R-E | `0x00573910`, `0x00607550` |
| WQ8R-F | `0x008c4fc0`, `0x0082f510` |
| WQ8R-G | `0x00571db0`, `0x0080d570` |
| WQ8R-H | `0x0085ce20`, `0x008e5ce0` |
| WQ8R-I | `0x0092adf0`, `0x00941f50` |
| WQ8R-J | `0x00522710`, `0x005706d0` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names** (not Ghidra iVar paste).
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq8rX-report.md`.
7. Prefer inventory-domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (not agent work)

After duals land, parent MUST lockstep: VERIFICATION_MATRIX rows for **all** dualed VAs, NAMING_REGISTRY entries + rename history, systems/inventory-transfer.md entry points, WORK_QUEUE/RESUME/CHANGE_LOG/progress.json.

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
