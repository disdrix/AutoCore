# Function record: Character_SetLocalVehiclePtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f4e0` |
| **Canonical name** | `Character_SetLocalVehiclePtr_Inferred` |
| **Address** | `0x0051f4e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | character / local vehicle |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_0051f4e0`
- Prior: `Named_CalleeOf_Client_RecvInventoryUsePaint_0051f4e0`

## Purpose

Store vehicle* (or null) at `character+0xcd0`. If non-null, call vehicle vfunc `+0x158`. Used by paint apply, inventory cursor set/clear via `client+0xe98`.

## Signature

```c
void __thiscall Character_SetLocalVehiclePtr_Inferred(void *character, void *vehicleOrNull);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051f4e0_FUN_0051f4e0.md`
- Annotated: `docs/reconstruction/raw/aa_0051f4e0_FUN_0051f4e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0051f4e0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md`

## Callers / callees

- Callers: `Client_RecvInventoryUsePaint`, `Client_ClearInventoryCursor`, `Client_SetInventoryCursor`
- Callees: indirect vfunc `+0x158`

## Confidence

| Claim | Level |
|---|---|
| `+0xcd0` store + optional vcall | **Confirmed** |
| Local vehicle field role | **High** |
| vfunc English | **Open** |
