# Function record: StdTree_EraseAndRebalance_Val28_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00603830` |
| **Canonical name** | `StdTree_EraseAndRebalance_Val28_Isnil29_Inferred` |
| **Ghidra name** | `FUN_00603830` |
| **Address** | `0x00603830` |
| **Body range** | `0x00603830`–`0x00603b03` exclusive (**723** B / `0x2D3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map erase+rebalance (Val28 / isnil@+0x29) |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + throw + epilogue size-- sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md`, `reviews/B_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md` (2026-08-04 WQ9E-F) |
| **Last reviewed** | `2026-08-04` |
| **Terminal** | **false** |

## Alias

- `FUN_00603830`
- Scaffold: `aa_00603830_FUN_00603830`

## Purpose

MSVC-style `_Tree::erase(const_iterator)` for Val28 / isnil@+0x29 nodes: nil throw, successor capture, unlink, RB rebalance if erased black, free mapped heap @+0x14 + node, size--, write out iterator.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Val28_Isnil29_Inferred(
    MapShell* map,     // ECX; +0x04 head, +0x08 size
    Node** outIt,      // *outIt = successor
    Node* node);       // node to erase
// RET 8
```

## Algorithm

1. If `node->isnil` → throw `"invalid map/set<T> iterator"` (`DAT_00acc34c`).
2. `FUN_004cb270(outIt)` — successor for return iterator.
3. Splice replacement; fix root / leftmost (`FUN_0051b5d0` Min) / rightmost (`FUN_00421b50` Max).
4. If erased black → RB fixup with `FUN_004192a0` Lrotate / `FUN_004192f0` Rrotate.
5. Free mapped heap @+0x14 if non-null; zero +0x14..+0x1C; `operator_delete(node)`.
6. If size>0 then `--size`; `*outIt` already successor; `ret 8`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00603830_FUN_00603830.md`
- Annotated: `docs/reconstruction/raw/aa_00603830_FUN_00603830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00603830.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00603830-00603c90-wq9ef-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004cb270`, `FUN_0051b5d0` Min, `FUN_00421b50` Max, `FUN_004192a0` Lrotate, `FUN_004192f0` Rrotate, `operator_delete`, STL throw chain |
| **Callers** | `FUN_00604280` only (1 xref @ `0x0060431f`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall + size-- | **High** (bytes) |
| isnil@+0x29 / color@+0x28 / Val28 | **High** |
| Throw string + ThrowInfo | **High** |
| Sole caller | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Insert twin: `aa_00603c90` StdTree_InsertAndRebalance_Val28_Isnil29_Inferred (WQ9E-F)
- Rotates: `aa_004192a0` StdTree_Lrotate_Isnil29, `aa_004192f0` StdTree_Rrotate_Isnil29_Inferred
- Min/Max: `aa_0051b5d0` StdTree_Min_Isnil29, `aa_00421b50` StdTree_Max_Isnil29_Inferred
- Peer Val12 erase: `aa_004e4130` StdTree_EraseAndRebalance_Val12
