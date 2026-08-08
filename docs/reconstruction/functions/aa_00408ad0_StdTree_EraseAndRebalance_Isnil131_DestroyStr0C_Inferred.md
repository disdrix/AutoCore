# Function record: StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408ad0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00408ad0` |
| **Address** | `0x00408ad0`–`0x00408e1d` inclusive (**846 B** / `0x34E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance |
| **Completion status** | **Dual-sealed 2026-08-05 WQ9L-A** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |
| **Verdict** | **accept-with-gaps** |

## Purpose

Erase one large red-black node (**isnil@+0x131**, string value @**+0x0c**), rebalance if black, destroy string, free node, decrement size, return successor iterator.

## Signature

```c
// map*, outIt**, node*; RET 0x0C
void StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred(
    MapShell_Isnil131 *map,
    MapNode_Isnil131 **outIt,
    MapNode_Isnil131 *node);
```

## Naming gate

| Evidence | Present? |
|---|---|
| `"invalid map/set<T> iterator"` throw | **Yes** |
| isnil@+0x131 / color@+0x130 | **Yes** |
| `~basic_string` @ node+0x0c | **Yes** |
| Sole caller erase-range isnil131 | **Yes** |
| Product/PDB English map type | **No** → **`_Inferred`** |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred`**. Aligns with free-subtree / erase-range family naming (`DestroyStr0C`). Reject merge with isnil31 (no string dtor) or isnil2d StringKey helpers.

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | successor (OWN peer) |
| `0x00407b70` | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | range parent |
| `0x00409920` | `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` | full-clear free |
| `0x00409b80` | `StdTree_DestroyStringAt0C_Inferred` | free-subtree string destroy |

## Artifacts

See `aa_00408ad0_FUN_00408ad0.md` for full path table.
