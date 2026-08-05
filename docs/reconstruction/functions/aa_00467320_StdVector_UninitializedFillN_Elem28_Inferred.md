# Function record: StdVector_UninitializedFillN_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467320` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem28_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00467320` |
| **Address** | `0x00467320`–`0x0046736e` (**79 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / std::vector uninitialized_fill_n (POD stride 0x1c) |
| **Completion status** | Dual A/B sealed W35-T 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf **uninitialized_fill_n** for POD T size **0x1c**: write `*value` into `count` consecutive dest slots (7-dword fieldwise). Used by `StdVector_InsertN_Elem28_CountEcx_Inferred` (`0x00466ea0`) fill arms.

## Signature

```c
// ECX=dest, EDX=value*, EAX=count; bare RET
void StdVector_UninitializedFillN_Elem28_Inferred(
    Pod28* dest /*ECX*/,
    const Pod28* value /*EDX*/,
    int count /*EAX*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23 CF
- Full body hex via `read_memory` (79 B); stride imm `0x1C`; bare `C3`
- 2 xrefs / sole parent `FUN_00466ea0`; leaf
- Dual A/B **accept**

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00467320_FUN_00467320.md` |
| Annotated | `docs/reconstruction/raw/aa_00467320_FUN_00467320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00467320.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00467320_FUN_00467320.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00467320.md` |
