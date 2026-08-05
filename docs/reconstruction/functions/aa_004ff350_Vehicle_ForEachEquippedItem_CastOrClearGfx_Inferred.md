# Function record: Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff350` |
| **Canonical name** | `Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred` |
| **Address** | `0x004ff350` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle equip / enter-world |
| **Ghidra symbol** | `FUN_004ff350` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Walk hardpoints + self + equip slots; `param_2==0` → `ClearItemGfxBindings`, else `CastItemSkillsOnEquip`. Status hooks (`004fe380`) only on +0x26c / +0x270. ActivateEnterWorld uses cast=1 when map+0x7e.

## Signature

```c
void __thiscall Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred(Vehicle* v, char doCast);
```

## Artifacts

- Raw / annotated / clean: `raw/aa_004ff350_*`, `reconstructed-exact/FUN_004ff350.cpp`
- Dual A/B: `reviews/A_aa_004ff350_Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred.md`, `B_aa_004ff350_*`
- Legacy: `functions/aa_004ff350_FUN_004ff350.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `Vehicle_ActivateEnterWorld` `0x00503f30`, `FUN_00502380` |
| Callee | `0x004fbb50`, `0x004fdcb0`, `0x004fe380` |

## Confidence

| Claim | Level |
|---|---|
| Clear vs cast branch | High |
| Slot product names | Tentative |
