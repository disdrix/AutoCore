# Review A (reconstruction fidelity): `aa_0053b330` CNDHash_RemoveAll_009cefdc

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b330` |
| **VA** | `0x0053b330` |
| **Canonical name** | `CNDHash_RemoveAll` (node vtbl stamp `PTR_LAB_009cefdc`; non-owning) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b330_CNDHash_RemoveAll_009cefdc.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile` + `force_decompile`; twin family + remove `00538d50` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**RemoveAll twin** — CF identical to sealed RemoveAll family (`0053b130` / `0053b230` / `0053b2b0` / `0053b3b0`):

1. If `this+0x1d` lock set → log `"HashError:RemoveAll, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue** (warn-only).
2. If bucket table `this+0x10` non-null: for `u = 0 .. mask` **inclusive** (`u <= *(this+0x08)`):
   - Walk chain at `table[u]->head` (`sentinel+4`).
   - For each node: save next `@node+0xc` (`puVar3[3]`); stamp vtbl `PTR_LAB_009cefdc`; clear value `@+0x08`; freelist-push via `this+0x20`.
   - Clear bucket head to 0.
3. Zero ordered list head/tail (`+0x14/+0x18`) and count (`+0x0c`).
4. Return **0**.

**Only delta vs other RemoveAll twins:** node vtbl stamp **`PTR_LAB_009cefdc`** — same family as remove `FUN_00538d50`.

**Non-owning:** does **not** `operator_delete` values (value zeroed only).

Direct code xrefs empty (vtbl / indirect / data).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ force ≡ raw | **Confirmed** |
| Inclusive mask walk `u <= +0x08` | **Confirmed** |
| Vtbl `009cefdc` pairs with remove `00538d50` | **High** |
| Non-owning (no value free) | **Confirmed** |
| Lock warn-only | **Confirmed** |

---

## 3. Recovered CF

```c
// int __fastcall CNDHash_RemoveAll_009cefdc(CNDHash *this)
if (this->lock) { log locked; /* continue */ }
if (this->buckets) {
  for (u = 0; u <= this->mask; u++) {
    for (n = this->buckets[u]->head; n; n = next) {
      next = n->bucketNext;
      n->vtbl = PTR_LAB_009cefdc; n->value = 0;
      n->vtbl = this->freelist; this->freelist = n; // freelist reuse of +0
    }
    this->buckets[u]->head = 0;
  }
}
this->listHead = this->listTail = 0; this->count = 0;
return 0;
```

---

## 4. Gaps

1. Product English name for this stamp family.
2. No direct CALL xrefs — ownership via object vtbl / indirect only.
3. Sibling RemoveAll stamps already dualed separately; do not merge VAs.

**Verdict:** **accept-with-gaps.**
