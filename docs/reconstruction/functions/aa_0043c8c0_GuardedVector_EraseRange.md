# Function record: GuardedVector_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c8c0` |
| **Canonical name** | `GuardedVector_EraseRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043c8c0` |
| **Address** | `0x0043c8c0`–`0x0043c9af` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W27-C 2026-07-29 — **accept-with-gaps** |

## Purpose

Erase `[erase_from, erase_to)` in the ring header under `GuardedVector_*` family. Fit-path partner of `GuardedVector_CopyAssign`; also shrink and single-element erase.

## Signature

```c
// Retail: EAX=container; stdcall 5 args; RET 0x14
GuardedVectorIteratorPair* GuardedVector_EraseRange(
    GuardedVectorIteratorPair* out,
    uint32_t seed2, int32_t erase_from, uint32_t seed4, int32_t erase_to,
    GuardedVectorHeader* container /*EAX*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c8c0_FUN_0043c8c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c8c0_FUN_0043c8c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c8c0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043c8c0_FUN_0043c8c0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043c8c0_GuardedVector_EraseRange.md`, `B_…` |
