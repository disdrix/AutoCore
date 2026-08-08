# Review B (skeptical / adversarial): `aa_00603c90` StdTree_InsertAndRebalance_Val28_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00603c90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md` |
| **Agent** | WQ9E-F OWN-ONLY dual |
| **Verdict** | **accept** on CF/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is erase | **Falsified** — `"map/set<T> too long"`, buynode, size++, no delete |
| 2 | Val12 max `0x15555553` / isnil@+0x19 | **Falsified** — max **`0x9249247`**, isnil@**+0x29**, node **0x2C** |
| 3 | Unique-insert with equal reject | **Falsified in-unit** — always links; uniqueness owned by caller walk |
| 4 | addLeft polarity inverted | **Falsified** — `param_3==0` → `where->right`; nonzero → `where->left` |
| 5 | Skill-only | **Falsified** — shared STL insert; sole caller lower-bound insert wrapper |
| 6 | ret 4 / void stack | **Falsified** — `C2 10 00` = **ret 0x10** |
| 7 | Runtime Confirmed | **Rejected** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert + RB fixup CF | **Confirmed** | Tree order / balance break |
| Max-size constant | **Confirmed** | Wrong throw / silent OOM path |
| addLeft / empty-tree link | **Confirmed** | leftmost/rightmost corruption |
| Product C++ name | **Inferred** | Rename only |
| Multimap vs unique map English | Open | Caller `FUN_00603f00` always sets inserted=1 |

---

## 3. Cross-check

```
00603c90: insert isnil29 Val28
00603830: erase twin (this dual)
004192a0 / 004192f0: rotates (callers include this VA)
00603b10: buynode new(0x2C)
00603f00: sole caller — int key lower-bound walk then insert
Map_TreeInsertAndRebalance_Val12*: same CF family, different node size / isnil
```

**Attack on “max size is node-count formula 0xFFFFFFFF/0x2C”:** bytes compare to **0x9249247** ≈ `0xFFFFFFFF / 0x1C` (value size), not `/ 0x2C`.

**Attack on “inline rotate ≠ Lrotate”:** pointer surgery matches Lrotate about grandparent; clean may call `FUN_004192a0` equivalently.

---

## 4. Surviving contract for AutoCore

```
// Node 0x2C: links + Val28 + color@0x28 isnil@0x29
// size > 0x9249247 → throw length_error "map/set<T> too long"

void StdTree_InsertAndRebalance_Val28_Isnil29(
    Map* m, Node** out, char addLeft, Node* where, Val28* val) {
  Node* n = buynode(head, where, head, val, /*red*/0);
  ++m->size;
  // link empty / left / right; update leftmost/rightmost
  // while parent red: uncle recolor or rotate
  root->color = black;
  *out = n;
}
```

Port notes:
- Do not merge with Val12 / isnil15 insert clones.  
- Parent must supply correct `where` + `addLeft` from key walk.  
- Pair with erase twin `StdTree_EraseAndRebalance_Val28_Isnil29_Inferred`.

---

**Verdict:** **accept**
