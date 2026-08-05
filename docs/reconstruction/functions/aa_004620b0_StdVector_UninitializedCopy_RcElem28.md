# Function record: StdVector_UninitializedCopy_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004620b0` |
| **Canonical name** | `StdVector_UninitializedCopy_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_004620b0` |
| **Address** | `0x004620b0`–`0x00462194` exclusive (**228 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::uninitialized_copy` style for refcounted **T** **0x1c** |
| **Completion status** | **Dual sealed** W35-N — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

For each element in `[src_begin, src_end)`: construct into `dest` with same AddRef semantics as `RcElem28_CopyCtor_EsiEdi`, advance both by **0x1c**, return advanced dest. SEH-guarded; EH Release residual.

## Signature

```c
RcElem28* StdVector_UninitializedCopy_RcElem28(
    RcElem28* src_begin, /* ECX */
    RcElem28* src_end,   /* stack */
    RcElem28* dest);     /* stack */
// plain RET; caller cleans 8
```

## Related

| VA | Role |
|---|---|
| `0x004617a0` | parent `StdVector_InsertN_RcElem28` (only callers) |
| `0x00461ac0` | single-element copy-ctor leaf (same layout/AddRef) |
| `0x00461c90` | fill-n sibling (W35-O owned) |
| `0x00461780` | destroy range sibling (W35-O owned) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004620b0_FUN_004620b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004620b0_FUN_004620b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004620b0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_004620b0_StdVector_UninitializedCopy_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00461ac0-004620b0-w35n-report.md` |
