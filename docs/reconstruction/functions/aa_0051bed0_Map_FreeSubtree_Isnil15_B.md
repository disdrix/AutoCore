# Function record: Map_FreeSubtree_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bed0` |
| **Canonical name** | `Map_FreeSubtree_Isnil15_B` |
| **Ghidra name** | `FUN_0051bed0` |
| **Address** | `0x0051bed0`–`0x0051bf05` exclusive (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 skill residual; isnil@+0x15) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md`, `B_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-D OWN-ONLY) |

## Alias

- `FUN_0051bed0`
- Scaffold chain-of-caller names: **reject** as canonical

## Purpose

MSVC map free-subtree for **isnil@+0x15** nodes: recursive free right, delete node, walk left. No value destroy. Called by dualed `Map_EraseRange_Isnil15_B` full-clear (`head->parent` = root). Distinct VA from twin-CF dualed `Map_FreeSubtree_Isnil15` (`0x0051be50`).

## Signature (sealed)

```c
void Map_FreeSubtree_Isnil15_B(void *node);
// stack node*; RET 4; ECX threaded unused
```

## Algorithm

1. If `node->isnil@+0x15`: return.
2. Loop: free right subtree @+8; `left = node->left@+0`; `operator_delete(node)`; `node = left`; until isnil.

## Related

- `aa_0051d940` `Map_EraseRange_Isnil15_B` (sole external caller)
- `aa_0051be50` `Map_FreeSubtree_Isnil15` (twin CF; free of `Map_EraseRange_Isnil15`)
- `aa_004ba770` `StdMap_FreeSubtree_Isnil15_Inferred` (third isnil15 free clone; different callers)
- `aa_0051bbc0` `Map_FreeSubtree_Isnil29`
- `aa_0051be90` `Map_FreeSubtree_B`
- `aa_0051e1b0` `Map_Tidy_FreeHead_Isnil15_B` (tidy host of erase-range that uses this free)

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0051bed0_FUN_0051bed0.md`
- Annotated: `docs/reconstruction/raw/aa_0051bed0_FUN_0051bed0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil15_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051bed0.cpp`
- Review A/B: `docs/reconstruction/reviews/A|B_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md`
- Scaffold alias: `docs/reconstruction/functions/aa_0051bed0_FUN_0051bed0.md`
