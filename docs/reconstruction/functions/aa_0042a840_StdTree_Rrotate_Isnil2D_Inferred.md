# Function record: StdTree_Rrotate_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042a840` |
| **Canonical name** | `StdTree_Rrotate_Isnil2D_Inferred` |
| **Ghidra name** | `FUN_0042a840` |
| **Address** | `0x0042a840`–`0x0042a88f` inclusive (**80 B** / `0x50`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / MSVC `std::_Tree` (isnil@+0x2D) |
| **Wave** | WQ9K-J OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_0042a840`
- Structural: `StdTree_Rrotate_Isnil2D_Inferred` (product demangle open)

## Purpose

Leaf **right rotate** for red-black trees with **isnil @ +0x2D**. Standard MSVC `_Tree` pivot: hoist `x->left` (`y`), reparent, hang `x` as `y->right`. No color writes.

## Signature

```c
// Register ABI: ECX = node x*; stack tree*; void; RET 4
// NOTE: inverted vs isnil29 rotates (those use ECX=tree, stack=node)
void __thiscall StdTree_Rrotate_Isnil2D_Inferred(
    /*ECX*/ void* x,
    /*stack*/ void* tree);
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0044e010` | (L-rotate isnil2D) | twin left — residual |
| `0x004192f0` | `StdTree_Rrotate_Isnil29_Inferred` | same CF, isnil@+0x29, opposite ECX role |
| `0x00430b60` | StringKey insert | rebalance caller |
| `0x004094c0` | StringKey erase | rebalance caller |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0042a840_FUN_0042a840.md`
- Annotated: `docs/reconstruction/raw/aa_0042a840_FUN_0042a840.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil2D_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0042a840.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md`
- Report: `docs/agents/task-dual-ab-0042a840-0040a590-wq9kj-report.md`

## Callers / callees

| **Callers (4)** | `FUN_00401db0`, `FUN_0042a930`, `FUN_00430b60`, `FUN_004094c0` |
| **Callees** | none (leaf) |
| **Xrefs** | 10 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| CF / right-rotate identity | **Confirmed** |
| ECX=node / stack tree / RET 4 | **Confirmed** |
| isnil@+0x2D | **Confirmed** |
| Product English | **Open** |
| Runtime / bit-exact | **Open** |
