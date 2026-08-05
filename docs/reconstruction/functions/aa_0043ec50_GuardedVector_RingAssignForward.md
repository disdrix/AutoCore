# Function record: GuardedVector_RingAssignForward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ec50` |
| **Canonical name** | `GuardedVector_RingAssignForward` (**Inferred**) |
| **Ghidra name** | `FUN_0043ec50` |
| **Address** | `0x0043ec50`–`0x0043ecdc` (**140 B**) |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W33-J 2026-07-29 — **accept** |

## Purpose

Forward-direction ring dword assign: walk source and destination indices forward, copying elements until the source cursor meets a stop `(container,index)` pair. Returns the final destination iterator through `out_pair`. Leaf worker for thiscall insert-N / insert-range forward arms. Sibling reverse in thiscall family: `FUN_0043ebb0`. Older-family forward: `GuardedVector_RingCopyElements` (`0x0043d390`).

## Signature

```c
// Retail: 7 stack args; plain RET (caller cleans); writes out_pair
GuardedVectorIteratorPair* GuardedVector_RingAssignForward(
    GuardedVectorIteratorPair* out_pair,
    GuardedVectorHeader* src_container, uint32_t src_index,
    GuardedVectorHeader* src_end_container, uint32_t src_end_index,
    GuardedVectorHeader* dst_container, uint32_t dst_index);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ec50_FUN_0043ec50.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ec50_FUN_0043ec50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignForward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ec50.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043ec50_FUN_0043ec50.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043ec50_GuardedVector_RingAssignForward.md`, `B_…` |
| Scratch | `docs/reconstruction/tmp/a_0043ec50.md` |
