# Review B (skeptical / adversarial): `aa_0040d6d0` StdTree_Tidy_FreeHead_Bare_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d6d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-A) |
| **Counterpart** | `reviews/A_aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md` |
| **Scratch** | `tmp/a_0040d6d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn after `operator_delete` drops null head/size + RET; **bytes win** |
| 2 | This is a host complete dtor | **Falsified** — no vtbl install; frees **head** not `this`; bare RET |
| 3 | Same body as `0040d7c0` | **Partial** — same tidy **order**, but no SEH / 46 B vs 92 B |
| 4 | `local_4 = param_1` is semantic | **Falsified as value** — `push ECX` only allocates out slot; erase overwrites |
| 5 | Erases partial range | **Falsified** — args are `*head` and `head` (full-range gate in `0040d700`) |
| 6 | Product map name sealed | **Careful** — structural Val12 only |
| 7 | Frees the tree object itself | **Falsified** — nulls facade fields after free head |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tidy order erase→delete head→null | **High** | Use-after-free / leak |
| ABI ECX + bare RET | **High** | Stack imbalance |
| Not host free | **High** | Double free host |
| No SEH in this body | **High** | Wrong twin pairing |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Peer SEH tidy FUN_0040d7c0 (W32-B):
//   SEH; FUN_0040d700(full); operator_delete(head); head=0; size=0; RET
// This FUN_0040d6d0:
//   no SEH; same erase/delete/null; 46 B
// Unwind@009bda70: MOV ECX,[EBP-10]; JMP 0040d6d0
// Erase range FUN_0040d700: RET 0xC; full-range free subtree
```

Live decompile 2026-07-29 ≡ scaffold truncate shape; 46 B hex seals post-delete. Closes wave33 high-mention nested callee residual from W32-C callers list.

---

## 4. Surviving contract for AutoCore

```
// Port as bare tree tidy (no SEH):
void StdTree_Tidy_FreeHead_Bare_Val12(Tree* t) {
  void* out;
  Node* head = t->head;
  StdTree_EraseRange_Val12(t, &out, head->left, head); // full
  operator_delete(head);
  t->head = nullptr;
  t->size = 0;
}
// Do not free t itself. Prefer SEH peer 0040d7c0 when that path is required.
```

---

## 5. Verdict

Adversarial pass confirms A on tidy order/ABI/epilogue. Residual product + twin rationale → **accept-with-gaps**.
