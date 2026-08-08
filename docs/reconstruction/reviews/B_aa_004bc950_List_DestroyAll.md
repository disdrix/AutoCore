# Review B (skeptical / adversarial): `aa_004bc950` List_DestroyAll

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-028) |
| **Counterpart** | `reviews/A_aa_004bc950_List_DestroyAll.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack-arg stdcall | **Falsified** — ECX formal `8B F1`; bare `C3` |
| 2 | Same as `List_RemoveAll` (merge VAs) | **Falsified** — different VA/body; no `node[+4]=0`; DestroyAll plate vs RemoveAll plate |
| 3 | Same as `ObjectCsList_DestroyAll_Inferred` `0x00424060` (one unit) | **Falsified** — CF twin at different VA/SEH; keep separate seals |
| 4 | Scaffold inventory-only helper | **Falsified** — 4 callers / 9 sites including list host dtors + inventory grid |
| 5 | Clears only one head | **Falsified** — zeros `+0x1c/+0x20/+0x24` |
| 6 | Safe under TraversalLock | **Falsified** — throws `0x80070005` when `+0x28≠0` |
| 7 | Mid-body `VOG_DEBUG_STOP` is main CF | **Falsified** — SEH landing after while; normal path jz to zero heads |
| 8 | Invented product name | **Falsified** — SEH string `"List Error!  DestroyAll Call Stack:\n%s\n"` @ `0x00a33af0` |
| 9 | Different layout than List family | **Falsified** — same CS@+4, head@+0x1c, next@+8, flag@+0x28 as RemoveAll/TraversalLock |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX + CS + drain + zero | **High** | Wrong list API |
| Product DestroyAll string | **High** | Wrong name |
| Distinct from RemoveAll (no node[+4] clear) | **High** | Wrong clear semantics |
| Family with TraversalLock / RemoveAll | **High** | Wrong lock model |
| Separate from ObjectCsList twin VA | **High** | VA merge error |
| Node payload type English | **Low** | Naming only |
| +0x20/+0x24 field roles | **Med** | Layout docs only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 251 B hex ends `5B 8B E5 5D C3`.
- Prologue: `55 8B EC … 8B F1` + chkstk `0x1004` (family stack for error path).
- SEH frame `LAB_009a16d0` (differs from RemoveAll `LAB_009a16b0` and ObjectCsList twin `LAB_009bd790`).
- String xref path uses `0x00a33af0` `"List Error!  DestroyAll Call Stack:\n%s\n"`.
- Live decompile main CF ≡ 2026-07-23 raw body (no wipe; append-only re-verify).

---

## 4. Surviving contract for AutoCore

```
// Port as ECX thiscall/fastcall list DestroyAll (not free function without host):
void List_DestroyAll(ListHost* h) {
  EnterCriticalSection(&h->cs); // +4
  if (h->traversalLock) { Leave; throw E_ACCESSDENIED; } // +0x28
  while (auto* n = h->head) { // +0x1c
    h->head = n->next; // +8
    n->vtbl->scalar_deleting_dtor(n, 1); // no n->field4 = 0
  }
  h->f24 = h->f20 = h->head = 0;
  LeaveCriticalSection(&h->cs);
}
// Pair with List_RemoveAll / List_TraversalLock / List_IterateNext.
// Prefer for host dtor / teardown paths; RemoveAll for mid-life clear.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, drain CF (no node[+4] clear), lock throw, product DestroyAll plate, multi-caller surface, and separation from RemoveAll + ObjectCsList twin. Residual product class English only → **accept**.
