# Function record: GuardedVector_RingFillFromPtr

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e910` |
| **Canonical name** | `GuardedVector_RingFillFromPtr` (**Inferred**) |
| **Ghidra name** | `FUN_0043e910` |
| **Address** | `0x0043e910`–`0x0043e963` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W33-K 2026-07-29 — **accept** |

## Purpose

Assign `*fill` across a half-open absolute ring index range using the GuardedVector page map (`+0x04` slots, `+0x08` capacity, 4 dwords/page). Fill pointer arrives as a stack formal; store is skipped when dest aliases fill. Parent: `GuardedVector_InsertN_Thiscall` fill residual. Twin of EBX-fill `GuardedVector_RingFillRange` (`0x0043cef0`).

## Signature

```c
// Retail: 5 stack args; plain RET (caller cleans 0x14)
void GuardedVector_RingFillFromPtr(
    GuardedVectorHeader* start_c, uint32_t start_i,
    GuardedVectorHeader* end_c,   uint32_t end_i,
    const uint32_t* fill);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e910_FUN_0043e910.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e910_FUN_0043e910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillFromPtr.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e910.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043e910_FUN_0043e910.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043e910_GuardedVector_RingFillFromPtr.md`, `B_…` |
