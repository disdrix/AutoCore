# Function record: FUN_0043ebb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ebb0` |
| **Canonical name** | `FUN_0043ebb0` |
| **Named alias** | `GuardedVector_RingAssignBackwardChecked` (**Inferred**) |
| **Address** | `0x0043ebb0`–`0x0043ec43` (**148 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W33-K 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Reverse-direction ring dword assign: walk source and destination indices backward, copying elements until the source cursor meets a stop `(container,index)` pair. Self-alias skip before store. Returns final destination iterator through `out_pair` (EAX). Leaf for InsertN_Thiscall back-biased mid-insert and InsertRange packing.

## Signature

```c
// Retail: 7 stack args; plain RET (caller cleans 0x1c); returns out in EAX
// Decompiler void is incomplete — bytes win on return.
GuardedVectorIteratorPair* FUN_0043ebb0(
    GuardedVectorIteratorPair* out,
    GuardedVectorHeader* stop_c, uint32_t stop_i,
    GuardedVectorHeader* src_c,  uint32_t src_i,
    GuardedVectorHeader* dst_c,  uint32_t dst_i);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackwardChecked.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ebb0.cpp` |
| Named record | `docs/reconstruction/functions/aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md`, `B_…` |

## Callers / callees

- **Callers (4):** `FUN_0043e080`, `FUN_0043df90`, `FUN_0044e1c0`, `FUN_005441d0`
- **Xrefs:** `0x0043e352`, `0x0043dfee`, `0x0044e4bd`, `0x0054454d`
- **Callees:** none (leaf)

## Confidence

| Claim | Level |
|---|---|
| Reverse CF + capacity wrap | **High** |
| Self-alias store skip | **High** |
| 7-arg plain RET + out in EAX | **High** (bytes) |
| Product English | **Inferred** only |
