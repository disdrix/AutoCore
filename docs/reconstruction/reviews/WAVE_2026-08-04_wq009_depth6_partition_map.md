# Partition map — WQ-009 depth-6 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper nested residual beyond WQ-009 depth-5 (WQ9H) |
| Dual start | **2348** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | WQ9H gap callees: freelist vector teardown, ConstructN/POD copy, isnil21 insert, buynode ctor, POD placement, CNDHash recreate caller, + 00416xxx residual neighborhood |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9I-A | `0x00416e80`, `0x00409db0` |
| WQ9I-B | `0x00409f30`, `0x00407200` |
| WQ9I-C | `0x00407060`, `0x004099b0` |
| WQ9I-D | `0x0040a6e0`, `0x007fe640` |
| WQ9I-E | `0x00416010`, `0x004160b0` |
| WQ9I-F | `0x004160d0`, `0x004160f0` |
| WQ9I-G | `0x00416110`, `0x00416160` |
| WQ9I-H | `0x00416240`, `0x00416350` |
| WQ9I-I | `0x00416370`, `0x00416390` |
| WQ9I-J | `0x00416590`, `0x004165f0` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names**.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9iX-report.md`.
7. Prefer domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
