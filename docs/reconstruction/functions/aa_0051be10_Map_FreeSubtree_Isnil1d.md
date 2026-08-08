# Function record: Map_FreeSubtree_Isnil1d

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be10` |
| **Canonical name** | `Map_FreeSubtree_Isnil1d` |
| **Ghidra name** | `FUN_0051be10` |
| **Address** | `0x0051be10`–`0x0051be44` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL map helper residual) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051be10_Map_FreeSubtree_Isnil1d.md`, `B_aa_0051be10_Map_FreeSubtree_Isnil1d.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-E OWN-ONLY) |

## Alias

- `FUN_0051be10`

## Purpose

MSVC map free-subtree for isnil@+0x1d nodes: recursive free right, delete node, walk left. No value destroy. Called by `Map_EraseRange_Isnil1d_Inferred` full-clear.

## Signature (sealed)

```c
void __fastcall Map_FreeSubtree_Isnil1d(void *tree_base, void *node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x1d`: return.
2. Loop: free right subtree; `left = node->left`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_0051d700` `Map_EraseRange_Isnil1d_Inferred` (sole external caller)
- `aa_0051bbc0` `Map_FreeSubtree_Isnil29` (peer CF, isnil@+0x29)
- `aa_0051be90` `Map_FreeSubtree_B` (peer CF, isnil@+0x29 / EraseRange_B)
- `aa_0051c880` single-node erase isnil1d (sibling residual WQ9F-F)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
