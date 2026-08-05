# Function record: StdVector_InsertN_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055be00` |
| **Canonical name** | `StdVector_InsertN_Elem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_0055be00` |
| **Address** | `0x0055be00` |
| **Body** | `0x0055be00`–`0x0055c11c` exclusive (**796 B** / `0x31C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>` insert-n for **POD elem stride 0x1c** |
| **Completion status** | **Dual-reviewed** W34-R — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Insert `count` copies of a **trivially copyable 0x1c** element at pointer iterator `where`. Same control-flow skeleton as `StdVector_InsertN_BasicString` / `BasicStringW` (1.5× grow, hole/mid in-place arms, max `0x9249249`) but value is a **7× dword / movss** stack copy and reallocation **skips destroy-range** (trivial dtor). Shares size helper `StdVector_Elem28_Size` (`0x00469c50`, W33-J). Callers: insert-one rebind `FUN_0055c310` and resize-growth `FUN_0055c250`.

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
| vec | ECX (`8B F1`) | **High** |
| where | stack `[ebp+8]` | **High** |
| count | stack `[ebp+0xC]` | **High** |
| value | stack `[ebp+0x10]` | **High** |
| cleanup | `C2 0C 00` | **High** |
| stride | `/ 0x1c` magic `0x92492493` | **High** |
| max | `0x9249249` | **High** |
| POD elem | 7× movss load/store; no dtor | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0055c250` @ `0x0055c2ae` (resize grow → insert at end); `FUN_0055c310` @ `0x0055c363` (insert-one rebind count=`1`) |
| Callees | `FUN_0055b3a0`; `FUN_00469c50`; `operator_new`/`delete`; `FUN_0055b6a0`; `FUN_0055b7a0`; `FUN_0055bd90`; `FUN_0055b5d0`; `FUN_0055b4d0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055be00_FUN_0055be00.md` (W34-R append)
- Annotated: `docs/reconstruction/raw/aa_0055be00_FUN_0055be00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0055be00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0055be00_StdVector_InsertN_Elem28.md`
- Review B: `docs/reconstruction/reviews/B_aa_0055be00_StdVector_InsertN_Elem28.md`
- Scaffold record: `docs/reconstruction/functions/aa_0055be00_FUN_0055be00.md`

## Confidence

| Claim | Level |
|---|---|
| Insert-n CF (grow / in-place) | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Stride 0x1c + max 0x9249249 | **High** |
| Element is POD (no string IAT) | **High** |
| Product type of Elem28 | **Low** (domain open) |
| Nested helper product plates | **Med** (not owned) |
