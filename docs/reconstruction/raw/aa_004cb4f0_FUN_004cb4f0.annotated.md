# Annotated low-level: StdTree_Predecessor_Isnil29_Inferred (FUN_004cb4f0)

| Field | Value |
|---|---|
| Stable ID | `aa_004cb4f0` |
| VA | `0x004cb4f0` |
| System | std red-black tree / map iterator (isnil @ +0x29) |
| Date | 2026-08-04 (WQ9G-B dual seal) |
| Ghidra | `FUN_004cb4f0` |
| Named | `StdTree_Predecessor_Isnil29_Inferred` |

## Machine-level notes

- **Role:** MSVC-style `_Tree::_Dec` / unchecked iterator **predecessor** for the **isnil@+0x29** node family (same header as dualed `StdTree_InsertAndRebalance_Isnil29` / insert-or-find / insert-hint).
- **ABI:** **ECX = Node****; bare **`C3`**; mutates `*it` only. Leaf (no callees).
- **Layout:** left@+0, parent@+4, right@+8, isnil@**+0x29**. Color/value payload not touched.
- **Not** successor (`FUN_004cb270`), insert, or rebalance.
- Scaffold `Named_CalleeOf_…_VOGClient_004cb4f0` is a generic callee-of alias — **reject** as product English.

## Control flow (three arms)

1. `cur = *it`. If `cur->isnil`: `*it = cur->right` (header/end path) and return.
2. Else if `cur->left` not isnil: set `*it` to **rightmost** of left subtree (walk right while right not isnil).
3. Else climb parents while `cur == parent->left`; if final parent not isnil, `*it = parent`.

## Pseudocode (annotated)

```c
// ECX = Node**; bare RET; isnil @ +0x29
void __fastcall StdTree_Predecessor_Isnil29_Inferred(Node** it /*ECX*/)
{
  Node* cur = *it;
  if (cur->isnil != 0) {
    *it = cur->right;
    return;
  }
  Node* left = cur->left;
  if (left->isnil == 0) {
    Node* p = left;
    while (p->right->isnil == 0) {
      p = p->right;
    }
    *it = p;
    return;
  }
  Node* parent = cur->parent;
  if (parent->isnil == 0) {
    do {
      if (*it != parent->left) break;
      *it = parent;
      parent = parent->parent;
    } while (parent->isnil == 0);
    if (parent->isnil == 0) {
      *it = parent;
    }
  }
}
```

## Callers (static)

| Caller | Role |
|---|---|
| `FUN_004cbe20` `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` | insert-or-find goLeft predecessor |
| `FUN_004cbee0` `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` | same |
| `FUN_004cc220` `StdTree_InsertHint_Isnil29_Inferred` | prev-neighbor for hint |
| `FUN_00406040` | insert-or-find peer (isnil@+0x21 family uses this pred? — residual) |
| `FUN_005a3b00` | insert-or-find peer |

## Open / residual

- Product / MSVC demangle English.
- Whether every caller shares identical value_type (isnil29 family vs mixed).
- Runtime / bit-exact / differential.
