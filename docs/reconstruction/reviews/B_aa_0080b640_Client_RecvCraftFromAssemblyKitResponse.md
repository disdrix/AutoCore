# Review B (skeptical / adversarial): `aa_0080b640` Client_RecvCraftFromAssemblyKitResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080b640_Client_RecvCraftFromAssemblyKitResponse.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Handler applies crafted item to inventory | **Falsified** — UI only |
| 2 | Status enum complete 0–5 only | **Partial** — default silent; higher codes possible |
| 3 | English strings are retail UI | **Probable** — may still be table keys via `FUN_007a6de0` |
| 4 | Success path same as fail toast helper | **Falsified** — success uses `FUN_0040c5c0`, fails `FUN_007fdfb0` |
| 5 | Name “AssemblyKit” implies only kits | **Overstated** — body is status switch only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Status→string map | High | Wrong craft UX |
| No inventory side effects | High | Duplicate grant design error |
| Opcode identity | Tentative | Wire table misbind |
| Localizer helpers | Probable | Wrong message channel |

---

## 3. Cross-check against raw

Raw switch is exhaustive for 0–5 + default. Clean is scaffold. Surviving: feedback-only manager.

---

## 4. Surviving contract for AutoCore

```
RecvCraftFromAssemblyKitResponse(pkt):
  switch pkt.status(+4):
    0: toast "Item Created!"
    1..5: fail message strings as table
    else: return
Do NOT grant items here; expect separate inventory S2C.
```

---

## 5. Open questions

1. Exact S2C opcode / dispatch slot.
2. C2S craft request manager.
3. Whether success always pairs with RecvInventoryAddItem.
4. Experimentation vs standard craft server codes.

**Verdict:** UI status table sealed; system integration open.
