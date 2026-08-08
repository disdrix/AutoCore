# Review B (skeptical / adversarial): `aa_00409b80` StdTree_DestroyStringAt0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-A) |
| **Counterpart** | `reviews/A_aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl `void(int)` with plain RET | **Falsified** — machine **`RET 4`** stdcall |
| 2 | Full node / large-value dtor | **Falsified** — only string @+0x0c; no other fields |
| 3 | Frees the node | **Falsified** — callers `operator_delete` after return |
| 4 | thiscall ECX=node | **Falsified** — node on stack; ECX set to `node+0x0c` for string dtor |
| 5 | Same as free-subtree itself | **Falsified** — leaf value destroy only; walk owned by `00409920`/`00409970` |
| 6 | Only one isnil family uses it | **Falsified** — **shared** by isnil131 and isnil2d free-subtrees |
| 7 | No-destroy free peers also call it | **Falsified** — `00406c00` / `0051bbc0` / `0040d630` lack this call |
| 8 | SEH optional / decomp fiction | **Falsified** — full FS:[0] frame + handler `LAB_009bc656` in bytes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String destroy @+0x0c | **High** | Leak string buffer |
| stdcall RET 4 | **High** | Stack corruption |
| Shared free-subtree role | **High** | Wrong dtor pairing |
| Product map English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against free-subtree parents

```
// Both FreeSubtree (isnil131 @ 00409942 / isnil2d @ 0040998f):
//   FreeSubtree(right);
//   left = node->left;
//   FUN_00409b80(node);     // THIS — string only
//   operator_delete(node);
//   node = left;
// Erase-range parents (00407b70 / 00407f90) call free-subtree, not this directly.
```

---

## 4. Surviving contract for AutoCore

```
// Port as string-only node value destroy:
void __stdcall StdTree_DestroyStringAt0C(void* node) {
  reinterpret_cast<std::string*>((char*)node + 0x0c)->~basic_string();
}
// Callers free-subtree then delete. Keep distinct from free-subtree and no-destroy peers.
// Preserve stdcall RET 4 at call boundary.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/string offset/shared callers. Residual product types → **accept-with-gaps**.
