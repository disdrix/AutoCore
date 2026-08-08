# Function record: StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409970` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00409970` |
| **Address** | `0x00409970`–`0x004099aa` inclusive (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL tree free-subtree; string-value erase neighborhood) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md`, `B_aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md` |
| **Last reviewed** | `2026-08-05` (WQ9J-I OWN-ONLY) |

## Alias

- `FUN_00409970`

## Purpose

MSVC map/tree free-subtree for isnil@+0x2d nodes: recursive free right, destroy string @+0x0c, delete node, walk left. Used by `FUN_00407f90` full-range clear.

## Signature (sealed)

```c
void __fastcall StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(void* tree_base, void* node);
// RET 4
```

## Algorithm

1. If `node->isnil@+0x2d`: return.
2. Loop: free right; left-load; `FUN_00409b80`; `operator_delete`; advance left; until isnil.

## Related

- `aa_00409920` isnil131 destroy twin (WQ9J-I OWN pair)
- `aa_00409b80` shared string dtor
- `aa_00406c00` / `aa_0051bbc0` no-destroy isnil29 frees
- Erase parent `FUN_00407f90` (residual)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409970_FUN_00409970.md`
- Annotated: `docs/reconstruction/raw/aa_00409970_FUN_00409970.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409970.cpp`
- FUN record: `docs/reconstruction/functions/aa_00409970_FUN_00409970.md`
- Agent report: `docs/agents/task-dual-ab-00409920-00409970-wq9ji-report.md`
