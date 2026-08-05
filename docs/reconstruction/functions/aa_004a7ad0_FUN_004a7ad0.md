# Function record: FUN_004a7ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ad0` |
| **Canonical name** | `FUN_004a7ad0` (scaffold) |
| **Named plate** | **`StdVector_InsertN_BasicStringW`** — see `aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| **Address** | `0x004a7ad0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<wchar_t>>` insert-n |
| **Completion status** | **Dual-reviewed** W34-R — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004a7ad0`. Prefer structural `StdVector_InsertN_BasicStringW`.

## Purpose

Insert-n for `vector<basic_string<wchar_t>>` (elem **0x1c**): 1.5× grow or in-place hole/mid fill. Twin of `StdVector_InsertN_BasicString` (`0x004306b0`).

## Signature (sealed)

```c
void __thiscall StdVector_InsertN_BasicStringW(
    VectorBasicStringW* vec,
    BasicStringW_0x1c* where,
    uint32_t count,
    BasicStringW_0x1c* value);
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.md`
- Annotated: `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicStringW.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a7ad0.cpp`
- Named record: `docs/reconstruction/functions/aa_004a7ad0_StdVector_InsertN_BasicStringW.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_004a7ad0_StdVector_InsertN_BasicStringW.md`, `B_aa_004a7ad0_StdVector_InsertN_BasicStringW.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004a7ff0` @ `0x004a8043` |
| Callees | wstring IAT; `FUN_004a6820`; `FUN_00469c50`; new/delete; `FUN_004a6b50`; `FUN_004a74f0`; `FUN_004a7aa0`; `FUN_004a7a70`; `FUN_004a68a0`; `FUN_004a68d0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Parameter semantic names | **High** (insert-n formals) |
| Types | **High** (wstring) / product demangle **Low** |
