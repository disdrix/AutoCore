# Review B (skeptical / adversarial): `aa_004bc580` List_RemoveAll

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-U) |
| **Counterpart** | `reviews/A_aa_004bc580_List_RemoveAll.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack-arg stdcall | **Falsified** — ECX formal `8B F1`; bare `C3` |
| 2 | Only reaction-system helper | **Falsified** — 6 callers including inventory grid + host reset (9 sites) |
| 3 | Scaffold callee-of-RemoveObject name | **Rejected** — product string seals **RemoveAll** |
| 4 | Clears only one head | **Falsified** — zeros `+0x1c/+0x20/+0x24` |
| 5 | Safe under TraversalLock | **Falsified** — throws `0x80070005` when `+0x28≠0` |
| 6 | Mid-body “VOG_DEBUG_STOP” is main CF | **Falsified** — SEH landing after while; normal path jz to zero heads |
| 7 | Different layout than List_IterateNext | **Falsified** — same CS@+4, head@+0x1c, next@+8, flag@+0x28 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX + CS + drain + zero | **High** | Wrong list API |
| Product RemoveAll string | **High** | Wrong name |
| Family with TraversalLock | **High** | Wrong lock model |
| Node payload type English | **Low** | Naming only |
| +0x20/+0x24 field roles | **Med** | Layout docs only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 252 B hex ends `5B 8B E5 5D C3`.
- Prologue: `55 8B EC … 8B F1` + chkstk `0x1004` (family stack for error path).
- String xref path uses `0x00a467ec` `"List Error!  RemoveAll Call Stack:\n%s\n"`.
- Sibling `FUN_004294f0` same chkstk/error pattern with `"…TraversalLock…"`.

---

## 4. Surviving contract for AutoCore

```
// Port as ECX thiscall/fastcall list RemoveAll (not free function without host):
void List_RemoveAll(ListHost* h) {
  EnterCriticalSection(&h->cs); // +4
  if (h->traversalLock) { Leave; throw E_ACCESSDENIED; } // +0x28
  while (auto* n = h->head) { // +0x1c
    h->head = n->next; // +8
    n->field4 = 0;
    n->vtbl->scalar_deleting_dtor(n, 1);
  }
  h->f24 = h->f20 = h->head = 0;
  LeaveCriticalSection(&h->cs);
}
// Pair with List_TraversalLock / List_IterateNext.
// Inventory grid embeds list at grid+0x2c (probable; residual).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, drain CF, lock throw, product RemoveAll plate, multi-caller surface. Residual product class English only → **accept**.
