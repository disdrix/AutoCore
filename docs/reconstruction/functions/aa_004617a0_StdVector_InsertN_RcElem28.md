# Function record: StdVector_InsertN_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004617a0` |
| **Canonical name** | `StdVector_InsertN_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_004617a0` |
| **Address** | `0x004617a0`–`0x00461abb` exclusive (**795 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>` insert-n, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W34-P — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **`vector<T>::_Insert_n`** for non-trivial **T** (0x1c) with shared resource pointer at **`+0x10`**. Local copy-ctor AddRef; grow/in-place use refcount-aware uninit-copy, fill-n, assign, destroy; epilogue Release.

## Signature

```c
void StdVector_InsertN_RcElem28(
    const RcElem28* value,       /* ECX */
    StdVectorRc28* vec,          /* stack */
    RcElem28* where,             /* stack */
    uint32_t count);             /* stack */
// RET 0xC
```

## Element layout (0x1c)

| Off | Field |
|---|---|
| +0x00..+0x0C | 4× u32 |
| +0x10 | shared* (refcount @ obj+4; AddRef vtbl+4; Release vtbl+8) |
| +0x14..+0x16 | 3× u8 |
| +0x18 | u32 |

## Related

| VA | Role |
|---|---|
| `0x00469c50` | `StdVector_Elem28_Size` |
| `0x004611e0` | resize-style caller (grow at end) |
| `0x004612d0` | insert-one wrapper (count=1) |
| `0x0045cd30` | POD insert-n sibling (different ABI/lifetime) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004617a0_FUN_004617a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004617a0_FUN_004617a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_RcElem28.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_004617a0_StdVector_InsertN_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0045cd30-004617a0-w34p-report.md` |
