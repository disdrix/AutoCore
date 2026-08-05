# Function record: StdVector_DestroyRange_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431aa0` |
| **Canonical name** | `StdVector_DestroyRange_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_00431aa0` |
| **Address** | `0x00431aa0` |
| **Body** | `0x00431aa0`–`0x00431ac2` exclusive (**34 B** / `0x22`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<char>>` destroy-range |
| **Completion status** | **Dual-reviewed** W33-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Destroy every `basic_string` in half-open pointer range `[first, last)` with element stride **0x1c**. Does **not** free the backing buffer. Used by `StdVector_InsertN_BasicString` after relocating into a grown buffer (and by its catch paths).

## Signature

```c
// stack first*, last*; RET 0x08; void
void StdVector_DestroyRange_BasicString(
    BasicString_0x1c* first,
    BasicString_0x1c* last);
```

| Formal | Source | Conf |
|---|---|---|
| first | Stack `[esp+4]` → ESI | **High** |
| last | Stack `[esp+8]` → EDI | **High** |
| stride 0x1c | `ADD ESI,0x1C` | **High** |
| cleanup | `C2 08 00` | **High** |
| dtor | IAT `[0x009c62f4]` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicString` / `FUN_004306b0` @ `0x0043084d`; Catch@`0x00430888`; Catch@`0x00430956` |
| Callees | `~basic_string` via IAT `0x009c62f4` → `0x006eace6` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431aa0_FUN_00431aa0.md` (W33-H append)
- Annotated: `docs/reconstruction/raw/aa_00431aa0_FUN_00431aa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00431aa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00431aa0_StdVector_DestroyRange_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_00431aa0_StdVector_DestroyRange_BasicString.md`
- Scaffold record: `docs/reconstruction/functions/aa_00431aa0_FUN_00431aa0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (loop dtor + stride) | **High** (bytes) |
| ABI stack + RET 0x08 | **High** |
| String elem 0x1c | **High** |
| Product demangle | **Low** |
| IAT dtor English symbol | **Med** (decompiler-labeled) |
