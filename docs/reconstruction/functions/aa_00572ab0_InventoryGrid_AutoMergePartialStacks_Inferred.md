# Function record: InventoryGrid_AutoMergePartialStacks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572ab0` |
| **Canonical name** | `InventoryGrid_AutoMergePartialStacks_Inferred` |
| **Ghidra name** | `FUN_00572ab0` |
| **Address** | `0x00572ab0` |
| **Body range (true)** | `0x00572ab0`–`0x00572ec7` exclusive (**1047** B / `0x417`); pad `CC` |
| **Ghidra plate range** | `0x00572ab0`–`0x00572e7f` (**false** end — `operator_delete` noreturn) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / InventoryGrid |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/max formula/merge key/epilogue sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md`, `reviews/B_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` (2026-07-29 W29-E) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00572ab0`
- Role: full-grid **auto-merge of underfilled stackables** by stack-group key (`clonebase+0x34`)
- Distinct from `InventoryGrid_MergeStackQty` (`0x00571830`, COID + delta) and `Item_CanAcceptStackQty` (predicate leaf)

## Purpose

Walk all items on an inventory grid under traversal lock. For each stack-eligible item below max stack, attempt to merge into a previously seen underfilled peer of the same stack group. Fully consumed items are removed from the grid and queue-deleted. Returns whether any quantity change occurred.

## Signature

```c
// __thiscall; bare RET; bool in AL
uint8_t InventoryGrid_AutoMergePartialStacks_Inferred(InventoryGrid* this);
```

## Algorithm (summary)

1. Build empty consume list + empty Val12 partial map.
2. `List_TraversalLock(this+0x2c)`; iterate via `List_IterateNext`.
3. Skip non-eligible / already-full stacks (max formula inlined ≡ `Item_CanAcceptStackQty`).
4. Scan partial map for peer with same `clonebase+0x34`:
   - residual room &lt; qty → transfer residual, erase peer, re-insert current
   - else full absorb → add qty to peer, zero current, enqueue consume
5. No peer → insert current into partial map (key = item ptr as uint).
6. End: leave CS; `RemoveItem(…,1000000,1)` + `Object_QueueDelete` for consume list; destroy map/list; return dirty.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00572ab0_FUN_00572ab0.md`
- Annotated: `docs/reconstruction/raw/aa_00572ab0_FUN_00572ab0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_AutoMergePartialStacks_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00572ab0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ae050-00572ab0-w29e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | see annotated call graph (Val12 helpers, RemoveItem, QueueDelete, list walk, dirty) |
| **Callers (1)** | `FUN_008c2f50` @ `0x008c2f72` — may send sector `0x204a` if AL≠0 |

## Confidence

| Claim | Level |
|---|---|
| Control flow merge / absorb | **High** |
| Max-stack formula (0x423F / 200 / +0x4BA) | **High** |
| Match key clonebase+0x34 | **High** |
| True epilogue AL=dirty beyond Ghidra plate | **High** (bytes) |
| ABI thiscall bare RET | **High** |
| Product English name | **Inferred** |
| Packet 0x204a product meaning | **Open** (caller-owned) |
| Runtime / differential | Open |

## Related

- `aa_0040abf0` Item_CanAcceptStackQty
- `aa_00513e70` Item_IsStackEligible
- `aa_00571830` InventoryGrid_MergeStackQty (different merge shape)
- `aa_00571b80` InventoryGrid_RemoveItem
- `aa_00573810` StdMap_InsertOrFind_Val12_UintKey
- `aa_005ae050` StdTree_Dec_Val12 (used by InsertOrFind, not directly here)
