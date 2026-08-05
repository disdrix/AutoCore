# Review A (reconstruction fidelity): `aa_004cb270` StdTree_IteratorIncrement_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb270` |
| **VA** | `0x004cb270` |
| **Canonical name** | `StdTree_IteratorIncrement_Inferred` |
| **Ghidra name** | `FUN_004cb270` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004cb270_StdTree_IteratorIncrement_Inferred.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree_iterator::operator++`) |
| **Verdict** | **accept** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**In-place increment** of a tree/map iterator (pointer to node*):

```text
// ECX = iterator*  (holds node*)
node = *it
if (node->isnil(+0x29) == 0):          // real node
  right = node->right(+8)
  if (right->isnil == 0):
    // successor = leftmost of right subtree
    walk left(+0) while child not nil
    *it = that
    return
  // else climb parents(+4) while was right-child
  parent = node->parent
  while (!parent->isnil && *it == parent->right)
    *it = parent; parent = parent->parent
  *it = parent
// if already nil: no-op
```

Classic red-black / MSVC tree successor. Node layout: `+0` left, `+4` parent, `+8` right, `+0x29` nil flag.

---

## 2. ABI

| Slot | Role |
|------|------|
| **ECX** | `node**` / iterator object |
| return | void (`*it` updated) |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004cb270` |
| Raw/clean | `aa_004cb270_*` |
| Callers | OnDeath TFID list walk (`004daa6d`), `0051cbcb`, `004cb7cb`, `0058dcbb`, `006038bb`, `0092f3d7`, `00807bfd`, … |

OnDeath pattern:
```
piVar11 = *head; while (piVar11 != head) { ...; FUN_004cb270(); reload head }
```
Note: some call sites use list-shaped rings with same nil-byte layout as tree nodes (shared MSVC node header family) — body is tree successor algorithm.

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Tree successor CF | **High** |
| Offsets left/parent/right/nil | **High** |
| In-place `*it` update | **High** |
| Nil at `+0x29` | **High** |
| Product English name | **Probable** |

---

## 5. Gaps

1. Color bit location unused here (not needed for ++).
2. Whether all callers are map vs list-with-nil-header (algorithm still successor).

**Verdict:** **accept**.
