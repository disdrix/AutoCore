# Function record: StdTree_Lrotate_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403e90` |
| **Canonical name** | `StdTree_Lrotate_Isnil31_Inferred` (**Inferred** — product map English open) |
| **Ghidra name** | `FUN_00403e90` |
| **Prior scaffold** | `FUN_00403e90` / `Named_CalleeOf_*NotifyActiveMission*` (reject) |
| **Address** | `0x00403e90`–`0x00403edb` inclusive (**76 B** / `0x4C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` left-rotate (isnil@+0x31) |
| **Agent** | WQ9L-B OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Classic **left rotate** about node X in a red-black tree whose nodes carry **isnil at +0x31** (color at +0x30, node size **0x38**). Promotes `x->right` to `x`'s position; hangs `x` as the new left child of that node. Leaf (no callees); no color writes.

```text
Y = X.right
X.right = Y.left
if Y.left non-nil@+0x31: Y.left.parent = X
Y.parent = X.parent
if X is root: root = Y
elif X is left of parent: parent.left = Y
else: parent.right = Y
Y.left = X; X.parent = Y
```

## Signature

```c
// __thiscall: ECX = node X; stack map*; RET 4; void
void __thiscall StdTree_Lrotate_Isnil31_Inferred(
    StdTreeNode_Isnil31 *x,
    StdTreeMapShell_Isnil31 *map);
```

## Layout (node)

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x2F | value payload |
| +0x30 | color (callers; not written here) |
| +0x31 | isnil |
| size | **0x38** |

Map shell: `myhead@+4`; root = `myhead->parent`.

## Call graph

| Role | Target |
|---|---|
| **Callers (2 funcs / 5 sites)** | dualed erase `StdTree_EraseAndRebalance_Isnil31_Inferred` `0x00408ed0` (3); `FUN_00403250` (2) |
| Callees | **none** (leaf) |
| Rrotate twin | `FUN_00403ee0` (WQ9L-C residual) |
| Peer isnil29 | `StdTree_Lrotate_Isnil29` `0x004192a0` — different family |
| Peer isnil2D | `StdTree_LeftRotate_Isnil2D_Inferred` `0x0044e010` — different family |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil31_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00403e90.cpp`
- Raw: `docs/reconstruction/raw/aa_00403e90_FUN_00403e90.md`
- Annotated: `docs/reconstruction/raw/aa_00403e90_FUN_00403e90.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md`
- Report: `docs/agents/task-dual-ab-00401bc0-00403e90-wq9lb-report.md`

## Confidence

| Claim | Level |
|---|---|
| Left-rotate CF | **Confirmed** |
| isnil@+0x31 | **Confirmed** |
| thiscall + RET 4; ECX=node; stack=map | **Confirmed** |
| Caller set (5) | **Confirmed** |
| Product map English | **Inferred** / open |
