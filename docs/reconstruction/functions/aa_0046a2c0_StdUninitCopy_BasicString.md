# Function record: StdUninitCopy_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a2c0` |
| **Canonical name** | `StdUninitCopy_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_0046a2c0` |
| **Address** | `0x0046a2c0` |
| **Body** | `0x0046a2c0`–`0x0046a34c` exclusive (**140 B** / `0x8C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Uninit_copy` for `basic_string<char>` (elem **0x1c**) |
| **Completion status** | **Dual-reviewed** W33-G — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Copy-construct `[first, last)` into uninitialized `dest` buffer, stride **0x1C**, returning the dest-end pointer. SEH-guarded; on exception destroys the partial dest range and calls `_CxxThrowException`. Primary consumers: vector insert grow relocate (`StdVector_InsertN_BasicString`) and vector range assign (`FUN_00469d10`).

## Signature

```c
// cdecl (first, last, dest) -> dest_end; bare RET (C3)
BasicString_0x1c* StdUninitCopy_BasicString(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest);
```

| Formal | Source | Conf |
|---|---|---|
| first | stack `[ebp+8]` / EDI | **High** |
| last | stack `[ebp+0xC]` | **High** |
| dest | stack `[ebp+0x10]` / ESI | **High** |
| return | EAX = dest_end | **High** |
| cleanup | bare `C3` cdecl | **High** |
| stride | `+0x1C` per element | **High** |
| SEH | `LAB_009bcce1` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004306b0` @ `0x004307e6`, `0x0043080f`; `FUN_00431430` @ `0x00431445`; `FUN_00469d10` @ `0x00469d76` |
| Callees | `basic_string` copy-ctor IAT (`[0x009C62EC]`→`0x006EAD80`); catch: dtor IAT + `_CxxThrowException` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0046a2c0_FUN_0046a2c0.md` (W33-G append)
- Annotated: `docs/reconstruction/raw/aa_0046a2c0_FUN_0046a2c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdUninitCopy_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0046a2c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0046a2c0_StdUninitCopy_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_0046a2c0_StdUninitCopy_BasicString.md`
- Scaffold record: `docs/reconstruction/functions/aa_0046a2c0_FUN_0046a2c0.md`
- Scratch: `docs/reconstruction/tmp/a_0046a2c0.md`

## Confidence

| Claim | Level |
|---|---|
| Uninit-copy CF + SEH | **High** |
| cdecl ABI / return dest-end | **High** |
| Stride 0x1c string elements | **High** |
| Catch destroy + throw | **High** (bytes; not in decompiler happy path) |
| Product demangle | **Low** |
| Nested IAT plates | **Med** |
