# Dual A/B report — WQ9H-E OWN-ONLY (`0x004195d0`, `0x0060c860`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-E**  
**Scope:** VAs `0x004195d0`, `0x0060c860` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-E**.  
**Work item:** WQ-009 depth-5 residual dual seal (CNDHash recreate stamp family + Escort factory/new path).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004195d0` CNDHash_Recreate_00a2c2e4 | **accept-with-gaps** — recreate CF/ABI/lock-continue/stamp helpers sealed; product host English open |
| `aa_0060c860` CVOGHBMissionEscort_ReactionFactory_Inferred | **accept-with-gaps** — reaction factory CF/ABI/size-0x78/Escort-ctor path sealed; method English + stub owners open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; skill-thiscall-merge, hard-lock-abort, ctor-identity, Outpost-identity, noreturn-delete, literal decompiler-return all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004195d0` — sealed facts

1. **Body:** `0x004195d0`–`0x00419618` inclusive (**73 B** / `0x49`); `CC` pad after bare `ret`.
2. **ABI:** custom **EAX = CNDHash\***; **BL = log2**; no stack args; **void**; bare **`ret`** (`5E C3`). Entry `56 8B F0`.
3. **Semantics:** host-family CNDHash **recreate**:
   - If lock `@+0x1d`: log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"` then **continue**.
   - `CNDHash_DestroyBucketTable_00a2c2e4` (`0x00406fc0`) via `mov eax,esi`.
   - Seed log2 `@+0x1c`, provisional count `1<<log2` `@+8`, clear ordered `@+0x14`/`@+0x18`.
   - `CNDHash_AllocBucketTable_00a2c2e4` (`0x00406f20`) with ESI (mask post-condition).
4. **Callers (1):** `FUN_007fe640` @ `0x007fe707` — unlock `@+0x1d`; `EAX=*(owner+0x3084)`; **`MOV BL,2`**.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `CNDHash_Recreate_00a2c2e4` (Ghidra `FUN_004195d0`). Reject `Named_VOG_DEBUG_STOP_004195d0`.
7. **Decompile ≡ raw CF**; ABI/strings sealed via `read_memory`.

### Gaps

- Product / PDB English for host class behind vtbl `00a2c2b0` / stamp `00a2c2e4`.  
- Full dual of caller `FUN_007fe640` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004195d0_FUN_004195d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004195d0_FUN_004195d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_00a2c2e4.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004195d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004195d0_FUN_004195d0.md` |
| Function named | `docs/reconstruction/functions/aa_004195d0_CNDHash_Recreate_00a2c2e4.md` |

---

## VA `0x0060c860` — sealed facts

1. **Body:** `0x0060c860`–`0x0060c991` inclusive (**306 B** / `0x132`); `CC` pad after `ret 8`.
2. **ABI:** **`__thiscall`**; ECX = **reqHost**; stack **ownerCtx**, **scoreFloats\***; **`ret 8`**; returns **bool AL** (fail `xor al,al`, success `mov al,1`).
3. **Semantics:** Escort **reaction factory / new path**:
   - Gate: ownerObj enable `@+0x7e` + key `req+0x40 == obj+0xfc`.
   - `CVOGReaction_ResolveSkillTargets`; optional `CastSkillOnTarget` if `req+0x20` (fail → delete targets, false).
   - Score: `scoreFloats[1+req[8]] = g_flOne` (`0x00a0f2a0`).
   - Spawn if `(g_flZero < req+0x1c float || req+0x18) && dword[targets+0x14c] != -1`:
     `operator_new(0x78)` → `CVOGHBMissionEscort_ctor` (`0x006507c0`) → `CVOGHBList_Enqueue` (`*(obj+0xe4ec)`) → `CVOGHBBase_Start`.
   - `operator_delete(targets)`; return true.
4. **Xrefs (2):** CALL stub `0x0060cab2` (`ret 0x1c`); JMP thunk `0x0060cac0`. Ghidra callers list empty (stubs outside named FUNs).
5. **Name:** `CVOGHBMissionEscort_ReactionFactory_Inferred` (Escort identity High via dualed ctor RTTI; method English open).
6. **Decompile ≡ raw CF**; return/size/gate sealed via `read_memory`. Decompiler `uVar3 & 0xffffff00` and noreturn-on-delete are **artifacts**.

### Gaps

- Product / PDB reaction method English.  
- Enclosing type of call stubs at `0060cab2` / `0060cac0`.  
- Deep types for Resolve/Cast skill APIs.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0060c860_FUN_0060c860.md` |
| Annotated | `docs/reconstruction/raw/aa_0060c860_FUN_0060c860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMissionEscort_ReactionFactory_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060c860.cpp` |
| Function | `docs/reconstruction/functions/aa_0060c860_FUN_0060c860.md` |
| Function named | `docs/reconstruction/functions/aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_007fe640  (post-traverse unlock on hash @ owner+0x3084)
  └─ CNDHash_Recreate_00a2c2e4 (0x004195d0)                 [OWN WQ9H-E]
        ├─ CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0) [dualed WQ9G-J]
        └─ CNDHash_AllocBucketTable_00a2c2e4   (0x00406f20) [dualed WQ9G-J]

CVOGHBMissionEscort_ReactionFactory_Inferred (0x0060c860)  [OWN WQ9H-E]
  ├─ CVOGReaction_ResolveSkillTargets / CastSkillOnTarget
  ├─ operator_new(0x78)
  ├─ CVOGHBMissionEscort_ctor (0x006507c0)                  [dualed WQ9G-E]
  │     └─ OnHB vtable+0x0C → CVOGHBMissionEscort_OnHeartBeat
  ├─ CVOGHBList_Enqueue
  └─ CVOGHBBase_Start
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004195d0-0060c860-wq9he-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004195d0` Recreate | Port as **shared CNDHash recreate** for stamp **`00a2c2e4`**. **EAX/BL** ABI (not thiscall). Lock soft-continues. Pair with destroy `00406fc0` + alloc `00406f20`. Do not merge with skill thiscall recreate `004cbdc0`. |
| `0060c860` Escort factory | Port as **reaction factory** for **CVOGHBMissionEscort**: size **0x78**, ctor `006507c0`, Enqueue `@+0xe4ec`, Start. **thiscall ret 8 → bool**. Preserve conditional spawn + cast-fail early false. Pair with OnHB `006508d0`. |
| Pair with | host hash ctor/dtor (WQ9H-D residuals); freelist; Escort ctor/OnHB duals. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual / CNDHash table **and** `systems/missions-progression.md` for Escort factory  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004195d0`, `0x0060c860`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only (headers updated for sealed names).  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: lock soft-continue; OOM null still Enqueue/Start; decompiler return artifact corrected in clean to bool AL.  
- Stamp-suffix naming for recreate; `_Inferred` for factory method English; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
