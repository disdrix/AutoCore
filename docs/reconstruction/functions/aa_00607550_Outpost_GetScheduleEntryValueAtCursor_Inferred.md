# Function record: Outpost_GetScheduleEntryValueAtCursor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00607550` |
| **Canonical name** | `Outpost_GetScheduleEntryValueAtCursor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00607550` |
| **Address** | `0x00607550` |
| **Body** | `0x00607550`–`0x006075a8` exclusive (**88 B** / `0x58`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | outpost / capture schedule |
| **Completion status** | **Dual-reviewed** WQ8R-E — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Select global schedule bank from outpost `+0x220`, index by schedule cursor `+0x23c`, return the **dword at entry+4** of the 16-byte vector element (or **0** if cursor is negative / out of range). Used by `Outpost_CaptureOutpost` to arm `timerBlob[+8]` after resetting the cursor to 0.

## Signature

```c
// ECX = outpost*; plain RET; returns EAX
uint32_t __thiscall Outpost_GetScheduleEntryValueAtCursor_Inferred(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `Outpost_CaptureOutpost` `0x006082e0` @ `0x006085cc` (only) |
| Callees | `FUN_00608620` (`"invalid vector<T> subscript"`; pathological only) |

## Layout / globals

| Symbol / off | Role |
|---|---|
| outpost `+0x220` | bank select (0 → `DAT_00d029f0`, else `DAT_00d029e0`) |
| outpost `+0x23c` | schedule cursor (signed index) |
| table `+4` / `+8` | vector begin / end |
| entry stride | `0x10` |
| return field | entry `+4` (dword) |

## Twin (context; not owned)

`Outpost_GetPulseXpPercent` @ `0x006075b0` — same bank/cursor/stride; returns **float at entry+8**.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00607550_FUN_00607550.md`
- Annotated: `docs/reconstruction/raw/aa_00607550_FUN_00607550.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Outpost_GetScheduleEntryValueAtCursor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00607550.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00607550_FUN_00607550.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + plain RET + EAX return | **High** |
| Soft OOB → 0 | **High** |
| CaptureOutpost timer arm use | **High** |
| Product English of entry+4 dword | **Medium** residual |
| Runtime | **Open** |
