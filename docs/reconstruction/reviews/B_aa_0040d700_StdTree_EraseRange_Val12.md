# Review B (skeptical / adversarial): `aa_0040d700` StdTree_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-C) |
| **Counterpart** | `reviews/A_aa_0040d700_StdTree_EraseRange_Val12.md` |
| **Scratch** | `tmp/a_0040d700.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is clear (`0040d5b0`) | **Falsified** — no value vtbl walk; full path is free-subtree + head reset only; partial uses single erase |
| 2 | Stack formals are 2 (missing out_it) | **Falsified** — `RET 0x0C` and three stack loads (`out`, `first`, `last`) |
| 3 | isnil at +0x15 (Isnil15 family) | **Falsified** — successor loads `+0x19` (Val12) |
| 4 | Full free destroys T* via vtbl[+0xc] | **Falsified for this body** — only `0040d630`; value destroy is clear residual |
| 5 | Same callees as `004e5120` peer | **Falsified** — free=`0040d630`, erase=`004188e0` (peer uses `004e2940`/`004e4130`) |
| 6 | Product map type sealed | **Careful** — structural name only |
| 7 | Decompile dropped ECX | **Partial** — analyze shows thiscall ECX; body uses EDI=this |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Full vs partial CF | **High** | Wrong bulk clear path |
| RET 0x0C / 3 stack args | **High** | ABI crash |
| Val12 isnil@+0x19 | **High** | Wrong node family |
| FreeSubtree full path | **High** | Leak / double free |
| Value dtor on full free | **Med** | Leak of pointed T if non-POD |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Callers both:
//   EraseRange(this, &tmp, *head, head);  // full [begin,end)
//   operator_delete(head);
// Peer W28-P 004e5120: identical CF skeleton, 180 B, RET 0xC
// Free dual W31-A 0040d630: left-walk free, isnil@+0x19
```

Live decompile 2026-07-29 ≡ raw 2026-07-23; body hex seals size + dual RET.

---

## 4. Surviving contract for AutoCore

```
// Port as MSVC tree range erase:
void StdTree_EraseRange_Val12(Map* m, Node** out, Node* first, Node* last) {
  if (first == m->head->left && last == m->head) {
    FreeSubtree(m->head->parent);
    reset head; m->size = 0; *out = m->head; return;
  }
  while (first != last) {
    Node* next = successor(first); // isnil@+0x19
    erase_one(m, first);
    first = next;
  }
  *out = first;
}
// RET 0xC. Do not invent value vtbl destroy on full path.
// Pair FreeSubtree 0040d630 + single erase 004188e0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/Val12/peer shape. Residual product T + value-dtor policy on free path → **accept-with-gaps**.
