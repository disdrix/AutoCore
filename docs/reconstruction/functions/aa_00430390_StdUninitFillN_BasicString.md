# Function record: StdUninitFillN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430390` |
| **Canonical name** | `StdUninitFillN_BasicString` (**Inferred** structural) |
| **Ghidra name** | `FUN_00430390` |
| **Address** | `0x00430390` |
| **Body** | `0x00430390`–`0x004303c0` exclusive (**48 B** / `0x30`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Uninit_fill_n` wrapper for `basic_string<char>` (elem **0x1c**) |
| **Completion status** | **Dual-reviewed** W33-G — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Copy-construct `count` elements at `dest` from a single `value` string (uninitialized fill-n), returning `dest + count*0x1C`. Delegates the loop to `FUN_00431700`. Used exclusively by `StdVector_InsertN_BasicString` when planting inserted values after grow or in-place shift.

## Signature

```c
// thiscall ECX=alloc/host; stack dest*, count, value*; RET 0x0C
BasicString_0x1c* __thiscall StdUninitFillN_BasicString(
    void* alloc,
    BasicString_0x1c* dest,
    int count,
    const BasicString_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| alloc | ECX (forwarded) | **High** (presence); **Med** (product role) |
| dest | stack arg1 / EDI | **High** |
| count | stack arg2 / ESI | **High** |
| value | stack arg3 | **High** |
| return | EAX = dest + count*0x1c | **High** |
| cleanup | `C2 0C 00` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004306b0` (`StdVector_InsertN_BasicString`) @ `0x004307f9`, `0x00430910` |
| Callees | `FUN_00431700` (fill loop body; not dual-owned) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00430390_FUN_00430390.md` (W33-G append)
- Annotated: `docs/reconstruction/raw/aa_00430390_FUN_00430390.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicString.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00430390.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00430390_StdUninitFillN_BasicString.md`
- Review B: `docs/reconstruction/reviews/B_aa_00430390_StdUninitFillN_BasicString.md`
- Scaffold record: `docs/reconstruction/functions/aa_00430390_FUN_00430390.md`
- Scratch: `docs/reconstruction/tmp/a_00430390.md`

## Confidence

| Claim | Level |
|---|---|
| Fill-n wrapper CF | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Stride 0x1c return math | **High** |
| Nested loop product plate | **Med** (unowned `FUN_00431700`) |
| Product demangle / allocator formal | **Low** |
