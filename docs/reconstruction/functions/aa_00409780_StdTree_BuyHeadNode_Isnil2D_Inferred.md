# Function record: StdTree_BuyHeadNode_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409780` |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00409780` |
| **Address** | `0x00409780` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00409780`–`0x00409809` inclusive (138 B / `0x8A`) |
| **System** | STL / map-set head node (isnil @ +0x2d) |
| **Wave** | WQ9J-G OWN-ONLY dual 2026-08-05 |
| **Completion status** | **accept-with-gaps** (dual A/B) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |

## Naming rationale

Structural name from sealed role (tree head shell) + isnil discriminator (**+0x2d**) matching family convention (`BuyHeadNode_Isnil29`, `BuynodeEmpty_Isnil21`). No product/PDB plate → `_Inferred`. Self-link/isnil1 stay on caller side (honest gap).

## Purpose

Allocate blank 0x30 node: zero L/P/R, color black @+0x2c, isnil=0 @+0x2d. Head install is outside this unit.

## Signature

```c
NodeIsnil2D* StdTree_BuyHeadNode_Isnil2D_Inferred(void);
```

## Related dualed units

| VA | Name | Relation |
|---|---|---|
| `0x00408a30` | `StdTree_BuyHeadNode_Isnil29_Inferred` | peer algorithm, isnil@+0x29 |
| `0x004088f0` | `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` | empty buy, size 0x28 isnil@+0x21 |
| `0x00409820` | `StdTree_Predecessor_Isnil29_Edx_Inferred` | co-located residual; **different** isnil family |

## Artifacts

- See `aa_00409780_FUN_00409780.md`
- Report: `docs/agents/task-dual-ab-00409780-00409820-wq9jg-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil@+0x2d / size 0x30 | **High** |
| Name structural | **Inferred** |
| Runtime | Open |
