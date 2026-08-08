# Partition map — WQ-009 depth-5 residual dual seal (2026-08-04)

| Field | Value |
|-------|-------|
| Work item | Deeper nested residual beyond WQ-009 depth-4 (WQ9G) |
| Dual start | **2328** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Rationale | WQ9G gap callees: CNDHash freelist/ctor/dtor/recreate stamp family, vector InsertN/construct/push_back, free-subtree full-clear, pair-key less peer, escort factory, env day-cycle parent, TFID find consumers |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| WQ9H-A | `0x004085e0`, `0x00408050` |
| WQ9H-B | `0x00409d40`, `0x004082f0` |
| WQ9H-C | `0x00406220`, `0x004062a0` |
| WQ9H-D | `0x004063a0`, `0x00406420` |
| WQ9H-E | `0x004195d0`, `0x0060c860` |
| WQ9H-F | `0x00407d70`, `0x00406560` |
| WQ9H-G | `0x00942e20`, `0x00807550` |
| WQ9H-H | `0x00408590`, `0x00408640` |
| WQ9H-I | `0x00408880`, `0x004088f0` |
| WQ9H-J | `0x00408990`, `0x00408a30` |

## Deliverables per owned VA

1. Live decompile + read_memory (no disassemble_bytes).
2. Trio raw + annotated + **clean reconstructed-exact with meaningful names**.
3. Dual A_aa_* + B_aa_* with evidence, confirmations, residual gaps.
4. Function records (FUN + named when evidence).
5. No parent ledger edits.
6. Report: `docs/agents/task-dual-ab-<va1>-<va2>-wq9hX-report.md`.
7. Prefer domain names with string/RTTI evidence; else `_Inferred`.

## Parent merge requirements (mandatory)

After duals land, parent MUST lockstep for **every** dualed VA:
- `VERIFICATION_MATRIX.md` row
- `NAMING_REGISTRY.md` entry + rename-history line
- `systems/skills-abilities.md` residual table entry (missions map if mission-domain)
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

## Verdict language

accept / accept-with-gaps / reject. Never claim runtime Confirmed without Launcher. Terminal false.
