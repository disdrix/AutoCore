# Function record: StdVector_InsertN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ad0` |
| **Canonical name** | `StdVector_InsertN_BasicStringW` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a7ad0` |
| **Address** | `0x004a7ad0` |
| **Body** | `0x004a7ad0`–`0x004a7df7` exclusive (**807 B** / `0x327`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<wchar_t>>` insert-n |
| **Completion status** | **Dual-reviewed** W34-R — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Insert `count` copies of a `basic_string<wchar_t>` value at pointer iterator `where` into a vector whose elements are **0x1c** bytes. Grows 1.5× when capacity is insufficient; in-place shift+fill when capacity allows. Sole direct caller `FUN_004a7ff0` uses count=`1` and rebinds an out-iterator (insert-one wrapper). Wide-string twin of sealed `StdVector_InsertN_BasicString` (`0x004306b0`, W32-B).

## Signature

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_BasicStringW(
    VectorBasicStringW* vec,
    BasicStringW_0x1c* where,
    uint32_t count,
    BasicStringW_0x1c* value);
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
| Callers | `FUN_004a7ff0` @ `0x004a8043` (insert-one rebind: count=`1`) |
| Callees | wstring copy/dtor IAT; `FUN_004a6820`; `FUN_00469c50` (Elem28_Size); `operator_new`/`delete`; `FUN_004a6b50`; `FUN_004a74f0`; `FUN_004a7aa0`; `FUN_004a7a70`; `FUN_004a68a0`; `FUN_004a68d0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.md` (W34-R append)
- Annotated: `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicStringW.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a7ad0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a7ad0_StdVector_InsertN_BasicStringW.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a7ad0_StdVector_InsertN_BasicStringW.md`
- Scaffold record: `docs/reconstruction/functions/aa_004a7ad0_FUN_004a7ad0.md`

## Confidence

| Claim | Level |
|---|---|
| Insert-n CF (grow / in-place) | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Stride 0x1c + max 0x9249249 | **High** |
| Element type = basic_string\<wchar_t\> | **High** (decompiler type + IAT ctor/dtor + destroy-range) |
| Product demangle / container plate | **Low** |
| Nested helper product plates | **Med** (not owned) |
