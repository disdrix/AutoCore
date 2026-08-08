# Partition map — WQ-009 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | **WQ-009** skills-abilities (priority 93) |
| Dual start | **2228** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | Highest remaining non-deferred WQ after WQ-008 residual; cast entry managers dualed; expand undualed nested skill-bank / cast residual callees |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9R-A | `0x0051b720`, `0x005749d0` |
| WQ9R-B | `0x0040aff0`, `0x0061fdf0` |
| WQ9R-C | `0x005130e0`, `0x00943340` |
| WQ9R-D | `0x00943520`, `0x004bb0d0` |
| WQ9R-E | `0x005190c0`, `0x00519280` |
| WQ9R-F | `0x005194f0`, `0x005197b0` |
| WQ9R-G | `0x00519d80`, `0x0051a120` |
| WQ9R-H | `0x0051b230`, `0x0051b2a0` |
| WQ9R-I | `0x0051b310`, `0x0051b350` |
| WQ9R-J | `0x0051b550`, `0x00518e30` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names** (not Ghidra iVar paste).
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9rX-report.md`.
7. Prefer skill-domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` entry-point/residual table
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
