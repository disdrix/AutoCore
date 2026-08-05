# Function record: Vehicle_ApplyHardpointFireMask_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005021d0` |
| **Canonical name** | `Vehicle_ApplyHardpointFireMask_Inferred` |
| **Ghidra symbol** | `FUN_005021d0` |
| **Address** | `0x005021d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle hardpoint weapons |
| **Completion status** | **dual A/B accept-with-gaps** — 2026-07-29 W21-H; 3-slot CF + callees + callers sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005021d0`
- Prior scaffold: `Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_005021d0`
- Prior record: `functions/aa_005021d0_FUN_005021d0.md`

## Purpose

Apply a **3-bit fire mask** to the vehicle’s primary hardpoint weapon table at **`vehicle+0x260`**. For each occupied slot, either run the **can-fire → set flags → fire helper → weapon-fire HB** path (when want-bit, `+0xCB` clear, world `+0x7E` set) or only **latch/clear fire flag pair** to the want-bit.

## Signature (decompiler + epilogue sealed)

```c
void __thiscall Vehicle_ApplyHardpointFireMask_Inferred(
    int vehicle /* ECX */,
    char fireMask /* bits 0..2, stack, RET 4 */);
```

## Layout

| Off | Object | Use |
|---:|---|---|
| `+0x260` | vehicle | hardpoint `weapon*` × 3 |
| `+0xCB` | weapon | block start-fire when non-zero |
| `+0x7E` | world (MI +0xA8) | allow-fire world flag |
| `+0xE8A0` | world | local player identity compare |
| `+0xE4EC` | world | HB enqueue list |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005021d0_FUN_005021d0.md` (+ 2026-07-29 append)
- Annotated: `docs/reconstruction/raw/aa_005021d0_FUN_005021d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_ApplyHardpointFireMask_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005021d0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005021d0_Vehicle_ApplyHardpointFireMask_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005021d0_Vehicle_ApplyHardpointFireMask_Inferred.md`

## Callers / callees

**Callees:** `FUN_0056a260`, `FUN_0056d160`, `FUN_005fe6a0`, `operator_new`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`, `Client_SendLogicUiPacket`; weapon vtbl+0x4C; plant vtbl+0x210.

**Callers:** `CVOGHBAIFollowVehicle_FireWeapons` (`0x005d736b`); `VehicleNet_ReconcilePrediction` (`0x005fa59e`, `0x005fa5be`).

## Confidence

| Claim | Level |
|---|---|
| 3-slot loop + mask bits | **High** |
| Fire path gates +0xCB / world+0x7E | **High** |
| SetFireFlagPair dual use (canFire vs want) | **High** |
| HB 0x24 + ctor + enqueue + Start | **High** |
| LogicUi opcode 0x31 + slot index | **High** (imm) / **Medium** English |
| FireHelper this / DAT_00b041b0 | **Medium** (decomp vs typical thiscall) |
| Product class names | **Tentative** `_Inferred` |
| Runtime / bit-exact | Open |
