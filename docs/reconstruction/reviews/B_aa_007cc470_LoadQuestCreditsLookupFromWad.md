# Review B (skeptical / adversarial): `aa_007cc470` LoadQuestCreditsLookupFromWad

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc470` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007cc470_LoadQuestCreditsLookupFromWad.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Awards credits to player | Falsified — table load |
| 2 | Hardcoded only 0..10 | Overstated — loads rows; comment is retail sample |
| 3 | XP table | Falsified — credits lookup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Table load path | High | Wrong credit mults |
| Column names | High | Parse fail |
| Memory layout | Tentative | Bad index lookup |

---

## 3. Cross-check against raw

```
parse tQuestCreditsLookup rows into index→float table.
Clean ≡ raw outline; COM noise residual.
```

---

## 4. Surviving contract for AutoCore

```
LoadQuestCreditsLookupFromWad(wad):
  credits index table; pair ComputeObjectiveCredits + LoadQuestBaseCredits
  AutoCore mission credit tables
```

---

## 5. Open questions

1. Dump loaded table vs retail sample.
2. Server load parity.

**Verdict:** **accept-with-gaps**
