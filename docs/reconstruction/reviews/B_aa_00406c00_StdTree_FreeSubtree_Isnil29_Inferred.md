# Review B (skeptical / adversarial): `aa_00406c00` StdTree_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9G-G) |
| **Counterpart** | `reviews/A_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn; real body is left-walk loop (53 B) |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded; **`RET 4`** |
| 3 | This destroys `T*` values | **Falsified** — no payload load / no vtbl call |
| 4 | Frees including isnil sentinel | **Falsified** — isnil@+0x29 returns without delete |
| 5 | Bit-identical merge with `0x0051bbc0` | **Narrow** — CF twin, **distinct VA** (different delete rel32 / callers); do not alias one symbol |
| 6 | Same as Val12 free | **Falsified** — isnil@+0x29 not +0x19 |
| 7 | Mission-notify scaffold is product | **Reject** — chain name only |
| 8 | Same as `Map_FreeSubtree_B` `0x0051be90` | **Falsified** — different VA / family pairing |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil/left/right layout | **High** | Wrong walk |
| No value destroy here | **High** | Missed dtor if assumed |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against range parent

```
// FUN_00407d70 full clear:
//   if first==head->left && last==head:
//     FUN_00406c00(head->parent); reset head L/P/R; size=0; *out=begin
//   else: successor + Map_EraseNode_B (00409220)
```

Phy reinit `FUN_009463b0` pushes root of map `@+0xf24` then free — same free-subtree role.

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree helper (not clear, not value dtor):
void StdTree_FreeSubtree_Isnil29(void* tree_base /*unused*/, NodeIsnil29* n) {
  if (n->isnil) return;
  while (!n->isnil) {
    StdTree_FreeSubtree_Isnil29(tree_base, n->right);
    NodeIsnil29* L = n->left;
    operator_delete(n);
    n = L;
  }
}
// Keep separate VA from Map_FreeSubtree_Isnil29 (0051bbc0) / Map_FreeSubtree_B / Val12.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout. Residual product types → **accept-with-gaps**.
