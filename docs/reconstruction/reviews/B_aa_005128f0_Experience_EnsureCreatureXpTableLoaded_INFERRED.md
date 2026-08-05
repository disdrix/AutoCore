# Review B (skeptical / adversarial): `aa_005128f0` Experience_EnsureCreatureXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005128f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005128f0_Experience_EnsureCreatureXpTableLoaded_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Loads player cumulative thresholds | Falsified — creature table |
| 2 | Computes grey kill XP | Falsified — load only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Creature map load pairing | High | Zero kill base XP |
| Ready flag | Medium | Reload thrash |

---

## 3. Cross-check against raw

```
EnsureCreatureXpTableLoaded:
  FUN_007e1d80; Mission_tCreatureExperienceLevel(&DAT_00b04270); FUN_007b7df0
Fail → VOG_DEBUG_STOP. Clean ≡ raw shape.
```

---

## 4. Surviving contract for AutoCore

```
Bring-up for kill-base XP table; required for LevelDiffBaseXp.
```

---

## 5. Open questions

1. Pair with Mission_tCreatureExperienceLevel dual review.

**Verdict:** **accept-with-gaps**
