# Function record: Vehicle_SetWheelset

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fea90` |
| **Canonical name** | `Vehicle_SetWheelset` |
| **Address** | `0x004fea90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / vehicle equip |
| **Completion status** | **Human-refined scaffold** — clean rewritten; dual review open; FUN_00512670 / FUN_004fdcb0 roles inferred |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Store wheelset object at `vehicle+0x258` (600), validate clonebase type `0x10`, bind owner, set up wheel contacts/graphics, notify sector map, and scale each wheel from chassis float table at clonebase `+0x600`.

## Signature (decompiler-derived + refined)

```c
void __thiscall Vehicle_SetWheelset(int thisVehicle, int pWheelset /* or null */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004fea90_Vehicle_SetWheelset.md`
- Annotated: `docs/reconstruction/raw/aa_004fea90_Vehicle_SetWheelset.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_SetWheelset.cpp`

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `FUN_00512670` | Pre-attach teardown (INFERRED) |
| Callee | `FUN_004fdcb0` | Wheel contact / graphics setup |
| Callee | `FUN_005a6e00` | Wheel object by index |
| Callee | wheelset vfunc+0x158 / +0x218 | Bind owner / sector notify |
| Callers | `Vehicle_EquipFromCreate`, InventoryEquip 0x203C | Plate |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Slot at +0x258 / type 0x10 | High |
| Wheel count at wheelset+0xb0 | High |
| Scale table chassis+0x600 | High (raw) |
| FUN_00512670 exact role | Tentative |
