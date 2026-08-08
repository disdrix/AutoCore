# Review A (reconstruction fidelity): `aa_00511b40` StdMap_InsertOrFind_IntKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511b40` |
| **VA** | `0x00511b40`–`0x00511bf8` inclusive (**185 B** / `0xB9`) |
| **Canonical name** | `StdMap_InsertOrFind_IntKey_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00511b40` |
| **Prior scaffold** | `FUN_00511b40` |
| **Review date** | `2026-08-05` (R13-031 OWN dual; dual start **2686**) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md` |
| **System** | skills-abilities partition / shared STL map insert-or-find |
| **Parent dual** | `0x00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (R12-014) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + parent dual evidence. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **`map::insert` unique insert-or-find** for the **Node24 / isnil@+0x21** family:

```text
lower_bound walk (signed key@node+0x0C, isnil@+0x21)
  if goLeft && where == begin: insert(addLeft=1) → {new, true}
  else if goLeft: predecessor(hint)
  if hint->key < value->key: insert(goLeft) → {new, true}
  else: equal → {hint, false}   // no mapped rewrite
```

Insert worker: dualed parent `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` @ `0x00511950`.  
Predecessor: residual `FUN_005adff0`.  
Sole caller: residual `FUN_0050ba90` @ `0x0050bbc4` (int-keyed host map with vector-ish mapped value).

**Not** always-insert (that is parent `00511950`). **Not** isnil29 twin `004cbe20`. **Not** PairKey isnil21 `00407060`. **Not** skill-product logic despite partition tag.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold raw CF (2026-07-23) |
| Full body | `disassemble_function` + `read_memory` 185 B body + CC pad |
| Parent insert | dualed R12-014 `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` |
| Callers | 1 UNCONDITIONAL_CALL `FUN_0050ba90` @ `0050bbc4` |
| Call-site ABI | `MOV ECX,EDI` + two stack pushes before CALL |
| Peer isnil29 | dualed `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` `004cbe20` (same CF plate; different isnil/key offsets) |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Signature (sealed)

```c
// ECX=map; stack (out*, value*); bare RET 8; result via out pair
void __thiscall StdMap_InsertOrFind_IntKey_Isnil21_Inferred(
    void *map /*ECX*/,
    InsertPair *out /*{it, inserted@+4}*/,
    const int *value /*key at [0]*/);
```

| Formal | Source | Conf |
|---|---|---|
| map | **ECX** → `MOV EDI,ECX`; loads `[EDI+4]` head | **High** (static) |
| out | stack+4 → written `*out` / `*(out+4)` | **High** (static) |
| value / key | stack+8 → `MOV EBP,[ESP+0x10]`; `*EBP` vs node+0xC | **High** (static) |
| cleanup | `RET 8` (`C2 08 00`) ×3 | **High** (static) |
| isnil | `CMP byte ptr [reg+0x21],0` | **High** (static) |
| key offset | `CMP EDX,[EAX+0xC]` + `SETL` (signed) | **High** (static) |
| inserted bool | `MOV byte ptr [EAX+4],0/1` | **High** (static) |
| callees | `00511950` ×2, `005adff0` ×1 | **High** (static) |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Prologue / thiscall | `PUSH ECX; … MOV EDI,ECX` | **High** |
| Root from head→parent | `MOV ESI,[EDI+4]; MOV EAX,[ESI+4]` | **High** |
| isnil@+0x21 gate | `CMP byte ptr [EAX+0x21],0` | **High** |
| Signed lower-bound walk | `CMP EDX,[EAX+0xC]; SETL CL; left/right` | **High** |
| Begin insert addLeft=1 | `PUSH 1; CALL 00511950; inserted=1` | **High** |
| Predecessor path | `CALL 005adff0` when goLeft && not begin | **High** |
| Open-side insert | `hint->key < *value` → CALL 00511950 | **High** |
| Equal / find | `inserted=0; *out=hint` | **High** |
| Epilogue RET 8 ×3 | `C2 08 00` | **High** |
| Decompile ≡ raw ≡ live | yes | **High** |

```c
void StdMap_InsertOrFind_IntKey_Isnil21_Inferred(Map *map, InsertPair *out, const int *val) {
  Node *head = map->head, *where = head;
  bool goLeft = true;
  Node *n = head->parent;
  if (!n->isnil) {
    Node *c = n;
    do {
      where = c;
      goLeft = (*val < where->key);
      c = goLeft ? where->left : where->right;
    } while (!c->isnil);
  }
  Node *hint = where;
  if (goLeft) {
    if (where == head->left) {
      out->it = *Insert(map, &hint, 1, where, val);
      out->inserted = 1; return;
    }
    Pred(&hint);
  }
  if (hint->key < *val) {
    out->it = *Insert(map, &hint, goLeft, where, val);
    out->inserted = 1; return;
  }
  out->inserted = 0; out->it = hint;
}
```

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (map insert-or-find shell) |
| External xrefs | **1** UNCONDITIONAL_CALL |
| Named enclosing | `FUN_0050ba90` @ `0x0050bbc4` |
| Site role | insert int-keyed value into host map (loop index key) |
| Callees | dualed insert parent; residual pred |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Insert-or-find CF (equal → inserted=0) | **Yes** |
| Signed int key @ +0x0C / isnil@+0x21 | **Yes** |
| Distinct from always-insert parent `00511950` | **Yes** |
| Distinct from isnil29 / PairKey peers | **Yes** |
| Product element / host English demangle | **No** → `_Inferred` |
| Skill plate string in **this** body | **No** |

**Decision:** promote **`StdMap_InsertOrFind_IntKey_Isnil21_Inferred`**. Scaffold `FUN_00511b40` retained as twin export.

---

## 7. Gaps

- Product English for mapped value_type / host container (`FUN_0050ba90` context).
- Dual of predecessor `FUN_005adff0` and sole caller `FUN_0050ba90`.
- Nested buynode residual under parent (already noted R12-014).
- Runtime / bit-exact / differential.

**Verdict:** Path A accepts CF/ABI/isnil21/signed-int-key/RET8 seal with product residual → **accept-with-gaps**.
