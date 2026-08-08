# Review B (skeptical / adversarial): `aa_0051bbc0` Map_FreeSubtree_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bbc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9E-H) |
| **Counterpart** | `reviews/A_aa_0051bbc0_Map_FreeSubtree_Isnil29.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn after right free; real body is left-walk loop (53 B) |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded (`MOV EBX,ECX`); **`RET 4`** |
| 3 | This destroys `T*` values | **Falsified** — no payload load / no vtbl call; node free only |
| 4 | Frees including isnil sentinel | **Falsified** — isnil@+0x29 gate returns without delete |
| 5 | Same as `FUN_0051be90` bit-identical | **Falsified** — different VA (Map_EraseRange_B free peer) |
| 6 | Same as MapFloatTfid free VA | **Falsified** — twin CF at `0x0058da00`, not this VA |
| 7 | Product name from Aggro xref | **Reject** — generic; EraseRange multi-caller |
| 8 | thiscall with no stack arg | **Falsified** — stack node + RET 4 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil/left/right @ +0x29/+0/+8 | **High** | Wrong walk |
| No value destroy here | **High** | Missed dtor if assumed |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against Map_EraseRange

```
// Map_EraseRange full clear @ 0x0051c7dc:
//   push head->parent (root); CALL Map_FreeSubtree_Isnil29
//   then reset head left/right/parent to head; size=0
```

Parent dual A claimed free via `FUN_0051bbc0` — confirmed this OWN dual seals nested free algebra.

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree helper (not clear, not value dtor):
void Map_FreeSubtree_Isnil29(void* tree_base /*unused*/, NodeIsnil29* n) {
  if (n->isnil) return;
  while (!n->isnil) {
    Map_FreeSubtree_Isnil29(tree_base, n->right);
    NodeIsnil29* L = n->left;
    operator_delete(n);
    n = L;
  }
}
// Call only after values already destroyed if required by type.
// Ignore Ghidra noreturn on operator_delete.
// Keep separate from FUN_0051be90 / Val12 / Isnil15 frees.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout. Residual product types → **accept-with-gaps**.
