# Function record: GuardedVector_AssignLinearRangeAt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e4f0` |
| **Canonical name** | `GuardedVector_AssignLinearRangeAt` (**Inferred**) |
| **Ghidra name** | `FUN_0044e4f0` |
| **Address** | `0x0044e4f0`–`0x0044e553` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W33-L 2026-07-29 — **accept** |

## Purpose

Copy linear `[first, last)` dwords into the GuardedVector ring at absolute `dest_idx`, using the standard page map. Leaf assign used by `GuardedVector_InsertRange` after shorter-side grow/move opens a gap.

## Signature

```c
// cdecl; plain RET
void GuardedVector_AssignLinearRangeAt(
    GuardedVectorIteratorPair* out,
    const uint32_t* first,
    const uint32_t* last,
    GuardedVectorHeader* container,
    uint32_t dest_idx);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044e4f0_FUN_0044e4f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044e4f0_FUN_0044e4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignLinearRangeAt.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e4f0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0044e4f0_FUN_0044e4f0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md`, `B_…` |
