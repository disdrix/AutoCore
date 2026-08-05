# Function record: GuardedVector_RingAssignBackwardChecked

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ebb0` |
| **Canonical name** | `GuardedVector_RingAssignBackwardChecked` (**Inferred**) |
| **Ghidra name** | `FUN_0043ebb0` |
| **Address** | `0x0043ebb0`–`0x0043ec43` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W33-K 2026-07-29 — **accept** |

## Purpose

Reverse ring dword assign with address self-guard: while src cursor ≠ stop pair, decrement src/dst indices, map through capacity-wrapped pages, and `*dst = *src` unless pointers equal. Returns `{dst_container, final_dst_index}` via out pair. Twin of `GuardedVector_RingAssignBackward` (`0x0043d300`, no self-guard).

## Signature

```c
// Retail: 7 stack args; plain RET; returns out_pair in EAX
GuardedVectorIteratorPair* GuardedVector_RingAssignBackwardChecked(
    GuardedVectorIteratorPair* out_pair,
    GuardedVectorHeader* stop_container, uint32_t stop_index,
    GuardedVectorHeader* src_container, uint32_t src_index,
    GuardedVectorHeader* dst_container, uint32_t dst_index);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackwardChecked.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ebb0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043ebb0_FUN_0043ebb0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md`, `B_…` |
