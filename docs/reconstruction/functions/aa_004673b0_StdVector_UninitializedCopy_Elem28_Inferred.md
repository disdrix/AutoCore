# Function record: StdVector_UninitializedCopy_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004673b0` |
| **Canonical name** | `StdVector_UninitializedCopy_Elem28_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004673b0` |
| **Address** | `0x004673b0`–`0x00467406` (**87 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / std::vector uninitialized_copy (POD stride 0x1c) |
| **Completion status** | Dual A/B sealed W35-T 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf **uninitialized_copy** for POD T size **0x1c**: fieldwise 7-dword assign over `[first, last)` into `dest`. Used by `StdVector_InsertN_Elem28_CountEcx_Inferred` (`0x00466ea0`) on grow/hole relocate.

## Signature

```c
// EAX=dest, ECX=first, stack last; bare RET
void StdVector_UninitializedCopy_Elem28_Inferred(
    Pod28* dest /*EAX*/,
    Pod28* first /*ECX*/,
    Pod28* last /*stack*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23 CF
- Full body hex via `read_memory` (87 B); stride imm `0x1C`; bare `C3`
- 4 xrefs / sole parent `FUN_00466ea0`; leaf
- Dual A/B **accept**

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004673b0_FUN_004673b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004673b0_FUN_004673b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004673b0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_004673b0_FUN_004673b0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004673b0.md` |
