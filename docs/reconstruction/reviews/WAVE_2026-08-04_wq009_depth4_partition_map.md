# Partition map — WQ-009 depth-4 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper skill/cast/map nested residual beyond WQ-009 depth-3 (WQ9F) |
| Dual start | **2308** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | Explicit next step: isnil29 free `0x004cb550` + SkillCNDHash complete dtor `0x0051de80` + insert predecessors / map free / escort ctor / sky caller / tree neighborhood leaves |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9G-A | `0x004cb550`, `0x0051de80` |
| WQ9G-B | `0x004cb4f0`, `0x00401480` |
| WQ9G-C | `0x004cc400`, `0x004c9380` |
| WQ9G-D | `0x0051bed0`, `0x0051e1b0` |
| WQ9G-E | `0x006507c0`, `0x0051f940` |
| WQ9G-F | `0x004912c0`, `0x00406f00` |
| WQ9G-G | `0x004cba00`, `0x00406c00` |
| WQ9G-H | `0x00406de0`, `0x00406e50` |
| WQ9G-I | `0x00406e70`, `0x00406ee0` |
| WQ9G-J | `0x00406f20`, `0x00406fc0` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names** (not Ghidra iVar paste).
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9gX-report.md`.
7. Prefer skill-domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
