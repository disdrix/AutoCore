# Review B (skeptical / adversarial): `aa_0052c860` Experience_GetCumulativeThreshold

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052c860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0052c860_Experience_GetCumulativeThreshold.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Missing returns 0 | Falsified — 0x7FFFFFFF |
| 2 | Same map as GetCreatureXpForLevel | Falsified — distinct tables/globals |
| 3 | Grants XP to character | Falsified — pure lookup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sentinel vs 0 miss semantics | High | Infinite level-up / false cap |
| +0x10 cumulative field | High | Wrong thresholds |
| Loader readiness flag | Medium | Empty map forever |

---

## 3. Cross-check against raw

```
GetCumulativeThreshold(wLevel):
  ensure level table; lower_bound; return +0x10 or 0x7FFFFFFF
Clean ≡ raw; map root residual.
```

---

## 4. Surviving contract for AutoCore

```
Player level cumulative XP thresholds for level-up/down and pulse XP span.
  AutoCore ExperienceService must match sentinel and +0x10 layout.
```

---

## 5. Open questions

1. Cross-check LevelUp loops against sentinel.
2. Table dump parity with retail tExperienceLevel.

**Verdict:** **accept-with-gaps**
