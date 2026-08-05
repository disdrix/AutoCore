# Function record: CNDHash_Recreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004138d0` |
| **Canonical name** | `CNDHash_Recreate` |
| **Address** | `0x004138d0` |
| **Module** | `autoassault.exe` |
| **System** | container / inventory-transfer |
| **Completion status** | **partial** — dual A/B accept-with-gaps 2026-07-29 |
| **Dual** | `reviews/A_aa_004138d0_CNDHash_Recreate.md`, `B_aa_004138d0_*` |

## Purpose

Recreate inventory u64 CNDHash: destroy bucket table, set log2 size from **BL**, alloc new buckets (mask = count−1). **EAX**=hash. String-sealed. Sole sealed caller: ClearItemWidgets after detach.

## ABI

`void` — EAX=hash*, BL=log2(buckets); plain ret.

## Artifacts

- Dual A/B reviews (this batch)
- Legacy scaffold: `functions/aa_004138d0_FUN_004138d0.md`
- Raw/clean: `raw/aa_004138d0_*`, `reconstructed-exact/FUN_004138d0.cpp`
