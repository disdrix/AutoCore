# Review B (skeptical / adversarial): `aa_007cbbb0` Mission_tExperienceLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cbbb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007cbbb0_Mission_tExperienceLevel.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Mission objective runtime evaluator | Falsified — table load |
| 2 | UI mission panel | Falsified — data path string |
| 3 | Creature XP table | Falsified — tExperienceLevel |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Column map to +0x10 | High | Wrong thresholds |
| Map insert identity | High | Corrupt level table |

---

## 3. Cross-check against raw

```
Mission_tExperienceLevel(mapCtx):
  load //tExperienceLevel/row into cumulative XP map
Ensure callee. Residual COM FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
Data bring-up for player level XP thresholds.
```

---

## 5. Open questions

1. Document all bound columns from raw.

**Verdict:** **accept-with-gaps**
