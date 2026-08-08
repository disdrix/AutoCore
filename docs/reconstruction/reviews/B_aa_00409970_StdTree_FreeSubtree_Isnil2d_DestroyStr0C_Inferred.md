# Review B (skeptical / adversarial): `aa_00409970` StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-I) |
| **Counterpart** | `reviews/A_aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — left-walk + destroy present in 59 B body |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded; **`RET 4`** |
| 3 | No value destroy | **Falsified** — `FUN_00409b80` before delete |
| 4 | Merge with isnil131 free `00409920` | **Falsified** — isnil **0x2d** vs **0x131**; distinct parents |
| 5 | Merge with isnil29 no-destroy free | **Falsified** — different isnil; no string dtor there |
| 6 | isnil@+0x29 misread as 0x2d | **Falsified** — bytes `80 7F 2D 00` unambiguous |
| 7 | Frees sentinel | **Falsified** — isnil gate before destroy/delete |
| 8 | thiscall ECX=node | **Falsified** — ECX=tree_base from `MOV ECX,EDI` at sole caller |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil@+0x2d layout | **High** | Wrong walk |
| String destroy @+0x0c | **High** | Leak string buffer |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against range parent

```
// FUN_00407f90 full clear (site 0x00407fb0):
//   MOV ECX, EDI
//   PUSH head->parent
//   CALL 00409970
//   head L/P/R = head; size = 0; *out = begin
// Partial: successor walk on isnil@+0x2d then FUN_004094c0 single erase
```

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree WITH string value destroy (compact isnil2d family):
void StdTree_FreeSubtree_Isnil2d_DestroyStr0C(void* tree_base, NodeIsnil2d* n) {
  if (n->isnil) return;
  while (!n->isnil) {
    StdTree_FreeSubtree_Isnil2d_DestroyStr0C(tree_base, n->right);
    NodeIsnil2d* L = n->left;
    DestroyNodeStringAt0C(n);   // FUN_00409b80 (shared with isnil131 free)
    operator_delete(n);
    n = L;
  }
}
// Keep distinct from isnil131 twin and no-destroy isnil29 frees.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/destroy. Residual product types → **accept-with-gaps**.
