# Review B (skeptical / adversarial): `aa_004cb550` StdTree_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9G-A) |
| **Counterpart** | `reviews/A_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn after right free; real body is left-walk loop (53 B) |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded (`MOV EBX,ECX`); **`RET 4`** |
| 3 | This destroys `T*` values | **Falsified** — no payload load / no vtbl call; node free only |
| 4 | Frees including isnil sentinel | **Falsified** — isnil@+0x29 gate returns without delete |
| 5 | Same VA as `Map_FreeSubtree_Isnil29` | **Falsified** — twin CF at `0x0051bbc0`, this is `0x004cb550` |
| 6 | Same as `Map_EraseRange_B` free `0051be90` | **Falsified** — different free for B family |
| 7 | Product name from VOG_DEBUG_STOP scaffold | **Reject** — generic free helper; EraseRange multi-caller chain |
| 8 | thiscall with no stack arg | **Falsified** — stack node + RET 4 |
| 9 | Only frees right child once (no left) | **Falsified** — `8B 36` / `74 E2` left loop sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil/left/right @ +0x29/+0/+8 | **High** | Wrong walk |
| No value destroy here | **High** | Missed dtor if assumed |
| Distinct from Map_FreeSubtree_Isnil29 | **High** | Wrong EraseRange pair |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against StdTree_EraseRange

```
// StdTree_EraseRange_Isnil29 full clear @ 0x004cbabc:
//   push head->parent (root); CALL StdTree_FreeSubtree_Isnil29_Inferred
//   then reset head left/right/parent to head; size=0
```

Parent dual A claimed free via `FUN_004cb550` residual — this OWN dual seals nested free algebra (including left walk parent listed as open).

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
// Call only from StdTree_EraseRange_Isnil29 full-clear (not Map_EraseRange free 0051bbc0).
// Ignore Ghidra noreturn on operator_delete.
// Keep separate from Map_FreeSubtree_Isnil29 / _B / Val12 / Isnil15 frees.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/caller pair. Residual product types → **accept-with-gaps**.
