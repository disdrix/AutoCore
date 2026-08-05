# Function record: _com_issue_error

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f00` |
| **Canonical name** | `_com_issue_error` |
| **Address** | `0x00717f00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `crt-com` (MSVC library — not game logic) |
| **Completion status** | **Dual A/B accept** (2026-07-29) — 19-byte wrapper sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC COM support: raise HRESULT with **no** `IErrorInfo` (`(*PTR_FUN_00af8b20)(hr, NULL)`). Library match VS2003/2005 Debug.

## Signature (sealed)

```c
void __stdcall _com_issue_error(long hr);  // ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717f00__com_issue_error.md`
- Annotated: `docs/reconstruction/raw/aa_00717f00__com_issue_error.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_com_issue_error.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00717f00__com_issue_error.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00717f00__com_issue_error.md`

## Callers / callees

- **Callee:** indirect `PTR_FUN_00af8b20` → `FUN_007181c0` (`0x007181c0`)
- **Callers:** many COM/DB wrappers (e.g. `DB_ReadPowerPlantSpecific`, `FUN_007b*` / `FUN_007c*` clusters)

## Confidence

| Claim | Level |
|---|---|
| Body CF / stdcall / NULL IErrorInfo | **Confirmed** |
| Library identity | **Confirmed** |
| Raise callee semantics | Probable (out of unit) |
