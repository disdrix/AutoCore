# Function record: StdTree_EraseRange_Val12_InventoryGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573700` |
| **Canonical name** | `StdTree_EraseRange_Val12_InventoryGrid_Inferred` |
| **Ghidra name** | `FUN_00573700` |
| **Address** | `0x00573700` |
| **Body range** | `0x00573700`–`0x005737b3` inclusive (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / MSVC `_Tree` range erase Val12 (InventoryGrid maps) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (MEGA-120) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md`, `reviews/B_aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md` (2026-08-05 MEGA-120) |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_00573700`
- `StdTree_RangeErase_Val12` (provisional name used in AutoMerge clean notes)
- Partition hint: `InventoryGrid_DestroyItemList` (full-clear product alias only — **not** sole purpose)

## Purpose

Erase a half-open iterator range on a Val12 red-black tree used by InventoryGrid:

1. **Full range** `[begin, end)`: free entire tree via `FUN_005731c0(root)`, reinit head self-links, `size=0`, publish begin.
2. **Partial range**: for each node, compute Val12 successor (isnil@`+0x19`), call dualed `StdTree_Erase_Val12`, advance.

## Signature

```c
void __thiscall StdTree_EraseRange_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    StdTreeNode_Val12** outIt,     // *outIt = first remaining / begin after clear
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last);
// RET 0x0C
```

### InventoryGrid embedding

| Offset | Field |
|---|---|
| grid `+0x5c` | map shell base (ECX for this unit) |
| grid `+0x60` | head sentinel pointer |
| grid `+0x64` | size |

## Algorithm

```text
if (first == head->left && last == head):
  FreeSubtree(head->parent)
  head links = head; size = 0; *out = head->left; RET 0xC
while first != last:
  next = successor_Val12(first)
  StdTree_Erase_Val12(map, first)
  first = next
*out = first; RET 0xC
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573700_FUN_00573700.md`
- Annotated: `docs/reconstruction/raw/aa_00573700_FUN_00573700.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Val12_InventoryGrid_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00573700.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00573700-mega-120-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005731c0` (free-subtree Val12), `StdTree_Erase_Val12` `0x00573250` (dualed W27-S) |
| **Callers** | InventoryGrid complete dtor `0x005725a0`; AutoMergePartialStacks `0x00572ab0`; map-shell dtor `0x005738d0` |

## Related

- Peer range erase (clone CF): `aa_0040d700` `StdTree_EraseRange_Val12` (free/erase leaves differ)
- Peer: `aa_004e5120` `StdMap_EraseRange_Val12`
- Single erase: `aa_00573250` `StdTree_Erase_Val12`
- L/R rotates: `aa_00573170` / `aa_00418c10`
- Grid ctor / dtor: `aa_00572650` ctor; `aa_00573910` scalar-deleting dtor; complete dtor `005725a0`

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x0C` + thiscall ECX=map | **High** |
| Val12 isnil@+0x19 | **High** |
| InventoryGrid shell @+0x5c | **High** |
| Peer 180 B clone of `0040d700` | **High** (hex) |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |
