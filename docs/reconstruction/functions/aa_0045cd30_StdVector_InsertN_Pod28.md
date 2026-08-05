# Function record: StdVector_InsertN_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cd30` |
| **Canonical name** | `StdVector_InsertN_Pod28` (**Inferred** structural) |
| **Ghidra name** | `FUN_0045cd30` |
| **Address** | `0x0045cd30`–`0x0045d01c` exclusive (**748 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>` insert-n, T POD **0x1c** |
| **Completion status** | **Dual sealed** W34-P — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **`vector<T>::_Insert_n(where, count, value)`** for trivially copyable **T** of size **0x1c** (7 dwords / floats). Local value via SSE `MOVSS`×7. Grow 1.5× or in-place shift; max elems `0x9249249`.

## Signature

```c
void StdVector_InsertN_Pod28(
    uint32_t count,              /* ECX */
    StdVectorPod28* vec,         /* EDX */
    Pod28* where,                /* stack */
    const Pod28* value);         /* stack */
// RET 8
```

## Layout

| Off | Field |
|---|---|
| vec+0x04 | begin |
| vec+0x08 | end |
| vec+0x0C | capEnd |

## Related

| VA | Role |
|---|---|
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) |
| `0x004540b0` | throw too long |
| `0x004306b0` | `StdVector_InsertN_BasicString` — string-aware sibling (different ABI) |
| `0x0045c4b0` | sole direct caller (ensure/resize path) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0045cd30_FUN_0045cd30.md` |
| Annotated | `docs/reconstruction/raw/aa_0045cd30_FUN_0045cd30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Pod28.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_0045cd30_StdVector_InsertN_Pod28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0045cd30-004617a0-w34p-report.md` |
