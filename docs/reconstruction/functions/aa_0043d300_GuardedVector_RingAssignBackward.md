# Function record: GuardedVector_RingAssignBackward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d300` |
| **Canonical name** | `GuardedVector_RingAssignBackward` (**Inferred**) |
| **Ghidra name** | `FUN_0043d300` |
| **Address** | `0x0043d300`–`0x0043d38d` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W28-C 2026-07-29 — **accept** |

## Purpose

Reverse-direction ring dword assign: walk source and destination indices backward, copying elements until the source cursor meets a stop `(container,index)` pair. Returns the final destination iterator through `out_pair`. Leaf worker for `GuardedVector_EraseRange` shorter-prefix arm and assign/grow packing.

## Signature

```c
// Retail: 7 stack args; plain RET (caller cleans); returns out_pair in EAX
GuardedVectorIteratorPair* GuardedVector_RingAssignBackward(
    GuardedVectorIteratorPair* out_pair,
    GuardedVectorHeader* stop_container, uint32_t stop_index,
    GuardedVectorHeader* src_container, uint32_t src_index,
    GuardedVectorHeader* dst_container, uint32_t dst_index);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d300_FUN_0043d300.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d300_FUN_0043d300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d300.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043d300_FUN_0043d300.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043d300_GuardedVector_RingAssignBackward.md`, `B_…` |
