# Review B (skeptical / adversarial): `aa_0085f1f0` Client_UI_InventoryWindow_GetPageWidth

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f1f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085f1f0_Client_UI_InventoryWindow_GetPageWidth.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns pixel width | **Unlikely** — DropHitTest multiplies as page cell count; name “width” is cells |
| 2 | Can throw / allocate | **Falsified** — pure load |
| 3 | Uses ECX thiscall | **Falsified** — bytes use **EAX** window |
| 4 | Same offset as type enum (`host+4`) | **Different field** — this unit only `+0x18` |
| 5 | Name must be GetPageWidth | **Working name** — sibling height at `+0x1c`; product string absent |

---

## 2. Surviving contract

```
// EAX = window*
host = *(window+0x56c)
return host ? *(i32*)(host+0x18) : 0
```

Three call sites inside DropHitTest family only (xref list).

---

## 3. Open

English page-dimension units; host type product name.

**Verdict:** Load path cannot be attacked. **accept-with-gaps.**
