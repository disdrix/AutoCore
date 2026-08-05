# Review B (skeptical / adversarial): `aa_008c26c0` InventorySheet_ClearTrackedSelection (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c26c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008c26c0_InventorySheet_ClearTrackedSelection_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Removes item from cargo grid | Only vcall on UI window | **Falsified** |
| 2 | Always clears | Triple null/`+0x2b0` gate | **Falsified** |
| 3 | Portable thiscall sheet | Host in **EAX** | **Falsified as ECX-this** |
| 4 | Many parents | Only ClearInventoryCursor (2 sites) | **Survives** |
| 5 | Different offsets than Drop | Drop uses same `0x15d`/`0x2b0`/`+0xb0` | **Falsified as different** — shared pattern |
| 6 | Product field names | Inferred | **Gap** |

---

## 2. Surviving contract

```
// EAX = inventory sheet host
// win = host[+0x580]; tracked = win[+0x574];
// if win && tracked && tracked[+0x2b0]: win->vtbl[+0xb0](tracked)
```

**Verdict:** clear-selection role **survives**. **accept-with-gaps.**
