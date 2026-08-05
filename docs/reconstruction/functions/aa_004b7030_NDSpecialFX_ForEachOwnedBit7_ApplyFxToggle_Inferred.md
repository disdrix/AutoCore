# Function record: NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7030` |
| **Canonical name** | `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` |
| **Ghidra name** | `FUN_004b7030` |
| **Address** | `0x004b7030` |
| **Body span** | `004b7030`–`004b708a` (**90** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / NDSpecialFX owned-child apply |
| **Convention** | MSVC thiscall; `RET 0x10` (4 stack dwords); ECX = FX host |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff open |
| **Dual verdict** | **accept** (A+B) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|------|--------|
| `FUN_004b7030` | Ghidra auto |
| `Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030` | **Rejected** as sole role (seed from parent string path only) |
| `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` | **Canonical** (this dual) |

## Purpose

Walk the NDSpecialFX host **owned-child circular list** at `+0x204`. For every child with **`+0x90e` bit7** set, dispatch a start/stop FX toggle helper:

- `use_slot_filter == 0` → `FUN_0058e300(child, want_start, want_stop)` (acts when `child+0x25c < 0`)
- else → `FUN_0058e270(child, want_start, want_stop, slot_filter)` (slot match / `-1` wild)

Shares list/flag layout with dualed `NDSpecialFX_DeactivateClear_Inferred` (`0x004b7150`).

## Signature

```c
// thiscall; RET 0x10
void __thiscall NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
    void *fx_host,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b7030_FUN_004b7030.md`
- Annotated: `docs/reconstruction/raw/aa_004b7030_FUN_004b7030.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004b7030.cpp`
- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b7030_FUN_004b7030.md`
- Review A: `docs/reconstruction/reviews/A_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md`
- Report: `docs/agents/task-dual-ab-own-w24d-009168d0-004b7030-report.md`

## Callers / callees

| Dir | VA | Name / role |
|---|---|---|
| Caller | `0x004c8110` | attachment clear/apply fan-out |
| Caller | `0x004ff850` | drive attach table (incl. `%s_VEHICLE_EXHAUST_%d`) |
| Caller | `0x005829d0` | single-host apply wrapper |
| Caller | `0x00583f10` | multi-table fan-out |
| Caller | `0x00584330` | related teardown/apply |
| Callee | `0x0058e300` | unrestricted child FX toggle |
| Callee | `0x0058e270` | slot-filtered child FX toggle |

## Confidence

| Claim | Level |
|---|---|
| Body span + `ret 0x10` thiscall | **Confirmed** (bytes) |
| List `+0x204` circular walk | **Confirmed** |
| Bit7 gate at `child+0x90e` | **Confirmed** |
| Callee this = `node[2]` | **Confirmed** (bytes; decompiler incomplete) |
| Branch `param_4` → e300 vs e270 | **Confirmed** |
| NDSpecialFX host family | **High** (layout peer `004b7150`) |
| Product method name | **Tentative** (`_Inferred`) |
| Bit7 English / full e270 dual | Open |
| Runtime / bit-exact | Open |
