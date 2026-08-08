# Annotated low-level: FUN_005ae6d0 → StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005ae6d0` |
| VA | `0x005ae6d0` |
| Body | `0x005ae6d0`–`0x005ae986` exclusive (**694 B** / `0x2B6`) |
| Canonical name | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| Ghidra symbol | `FUN_005ae6d0` |
| System | MSVC std `_Tree` erase + RB rebalance (isnil@+0x21) |
| Date | 2026-08-05 (R12-035 OWN dual; scaffold 2026-07-23) |

## Machine-level notes

- **ABI:** `__thiscall`; ECX = map shell; stack `Node** outIt`, `Node* node`; **`ret 8`**.
- **Layout:** left@+0, parent@+4, right@+8, value@+0xC (16 B / Val16), color@**+0x20**, isnil@**+0x21**; node alloc **0x28**; map+4=head, map+8=size; head+0=leftmost, head+4=root, head+8=rightmost.
- **Nil throw:** `cmp byte [node+0x21],0` → `"invalid map/set<T> iterator"` @ `0x00a152f0` → `_CxxThrowException(..., DAT_00acc34c)`.
- **Successor:** `FUN_004e12c0` (isnil21 iterator++) before unlink.
- **Unlink:** splice replacement child; fix parent link; update head leftmost (`FUN_004cb2c0` min) / rightmost (`FUN_00421a60` max) / root.
- **Two-child path:** bytes at `0x005ae7f0`–`0x005ae835` (decomp marks unreachable) — successor-swap / transplant; present in retail.
- **RB fixup:** if erased color black (`[node+0x20]==1`): while not root and sibling black-children recolor; Lrotate `FUN_0050e9f0` / Rrotate `FUN_005a27f0` (parent dual).
- **Epilogue (decomp misses):** `operator_delete(node)` → if size>0 then size-- → `*outIt = succ` → SEH teardown → `add esp,0x54; ret 8`.
- **Sole caller:** range erase `FUN_005af2e0` @ `0x005af37f` (`MOV ECX,EDI` seals thiscall).

## Pseudocode (annotated)

```c
// thiscall: ECX = MapShell_Isnil21* map
// stack:    Node** outIt, Node* node
// ret 8
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21 *map, Node **outIt, Node *node)
{
  // SEH: LAB_009a65a2
  if (node->isnil) { // +0x21
    // throw "invalid map/set<T> iterator" via DAT_00acc34c
  }

  FUN_004e12c0(/* successor into shadow / outIt path */); // isnil21 ++

  // --- unlink (1-child / 0-child primary path in decomp) ---
  // repl = left if present else right; if both children, two-child splice
  //   (bytes @ 005ae7f0+; decomp "unreachable")
  // parent rehang; if root → head->parent = repl
  // if node was leftmost → head->left = min(repl) via FUN_004cb2c0
  // if node was rightmost → head->right = max(repl) via FUN_00421a60

  // --- RB rebalance if erased was black (color@+0x20 == 1) ---
  // while repl != root && repl color black:
  //   if left-of-parent: sibling = parent->right
  //     if sibling red: recolor; Lrotate(parent) via FUN_0050e9f0
  //     if both sibling children black: recolor sibling red; climb
  //     else: if right-child black: recolor; Rrotate(sibling) via FUN_005a27f0
  //           recolor; Lrotate(parent)
  //   else: mirror with Rrotate / Lrotate swapped
  // paint repl black

  operator_delete(node);
  if (map->size > 0) map->size--;
  *outIt = /* successor */;
  // ret 8
}
```

## Callee map

| Symbol | Role | Dual status |
|---|---|---|
| `FUN_004e12c0` | successor / ++ isnil21 | residual |
| `FUN_004cb2c0` | min / leftmost isnil21 | residual |
| `FUN_00421a60` | max / rightmost isnil21 | residual |
| `FUN_0050e9f0` | Lrotate isnil21 | R10-030 dualed |
| `FUN_005a27f0` | Rrotate isnil21 | R11-007 dualed (parent) |
| `operator_delete` | free node | CRT |
| throw plate | string + `_CxxThrowException` | shared STL |

## Callers

| Caller | Site | Note |
|---|---|---|
| `FUN_005af2e0` | `0x005af37f` | range erase loop; `MOV ECX,EDI` |

## Confidence

| Claim | Level |
|---|---|
| CF throw / unlink / rebalance | **High** (live ≡ raw) |
| ABI thiscall + ret 8 + size-- | **High** (bytes) |
| isnil@+0x21 / color@+0x20 | **High** (bytes + rotate peers) |
| Two-child splice plate | **Probable** (bytes present; decomp gap) |
| Product map English | **Inferred** / open |
| Runtime / differential | Open |
