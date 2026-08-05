# Review B (skeptical / adversarial): `aa_0085e890` Client_UI_InventoryWindow_ClearBoundItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085e890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085e890_Client_UI_InventoryWindow_ClearBoundItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always clears bound item | **Falsified** — dual null/`+0x2b0` gates |
| 2 | Sends network packet | **Falsified** — single vcall only |
| 3 | `param_1` is item not window | **Falsified** — bytes load `[ecx+0x574]` then push that as item |
| 4 | Destroys item object | **Open** — vtbl `+0xb0` body not this unit |
| 5 | DropToGrid requires this call | **Partial** — Drop **inlines** same CF; other paths call helper |
| 6 | `+0x2b0` means “equipped” | **Unsealed** — only non-zero gate proven |

---

## 2. Surviving contract

```
thiscall(window):
  item = *(window+0x574)
  if item && *(item+0x2b0):
    (*window->vtbl)[+0xb0](item)
```

**Xrefs cannot be attacked away** — five UNCONDITIONAL_CALL sites including cursor / drop-response families.

---

## 3. Open

| Topic | Why |
|---|---|
| vtbl `+0xb0` semantics | Callee dual not this unit |
| Field `+0x2b0` English | Gate only |
| Complete caller inventory names | Some sites not in named functions |

**Verdict:** CF/bytes sealed. **accept-with-gaps.**
