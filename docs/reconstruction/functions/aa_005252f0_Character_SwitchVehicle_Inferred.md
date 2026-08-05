# Function record: Character_SwitchVehicle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005252f0` |
| **Canonical name** | `Character_SwitchVehicle_Inferred` |
| **Ghidra name** | `FUN_005252f0` |
| **Address** | `0x005252f0`–`0x00525a92` (1955 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle / inventory-transfer / client chassis switch |
| **Completion status** | **dual-sealed** W25-E 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Client-side character vehicle chassis switch with cargo page migration, hardpoint deactivate/activate pair, optional phys+wheelset, and dual-try inventory stow of the old chassis.

## Signature

```c
HRESULT __thiscall Character_SwitchVehicle_Inferred(
    Character *self,
    Vehicle *newVehicle,
    Vehicle **outOldVehicle,
    unsigned argA,
    unsigned argB);
// RET 0x10
```

## Artifacts

See `aa_005252f0_FUN_005252f0.md` for full table + A/B paths.
