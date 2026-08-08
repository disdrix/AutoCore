# Review B (skeptical / adversarial): `aa_004192f0` StdTree_Rrotate_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004192f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md` |
| **Agent** | WQ9D-D OWN-ONLY dual |
| **Verdict** | **accept** on CF/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is left-rotate | **Falsified** — y = `*x` (left); reattach `y->right = x` |
| 2 | isnil is Val12 @+0x19 | **Falsified** — bytes `80 7E 29 00` (offset **0x29**) |
| 3 | Skill-only / cast residual | **Falsified** — 10 map/tree rebalance callers; shared STL helper |
| 4 | Has callees / non-leaf | **Falsified** — analyze_function_complete callees empty |
| 5 | Returns meaningful EAX | **Rejected as required** — void rotate; RET 4 only |
| 6 | Scaffold human name via aggro GetTarget is product | **Falsified as product** — naming artifact from early xref walk; role is tree rotate |
| 7 | Same clone as Val12 rotate can be reused without offset change | **Falsified** — isnil offset differs; wrong offset corrupts parent links |
| 8 | Runtime Confirmed | **Rejected** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Rrotate CF | **Confirmed** | Map rebalance corruption |
| isnil@+0x29 | **Confirmed** | Nil parent writes into value payload |
| Twin pairing with `004192a0` Lrotate | **High** | Mirror CF sealed by decompile of twin |
| Product C++ name | **Inferred** | Rename only |
| Value type English | Open | Does not affect rotate port |

---

## 3. Cross-check

```
004192f0:  y=x->left;  x->left=y->right;  reattach; y->right=x   // Rrotate isnil29
004192a0:  y=x->right; x->right=y->left; reattach; y->left=x    // Lrotate isnil29
00418c10:  same Rrotate CF as 004192f0 but isnil@+0x19 (Val12)
0051cb40 / 00406c40 / 00409220: erase/rebalance call both rotates
```

**Attack on “decompiler void is wrong”:** rotate has no value return; epilogue is pure `ret 4`. No EAX seal required.

**Attack on “+0x29 is color not isnil”:** convention across Isnil29 family (iterator, lower_bound, erase) treats +0x29 as isnil; test is `== 0` before parent write — classic MSVC `_Isnil` gate.

---

## 4. Surviving contract for AutoCore

```
// Node: left@0 parent@4 right@8 isnil@0x29
// Tree: this+4 header; root = header->parent (header+4)

void StdTree_Rrotate_Isnil29(Tree* t, Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if (!y->right->isnil) y->right->parent = x;
  y->parent = x->parent;
  if (x == root(t)) root(t) = y;
  else if (x == x->parent->right) x->parent->right = y;
  else x->parent->left = y;
  y->right = x;
  x->parent = y;
}
```

Port notes:
- Keep **separate** from Val12 rotate (`isnil@+0x19`).
- Pair with Lrotate `FUN_004192a0` in rebalance paths.
- Not a skill-cast manager — depth residual only via shared map erase/insert.

---

## 5. Gaps

1. Product demangle / per-map value type.  
2. Runtime / bit-exact / differential.

**Verdict:** **accept**
