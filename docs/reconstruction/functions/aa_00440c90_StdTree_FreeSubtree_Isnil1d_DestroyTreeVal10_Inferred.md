# Function record: StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440c90` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` |
| **Ghidra name** | `FUN_00440c90` |
| **Address** | `0x00440c90`–`0x00440cca` inclusive (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL tree free; gfxUIWindow shell@+0x10 family) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md`, `B_aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md` |
| **Last reviewed** | `2026-08-05` (MEGA-131 OWN-ONLY) |

## Alias

- `FUN_00440c90`
- `Named_CalleeOf_Named_gfxUIWindow_00440c90` (**retired scaffold**)
- Partition hint `StdTree_ClearShell_At10` — describes **parent** clear pattern (free + reset), not this VA alone

## Purpose

MSVC map/tree free-subtree for isnil@+0x1d nodes: recursive free right, destroy embedded tree value at node+0x10 (`FUN_00442730`), delete node, walk left. Called by gfxUIWindow complete-dtor and peers when clearing the tree shell at **host+0x10**.

## Signature (sealed)

```c
void __fastcall StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred(
    void *tree_shell, void *node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x1d`: return.
2. Loop: free right subtree; `left = node->left`; `FUN_00442730(EAX=node)`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_00759de0` `gfxUIWindow_CompleteDtor` (parent dual; shell@+0x10 clear)
- `aa_0051be10` `Map_FreeSubtree_Isnil1d` (CF peer, **no** value dtor)
- `FUN_00440ab0` (shell@+0x04 free; isnil@+0x3d + `FUN_00442720`)
- `FUN_00442730` (value dtor; residual)
- `FUN_00441720` (erase-range full-clear caller)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report `task-dual-ab-00440c90-mega-131-report.md`
