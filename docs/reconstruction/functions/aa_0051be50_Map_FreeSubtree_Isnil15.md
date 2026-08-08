# Function record: Map_FreeSubtree_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be50` |
| **Canonical name** | `Map_FreeSubtree_Isnil15` |
| **Ghidra name** | `FUN_0051be50` |
| **Address** | `0x0051be50`–`0x0051be85` exclusive (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 skill residual; isnil@+0x15) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051be50_Map_FreeSubtree_Isnil15.md`, `B_aa_0051be50_Map_FreeSubtree_Isnil15.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-F OWN-ONLY) |

## Alias

- `FUN_0051be50`
- Scaffold chain-of-caller names: **reject** as canonical

## Purpose

MSVC map free-subtree for **isnil@+0x15** nodes: recursive free right, delete node, walk left. No value destroy. Called by `Map_EraseRange_Isnil15` full-clear (`head->parent` = root). Distinct VA from twin-CF `StdMap_FreeSubtree_Isnil15_Inferred` (`0x004ba770`).

## Signature (sealed)

```c
void Map_FreeSubtree_Isnil15(void *node);
// stack node*; RET 4; ECX threaded unused
```

## Algorithm

1. If `node->isnil@+0x15`: return.
2. Loop: free right subtree @+8; `left = node->left@+0`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_0051d7c0` `Map_EraseRange_Isnil15` (sole external caller)
- `aa_004ba770` `StdMap_FreeSubtree_Isnil15_Inferred` (twin CF; different callers)
- `aa_0051bbc0` `Map_FreeSubtree_Isnil29`
- `aa_0051be90` `Map_FreeSubtree_B`
- `aa_0051be10` free-subtree isnil@+0x1d (peer shape; not OWN)

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0051be50_FUN_0051be50.md`
- Annotated: `docs/reconstruction/raw/aa_0051be50_FUN_0051be50.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil15.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051be50.cpp`
- Review A/B: `docs/reconstruction/reviews/A|B_aa_0051be50_Map_FreeSubtree_Isnil15.md`
- Scaffold alias: `docs/reconstruction/functions/aa_0051be50_FUN_0051be50.md`
