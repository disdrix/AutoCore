# Annotated low-level: StdTree_InsertAndRebalance_Val12 / FUN_005ae4e0

| Field | Value |
|---|---|
| Stable ID | `aa_005ae4e0` |
| VA | `0x005ae4e0` |
| Body | `0x005ae4e0`–`0x005ae6ca` exclusive (**490** B) |
| Canonical | `StdTree_InsertAndRebalance_Val12` (inferred) |
| System | MSVC std `_Tree` always-insert + RB rebalance (Val12 / node 0x1c) |
| Date | 2026-07-29 W27-T |
| Live tools | `decompile_function` + `read_memory` (**no** `disassemble_bytes`) |

## Machine-level notes

- **ABI:** `__thiscall` ECX = map shell (`head@+4`, `size@+8`); stack `(outIt*, addLeft, where, value*)`; **`ret 0x10`**.
- **Size gate:** if `size > 0x15555553` throw length_error-style `"map/set<T> too long"`.
- **Buynode:** `FUN_005ae220(head, where, head, value, color=0)` — sealed `StdTree_Buynode_Val12` (node 0x1c; value 12 B @ +0x0c; color @ +0x18; isnil @ +0x19).
- **Link:** empty head → root/leftmost/rightmost = n; else left (`addLeft!=0`) or right of `where` (+ extremity updates).
- **RB loop:** while parent color red (0): uncle recolor or rotate (`FUN_00573170` L / `FUN_00418c10` R; one L-rotate case inlined in decomp); exit paints root black; `*outIt = n`.
- **Not** a key walk — parent `FUN_005aed20` owns lower-bound / duplicate gate (int key @ node+0x0c).
- **Peer:** structural twin of `Map_TreeInsertAndRebalance_Val12` (`0x0051c1c0`) — do not merge VAs; different SEH (`LAB_009a65a2` vs `LAB_009a3502`) and sole caller.
- Legacy scaffold name `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae4e0` is **narrow** (xref chain only).

## Layout (Val12)

| Offset | Field |
|---|---|
| node+0x00 | left |
| node+0x04 | parent |
| node+0x08 | right |
| node+0x0c | value[12] (3 dwords; key often dword0) |
| node+0x18 | color (0=red, 1=black) |
| node+0x19 | isnil |
| map+0x04 | head (sentinel) |
| map+0x08 | size |

## Pseudocode (annotated, CF equiv raw / live)

```c
// __thiscall; ret 0x10
void StdTree_InsertAndRebalance_Val12(
    MapShell* map,           // ECX
    Node** outIt,
    char addLeft,            // 1 left of where; 0 right
    Node* where,
    const Val12* value)
{
  if (map->size > 0x15555553u)
    throw_map_set_too_long(); // "map/set<T> too long"

  Node* n = StdTree_Buynode_Val12(map->head, where, map->head, value, /*color*/0);
  map->size += 1;

  if (where == map->head) {
    map->head->parent = map->head->left = map->head->right = n;
  } else if (addLeft == 0) {
    where->right = n;
    if (where == map->head->right) map->head->right = n;
  } else {
    where->left = n;
    if (where == map->head->left) map->head->left = n;
  }

  // while parent red: recolor uncle or rotate; then root black
  // *outIt = n; return;
}
```

## Confidence

| Claim | Level |
|---|---|
| CF + bytes + ret 0x10 | **High** |
| Val12 layout / buynode | **High** |
| Always-insert (no key cmp) | **High** |
| Sole caller FUN_005aed20 | **High** |
| Product demangle | **Inferred** / open |
| Runtime / differential | Open |
