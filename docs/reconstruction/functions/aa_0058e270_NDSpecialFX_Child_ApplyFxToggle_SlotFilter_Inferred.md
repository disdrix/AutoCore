# Function record: NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e270` |
| **Canonical name** | `NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred` |
| **Ghidra name** | `FUN_0058e270` |
| **Address** | `0x0058e270`–`0x0058e2f1` (**129 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX |
| **Completion status** | **Dual sealed** (W26-K 2026-07-29) |
| **Name confidence** | **Inferred** — role sealed; no product string in body |

## Purpose

Slot-filtered child FX start/stop toggle with active-flag bit0 at `+0x90f`.

## Signature

```c
void __thiscall NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred(
    void *child,
    void *effect_start,
    void *effect_stop,
    int slot_filter);
```

## Artifacts

See `aa_0058e270_FUN_0058e270.md` for full table.

## Dual

| Review | Verdict |
|---|---|
| A | **accept** |
| B | **accept** |
