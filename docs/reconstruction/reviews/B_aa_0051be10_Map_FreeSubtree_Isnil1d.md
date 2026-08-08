# Review B (skeptical / adversarial): `aa_0051be10` Map_FreeSubtree_Isnil1d

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9F-E) |
| **Counterpart** | `reviews/A_aa_0051be10_Map_FreeSubtree_Isnil1d.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn after right free; real body is left-walk loop (53 B) |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded (`MOV EBX,ECX`); **`RET 4`** |
| 3 | This destroys `T*` values | **Falsified** — no payload load / no vtbl call; node free only |
| 4 | Frees including isnil sentinel | **Falsified** — isnil@+0x1d gate returns without delete |
| 5 | Same as `Map_FreeSubtree_Isnil29` bit-identical | **Falsified** — isnil imm `0x1d` vs `0x29`; different delete rel32; different host |
| 6 | Same as `Map_FreeSubtree_B` (`0051be90`) | **Falsified** — different VA; B is isnil@+0x29 for EraseRange_B |
| 7 | Skill-cast product free | **Reject** — generic STL free-subtree for range erase |
| 8 | thiscall with no stack arg | **Falsified** — stack node + RET 4 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil/left/right @ +0x1d/+0/+8 | **High** | Wrong walk |
| No value destroy here | **High** | Missed dtor if assumed |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against Map_EraseRange_Isnil1d

```
// Map_EraseRange_Isnil1d full clear @ 0x0051d71c:
//   push head->parent (root); CALL Map_FreeSubtree_Isnil1d
//   then reset head left/right/parent to head; size=0
// Parent dual A (WQ9E-I) claimed free via FUN_0051be10 — confirmed this OWN seals nested free.
```

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree helper (not clear, not value dtor):
void Map_FreeSubtree_Isnil1d(void* tree_base /*unused*/, NodeIsnil1d* n) {
  if (n->isnil@0x1d) return;
  while (!n->isnil@0x1d) {
    Map_FreeSubtree_Isnil1d(tree_base, n->right);
    NodeIsnil1d* L = n->left;
    operator_delete(n);
    n = L;
  }
}
// Call only after values already destroyed if required by type.
// Ignore Ghidra noreturn on operator_delete.
// Keep separate from Isnil29 / FreeSubtree_B / Val12 / Isnil15 frees.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout. Residual product types → **accept-with-gaps**.
