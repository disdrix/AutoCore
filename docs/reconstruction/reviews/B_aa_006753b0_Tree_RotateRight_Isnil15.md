# Review B (skeptical / adversarial): `aa_006753b0` Tree_RotateRight_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_006753b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-O) |
| **Counterpart** | `reviews/A_aa_006753b0_Tree_RotateRight_Isnil15.md` |
| **Scratch** | `tmp/a_006753b0.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a **left** rotate | **Falsified** — pivot child loaded from `*node` (left), not `node+8` (right); twin `FUN_004e22d0` is L-rotate |
| 2 | isnil/color at staging `+0x49` | **Falsified** — guard is **`+0x15`** (`80 7E 15 00`) |
| 3 | Identical to `Tree_RotateRight` @ `005681a0` | **Near-clone only** — CF match but isnil immediate `15`≠`49`; separate VA for separate family |
| 4 | `__cdecl` / two stack args / bare `ret` | **Falsified** — ECX is map; epilogue **`ret 4`** |
| 5 | Rewrites color / does RB fixup | **Falsified** — no `+0x14` access; pure structure |
| 6 | Allocates / deletes nodes | **Falsified** — leaf pointer rewires only |
| 7 | Args are (node, map) reversed | **Falsified** — ECX loads `map+4`; stack is rotate subject |
| 8 | Non-leaf / has side effects beyond links | **Falsified** — 82-byte body, no calls |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Right vs left rotate | **High** | Tree corruption on insert/erase |
| isnil offset `+0x15` | **High** | Parent write into nil sentinel / wrong family |
| ABI thiscall + ret 4 | **High** | Stack smash on port |
| Root/left/right cases | **High** | Detached subtrees |

---

## 3. Cross-check against raw + bytes

```
y = x->left
x->left = y->right; fix parent if !isnil(+0x15)
y->parent = x->parent
reattach y at x's former parent slot
y->right = x; x->parent = y
ret 4
```

Clean must **not** invent color flips, deletions, left-rotate polarity, or isnil@`+0x49`.

---

## 4. Surviving contract for AutoCore

```c
// Port of Tree_RotateRight_Isnil15 (client map/set leaf)
// thiscall MapShell* map, Node* x; stack-cleanup 4
void Tree_RotateRight_Isnil15(MapShell* map, Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if (!IsNil15(y->right)) y->right->parent = x;  // isnil @ +0x15
  y->parent = x->parent;
  if (x == Root(map)) Root(map) = y;
  else if (x == x->parent->right) x->parent->right = y;
  else x->parent->left = y;
  y->right = x;
  x->parent = y;
}
```

Pair with `Tree_RotateLeft_Isnil15`; do **not** mix with staging isnil@`+0x49` rotates.

---

## 5. Verdict

Adversarial pass **confirms** A: polarity, isnil family, ABI, and three reattach cases sealed → **accept**.
