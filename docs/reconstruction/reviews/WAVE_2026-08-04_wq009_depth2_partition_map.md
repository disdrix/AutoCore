# Partition map — WQ-009 depth-2 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper skill/cast nested residual beyond WQ-009 depth (WQ9D) |
| Dual start | **2268** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | Undualed nested callees of dualed WQ9D units (SkillCNDHash destroy/alloc, presence-flag store/consumer, name-color palette/band, convoy menu parent, crew back-link, tree erase/rebalance callers, hash second factory, map/tree helpers) |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9E-A | `0x004cba60`, `0x004cb410` |
| WQ9E-B | `0x0054fec0`, `0x00627ec0` |
| WQ9E-C | `0x00930f40`, `0x0092d580` |
| WQ9E-D | `0x0082fe20`, `0x00520330` |
| WQ9E-E | `0x004cb740`, `0x004cbb60` |
| WQ9E-F | `0x00603830`, `0x00603c90` |
| WQ9E-G | `0x00406c40`, `0x00409220` |
| WQ9E-H | `0x004c8f00`, `0x0051bbc0` |
| WQ9E-I | `0x0051be90`, `0x0051d700` |
| WQ9E-J | `0x0051d7c0`, `0x0051da30` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names** (not Ghidra iVar paste).
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9eX-report.md`.
7. Prefer skill-domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
