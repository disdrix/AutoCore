# Dual A/B report — R11-040 OWN-ONLY (`0x0092bf60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-040**  
**Scope:** VA `0x0092bf60` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x0092adf0` edits.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-040**.  
**Work item:** Residual dual wave R11 — inventory-transfer partition (parent `0x0092adf0`); role = MissionTracker target refresh.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092bf60` MissionTracker_RefreshTrackedTargets_Inferred | **accept-with-gaps** — CF/ABI/timer/primary-bind/secondary/sole-caller sealed from bytes; product English + residual callees open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler-complete / thiscall / void / always-both-arms / multi-caller / HUD-same claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092bf60` — sealed facts

1. **Body:** `0x0092bf60`–`0x0092c075` inclusive (**278 B** / `0x116`); next `FUN_0092c080` after `CC` pad.
2. **ABI:** **EAX = MissionTracker\* host** (`MOV EDI,EAX`); no stack args; **AL = bool**; **`ADD ESP,8; RET`** (locals only).
3. **Semantics — tracked-target refresh:**
   - Guards: `*host` client, `client+0xE98` character, `client+0xE04` non-null.
   - `Tracker_ClearOwnedPtrVectorAt11c_Inferred` (`0x0092a3d0`, EDI=host).
   - `host+0x14 = 4.0f` (`DAT_00aaa690`).
   - Busy gate `character+0x4F1==0` and `client+0xD34!=0`.
   - Origin via character this-adjust + vtbl **`+0x1A0`**.
   - Primary: `FUN_0092af80` with bestObj=null, bestDistSq=**1e9f** (`DAT_00aaaaf8`); EAX=host filter ctx.
   - On hit: type flag `host+0xB` vs clonebase `+0x38` ∈ {**`0x12`**, **`0x0E`**}; `FUN_0092a440(obj, host)`; on non-null node clear `host+0x8` and copy **TFID_16** from `obj+0x160`.
   - Secondary: `FUN_0092b2a0(host, origin)`; fail clears `host+0x8`, returns 0.
4. **Callees:** `0x0092a3d0`, vtbl+`0x1A0`, `0x0092af80`, `0x0092a440`, `0x0092b2a0`.
5. **Callers:** **1** — `FUN_0092c640` @ `0x0092c67c` (`MOV EAX,ESI` after `FUN_0092c080` when dirty `host+4`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `MissionTracker_RefreshTrackedTargets_Inferred` (Ghidra `FUN_0092bf60`).
8. **Decompiler ⊊ bytes CF** — primary bind path must come from `read_memory` / assembly context.

### Gaps

- Product/PDB host class and vector element English.  
- Official names for vtbl `+0x1A0`, flags `+0x08`/`+0x0B`, clone types `0x12`/`0x0E`.  
- Duals of residuals `0092af80` / `0092a440` / `0092b2a0` / `0092c640` / `0092c080`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R11-040 re-verify append) | `docs/reconstruction/raw/aa_0092bf60_FUN_0092bf60.md` |
| Annotated | `docs/reconstruction/raw/aa_0092bf60_FUN_0092bf60.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/MissionTracker_RefreshTrackedTargets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092bf60.cpp` |
| Function | `docs/reconstruction/functions/aa_0092bf60_FUN_0092bf60.md` |
| Function named | `docs/reconstruction/functions/aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0092c640  MissionTracker timer/dirty tick  [residual]
  when host+0x14 countdown < 0: reload 4.0f, set dirty host+4
  when dirty:
    MOV EAX,ESI ; CALL FUN_0092c080   bind/fill filter lists  [residual]
    MOV EAX,ESI ; CALL FUN_0092bf60   RefreshTrackedTargets   [OWN R11-040]
    host+4 = 0

FUN_0092bf60  MissionTracker_RefreshTrackedTargets_Inferred  [OWN R11-040]
  ├─ FUN_0092a3d0  Tracker_ClearOwnedPtrVectorAt11c_Inferred  [dualed MEGA-088]
  ├─ character vtbl+0x1A0  origin
  ├─ FUN_0092af80  multi-list target dispatcher  [residual]
  │    └─ FUN_0092adf0  TargetFilter_FindNearestWorldObjByCbidList_Inferred  [dualed WQ8R-I]
  │         └─ InventoryGrid_FindItemByCoid (locker absence gate)
  ├─ FUN_0092a440  node alloc/bind + optional reaction scan  [residual]
  └─ FUN_0092b2a0  secondary multi-target fill into +0x11c  [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092bf60-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092bf60` | Port as **MissionTracker tracked-target refresh**. **EAX=host**, **AL=bool**, no stack args. Always clear vector `+0x11c` + set timer `+0x14=4.0f` first. Primary: multi-list filter → node + **TFID_16** from `obj+0x160`. Secondary: `0092b2a0`. **Do not** trust collapsed Ghidra decompiler for the primary bind arm. Pair with timer `0092c640`, bind `0092c080`, clear `0092a3d0`, filter parent `0092adf0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md`  
- `systems/inventory-transfer.md` and/or missions-progression residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
