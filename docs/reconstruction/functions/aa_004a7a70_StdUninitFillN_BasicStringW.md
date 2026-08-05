# Function record: StdUninitFillN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7a70` |
| **Canonical name** | `StdUninitFillN_BasicStringW` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a7a70` |
| **Address** | `0x004a7a70` |
| **Body** | `0x004a7a70`–`0x004a7aa0` exclusive (**48 B** / `0x30`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Uninit_fill_n` wrapper for `basic_string<wchar_t>` (elem **0x1c**) |
| **Completion status** | **Dual-reviewed** W36-S — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Copy-construct `count` elements at `dest` from a single `value` wstring (uninitialized fill-n), returning `dest + count*0x1C`. Delegates the loop to `FUN_004a74f0`. Used exclusively by `StdVector_InsertN_BasicStringW` on the **in-place hole** arm (grow path calls `FUN_004a74f0` directly).

## Signature

```c
// thiscall ECX=alloc/host; stack dest*, count, value*; RET 0x0C
BasicStringW_0x1c* __thiscall StdUninitFillN_BasicStringW(
    void* alloc,
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value);
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
| Callers | `FUN_004a7ad0` (`StdVector_InsertN_BasicStringW`) @ `0x004a7d4a` |
| Callees | `FUN_004a74f0` (fill loop body; not dual-owned) |

## Related

| VA | Role |
|---|---|
| `0x00430390` | Char twin `StdUninitFillN_BasicString` (W33-G) |
| `0x004a74f0` | Nested fill loop (W36-R; not owned) |
| `0x004a7ad0` | Parent insert-n (W34-R) |
| `0x004a7aa0` | Wave-mate destroy-range (this dual) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a7a70_FUN_004a7a70.md` (W36-S append)
- Annotated: `docs/reconstruction/raw/aa_004a7a70_FUN_004a7a70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicStringW.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004a7a70.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a7a70_StdUninitFillN_BasicStringW.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a7a70_StdUninitFillN_BasicStringW.md`
- Scaffold record: `docs/reconstruction/functions/aa_004a7a70_FUN_004a7a70.md`

## Confidence

| Claim | Level |
|---|---|
| Fill-n wrapper CF | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Stride 0x1c return math | **High** |
| Nested loop product plate | **Med** (unowned `FUN_004a74f0`) |
| Product demangle / allocator formal | **Low** |
