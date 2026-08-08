# Annotated low-level: FUN_004cbb60 → StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cbb60` |
| VA | `0x004cbb60` |
| Canonical name | `StdTree_InsertAndRebalance_Isnil29_Inferred` |
| System | MSVC `std::_Tree` always-insert + RB rebalance (isnil@+0x29) |
| Date | 2026-08-04 (WQ9E-E); scaffold 2026-07-23 |
| Tools | decompile + read_memory + analyze_function_complete + xrefs (**no** disassemble_bytes) |

---

## Machine-level notes

- **Body:** `0x004cbb60`–`0x004cbd4b` exclusive (**491 B**); **RET 0x10**.
- **ABI:** `__thiscall` ECX=map; stack `Node** outIt`, `char addLeft`, `Node* where`, `Val24* value`.
- **Max size:** `size > 0xAAAAAA8` → `"map/set<T> too long"` / `DAT_00acc388`.
- **Buynode:** `FUN_005a2de0` — `operator_new(0x30)`; left/parent/right; **6 dwords** value @ +0x10; color@+0x28; isnil=0 @+0x29.
- **Link:** empty tree sets root=leftmost=rightmost; else left (`addLeft!=0`) or right (`addLeft==0`) of `where`; update extremities.
- **RB:** while parent red — uncle recolor or rotate; one grand Lrotate path **inlined** (isnil tests @+0x29); calls `FUN_004192a0` / `FUN_004192f0` for the other rotates.
- **Exit:** root color black; `*outIt = newNode`.
- **Reject:** aggro/GetTargetFromAggro scaffold chain as product role — shared container helper.

---

## Control flow (annotated)

```
if (map->size > 0xAAAAAA8) throw "map/set<T> too long";
n = FUN_005a2de0(head, where, head, value, color=0);  // red leaf
map->size++;
if (where == head) {
  head->parent = head->left = head->right = n;         // empty
} else if (addLeft == 0) {
  where->right = n; if (where == head->right) head->right = n;
} else {
  where->left = n;  if (where == head->left)  head->left  = n;
}
x = n;
loop:
  if (x->parent->color != red) { head->parent->color = black; *outIt = n; return; }
  // parent red: uncle cases (left-parent / right-parent symmetric)
  // recolor-uncle climb OR rotate zig-zag then recolor+rotate
  // one Lrotate-about-grand is inlined with isnil@+0x29 child reparent
```

---

## Callers / callees

| Role | Symbol |
|---|---|
| Callers | `FUN_004cbe20` (2), `FUN_004cbee0` (2), `FUN_004cc220` (7) — 11 sites |
| Buynode | `FUN_005a2de0` (`operator_new(0x30)`) |
| L / R rotate | `FUN_004192a0`, `FUN_004192f0` |

---

## Peer do-not-merge

| Peer | VA | Diff |
|---|---|---|
| `StdTree_InsertAndRebalance_Val12` | `0x005ae4e0` | isnil@+0x19; max `0x15555553`; Val12 buynode |
| Erase twin | `0x004cb740` | same isnil29 family, erase path |

---

## Pseudocode source

Authoritative raw body: `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.md`  
Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp`
