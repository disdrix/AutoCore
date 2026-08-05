# Function record: _com_issue_errorex

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f20` |
| **Canonical name** | `_com_issue_errorex` |
| **Address** | `0x00717f20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `crt-com` (MSVC library — not game logic) |
| **Completion status** | **Dual A/B accept** (2026-07-29) — CF + ISupportErrorInfo GUID sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC COM support: raise HRESULT, optionally attaching `IErrorInfo` when `punk` supports `IID_ISupportErrorInfo` for the given interface GUID. Twin of `_com_issue_error` with richer context.

## Signature (sealed)

```c
void __stdcall _com_issue_errorex(long hr, IUnknown *punk, const GUID *iid);  // ret 0xC
```

`DAT_00a14020` = `{DF0B3D60-548F-101B-8E65-08002BBBD119}` (`IID_ISupportErrorInfo`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717f20__com_issue_errorex.md`
- Annotated: `docs/reconstruction/raw/aa_00717f20__com_issue_errorex.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_com_issue_errorex.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00717f20__com_issue_errorex.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00717f20__com_issue_errorex.md`

## Callers / callees

- **Callees:** QI path, `GetErrorInfo`, same raise slot `PTR_FUN_00af8b20` → `FUN_007181c0`
- **Callers:** COM wrapper clusters (`FUN_00419e90` family, `0x007b*`/`0x007c*`)

## Confidence

| Claim | Level |
|---|---|
| Body CF / stdcall 3 args | **Confirmed** |
| ISupportErrorInfo GUID | **Confirmed** |
| Library identity | **Confirmed** |
| Raise callee semantics | Probable (out of unit) |
