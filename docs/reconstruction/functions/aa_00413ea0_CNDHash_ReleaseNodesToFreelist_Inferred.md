# Function record: CNDHash_ReleaseNodesToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413ea0` |
| **Canonical name** | `CNDHash_ReleaseNodesToFreelist_Inferred` |
| **Address** | `0x00413ea0` |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B 2026-07-29 |
| **Dual** | `reviews/A_aa_00413ea0_CNDHash_ReleaseNodesToFreelist_Inferred.md`, `B_*` |

## Purpose

Walk all buckets; destroy values via vtbl(1); push nodes to freelist `hash+0x20`. EBX=hash. Nested of DestroyBucketTable.
