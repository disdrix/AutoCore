# Function record: StdVector_Resize_Elem56_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437e40` |
| **Canonical name** | `StdVector_Resize_Elem56_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00437e40` |
| **Address** | `0x00437e40`–`0x00437f1e` exclusive (**222 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>::resize(n, value)`, T non-trivial **0x38** (dual `basic_string`) |
| **Completion status** | **Dual sealed** W38-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Resize dual-string element vector (stride **0x38**) to `new_size`. Grow via InsertN-class `FUN_00438520`; shrink via erase `FUN_00438430`; always destroy stack fill via `FUN_00437da0`.

## Signature

```c
// EDI=vec*, ECX=new_size, stack Elem56 by value; RET 0x38
void StdVector_Resize_Elem56_Inferred(
    StdVectorElem56* vec,
    uint32_t new_size,
    Elem56 value);
```

## Layout

| Off | Field |
|---|---|
| vec+0x04 | begin |
| vec+0x08 | end |
| vec+0x0C | capEnd (unused here) |
| T+0x00 / +0x1c | two MSVC `basic_string` |

## Related

| VA | Role |
|---|---|
| `0x00438520` | grow InsertN-class |
| `0x00438430` | shrink erase-range |
| `0x00437da0` | element / stack-value dtor |
| `0x00437ad0` | default-value resize wrapper |
| `0x00437f70` | sibling resize Elem20 (W38-F pair) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437e40_FUN_00437e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00437e40_FUN_00437e40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem56_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00437e40.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00437e40_StdVector_Resize_Elem56_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00437e40-00437f70-w38f-report.md` |
