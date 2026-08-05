# Function record: StdVector_PushBack_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8100` |
| **Canonical name** | `StdVector_PushBack_BasicStringW` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a8100` |
| **Address** | `0x004a8100`–`0x004a8187` exclusive (**135 B** / `0x87`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<basic_string<wchar_t>>::push_back` (elem **0x1c**) |
| **Completion status** | **Dual sealed** W38-K — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Push **one** `basic_string<wchar_t>` (elem **0x1c**) onto a triad vector. **Spare capacity** → uninit-fill-n count=1 at `end` then advance. **Empty buffer or full** → insert-one-rebind at `end` (growth path; outIt discarded).

## Signature

```c
// __thiscall ECX=vec*; stack value*; RET 0x04
void StdVector_PushBack_BasicStringW(
    StdVectorBasicStringW* vec,
    const BasicStringW_0x1c* value);
```

## Related

| VA | Role |
|---|---|
| `0x004a74f0` | `StdUninitFillN_BasicStringW` (W36-R) — fast path |
| `0x004a7ff0` | `StdVector_InsertOne_RebindIt_BasicStringW` (W37-W) — slow path |
| `0x004a7ad0` | `StdVector_InsertN_BasicStringW` (W34-R) — insert-n under insert-one |
| `0x004a1d80` | sole listed caller — wstring token split → push_back |
| `0x00460f90` | RcElem28 push_back twin (different ABI/callee) |
| `0x00469c80` | POD Elem28 push_back twin |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a8100_FUN_004a8100.md` |
| Annotated | `docs/reconstruction/raw/aa_004a8100_FUN_004a8100.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a8100.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_004a8100_FUN_004a8100.md` |
| A/B | `docs/reconstruction/reviews/A_aa_004a8100_StdVector_PushBack_BasicStringW.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0096b930-004a8100-w38k-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow spare/full + stride 0x1c | **Confirmed** (decompile + bytes) |
| RET 0x04 / thiscall | **Confirmed** |
| Fast fill-n count=1 / slow insert-one | **Confirmed** |
| Product STL demangle | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
