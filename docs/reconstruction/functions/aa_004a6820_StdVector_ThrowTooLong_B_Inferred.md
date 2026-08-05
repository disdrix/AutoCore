# Function record: StdVector_ThrowTooLong_B_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6820` |
| **Canonical name** | `StdVector_ThrowTooLong_B_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a6820` |
| **Address** | `0x004a6820`–`0x004a6890` exclusive (**112 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / MSVC STL vector |
| **Completion status** | **Dual sealed** W36-Q — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_004a6820_StdVector_ThrowTooLong_B_Inferred.md`, `B_…` |

## Purpose

Shared MSVC **`vector::_Xlen()`-class** noreturn helper (B path): construct plate message `"vector<T> too long"`, wrap as C++ exception via IAT `exception::exception` + string copy + vtbls, throw via `_CxxThrowException` with `ThrowInfo` at `DAT_00acc388`. Invoked when 004a* vector growth/insert would exceed max size.

## Signature

```c
void __cdecl StdVector_ThrowTooLong_B_Inferred(void);  /* noreturn */
```

## Related

| VA | Role |
|---|---|
| `0x004540b0` | `StdVector_ThrowTooLong` (W19-B) — primary twin; `FUN_00401a40` wrap |
| `0x004a7ad0` | `StdVector_InsertN_BasicStringW` (W34-R) — known overflow caller |
| `0x00a15830` | plate string `"vector<T> too long"` |
| `0x00acc388` | ThrowInfo |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a6820_FUN_004a6820.md` |
| Annotated | `docs/reconstruction/raw/aa_004a6820_FUN_004a6820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_ThrowTooLong_B_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004a6820.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_004a6820_FUN_004a6820.md` |
| Dual report | `docs/agents/task-dual-ab-00469e20-004a6820-w36q-report.md` |
