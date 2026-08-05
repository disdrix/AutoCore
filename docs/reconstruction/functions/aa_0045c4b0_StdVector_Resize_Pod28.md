# Function record: StdVector_Resize_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045c4b0` |
| **Canonical name** | `StdVector_Resize_Pod28` (**Inferred** structural) |
| **Ghidra name** | `FUN_0045c4b0` |
| **Address** | `0x0045c4b0`–`0x0045c552` exclusive (**162 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>::resize(n, value)`, T POD **0x1c** |
| **Completion status** | **Dual sealed** W35-M — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Resize POD vector of stride **0x1c** to `new_size`, using stack **value** as fill for growth. Sole direct parent of sealed `StdVector_InsertN_Pod28` (`0x0045cd30`).

## Signature

```c
// EBX=vec*, ECX=new_size, stack Pod28 by value; RET 0x1C
void StdVector_Resize_Pod28(
    StdVectorPod28* vec,
    uint32_t new_size,
    Pod28 value);
```

## Layout

| Off | Field |
|---|---|
| vec+0x04 | begin |
| vec+0x08 | end |
| vec+0x0C | capEnd (unused in this unit) |

## Related

| VA | Role |
|---|---|
| `0x0045cd30` | `StdVector_InsertN_Pod28` grow callee (W34-P) |
| `0x0045cce0` | erase/truncate shrink callee (unowned) |
| `0x00469c50` | `StdVector_Elem28_Size` family (not called here; size inlined) |
| `0x00459750` | sole direct caller (unowned) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0045c4b0_FUN_0045c4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045c4b0_FUN_0045c4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Pod28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045c4b0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_0045c4b0_StdVector_Resize_Pod28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0045efe0-0045c4b0-w35m-report.md` |
