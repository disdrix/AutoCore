# Review A (reconstruction fidelity): `aa_00522f70` Character_SyncEquippedRaceItemFromCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522f70` |
| **VA** | `0x00522f70` |
| **Canonical name** | `Character_SyncEquippedRaceItemFromCbid_Inferred` (Ghidra `FUN_00522f70`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00522f70_Character_SyncEquippedRaceItemFromCbid_Inferred.md` |
| **System** | character race-item equip / inventory / ghost |
| **Evidence pass** | Live `batch_decompile`; callees `Object_ResolveFromTFID`, `CVOGReaction_GiveItemByCbid`, `FUN_005210b0`; caller `FUN_00524680` setter |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Materialize / resync** the character’s equipped race-item world object from stored CBID **`this+0x514`**, using cached TFID at **`this+0x518`**.

High-level CF:

1. `obj = Object_ResolveFromTFID(this+0x518)`.
2. If `obj` is null **or** `*(clonebase(obj)+0x34) != *(this+0x514)` (CBID mismatch):
   - `FUN_005210b0()` — teardown/clear prior race-item binding (inferred).
   - If `*(this+0x514) == -1`: stop (cleared; no new item).
   - Else `item = CVOGReaction_GiveItemByCbid(cbid)`:
     - vfunc `+0x8(cbid, map, 0)` init
     - `obj2 = vfunc +0x1d8()`; if null, dtor `*vtbl(1)`
     - Adjust map counters at `map+0xe6e8/0xe6ec`, `FUN_00512160`
     - `FUN_004bc180` on object subobject
     - Pull character pose TFID via vtbl `+0x1a0`; `FUN_004e9720(map, pose, 15.0f, 1.0f, scratch, 0x14, 10, 0)` place/spawn helper
     - Attach vfunc `+0x218(map)`
     - `FUN_004ca910(char+0x164, 0)`
     - Scale/UI fields on new object: `+0x270` (level-up UI base vs alt), `+0x1f0` from `FUN_004c55e0 * _DAT_00a0f69c`, `+0x310` map-flagged constant
     - `FUN_004bff90(obj+0x40, …)`
     - Copy object TFID (`obj` subobject `+0x164`) into destination (decomp shows `unaff_ESI` — likely `this+0x518` write residual)

If existing object already matches CBID: no-op.

**Callers:** `FUN_00524680` (primary setter), `VehicleNet_UnpackGhostVehicle`, `VehicleNet_ReconcilePrediction`, `FUN_0060a030`, `FUN_0060a820`.

Related: vehicle race-item equip is `Vehicle_SetEquippedRaceItem` (`0x00502460`); this is the **character-side** CBID→object sync.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00522f70_FUN_00522f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00522f70_FUN_00522f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00522f70.cpp` |
| Function record | `docs/reconstruction/functions/aa_00522f70_FUN_00522f70.md` |

**Three-rep:** present (scaffold clean; decomp `unaff_ESI` residual).

---

## 3. Signature

```c
// __fastcall  ECX = character*  (no stack args observed)
void Character_SyncEquippedRaceItemFromCbid(void *self);
// reads:  self+0x514 (cbid, -1 = none), self+0x518 (TFID_16)
// writes: race-item object + TFID cache (via teardown/spawn path)
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`__fastcall` decomp) | **High** |
| cbid field | `+0x514` | **High** |
| tfid cache | `+0x518` | **High** |
| clonebase CBID | `obj+0xa8 → +0x34` | **High** |
| `-1` = unequip/clear | after teardown | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Resolve TFID; mismatch gate | **Yes** | **High** |
| Teardown then GiveItemByCbid | **Yes** | **High** |
| `-1` skips create | **Yes** | **High** |
| Map counter / place / attach / scale tail | **Yes** | **High** (order) |
| Final TFID write target | **Tentative** | decomp `unaff_ESI` — likely `+0x518` but not sealed |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role: sync race-item object from CBID | **High** | GiveItemByCbid + mismatch vs `+0x514` |
| Fields `+0x514` / `+0x518` | **High** | |
| Teardown helper `FUN_005210b0` | **Probable** | called only on mismatch |
| Place constants 15.0f / 1.0f | **High** | imm `0x41700000` / `0x3f800000` |
| Exact TFID store destination | **Tentative** | unaff register |
| English “race item” product term | **Probable** | parallel vehicle race-item path; not string-proven |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Seal `unaff_ESI` / TFID write as `this+0x518` via asm or force-decompile.
2. Full semantics of `FUN_005210b0`, `FUN_004e9720`, `FUN_004bff90` callees.
3. Map flags `map+0xf5` branch constants (`g_flLevelUpUiBase_Inferred`, `DAT_00a110d8`, `DAT_00aaa7a4`, `DAT_00a0f694`).
4. Relationship to vehicle hardpoint race-item slot 8.

**Verdict:** **accept-with-gaps**
