# Function record: Object_TeardownOwnedFxLists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005179e0` |
| **Canonical name** | `Object_TeardownOwnedFxLists_Inferred` |
| **Ghidra name** | `FUN_005179e0` |
| **Address** | `0x005179e0`–`0x00517a6a` |
| **Module** | `autoassault.exe` |
| **System** | client-fx / object-owned NDSpecialFX ptr-vector teardown |
| **Completion status** | **dual-sealed** 2026-07-29 W28-H |
| **Dual A/B** | `reviews/A_aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md`, `reviews/B_aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md` |

## Purpose

Manager/object teardown of owned SpecialFX pointer vectors (primary `+0x124` + secondary nested `+0x138` via `FUN_00516930`). Free polarity matches sealed StopFinalize dual (`+9==0` and return ≠0 → TeardownCore + delete).

```c
void __thiscall Object_TeardownOwnedFxLists_Inferred(void *self);
```

## Artifacts

- Named: `docs/reconstruction/reconstructed-exact/Object_TeardownOwnedFxLists_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005179e0.cpp`
- Raw / annotated under `aa_005179e0_FUN_005179e0*`

## Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_00518ec0` | `0x00518f8b` | object destroy path (call) |
| `Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred` | `0x005843ab` | **tail jmp** |
| vtables | `009ce348` / `009d34c0` / `009d4248` / `009dbcf8` | virtual |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI sealed | **Confirmed** |
| Free gate vs StopFinalize | **Confirmed** |
| Product English | **Inferred** |
