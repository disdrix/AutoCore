# Function record: CNDHash_AllocBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413d80` |
| **Canonical name** | `CNDHash_AllocBucketTable_Inferred` |
| **Address** | `0x00413d80` |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B 2026-07-29 |
| **Dual** | `reviews/A_aa_00413d80_CNDHash_AllocBucketTable_Inferred.md`, `B_*` |

## Purpose

Alloc pointer array + 0xc sentinel slab; require log2 in 1..16; convert count at +8 to mask (count−1). ESI=hash. Nested of Recreate / hash ctor.
