# Function record: StdTree_Predecessor_Isnil29_Edx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409820` |
| **Canonical name** | `StdTree_Predecessor_Isnil29_Edx_Inferred` |
| **Ghidra symbol** | `FUN_00409820` |
| **Address** | `0x00409820` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00409820`–`0x00409870` inclusive (81 B / `0x51`) |
| **System** | std red-black tree / map iterator (isnil @ +0x29, EDX) |
| **Wave** | WQ9J-G OWN-ONLY dual 2026-08-05 |
| **Completion status** | **accept-with-gaps** (dual A/B) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |

## Naming rationale

Structural name from sealed role (tree predecessor) + isnil discriminator (**+0x29**) + **Edx** ABI suffix matching `Map_Tree_Predecessor_Isnil15_Edx`. Twin ECX unit is dualed as `StdTree_Predecessor_Isnil29_Inferred` (`0x004cb4f0`). Scaffold Named_CalleeOf **rejected**. Product open → `_Inferred`.

## Purpose

Advance `*it` to in-order predecessor. Three arms: header→right, left-subtree max, parent climb while left-child.

## Signature

```c
void StdTree_Predecessor_Isnil29_Edx_Inferred(StdTreeNode_Isnil29** it /*EDX*/);
```

## Related dualed units

| VA | Name | Relation |
|---|---|---|
| `0x004cb4f0` | `StdTree_Predecessor_Isnil29_Inferred` | same CF/isnil; **ECX** ABI |
| `0x00408590` | `StdTree_IteratorIncrement_Isnil31` | successor peer (right-min) |
| `0x00409780` | `StdTree_BuyHeadNode_Isnil2D_Inferred` | co-located residual; different isnil |

## Artifacts

- See `aa_00409820_FUN_00409820.md`
- Report: `docs/agents/task-dual-ab-00409780-00409820-wq9jg-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil@+0x29 | **High** |
| Name structural | **Inferred** |
| Runtime | Open |
