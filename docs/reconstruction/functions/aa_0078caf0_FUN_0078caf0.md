# Function record: FUN_0078caf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078caf0` |
| **Canonical name** | `CNDUIWndBuffered_Ctor_Inferred` (preferred) |
| **Ghidra name** | `FUN_0078caf0` |
| **Address** | `0x0078caf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / ND UI buffered window |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W34-T); see named record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Canonical: `CNDUIWndBuffered_Ctor_Inferred`
- **Reject:** `Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0078caf0`

## Purpose

`CNDUIWndBuffered` complete constructor (RTTI Confirmed). See named function record.

## Signature (sealed W34-T)

```c
undefined4 * FUN_0078caf0(undefined4 *this, undefined4 arg1, undefined4 arg2);
// ret 12; returns this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0078caf0_FUN_0078caf0.md`
- Annotated: `docs/reconstruction/raw/aa_0078caf0_FUN_0078caf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0078caf0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_Ctor_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md`
- Report: `docs/agents/task-dual-ab-0078caf0-0048eb10-w34t-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| Class RTTI CNDUIWndBuffered | **Confirmed** |
| Parameter semantic names arg1/arg2 | **Tentative** (constants only) |
