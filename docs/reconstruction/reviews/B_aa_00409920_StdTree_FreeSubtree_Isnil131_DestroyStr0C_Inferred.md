# Review B (skeptical / adversarial): `aa_00409920` StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409920` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-I) |
| **Counterpart** | `reviews/A_aa_00409920_StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn; real body is left-walk loop (65 B) with value dtor |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded; **`RET 4`** |
| 3 | No value destroy (like isnil29 free) | **Falsified** — `FUN_00409b80` stdcall before delete; string @+0x0c |
| 4 | Frees including isnil sentinel | **Falsified** — isnil@+0x131 returns without destroy/delete |
| 5 | Same as isnil2d free `00409970` | **Narrow** — CF twin, **distinct isnil** (0x131 vs 0x2d); keep separate symbols |
| 6 | Same as no-destroy isnil29 free `00406c00` / `0051bbc0` | **Falsified** — those lack `FUN_00409b80`; different isnil |
| 7 | Full tree dtor / clear | **Falsified** — free-subtree only; head reset owned by erase-range parent |
| 8 | Dtor destroys whole large value | **Narrow** — only `basic_string` @+0x0c proven; rest of payload not touched here |
| 9 | thiscall ECX=node | **Falsified** — ECX=tree_base; node on stack |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape + left walk | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil@+0x131 / left / right | **High** | Wrong walk |
| String destroy @+0x0c via 00409b80 | **High** | Leak string buffer |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against range parent

```
// FUN_00407b70 full clear (site 0x00407b8f):
//   MOV ECX, ESI          // tree_base
//   PUSH head->parent     // root
//   CALL 00409920
//   head L/P/R = head; size = 0; *out = head->left
```

Partial range path uses other helpers (`FUN_00404000` / `FUN_00408ad0`) — not this free-subtree.

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree WITH string value destroy:
void StdTree_FreeSubtree_Isnil131_DestroyStr0C(void* tree_base, NodeIsnil131* n) {
  if (n->isnil) return;
  while (!n->isnil) {
    StdTree_FreeSubtree_Isnil131_DestroyStr0C(tree_base, n->right);
    NodeIsnil131* L = n->left;
    DestroyNodeStringAt0C(n);   // FUN_00409b80
    operator_delete(n);
    n = L;
  }
}
// Keep distinct from isnil2d destroy twin (00409970) and no-destroy isnil29 frees.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/destroy. Residual product types → **accept-with-gaps**.
