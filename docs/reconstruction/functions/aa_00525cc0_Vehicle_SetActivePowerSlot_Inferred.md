# Function record: Vehicle_SetActivePowerSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525cc0` |
| **Canonical name** | `Vehicle_SetActivePowerSlot_Inferred` |
| **Address** | `0x00525cc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle skills / power slot |
| **Ghidra symbol** | `FUN_00525cc0` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Transition active slot at `vehicle+0xD64` within `[-1,2]`; optional skill cast teardown/setup when continent gate +0x7e set; force flag re-applies same slot.

## Signature

```c
uint32_t __thiscall Vehicle_SetActivePowerSlot_Inferred(Vehicle* v, int newSlot, char force);
// 0 reject, 1 accept
```

## Artifacts

- Raw / annotated / clean: `raw/aa_00525cc0_*`, `reconstructed-exact/FUN_00525cc0.cpp`
- Dual A/B: `reviews/A_aa_00525cc0_Vehicle_SetActivePowerSlot_Inferred.md`, `B_aa_00525cc0_*`
- Legacy: `functions/aa_00525cc0_FUN_00525cc0.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `Vehicle_ActivateEnterWorld`, `FUN_008089a0` |
| Callee | `FUN_0040abd0`, `CNDHash_LookupByKey`, skill cast family |

## Confidence

| Claim | Level |
|---|---|
| Slot domain + storage | High |
| Cast result product codes | Tentative |
