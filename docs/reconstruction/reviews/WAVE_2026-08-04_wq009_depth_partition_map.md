# Partition map — WQ-009 depth residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper skill/cast nested residual beyond WQ-009 residual |
| Dual start | **2248** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | High-mention undualed callees of dualed skill-hash / rank / cast residual paths |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9D-A | `0x004cbdc0`, `0x0051dd60` |
| WQ9D-B | `0x0051b5d0`, `0x0061f940` |
| WQ9D-C | `0x0061b6f0`, `0x004192a0` |
| WQ9D-D | `0x004192f0`, `0x005755b0` |
| WQ9D-E | `0x00627be0`, `0x0040c700` |
| WQ9D-F | `0x00578ce0`, `0x007a4170` |
| WQ9D-G | `0x00421b50`, `0x00574a90` |
| WQ9D-H | `0x0051c7c0`, `0x0051d880` |
| WQ9D-I | `0x007ffef0`, `0x0082fb30` |
| WQ9D-J | `0x00930fc0`, `0x00553dd0` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names** (not Ghidra iVar paste).
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9dX-report.md`.
7. Prefer skill-domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
