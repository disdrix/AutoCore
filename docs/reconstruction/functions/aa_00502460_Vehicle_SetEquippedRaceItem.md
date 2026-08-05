# Function record: Vehicle_SetEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502460` |
| **Canonical name** | `Vehicle_SetEquippedRaceItem` |
| **Address** | `0x00502460` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean** — dual review not required this wave; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Set race-item hardpoint `this+0x270`. Optional previous-out, unbind, type-check class 6 / subtype `0xb`, bind + post-attach, `Vehicle_RecalcCombatPools`.

## Signature

```c
void __thiscall Vehicle_SetEquippedRaceItem(
    void* thisVehicle, void* pRaceItem, void** ppOutPrevious, char bSkipUnbind);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00502460_Vehicle_SetEquippedRaceItem.md`
- Annotated: `docs/reconstruction/raw/aa_00502460_Vehicle_SetEquippedRaceItem.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_SetEquippedRaceItem.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| Slot +0x270 / type 6 subtype 0xb | High |
| Regen coupling (docs) | Probable |
