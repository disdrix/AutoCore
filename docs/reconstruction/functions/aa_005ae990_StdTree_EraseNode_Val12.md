# Function record: StdTree_EraseNode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae990` |
| **Canonical name** | `StdTree_EraseNode_Val12` (Inferred) |
| **Ghidra name** | `FUN_005ae990` |
| **Address** | `0x005ae990` |
| **Body range** | `0x005ae990`–`0x005aec44` exclusive (**692** B / `0x2B4`); Ghidra lists `005aec16` (false noreturn) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map single-node erase (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + throw + size-- sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ae990_StdTree_EraseNode_Val12.md`, `reviews/B_aa_005ae990_StdTree_EraseNode_Val12.md` (2026-07-29 W27-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005ae990`
- Role: MSVC `_Tree::erase` single iterator for **Val12** nodes (0x1c; isnil@+0x19)

## Purpose

Erase one non-nil Val12 tree node: compute successor, unlink, RB rebalance if black, `operator_delete`, decrement size if >0, write `*outIt = successor`. Throw `"invalid map/set<T> iterator"` on nil.

## Signature

```c
void __thiscall StdTree_EraseNode_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,     // *outIt = successor
    MapNode_Val12* node);      // node to erase
// RET 8
```

## Algorithm

1. If `node->isnil` -> throw `"invalid map/set<T> iterator"`.
2. Successor via `FUN_005ae0b0`.
3. Unlink + fix root/begin/end (`FUN_005adfa0` / `FUN_00418bf0`).
4. If erased black: RB fixup with `FUN_00573170` / `FUN_00418c10`.
5. `operator_delete(node)` (falls through).
6. If `size > 0` then `size--`; `*outIt = successor`; `ret 8`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae990_FUN_005ae990.md`
- Annotated: `docs/reconstruction/raw/aa_005ae990_FUN_005ae990.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseNode_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ae990.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ae4e0-005ae990-w27t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, `FUN_00573170`, `FUN_00418c10`, `operator_delete`, exception path |
| **Callers** | `FUN_005af3a0` only (range erase) |

## Confidence

| Claim | Level |
|---|---|
| Control flow unlink + rebalance | **High** |
| `ret 8` + thiscall ECX=map | **High** (bytes) |
| Val12 isnil@+0x19 / color@+0x18 | **High** |
| size-- after delete | **High** (bytes) |
| Sole caller FUN_005af3a0 | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Sibling insert (this wave): `aa_005ae4e0` `StdTree_InsertAndRebalance_Val12`
- Rotates: `aa_00573170` Lrotate, `aa_00418c10` Rrotate
- Peer erase (other node sizes): `aa_0051cb40` Map_EraseNode; `aa_004baa30` StdMap_EraseIterator_Inferred
