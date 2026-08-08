# Partition map — WQ-009 depth-3 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper skill/cast/map nested residual beyond WQ-009 depth-2 (WQ9E) |
| Dual start | **2288** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | Explicit WQ9E ADV residual freelist `0x004cb680` + buynode twins + erase/insert callers + map free/erase helpers + skill neighborhood leaves |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9F-A | `0x004cb680`, `0x005a2de0` |
| WQ9F-B | `0x00407e30`, `0x004c8610` |
| WQ9F-C | `0x004c8780`, `0x004cbaa0` |
| WQ9F-D | `0x004cbe20`, `0x004cbee0` |
| WQ9F-E | `0x004cc220`, `0x0051be10` |
| WQ9F-F | `0x0051c880`, `0x0051be50` |
| WQ9F-G | `0x0051ce00`, `0x0051e120` |
| WQ9F-H | `0x0051de60`, `0x0051e180` |
| WQ9F-I | `0x0051f880`, `0x00574880` |
| WQ9F-J | `0x00553cd0`, `0x0051d940` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names** (not Ghidra iVar paste).
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9fX-report.md`.
7. Prefer skill-domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
