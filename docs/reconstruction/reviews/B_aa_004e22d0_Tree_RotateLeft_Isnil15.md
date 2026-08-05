# Review B (skeptical / adversarial): `aa_004e22d0` Tree_RotateLeft_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e22d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-O) |
| **Counterpart** | `reviews/A_aa_004e22d0_Tree_RotateLeft_Isnil15.md` |
| **Scratch** | `tmp/a_004e22d0.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a **right** rotate | **Falsified** — pivot child loaded from `node+8` (right), not `*node` (left); twin `FUN_006753b0` is R-rotate |
| 2 | isnil/color at staging `+0x49` | **Falsified** — guard is **`+0x15`** (`80 7E 15 00`) |
| 3 | Same body as `Tree_RotateLeft` @ `00568b70` | **Falsified as identical** — same CF but isnil immediate differs (`15` vs `49`); separate VA |
| 4 | `__cdecl` / two stack args / bare `ret` | **Falsified** — ECX is map; epilogue **`ret 4`** |
| 5 | Rewrites color / does RB fixup | **Falsified** — no `+0x14` access; pure structure |
| 6 | Allocates / deletes nodes | **Falsified** — leaf pointer rewires only |
| 7 | Args are (node, map) reversed | **Falsified** — ECX loads `map+4`; stack is rotate subject |
| 8 | Only used by skill map | **Falsified** — 30 callers across erase/insert helpers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Left vs right rotate | **High** | Tree corruption on insert/erase |
| isnil offset `+0x15` | **High** | Parent write into nil sentinel / wrong family |
| ABI thiscall + ret 4 | **High** | Stack smash on port |
| Root/left/right cases | **High** | Detached subtrees |

---

## 3. Cross-check against raw + bytes

```
y = x->right
x->right = y->left; fix parent if !isnil(+0x15)
y->parent = x->parent
reattach y at x's former parent slot
y->left = x; x->parent = y
ret 4
```

Clean must **not** invent color flips, deletions, right-rotate polarity, or isnil@`+0x49`.

---

## 4. Surviving contract for AutoCore

```c
// Port of Tree_RotateLeft_Isnil15 (client map/set leaf)
// thiscall MapShell* map, Node* x; stack-cleanup 4
void Tree_RotateLeft_Isnil15(MapShell* map, Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if (!IsNil15(y->left)) y->left->parent = x;  // isnil @ +0x15
  y->parent = x->parent;
  if (x == Root(map)) Root(map) = y;
  else if (x == x->parent->left) x->parent->left = y;
  else x->parent->right = y;
  y->left = x;
  x->parent = y;
}
```

Do **not** reuse staging `Tree_RotateLeft` (isnil@`+0x49`) for isnil15 maps.

---

## 5. Verdict

Adversarial pass **confirms** A: polarity, isnil family, ABI, three reattach cases sealed → **accept**.
