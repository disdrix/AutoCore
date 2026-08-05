# Review B (skeptical / adversarial): `aa_0040d630` StdTree_FreeSubtree_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-A) |
| **Counterpart** | `reviews/A_aa_0040d630_StdTree_FreeSubtree_Val12.md` |
| **Scratch** | `tmp/a_0040d630.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn; real body is left-walk loop after recursive right free |
| 2 | Bare cdecl void(node*) only | **Falsified** — ECX threaded (`MOV EBX,ECX` / recursive `MOV ECX,EBX`); **`RET 4`** |
| 3 | This destroys `T*` values | **Falsified** — no load of +0x14 / no vtbl call; only node free |
| 4 | Frees entire tree including sentinel | **Falsified** — isnil@+0x19 gate skips nil head; clear still needs head free via `FUN_0040d7c0` |
| 5 | Same as clear (`0040d5b0`) | **Falsified** — clear does value destroy + free root left-walk + reset; this is free-subtree helper only |
| 6 | Name claims product plate | **Careful** — structural `_Inferred` only; no PDB English |
| 7 | thiscall with no stack arg | **Falsified** — stack node + RET 4 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption on call |
| isnil/left/right layout | **High** | Wrong node walk |
| No value destroy here | **High** | Missed dtor if assumed here |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Clear free path (caller FUN_0040d5b0 @ 0x0040d5f6):
//   EDI = this+4; push node->right; ECX=EDI; call FUN_0040d630
// Erase path FUN_0040d700 @ 0x0040d71c: same helper
// Self @ 0x0040d647 recursive right
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 collapsed shape. Full 53 B hex seals left-walk + RET4.

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree helper (not clear, not value dtor):
void StdTree_FreeSubtree_Val12(void* tree_base /*unused*/, Node* n) {
  if (n->isnil) return;
  while (!n->isnil) {
    FreeSubtree(tree_base, n->right);
    Node* L = n->left;
    operator_delete(n);
    n = L;
  }
}
// Call after value destroy if needed. Pair with StdTree_Clear_PtrVal_Vtbl0C.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout. Residual product types → **accept-with-gaps**.
