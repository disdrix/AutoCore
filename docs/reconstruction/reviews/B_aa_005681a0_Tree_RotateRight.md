# Review B (skeptical / adversarial): `aa_005681a0` Tree_RotateRight

| Field | Value |
|---|---|
| **Stable ID** | `aa_005681a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-B) |
| **Counterpart** | `reviews/A_aa_005681a0_Tree_RotateRight.md` |
| **Scratch** | `tmp/a_005681a0.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a **left** rotate | **Falsified** — pivot child loaded from `*node` (left), not `node+8` (right); twin `FUN_00568b70` is L-rotate |
| 2 | `__cdecl` / two stack args / bare `ret` | **Falsified** — ECX is map; epilogue **`ret 4`** |
| 3 | isnil/color at standard MSVC `+0xD` | **Falsified** — guard is **`+0x49`** (large staging node) |
| 4 | Rewrites color / does RB fixup | **Falsified** — no `+0x48` access; pure structure |
| 5 | Allocates / deletes nodes | **Falsified** — leaf pointer rewires only |
| 6 | Args are (node, map) reversed | **Falsified** — ECX loads `map+4`; stack is rotate subject |
| 7 | Non-leaf / has side effects beyond links | **Falsified** — 82-byte body, no calls |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Right vs left rotate | **High** | Tree corruption on insert/erase |
| isnil offset `+0x49` | **High** | Parent write into nil sentinel |
| ABI thiscall + ret 4 | **High** | Stack smash on port |
| Root/left/right cases | **High** | Detached subtrees |

---

## 3. Cross-check against raw + bytes

```
y = x->left
x->left = y->right; fix parent if !isnil
y->parent = x->parent
reattach y at x's former parent slot
y->right = x; x->parent = y
ret 4
```

Clean must **not** invent color flips, deletions, or left-rotate polarity.

---

## 4. Surviving contract for AutoCore

```c
// Port of Tree_RotateRight (client map/set leaf)
// thiscall MapShell* map, Node* x; stack-cleanup 4
void Tree_RotateRight(MapShell* map, Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if (!IsNil(y->right)) y->right->parent = x;  // isnil @ +0x49
  y->parent = x->parent;
  if (x == Root(map)) Root(map) = y;
  else if (x == x->parent->right) x->parent->right = y;
  else x->parent->left = y;
  y->right = x;
  x->parent = y;
}
```

---

## 5. Verdict

Adversarial pass **confirms** A: polarity, isnil, ABI, and three reattach cases sealed → **accept**.
