# Partition map — WQ-009 depth-9 residual dual seal (2026-08-05)

| Field | Value |
|-------|-------|
| Work item | Deeper nested residual beyond WQ-009 depth-8 (WQ9K) |
| Dual start | **2408** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | WQ9K gap callees: map/tree helpers, UI complete-dtor chain leaves, shop list helpers, CS/string teardown |

## Ownership (2 VAs each)

| Agent | VAs | Parent context |
|-------|-----|----------------|
| WQ9L-A | `0x00404000`, `0x00408ad0` | erase-range isnil131 free parents |
| WQ9L-B | `0x00401bc0`, `0x00403e90` | erase-and-rebalance isnil31 |
| WQ9L-C | `0x00403ee0`, `0x004043e0` | erase-and-rebalance isnil31 |
| WQ9L-D | `0x0076c4d0`, `0x0078c3d0` | CWndVehicle / CNDUIWndBuffered dtor chain |
| WQ9L-E | `0x007a8580`, `0x00424060` | CNDUIWindow complete dtor |
| WQ9L-F | `0x00759de0`, `0x00797d70` | CNDUIWindow complete dtor |
| WQ9L-G | `0x007aec70`, `0x007aff00` | CNDUIWindow complete dtor |
| WQ9L-H | `0x0082ce20`, `0x00415e90` | CVOGMenu / CNDUIDialog dtor |
| WQ9L-I | `0x007917c0`, `0x0083a860` | dialog dtor / shop reindex |
| WQ9L-J | `0x0083a880`, `0x0083abf0` | shop reindex helpers |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes). Prefer `disassemble_function` only if decompiler ABI is clearly wrong.
2. Trio: refresh raw (append re-verify section only — never wipe original capture) + annotated + **clean reconstructed-exact with meaningful names**.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps; verdict accept / accept-with-gaps / reject.
4. Function records (FUN + named when evidence).
5. **No parent ledger edits** (VERIFICATION_MATRIX, NAMING_REGISTRY, WORK_QUEUE, RESUME, ACTIVE_WORK, CHANGE_LOG, COVERAGE_LEDGER, progress.json, system maps).
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9lX-report.md`.
7. Prefer domain names with string/RTTI evidence; else `_Inferred`. Never invent product names.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry (depth-9 section)
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
