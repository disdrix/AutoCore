# Annotated low-level: FUN_005aed20 → StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| Stable ID | `aa_005aed20` |
| VA | `0x005aed20`–`0x005aedd8` exclusive (**184 B**) |
| System | std map insert-or-find Val12 int key |
| Date | 2026-07-29 (W30-M seal) |

## Machine-level notes

- **ABI:** `__thiscall` ECX = map shell (`head` @ +4, `size` @ +8); stack `(InsertPair* out, Val12* value)`; **`ret 8`** (`c2 08 00` ×3).
- **Node:** Val12 — left@0 parent@+4 right@+8 key@+0x0C color@+0x18 **isnil@+0x19**.
- **InsertPair:** iterator pointer @ +0; **inserted** byte @ +4 (`mov byte [eax+4], imm`).
- **Callees:** `FUN_005ae4e0` always-insert+rebalance (W27-T); `FUN_005ae050` predecessor Dec (W29-E).
- **Callers:** `FUN_005acf10` @ `005ad0ae` (CrazyTaxi TimeLimit populate during XML dump rebuild); `005ada8b` in orphan parse body ~`005ad2f0` (vtable +0x48).
- **Peer:** `aa_0053a1a0` same algorithm, insert via `00539210` — do not merge.
- Live decompile **≡** raw body (W30-M). **No** `disassemble_bytes`.

## Pseudocode (annotated)

```c
// map insert-or-find by signed int key @ value[0] / node[3]
void __thiscall FUN_005aed20(Map* map, InsertPair* out, int* value /* Val12* */)
{
  Node* head = map->head;          // map+4
  Node* where = head;
  bool addLeft = true;
  if (head->parent->isnil == 0) {  // root exists
    Node* cur = head->parent;
    do {
      where = cur;
      addLeft = (*value < where->key);  // key @ +0x0C
      cur = addLeft ? where->left : where->right;
    } while (cur->isnil == 0);          // isnil @ +0x19
  }
  Node* slot = where;
  if (addLeft) {
    if (where == head->left) {          // begin — leftmost insert
      out->it = *InsertAndRebalance(map, &slot, 1, where, value);
      out->inserted = 1;
      return; // ret 8
    }
    StdTree_Dec_Val12(&where);          // predecessor
  }
  if (where->key < *value) {
    out->it = *InsertAndRebalance(map, &slot, addLeft, where, value);
    out->inserted = 1;
    return; // ret 8
  }
  out->inserted = 0;
  out->it = where;
  return; // ret 8
}
```

## Open questions

- Product/MSVC demangle for map instantiation (TimeLimit is one consumer).
- Runtime / bit-exact / differential.
