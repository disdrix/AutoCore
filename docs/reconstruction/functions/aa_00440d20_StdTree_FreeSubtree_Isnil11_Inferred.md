# Function record: StdTree_FreeSubtree_Isnil11_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440d20` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil11_Inferred` |
| **Ghidra name** | `FUN_00440d20` |
| **Address** | `0x00440d20`–`0x00440d54` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (STL tree free-subtree; gfxUIWindow shell `@+0xA4`) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md`, `B_aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md` |
| **Last reviewed** | `2026-08-05` (MEGA-132 OWN-ONLY) |

## Alias

- `FUN_00440d20`
- `StdTree_ClearShell_AtA4` (partition host-role hint)
- `Named_CalleeOf_Named_gfxUIWindow_00440d20` (scaffold; **retired**)

## Purpose

MSVC map/tree free-subtree for isnil@+0x11 nodes: recursive free right, delete node, walk left. No value destroy. Primary external role: free root of gfxUIWindow tree shell `@+0xA4` during complete dtor; also erase-all full-clear and UI rebuild clear.

## Signature (sealed)

```c
void __fastcall StdTree_FreeSubtree_Isnil11_Inferred(void* tree_base, void* node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x11`: return.
2. Loop: free right subtree; `left = node->left@+0`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_00759de0` `gfxUIWindow_CompleteDtor` (host parent; dualed WQ9L-F)
- `aa_00441960` erase-all isnil11 residual (MEGA-136)
- `aa_00440ab0` / `aa_00440c90` free-subtree with value dtor (MEGA-130/131 residual)
- `aa_00406c00` `StdTree_FreeSubtree_Isnil29_Inferred` (CF twin, isnil@+0x29)
- `aa_0051bbc0` `Map_FreeSubtree_Isnil29` (CF twin)
- `aa_0040d630` `StdTree_FreeSubtree_Val12` (peer shape, isnil@+0x19)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report `task-dual-ab-00440d20-mega-132-report.md`
