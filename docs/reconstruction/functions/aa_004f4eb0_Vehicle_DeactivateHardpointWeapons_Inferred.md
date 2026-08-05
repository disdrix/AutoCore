# Function record: Vehicle_DeactivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4eb0` |
| **Canonical name** | `Vehicle_DeactivateHardpointWeapons_Inferred` |
| **Ghidra symbol** | `FUN_004f4eb0` |
| **Address** | `0x004f4eb0`–`0x004f4efe` (78 B exclusive end) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle hardpoint weapons |
| **Completion status** | **partial** — dual A/B accept-with-gaps (W24-Q 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Body sealed via `read_memory`; package / runtime open |

## Alias

| Name | Notes |
|---|---|
| `FUN_004f4eb0` | Ghidra default |
| `Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl_004f4eb0` | Weak parent-seed alias (superseded) |

## Purpose

Deactivate all **hardpoint weapons** on a vehicle:

1. Walk the **3-slot** pointer table at **`vehicle+0x260`** (stride 4, bound `0xC`).
2. For each non-null weapon:
   - `Weapon_SetFireFlagPair_Inferred(w, 0)`
   - `Weapon_SetSuppressFlag_Cb_Inferred(w, 0)`
   - `w->vtbl[+0x18](0)` deactivate-class vfunc

Called during vehicle switch (`FUN_005252f0`) with ECX = `*(session+0x250)`.

## Signature

```c
void __fastcall Vehicle_DeactivateHardpointWeapons_Inferred(
    void* vehicle /* ECX */);
```

## Machine body

```
56 57 8bf9 33f6 eb08 8da42400000000 90
8b8760020000 8b0c06 85c9 7427
6a00 e8...          ; 0056a260(0)
8b8f60020000 8b0c31
6a00 e8...          ; 0056b400(0)
8b9760020000 8b0c16 8b01
6a00 ff5018         ; vtbl+0x18(0)
83c604 83fe0c 7cc4
5f5e c3
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f4eb0_FUN_004f4eb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004f4eb0_FUN_004f4eb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_DeactivateHardpointWeapons_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004f4eb0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |

## Callers / callees

**Callees:** `FUN_0056a260`, `FUN_0056b400`, weapon `vtbl+0x18`.

**Callers (live xrefs 2026-07-29):**

| Function | Entry | Call site | ECX |
|---|---|---|---|
| `FUN_005252f0` | `0x005252f0` | `0x0052556b` | `*(this+0x250)` vehicle |

## Related (not owned)

| Unit | VA | Relation |
|---|---|---|
| `FUN_004f4f00` | `0x004f4f00` | Activate twin (same table; vfunc arg 1) |
| `Vehicle_FireAllPrimaryWeapons_Inferred` | `0x004f50d0` | Same `+0x260` table, fire path |
| `Weapon_SetFireFlagPair_Inferred` | `0x0056a260` | Fire flags +0xC7/+0xC8 |
| `Weapon_SetSuppressFlag_Cb_Inferred` | `0x0056b400` | Suppress +0xCB |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes / plain ret | **High** |
| 3-slot table at +0x260 | **High** |
| Clear fire + suppress + vfunc(0) order | **High** |
| ECX = vehicle from session+0x250 | **High** |
| Name role `…DeactivateHardpointWeapons…` | **Probable** / product open |
| `vtbl+0x18` English | **Medium** |
| Runtime / bit-exact package | **Open** |
