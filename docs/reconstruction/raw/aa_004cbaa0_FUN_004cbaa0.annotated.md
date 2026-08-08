# Annotated low-level: StdTree_EraseRange_Isnil29_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cbaa0` |
| VA | `0x004cbaa0`–`0x004cbb54` exclusive (**180 B**) |
| Ghidra | `FUN_004cbaa0` |
| Canonical | `StdTree_EraseRange_Isnil29_Inferred` |
| Prior alias | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cbaa0` (**narrow**) |
| System | STL map/set range erase (isnil@+0x29; pairs with `StdTree_EraseAndRebalance_Isnil29`) |
| Date | 2026-08-04 (WQ9F-C OWN dual; raw 2026-07-23 re-verified) |

## Machine-level notes

- Live decompile CF ≡ raw; both exits **`C2 0C 00`**.
- Full clear: `first==*head && last==head` → free-subtree `FUN_004cb550(root)` then head reset + size 0.
- Partial: isnil@+0x29 in-order successor, then `StdTree_EraseAndRebalance_Isnil29` with **`mov ecx,edi`** (map shell).
- **Do not merge** with `Map_EraseRange` / `_B` (different free + single-erase callees) despite identical CF shape and 180 B size.

## Pseudocode (annotated)

```c
// __thiscall; ECX = MapShell*; stack outIt*, first, last; RET 0x0C
void StdTree_EraseRange_Isnil29_Inferred(
    MapShell_Isnil29 *map,
    MapNode_Isnil29 **outIt,
    MapNode_Isnil29 *first,
    MapNode_Isnil29 *last)
{
  MapNode_Isnil29 *head = map->head; // +0x04

  // Full clear [begin, end)
  if (first == head->left && last == head) {
    FUN_004cb550(head->parent); // free non-nil subtree (isnil@+0x29)
    head->parent = head;
    map->size = 0;              // +0x08
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return; // ret 0x0c
  }

  while (first != last) {
    MapNode_Isnil29 *succ = first;
    if (first->isnil == 0) {
      // MSVC tree successor (isnil@+0x29)
      succ = first->right;
      if (succ->isnil == 0) {
        MapNode_Isnil29 *l = succ->left;
        while (l->isnil == 0) { succ = l; l = l->left; }
      } else {
        MapNode_Isnil29 *p = first->parent;
        MapNode_Isnil29 *cur = first;
        while (p->isnil == 0 && cur == p->right) {
          cur = p; p = p->parent;
        }
        succ = p;
      }
    }
    // bytes: push node; lea out; push out; mov ecx,map; call 004cb740
    StdTree_EraseAndRebalance_Isnil29_Inferred(map, &first, first);
    first = succ;
  }
  *outIt = first;
  return; // ret 0x0c
}
```

## Gaps

1. Product demangle of map value_type (shared with erase/insert isnil29 family).
2. Full free-subtree algebra of `FUN_004cb550` (decomp may drop left recurse).
3. Runtime / bit-exact / differential.
