# Function record: StdTree_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb550` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cb550` |
| **Address** | `0x004cb550`–`0x004cb584` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / std map-set (isnil@+0x29 free-subtree for StdTree_EraseRange) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md`, `B_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-A OWN-ONLY) |

## Alias

- `FUN_004cb550`
- `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb550` (scaffold; reject)

## Purpose

MSVC tree free-subtree for isnil@+0x29 nodes: recursive free right, delete node, walk left. No value destroy. Called by `StdTree_EraseRange_Isnil29_Inferred` full-clear.

## Signature (sealed)

```c
void __fastcall StdTree_FreeSubtree_Isnil29_Inferred(void *tree_base, void *node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x29`: return.
2. Loop: free right subtree; `left = node->left`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_004cbaa0` `StdTree_EraseRange_Isnil29_Inferred` (sole external caller)
- `aa_004cb740` `StdTree_EraseAndRebalance_Isnil29_Inferred` (partial-range erase path)
- `aa_0051bbc0` `Map_FreeSubtree_Isnil29` (twin CF; Map_EraseRange free — do not merge)
- `aa_0040d630` `StdTree_FreeSubtree_Val12` (isnil@+0x19 peer shape)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
