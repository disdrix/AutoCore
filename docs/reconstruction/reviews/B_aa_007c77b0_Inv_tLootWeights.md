# Review B (skeptical / adversarial): `aa_007c77b0` Inv_tLootWeights

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c77b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007c77b0_Inv_tLootWeights.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uniform random only — no weights | Falsified — weights table exists |
| 2 | UI inventory layout | Falsified — data load |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Weight join keys | High | Skewed drops |

---

## 3. Cross-check against raw

```
Inv_tLootWeights: load //tLootWeights/row
Residual COM. Clean ≡ raw shape.
```

---

## 4. Surviving contract for AutoCore

```
Loot weight table for AutoCore drop RNG.
```

---

## 5. Open questions

1. Sample weight distributions from retail.

**Verdict:** **accept-with-gaps**
