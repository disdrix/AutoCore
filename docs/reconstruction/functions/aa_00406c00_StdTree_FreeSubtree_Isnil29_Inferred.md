# Function record: StdTree_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406c00` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil29_Inferred` |
| **Ghidra name** | `FUN_00406c00` |
| **Address** | `0x00406c00`–`0x00406c34` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL tree free-subtree; insert/erase neighborhood) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md`, `B_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-G OWN-ONLY) |

## Alias

- `FUN_00406c00`
- `Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00406c00` (scaffold; reject)

## Purpose

MSVC map/tree free-subtree for isnil@+0x29 nodes: recursive free right, delete node, walk left. No value destroy. CF twin of `Map_FreeSubtree_Isnil29` (`0x0051bbc0`) at a distinct VA (this neighborhood / callers).

## Signature (sealed)

```c
void __fastcall StdTree_FreeSubtree_Isnil29_Inferred(void* tree_base, void* node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x29`: return.
2. Loop: free right subtree; `left = node->left`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_00406c40` `StdTree_InsertAndRebalance_Isnil29_Inferred` (neighborhood insert; WQ9E-G)
- `aa_00409220` `Map_EraseNode_B` (partial erase in range parent `00407d70`)
- `aa_0051bbc0` `Map_FreeSubtree_Isnil29` (CF twin, distinct VA)
- `aa_0040d630` `StdTree_FreeSubtree_Val12` (peer shape, isnil@+0x19)
- Range parent `FUN_00407d70` (undualed residual)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report `task-dual-ab-004cba00-00406c00-wq9gg-report.md`
