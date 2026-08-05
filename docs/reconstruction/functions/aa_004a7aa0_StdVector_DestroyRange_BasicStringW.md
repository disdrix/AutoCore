# Function record: StdVector_DestroyRange_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7aa0` |
| **Canonical name** | `StdVector_DestroyRange_BasicStringW` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a7aa0` |
| **Address** | `0x004a7aa0` |
| **Body** | `0x004a7aa0`–`0x004a7ac4` exclusive (**36 B** / `0x24`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<wchar_t>>` destroy-range |
| **Completion status** | **Dual-reviewed** W36-S — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Destroy every `basic_string<wchar_t>` in half-open pointer range `[first, last)` with element stride **0x1c**. Does **not** free the backing buffer. Used by `StdVector_InsertN_BasicStringW` after relocating into a grown buffer (and by its catch paths).

## Signature

```c
// stack first*, last*; RET 0x08; void
void StdVector_DestroyRange_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last);
```

| Formal | Source | Conf |
|---|---|---|
| first | Stack `[esp+4]` → ESI | **High** |
| last | Stack `[esp+8]` → EDI | **High** |
| stride 0x1c | `ADD ESI,0x1C` | **High** |
| cleanup | `C2 08 00` | **High** |
| dtor | IAT `[0x009c62ac]` → `0x006eb03a` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicStringW` / `FUN_004a7ad0` @ `0x004a7c82`; Catch@`0x004a7cbd`; Catch@`0x004a7d90` |
| Callees | IAT `~basic_string<wchar_t>` via `0x009c62ac` |

## Related

| VA | Role |
|---|---|
| `0x00431aa0` | Char twin `StdVector_DestroyRange_BasicString` (W33-H) |
| `0x004a7ad0` | Parent insert-n `StdVector_InsertN_BasicStringW` (W34-R) |
| `0x004a7a70` | Wave-mate uninit-fill-n wrapper (this dual) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.md` (W36-S append)
- Annotated: `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicStringW.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a7aa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md`
- Scaffold record: `docs/reconstruction/functions/aa_004a7aa0_FUN_004a7aa0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (loop dtor + stride) | **High** (bytes) |
| ABI stack + RET 0x08 | **High** |
| String elem 0x1c | **High** |
| Product demangle | **Low** |
| IAT dtor English symbol | **Med** (decompiler-labeled) |
