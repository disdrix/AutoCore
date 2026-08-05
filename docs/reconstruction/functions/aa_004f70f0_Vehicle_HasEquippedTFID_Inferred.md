# Function record: Vehicle_HasEquippedTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f70f0` |
| **Canonical name** | `Vehicle_HasEquippedTFID_Inferred` |
| **Address** | `0x004f70f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle equip |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004f70f0`
- Prior: `Named_CalleeOf_Named_VOGClient_004f70f0`

## Purpose

Bool predicate: vehicle holds equipped object matching TFID `(a,b)` in weapon mounts (`+0x260`×3 via `FUN_004f5680`) or slots `+0x270/+0x26c/+0x268/+0x258/+0x254/+0x264`. Pure read; CompletelyDestroyObject uses result to trigger unequip cleanup.

## Signature

```c
int __thiscall Vehicle_HasEquippedTFID_Inferred(void *vehicle, int tfid_a, int tfid_b);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f70f0_FUN_004f70f0.md`
- Annotated: `docs/reconstruction/raw/aa_004f70f0_FUN_004f70f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004f70f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md`

## Callers / callees

- Callers: `FUN_009440e0`, `FUN_00944d50`, `Skill_RangeCheckTargetForResolveList_Inferred`, `FUN_0054f033`
- Callees: `FUN_004f5680`

## Confidence

| Claim | Level |
|---|---|
| TFID equip predicate | **Confirmed** |
| Slot set vs garage UI | **High** |
| Product name | **Open** |
