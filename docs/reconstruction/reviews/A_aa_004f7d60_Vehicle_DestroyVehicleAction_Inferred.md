# Review A (reconstruction fidelity): `aa_004f7d60` Vehicle_DestroyVehicleAction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7d60` |
| **VA** | `0x004f7d60` |
| **Canonical name** | `Vehicle_DestroyVehicleAction_Inferred` (was `FUN_004f7d60`) |
| **Ghidra symbol** | `FUN_004f7d60` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — vehicle action residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f7d60_Vehicle_DestroyVehicleAction_Inferred.md` |
| **System** | input-drive-control / vehicle action lifecycle |
| **Callers** | `Vehicle_createVehicleAction` `0x004fb660` (duplicate path), `FUN_004f8fe0`, `FUN_005004f0` |
| **Callees** | `FUN_0055df40` (unregister action), COM release vtbl, `operator_delete` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Tear down vehicle action holder** at `entity+0x1a0` (the 0xC triple produced by `Vehicle_createVehicleAction`).

Live body:

```
if (entity+0x1a0 == 0) return;

// 1) Release mode-helper COM at physics object (entity+8)+0x54; null it
phys = *(entity+8)
if phys+0x54: ReleaseRef(phys+0x54); phys+0x54 = 0

// 2) If holder[0] (VehicleAction*) non-null:
//      FUN_0055df40(action)   // unregister from world/action list
//      ReleaseRef(action)

// 3) ReleaseRef(holder[1])    // framework COM at +4
//    (no explicit release of holder[2] driver-input — residual ownership)

// 4) operator_delete(holder); entity+0x1a0 = 0
```

Refcount pattern: short at COM `+6`; when hits 0, `(*vtbl)(1)` destroy.

Used as **duplicate-action hard cleanup** from createVehicleAction after log string, and from other vehicle teardown paths.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004f7d60` |
| Callers | `get_function_callers` → `004f8fe0`, `005004f0`, `004fb660` |
| Parent layout | `physics/verified/fn_004fb660_createVehicleAction.md` (`+0x1a0` triple) |
| Related dual | `A_aa_004fb660_Vehicle_createVehicleAction.md` |
| Raw / clean | `raw/aa_004f7d60_*`, `FUN_004f7d60.cpp` |

---

## 3. Signature

```c
// ECX = vehicle entity
void __fastcall Vehicle_DestroyVehicleAction(VehicleEntity *entity);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| No-op when `+0x1a0 == 0` | **High** |
| Clears `*(entity+8)+0x54` mode helper | **High** |
| Unregisters action via `FUN_0055df40` then releases | **High** |
| Releases framework at holder+4 | **High** |
| Deletes holder; nulls `+0x1a0` | **High** (Ghidra “delete noreturn” warning is analysis noise; store after call present in CF intent) |
| Does **not** release holder+8 (driver input) in this body | **High** CF / ownership **Open** |
| Exact English for `FUN_0055df40` | **Medium** (unregister family) |

**Verdict:** **accept-with-gaps**
