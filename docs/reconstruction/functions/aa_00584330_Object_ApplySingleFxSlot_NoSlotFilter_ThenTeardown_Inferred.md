# Function record: Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00584330` |
| **Canonical name** | `Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred` |
| **Ghidra name** | `FUN_00584330` |
| **Address** | `0x00584330`–`0x005843af` (**127 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx |
| **Completion status** | **Dual sealed** (W26-K 2026-07-29) |
| **Name confidence** | **Inferred** — role sealed from CF + chain peer `004c8110`; no product string |

## Purpose

Single effect-slot (`this-0x88`) FX toggle with **use_slot_filter=0**, then tail-chain teardown `FUN_005179e0`.

## Signature

```c
void __thiscall Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred(void *self);
```

## Artifacts

See `aa_00584330_FUN_00584330.md` for full artifact table and callers/callees.

## Dual

| Review | Verdict |
|---|---|
| A | **accept** |
| B | **accept** |
