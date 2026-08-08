# Function record: StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440ab0` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00440ab0` |
| **Partition alias** | `StdTree_ClearShell_At04` |
| **Address** | `0x00440ab0` |
| **Body** | `0x00440ab0`–`0x00440aeb` exclusive (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / MSVC `_Tree` free-subtree (isnil@+0x3D, val@+0x0C) |
| **Completion status** | **Dual-reviewed** MEGA-130 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Free a red-black **subtree** of isnil@**+0x3D** nodes:

1. Early-out if `node.isnil != 0`.
2. Loop left spine: free **right** child recursively, destroy embedded value at **node+0x0C** (`FUN_00442720`), `operator_delete(node)`, advance to left.
3. Stop at nil sentinel.

Does **not** run empty-head reset (size=0 / parent=left=right=head) — that is done by callers after free (gfxUIWindow complete at shell **this+0x04**, erase-all `FUN_004413c0`).

## Signature

```c
// ECX = tree_host (threaded; unused in body loads); stack node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred(
    void* tree_host, StdTreeNode_Isnil3D* node);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `gfxUIWindow_CompleteDtor` / `FUN_00759de0` @ `0x00759e79`; `FUN_004413c0` @ `0x004413e0`; `Catch@004424ff` @ `0x00442506`; self @ `0x00440ac7` |
| Callees | self, `FUN_00442720` (val dtor trampoline), `operator_delete` @ `0x00489822` |

## Peer family (not owned)

| VA | isnil | Value path | Role |
|---|---|---|---|
| `0x00440ab0` (this) | +0x3D | `00442720` | ClearShell_At04 |
| `0x00440c90` | +0x1D | `00442730` | ClearShell_At10 (MEGA-131 residual) |
| `0x00440d20` | +0x11 | none | ClearShell_AtA4 (MEGA-132 residual) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00440ab0_FUN_00440ab0.md`
- Annotated: `docs/reconstruction/raw/aa_00440ab0_FUN_00440ab0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00440ab0.cpp`
- Scaffold FUN record: `docs/reconstruction/functions/aa_00440ab0_FUN_00440ab0.md`
- Review A: `docs/reconstruction/reviews/A_aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md`
- Report: `docs/agents/task-dual-ab-00440ab0-mega-130-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes left-walk + recursive right) | **High** |
| ABI ECX + stack arg + RET 4 | **High** |
| isnil@+0x3D / val destroy @+0x0C | **High** |
| gfxUIWindow+0x04 ClearShell role | **High** |
| Product map / value type English | **Low** |
| tree_host use beyond threading | **Med** (unused in body) |
