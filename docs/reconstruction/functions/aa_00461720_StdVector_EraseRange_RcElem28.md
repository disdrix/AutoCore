# Function record: StdVector_EraseRange_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461720` |
| **Canonical name** | `StdVector_EraseRange_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_00461720` |
| **Address** | `0x00461720`–`0x0046177F` exclusive (**95 B** / `0x5F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector` erase-range, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W36-N — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **`vector::erase(first, last)`** for non-trivial RC elements size **0x1c**:

1. No-op equal range → write `*outIt = first`.
2. RC move-assign `[last, end)` onto `first` via `FUN_00461e60` (EAX dest).
3. Destroy leftover `[new_end, old_end)` via `FUN_00460d70` stride 0x1c.
4. Publish `end = new_end`; return `outIt` with `*outIt = first`.

Primary consumer: `StdVector_Resize_RcElem28` shrink path (W35-Q).

## Signature

```c
// stdcall; RET 0x10
RcElem28** StdVector_EraseRange_RcElem28(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* first,
    RcElem28* last);
```

## Related

| VA | Role |
|---|---|
| `0x004611e0` | `StdVector_Resize_RcElem28` (W35-Q) — sole caller |
| `0x00461780` | `StdDestroyRange_RcElem28` (W35-O) — destroy-only sibling |
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) |
| `0x00461e60` | RC move-assign range (unowned) |
| `0x00460d70` | per-elem Release leaf (unowned) |
| `0x00965ab0` | mesh-weight overlay parent of resize (this dual) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00461720_FUN_00461720.md` |
| Annotated | `docs/reconstruction/raw/aa_00461720_FUN_00461720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_EraseRange_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461720.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00461720_StdVector_EraseRange_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00461720-00965ab0-w36n-report.md` |
