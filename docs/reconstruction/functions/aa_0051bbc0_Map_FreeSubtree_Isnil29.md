# Function record: Map_FreeSubtree_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bbc0` |
| **Canonical name** | `Map_FreeSubtree_Isnil29` |
| **Ghidra name** | `FUN_0051bbc0` |
| **Address** | `0x0051bbc0`–`0x0051bbf4` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL map helper residual) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051bbc0_Map_FreeSubtree_Isnil29.md`, `B_aa_0051bbc0_Map_FreeSubtree_Isnil29.md` |
| **Last reviewed** | `2026-08-04` (WQ9E-H OWN-ONLY) |

## Alias

- `FUN_0051bbc0`
- `Named_CalleeOf_Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051bbc0` (scaffold; reject)

## Purpose

MSVC map free-subtree for isnil@+0x29 nodes: recursive free right, delete node, walk left. No value destroy. Called by `Map_EraseRange` full-clear.

## Signature (sealed)

```c
void __fastcall Map_FreeSubtree_Isnil29(void *tree_base, void *node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x29`: return.
2. Loop: free right subtree; `left = node->left`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_0051c7c0` `Map_EraseRange` (sole external caller)
- `aa_0051cb40` `Map_EraseNode` (same isnil family)
- `aa_0058da00` MapFloatTfid free twin CF
- `aa_0040d630` StdTree_FreeSubtree_Val12 (isnil@+0x19 peer shape)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
