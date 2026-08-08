# Partition map — WQ-009 depth-8 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper nested residual beyond WQ-009 depth-7 (WQ9J) |
| Dual start | **2388** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | WQ9J gap callees: range-copy trampoline, string dtor, erase-range free callers, buynode wrappers, tree head/predecessor, UI base/nested dtors, shop reindex, rotates, factories |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9K-A | `0x00409ae0`, `0x00409b80` |
| WQ9K-B | `0x00407b70`, `0x00407f90` |
| WQ9K-C | `0x00404180`, `0x00405f20` |
| WQ9K-D | `0x00406190`, `0x00405bd0` |
| WQ9K-E | `0x00408ed0`, `0x00833d50` |
| WQ9K-F | `0x0078ca80`, `0x007b5be0` |
| WQ9K-G | `0x0082d540`, `0x00792c20` |
| WQ9K-H | `0x0083ac90`, `0x00416830` |
| WQ9K-I | `0x004168c0`, `0x0044e010` |
| WQ9K-J | `0x0042a840`, `0x0040a590` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names**.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9kX-report.md`.
7. Prefer domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
