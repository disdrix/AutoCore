# Function record: Vehicle_SetEquippedArmor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502090` |
| **Canonical name** | `Vehicle_SetEquippedArmor` |
| **Address** | `0x00502090` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean** — dual review not required this wave; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Set armor hardpoint `this+0x254`. Optional skip-unbind, type-check class `0x1c`, bind vfunc+0x158, `Vehicle_RecalcCombatPools`.

## Signature

```c
void __thiscall Vehicle_SetEquippedArmor(void* thisVehicle, void* pArmorItem, char bSkipUnbind);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00502090_Vehicle_SetEquippedArmor.md`
- Annotated: `docs/reconstruction/raw/aa_00502090_Vehicle_SetEquippedArmor.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_SetEquippedArmor.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| Slot +0x254 / type 0x1c | High |
| Types / helper names | Tentative–Probable |
