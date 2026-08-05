# Function record: Vehicle_ActivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4f00` |
| **Canonical name** | `Vehicle_ActivateHardpointWeapons_Inferred` |
| **Ghidra name** | `FUN_004f4f00` |
| **Address** | `0x004f4f00`–`0x004f4faa` (171 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / vehicle hardpoint weapons |
| **Completion status** | **dual-sealed** W25-E 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Per-slot fire-clear + activate for the 3-entry weapon hardpoint table at `vehicle+0x260`. Sibling of `Vehicle_DeactivateHardpointWeapons_Inferred` (`0x004f4eb0`).

## Signature

```c
void __thiscall Vehicle_ActivateHardpointWeapons_Inferred(Vehicle *vehicle);
// ECX=vehicle; 0 stack args; ret
```

## Artifacts

See `aa_004f4f00_FUN_004f4f00.md` for full table + A/B paths.

## Twin

| Twin | VA | Role |
|---|---|---|
| `Vehicle_DeactivateHardpointWeapons_Inferred` | `0x004f4eb0` | fire+suppress clear, vtbl+0x18(0) |
