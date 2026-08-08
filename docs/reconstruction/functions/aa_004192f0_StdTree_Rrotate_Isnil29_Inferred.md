# Function record: StdTree_Rrotate_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004192f0` |
| **Canonical name** | `StdTree_Rrotate_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004192f0` |
| **Address** | `0x004192f0` |
| **Body** | `0x004192f0`–`0x00419341` exclusive (81 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` / shared containers |
| **Completion status** | **Dual sealed** (WQ9D-D 2026-08-04) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Right-rotate about node `x` for RB-tree nodes with **isnil at +0x29**. Promote `x->left`; hang `x` as `y->right`. Shared leaf used by multiple map erase/rebalance helpers (not a skill-cast manager).

## Signature

```c
// __thiscall  RET 4
void StdTree_Rrotate_Isnil29_Inferred(Tree* this, Node* x);
```

## Layout

| Offset | Role |
|---|---|
| node `+0x00` | left |
| node `+0x04` | parent |
| node `+0x08` | right |
| node `+0x29` | isnil (`0` = real) |
| tree `+0x04` | header; root = `*(header+4)` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004192f0_FUN_004192f0.md`
- Annotated: `docs/reconstruction/raw/aa_004192f0_FUN_004192f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil29_Inferred.cpp`
- Twin scaffold: `docs/reconstruction/reconstructed-exact/FUN_004192f0.cpp`
- Dual A/B: `reviews/A|B_aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md`

## Related

| VA | Name | Relation |
|---|---|---|
| `0x004192a0` | Lrotate isnil29 (WQ9D-C) | twin |
| `0x00418c10` | `StdTree_Rrotate_Val12` | peer CF; isnil@+0x19 |
| `0x0051cb40` | Map erase family | caller |

## Confidence

| Claim | Level |
|---|---|
| Rrotate CF / ABI / isnil@+0x29 | **Confirmed** |
| Role High | **Confirmed** |
| Product C++ name | **Inferred** |
