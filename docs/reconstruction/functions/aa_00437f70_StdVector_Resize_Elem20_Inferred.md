# Function record: StdVector_Resize_Elem20_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437f70` |
| **Canonical name** | `StdVector_Resize_Elem20_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00437f70` |
| **Address** | `0x00437f70`–`0x00438040` exclusive (**208 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>::resize(n, value)`, T size **0x14** |
| **Completion status** | **Dual sealed** W38-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Resize element-20 vector (stride **0x14**) to `new_size`. Grow via InsertN-class `FUN_004388b0`; shrink via erase `FUN_00438850`.

## Signature

```c
// ESI=vec*, ECX=new_size, stack Elem20 by value; RET 0x14
void StdVector_Resize_Elem20_Inferred(
    StdVectorElem20* vec,
    uint32_t new_size,
    Elem20 value);
```

## Layout

| Off | Field |
|---|---|
| vec+0x04 | begin |
| vec+0x08 | end |
| vec+0x0C | capEnd (unused here) |

## Related

| VA | Role |
|---|---|
| `0x004388b0` | grow InsertN-class |
| `0x00438850` | shrink erase-range |
| `0x00437f20` | epilogue helper (residual) |
| `0x00765740` | sole parent function |
| `0x00437e40` | sibling resize Elem56 (W38-F pair) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437f70_FUN_00437f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00437f70_FUN_00437f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem20_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00437f70.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00437f70_StdVector_Resize_Elem20_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00437e40-00437f70-w38f-report.md` |
