# Function record: StdVector_InsertN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_004306b0` |
| **Canonical name** | `StdVector_InsertN_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_004306b0` |
| **Address** | `0x004306b0` |
| **Body** | `0x004306b0`–`0x004309bf` exclusive (**783 B** / `0x30F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<char>>` insert-n |
| **Completion status** | **Dual-reviewed** W32-B — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Insert `count` copies of a `basic_string` value at pointer iterator `where` into a vector whose elements are **0x1c** bytes. Grows 1.5× when capacity is insufficient; in-place shift+fill when capacity allows. Sole direct caller `FUN_00430310` uses count=`1` and rebinds an out-iterator (insert-one wrapper).

## Signature

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_BasicString(
    VectorBasicString* vec,
    BasicString_0x1c* where,
    uint32_t count,
    BasicString_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B F1`) | **High** |
| where | stack `[ebp+8]` | **High** |
| count | stack `[ebp+0xC]` | **High** |
| value | stack `[ebp+0x10]` | **High** |
| cleanup | `C2 0C 00` | **High** |
| stride | `/ 0x1c` magic `0x92492493` | **High** |
| max | `0x9249249` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00430310` @ `0x00430363` (and indirectly `StringVec_PushFront_EnsureTrailingDirSep` via that) |
| Callees | string copy/dtor IAT; `FUN_004540b0`; `FUN_00469c50`; `operator_new`/`delete`; `FUN_0046a2c0`; `FUN_00430390`; `FUN_00431aa0`; `FUN_00431430`; `FUN_00431450`; `FUN_00431480` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004306b0_FUN_004306b0.md` (W32-B append)
- Annotated: `docs/reconstruction/raw/aa_004306b0_FUN_004306b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004306b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004306b0_StdVector_InsertN_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_004306b0_StdVector_InsertN_BasicString.md`
- Scaffold record: `docs/reconstruction/functions/aa_004306b0_FUN_004306b0.md`

## Confidence

| Claim | Level |
|---|---|
| Insert-n CF (grow / in-place) | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Stride 0x1c + max 0x9249249 | **High** |
| Element type = basic_string | **High** (decompiler + destroy/fill helpers) |
| Product demangle / container plate | **Low** |
| Nested helper product plates | **Med** (not owned) |
