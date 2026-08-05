# Function record: FUN_004a7aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7aa0` |
| **Canonical name** | `FUN_004a7aa0` (scaffold) — preferred **`StdVector_DestroyRange_BasicStringW`** |
| **Address** | `0x004a7aa0` |
| **Body** | `0x004a7aa0`–`0x004a7ac4` exclusive (**36 B** / `0x24`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<wchar_t>>` destroy-range |
| **Completion status** | **Dual-reviewed** W36-S — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Preferred: `StdVector_DestroyRange_BasicStringW`
- **Reject** scaffold `Named_CalleeOf_*_004a7aa0`

## Purpose

Destroy every `basic_string<wchar_t>` in half-open pointer range `[first, last)` with element stride **0x1c**. Does **not** free the backing buffer. Used by `StdVector_InsertN_BasicStringW` after relocating into a grown buffer (and by its catch paths).

## Signature

```c
// stack first*, last*; RET 0x08; void
void StdVector_DestroyRange_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicStringW` / `FUN_004a7ad0` @ `0x004a7c82`; Catch@`0x004a7cbd`; Catch@`0x004a7d90` |
| Callees | IAT `~basic_string<wchar_t>` via `0x009c62ac` → `0x006eb03a` |

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md`
- Raw: `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.md` (W36-S append)
- Annotated: `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicStringW.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a7aa0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md`, `B_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (loop dtor + stride) | **High** (bytes) |
| ABI stack + RET 0x08 | **High** |
| String elem 0x1c | **High** |
| Product demangle | **Low** |
