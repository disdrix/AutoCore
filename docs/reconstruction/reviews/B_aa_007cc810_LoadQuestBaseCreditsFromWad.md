# Review B (skeptical / adversarial): `aa_007cc810` LoadQuestBaseCreditsFromWad

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007cc810_LoadQuestBaseCreditsFromWad.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Computes objective credits delta | Falsified — table load; math is ComputeObjectiveCredits |
| 2 | Identical to lookup loader | Falsified — base vs scaler table |
| 3 | Finished xpath | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base table exists | High | Zero credits |
| Not award path | High | Wrong layer |
| Schema | Tentative | Misaligned levels |

---

## 3. Cross-check against raw

```
load base credits table from wad; companion to credits lookup.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
LoadQuestBaseCreditsFromWad(wad):
  base credit by level; pair CreditsLookup + ComputeObjectiveCredits
  AutoCore mission economy tables
```

---

## 5. Open questions

1. Seal wad xpath + columns.
2. Cross-check retail base values.

**Verdict:** **accept-with-gaps**
