# Function record: StdTree_Predecessor_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4f0` |
| **Canonical name** | `StdTree_Predecessor_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_004cb4f0` |
| **Address** | `0x004cb4f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cb4f0`–`0x004cb540` exclusive (80 B / `0x50`) |
| **System** | std red-black tree / map iterator (isnil @ +0x29) |
| **Wave** | WQ9G-B OWN-ONLY dual 2026-08-04 |
| **Completion status** | **accept-with-gaps** (dual A/B) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |

## Naming rationale

Structural name from sealed role (tree predecessor) + isnil discriminator (**+0x29**) matching dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` / `StdTree_InsertHint_Isnil29_Inferred`. No product/PDB plate → `_Inferred`. Scaffold VOGClient Named_CalleeOf **rejected**.

## Purpose

Advance `*it` to the in-order predecessor for isnil29 RB-tree nodes. Three arms: header→right, left-subtree max, parent climb while left-child.

## Signature

```c
void __fastcall StdTree_Predecessor_Isnil29_Inferred(StdTreeNode_Isnil29** it /*ECX*/);
```

## Related dualed units

| VA | Name | Relation |
|---|---|---|
| `0x004cbb60` | `StdTree_InsertAndRebalance_Isnil29_Inferred` | same node family |
| `0x004cbe20` | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` | caller (goLeft pred) |
| `0x004cbee0` | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` | caller |
| `0x004cc220` | `StdTree_InsertHint_Isnil29_Inferred` | caller (prev neighbor) |
| `0x004129f0` | `Map_Tree_Predecessor_Isnil15_Edx` | peer algorithm, isnil15 + EDX |

## Artifacts

- Raw / annotated / clean / dual A/B / FUN record: see `aa_004cb4f0_FUN_004cb4f0.md`
- Report: `docs/agents/task-dual-ab-004cb4f0-00401480-wq9gb-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil@+0x29 | **High** |
| Name structural | **Inferred** |
| Runtime | Open |
