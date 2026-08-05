# Function record: BasicStringW_FillAssignRange_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a68a0` |
| **Canonical name** | `BasicStringW_FillAssignRange_0x1c` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a68a0` |
| **Address** | `0x004a68a0` |
| **Body** | `0x004a68a0`–`0x004a68c6` inclusive (**39 B** / `0x27`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `basic_string<wchar_t>` range assign-fill |
| **Completion status** | **Dual-reviewed** W36-T — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Assign one source `basic_string<wchar_t>` into every existing element of half-open range `[first, last)` with element stride **0x1c**. Implements the in-place hole-fill step of `vector<wstring>::insert(where, count, value)` (`StdVector_InsertN_BasicStringW`).

## Signature

```c
// cdecl; 3 stack args; plain RET; void
void BasicStringW_FillAssignRange_0x1c(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    const BasicStringW_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| first | stack `[esp+4]` → ESI | **High** |
| last | stack `[esp+8]` → EDI | **High** |
| value | stack `[esp+0xC]` → EBX | **High** |
| stride | `ADD ESI, 0x1C` | **High** |
| cleanup | plain `C3` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicStringW` (`FUN_004a7ad0`) @ `0x004a7d67`, `0x004a7dcc` |
| Callees | IAT `basic_string<wchar_t>::operator=` via `[0x009c63bc]` → `0x006ec314` |

## Related

| VA | Role |
|---|---|
| `0x00431450` | char twin `BasicString_FillAssignRange_0x1c` (W33-I) |
| `0x004a68d0` | sibling mid-shift `BasicStringW_CopyBackward_0x1c` (W36-T) |
| `0x004a7ad0` | sole parent insert-n (W34-R) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a68a0_FUN_004a68a0.md` (W36-T append)
- Annotated: `docs/reconstruction/raw/aa_004a68a0_FUN_004a68a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BasicStringW_FillAssignRange_0x1c.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a68a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md`
- Scaffold record: `docs/reconstruction/functions/aa_004a68a0_FUN_004a68a0.md`

## Confidence

| Claim | Level |
|---|---|
| Fill-by-assign CF | **High** |
| ABI cdecl 3-arg + plain RET | **High** |
| Stride 0x1c + wstring operator= | **High** |
| Product demangle plate | **Low** |
