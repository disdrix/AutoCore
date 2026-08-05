# Review B (skeptical / adversarial): `aa_0089bf50` Inv_Client_ValidateCraftAffordability

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089bf50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0089bf50_Inv_Client_ValidateCraftAffordability.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Commits craft on server | Falsified — validate UI |
| 2 | Ignores inventory | Falsified — component check |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mat + credit gates | High | Craft without mats |
| Recipe hash key | High | Wrong recipe |
| UI format only residual | Tentative | Display desync |

---

## 3. Cross-check against raw

```
lookup recipe; if mats/credits fail block + message; else format cost.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
ValidateCraftAffordability(...):
  client craft enablement
  AutoCore: mirror gates before C2S craft
```

---

## 5. Open questions

1. Seal credit offset.
2. Map recipe def fields.

**Verdict:** **accept-with-gaps**
