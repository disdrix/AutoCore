# Function record: StdVector_Resize_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466df0` |
| **Canonical name** | `StdVector_Resize_Elem28_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00466df0` |
| **Address** | `0x00466df0`–`0x00466e92` exclusive (**162 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>::resize(n, value)`, T POD **0x1c** |
| **Calling convention** | **EBX=vec\***; **ECX=new_size**; stack **value 0x1c**; **`ret 0x1C`** |
| **Completion status** | **Dual sealed** W36-P — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A** | `reviews/A_aa_00466df0_StdVector_Resize_Elem28_Inferred.md` |
| **Dual B** | `reviews/B_aa_00466df0_StdVector_Resize_Elem28_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W36-P) |

## Purpose

Resize POD vector of stride **0x1c** to `new_size`, using stack **value** as fill for growth. Sole direct parent of sealed `StdVector_InsertN_Elem28_CountEcx_Inferred` (`0x00466ea0`). Twin of `StdVector_Resize_Pod28` (`0x0045c4b0`) with CountEcx InsertN grow path.

## Signature

```c
// EBX=vec*, ECX=new_size, stack Elem28 by value; RET 0x1C
void StdVector_Resize_Elem28_Inferred(
    VectorElem28* vec,
    uint32_t new_size,
    Elem28 value);
```

## Layout

| Off | Field |
|---|---|
| vec+0x04 | begin |
| vec+0x08 | end |
| vec+0x0C | capEnd (unused in this unit) |

## Behavioral summary

| Branch | Condition | Effect |
|---|---|---|
| Grow | `size < new_size` | InsertN CountEcx at end with fill value; RET 1C |
| Shrink | `begin && new_size < size` | erase `[begin+n*0x1c, end)` via `FUN_0045cce0`; RET 1C |
| Equal / empty | else | no-op; RET 1C |

## Related

| VA | Role |
|---|---|
| `0x00466ea0` | `StdVector_InsertN_Elem28_CountEcx_Inferred` grow callee (W34-Q) |
| `0x0045cce0` | erase/truncate shrink callee (unowned) |
| `0x0045c4b0` | `StdVector_Resize_Pod28` structural twin (W35-M) |
| `0x00469c50` | `StdVector_Elem28_Size` family (not called; size inlined) |
| `0x00963fb0` | sole direct caller (unowned) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00466df0_FUN_00466df0.md` |
| Annotated | `docs/reconstruction/raw/aa_00466df0_FUN_00466df0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem28_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00466df0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00466df0_StdVector_Resize_Elem28_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00466df0-0046a350-w36p-report.md` |
