# Partition map — WQ-009 depth-7 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper nested residual beyond WQ-009 depth-6 (WQ9I) |
| Dual start | **2368** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | WQ9I gap callees: POD copy Elem12, range-copy 0x28, UI complete dtors, FieldBlock callers, 00409xxx residual neighborhood |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9J-A | `0x00409f50`, `0x0040a520` |
| WQ9J-B | `0x00834520`, `0x00832fa0` |
| WQ9J-C | `0x008327f0`, `0x0097a8a0` |
| WQ9J-D | `0x00634c50`, `0x00833160` |
| WQ9J-E | `0x00416f00`, `0x00409160` |
| WQ9J-F | `0x00409180`, `0x004094c0` |
| WQ9J-G | `0x00409780`, `0x00409820` |
| WQ9J-H | `0x00409880`, `0x004098d0` |
| WQ9J-I | `0x00409920`, `0x00409970` |
| WQ9J-J | `0x00409a00`, `0x00409a30` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names**.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9jX-report.md`.
7. Prefer domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
