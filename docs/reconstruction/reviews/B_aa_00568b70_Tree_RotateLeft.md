# Review B (skeptical / adversarial): `aa_00568b70` Tree_RotateLeft

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568b70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-K) |
| **Counterpart** | `reviews/A_aa_00568b70_Tree_RotateLeft.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a **right** rotate | **Falsified** — pivot child loaded from `node+8` (right), not `*node` (left); twin `FUN_005681a0` is R-rotate |
| 2 | `__cdecl` / two stack args / bare `ret` | **Falsified** — ECX is map; epilogue **`ret 4`** |
| 3 | isnil/color at standard MSVC `+0xD` | **Falsified** — guard is **`+0x49`** (large staging node) |
| 4 | Rewrites color / does RB fixup | **Falsified** — no `+0x48` access; pure structure |
| 5 | Allocates / deletes nodes | **Falsified** — leaf pointer rewires only |
| 6 | Args are (node, map) reversed | **Falsified** — ECX loads `map+4`; stack is rotate subject |
| 7 | Non-leaf / has side effects beyond links | **Falsified** — 78-byte body, no calls |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Left vs right rotate | **High** | Tree corruption on insert/erase |
| isnil offset `+0x49` | **High** | Parent write into nil sentinel |
| ABI thiscall + ret 4 | **High** | Stack smash on port |
| Root/left/right cases | **High** | Detached subtrees |

---

## 3. Cross-check against raw + bytes

```
y = x->right
x->right = y->left; fix parent if !isnil
y->parent = x->parent
reattach y at x's former parent slot
y->left = x; x->parent = y
ret 4
```

Clean must **not** invent color flips, deletions, or right-rotate polarity.

---

## 4. Surviving contract for AutoCore

```c
// Port of Tree_RotateLeft (client map/set leaf)
// thiscall MapShell* map, Node* x; stack-cleanup 4
void Tree_RotateLeft(MapShell* map, Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if (!IsNil(y->left)) y->left->parent = x;  // isnil @ +0x49
  y->parent = x->parent;
  if (x == Root(map)) Root(map) = y;
  else if (x == x->parent->left) x->parent->left = y;
  else x->parent->right = y;
  y->left = x;
  x->parent = y;
}
```

---

## 5. Open questions

1. Product symbol name (none in body).
2. Whether all four static callers share identical node size (isnil offset sealed regardless).

**Verdict:** **accept**
