# Function record: StdVector_InsertN_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068a1d0` |
| **Canonical name** | `StdVector_InsertN_Elem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_0068a1d0` |
| **Address** | `0x0068a1d0` |
| **Body** | `0x0068a1d0`–`0x0068a49a` exclusive (**714 B** / `0x2CA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>` insert-n for **POD T size 0x1c** |
| **Completion status** | **Dual-reviewed** W34-S — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Insert `count` copies of a POD **0x1c** value at `where` into the vector. Capacity/size via triad begin@`+4` / end@`+8` / capEnd@`+0xC` and `/0x1c`. Grows **1.5×** when needed; in-place hole/mid when capacity allows. Nested relocate/fill/assign helpers are **raw 7-dword memcpy** (not `basic_string` IAT). Sibling of size leaf `StdVector_Elem28_Size` (`0x00469c50`). Algorithm twin of `StdVector_InsertN_BasicString` (`0x004306b0`) with different element semantics.

## Signature

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec,
    Elem28* where,
    uint32_t count,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B D9`) | **High** |
| where | stack `[ebp+8]` | **High** |
| count | stack `[ebp+0xC]` | **High** |
| value | stack `[ebp+0x10]` (`8B 75 10`) | **High** |
| cleanup | `C2 0C 00` | **High** |
| stride | `/0x1c` magic `0x92492493` | **High** |
| max | `0x9249249` | **High** |
| local value | `F3 A5` ECX=7 | **High** (POD) |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0068a620` @ `0x0068a673` (count=`1`, rebind `*out = begin + idx*0x1c`) |
| Callees | `FUN_00686070`; `FUN_00469c50`; `operator_new`/`delete`; `FUN_00687d10`; `FUN_00688550`; `FUN_0068a1a0`; `FUN_00687ce0`; `FUN_006860f0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0068a1d0_FUN_0068a1d0.md` (W34-S append)
- Annotated: `docs/reconstruction/raw/aa_0068a1d0_FUN_0068a1d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0068a1d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0068a1d0_StdVector_InsertN_Elem28.md`
- Review B: `docs/reconstruction/reviews/B_aa_0068a1d0_StdVector_InsertN_Elem28.md`
- Scaffold record: `docs/reconstruction/functions/aa_0068a1d0_FUN_0068a1d0.md`
- Scratch: `docs/reconstruction/tmp/a_0068a1d0.md`

## Confidence

| Claim | Level |
|---|---|
| Insert-n CF | **High** |
| ABI thiscall + RET 0x0C | **High** |
| POD 0x1c (not basic_string) | **High** (helper decompiles) |
| Max / 1.5× | **High** |
| Product T plate | **Low** |
| Nested helper English | **Med** |
