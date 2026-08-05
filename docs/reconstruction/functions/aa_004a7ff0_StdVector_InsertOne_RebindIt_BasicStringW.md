# Function record: StdVector_InsertOne_RebindIt_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ff0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_BasicStringW` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a7ff0` |
| **Address** | `0x004a7ff0`–`0x004a8063` exclusive (**115 B** / `0x73`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<wchar_t>>` insert-one + rebind |
| **Completion status** | **Dual sealed** W37-W — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Insert **exactly one** `basic_string<wchar_t>` (elem **0x1c**) at `where` via sealed insert-n (`count=1`), then write a **rebased** iterator to `*outIt` so callers survive reallocation of `begin`.

Primary known caller: **`FUN_004a8100`** capacity-full push_back slow path (fast path: `FUN_004a74f0` fill-one at end when spare cap).

## Signature

```c
// __thiscall ECX=vec*; stack (outIt*, where*, value*); RET 0x0C
void StdVector_InsertOne_RebindIt_BasicStringW(
    StdVectorBasicStringW* vec,
    BasicStringW_0x1c** outIt,
    BasicStringW_0x1c* where,
    const BasicStringW_0x1c* value);
```

## Related

| VA | Role |
|---|---|
| `0x004a7ad0` | `StdVector_InsertN_BasicStringW` (W34-R) — callee |
| `0x004a8100` | push_back parent (unowned) |
| `0x0040dbf0` | dword insert-one rebind twin (stride 4) |
| `0x004612d0` | RcElem28 insert-one rebind twin (customcc) |
| `0x00469e20` | Elem28 insert-one rebind twin |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a7ff0_FUN_004a7ff0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7ff0_FUN_004a7ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a7ff0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_004a7ff0_FUN_004a7ff0.md` |
| A/B | `docs/reconstruction/reviews/A_aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-004a7ff0-00970cf0-w37w-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / count=1 / stride 0x1c | **Confirmed** (decompile + bytes) |
| RET 0x0C / thiscall | **Confirmed** |
| Index-then-rebind after insert | **Confirmed** |
| Product STL demangle | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
