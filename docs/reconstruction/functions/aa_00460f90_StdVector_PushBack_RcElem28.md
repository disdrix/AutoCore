# Function record: StdVector_PushBack_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00460f90` |
| **Canonical name** | `StdVector_PushBack_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_00460f90` |
| **Address** | `0x00460f90`–`0x00461011` exclusive (**129 B** / `0x81`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector::push_back`, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W36-O — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **push_back**: if spare capacity, uninit-fill one element at `end` and advance; else insert-one (rebind) at `end` via capacity growth path. Thin router over sealed fill-n and insert-one for the RC-elem28 family.

## Signature

```c
void StdVector_PushBack_RcElem28(
    StdVectorRc28* vec,       /* EAX */
    const RcElem28* value);   /* ECX */
// RET 0
```

## Related

| VA | Role |
|---|---|
| `0x00461c90` | `StdUninitFillN_RcElem28` (W35-O) — fast path |
| `0x004612d0` | `StdVector_InsertOne_RebindIt_RcElem28` (W35-Q) — slow path |
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — engine under insert-one |
| `0x004611e0` | `StdVector_Resize_RcElem28` (W35-Q) — sibling mutator |
| `0x00460d70` | `RcElem28_Release` (this dual) — dtor leaf of same T |
| `0x00965ab0` | sole live parent (mesh/UI residual) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00460f90_FUN_00460f90.md` |
| Annotated | `docs/reconstruction/raw/aa_00460f90_FUN_00460f90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00460f90.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00460f90_StdVector_PushBack_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00460f90-00460d70-w36o-report.md` |
