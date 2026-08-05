# Review B (skeptical / adversarial): `aa_007cd150` Mission_tCreatureExperienceLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cd150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007cd150_Mission_tCreatureExperienceLevel.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Computes grey kill slope | Falsified — load only |
| 2 | Player level thresholds | Falsified — creature table |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Creature XP row layout | High | Wrong kill base |
| Map root pairing | High | Lookup miss → 0 |

---

## 3. Cross-check against raw

```
Mission_tCreatureExperienceLevel(mapCtx):
  load //tCreatureExperienceLevel/row → creature XP map
EnsureCreature callee.
```

---

## 4. Surviving contract for AutoCore

```
Kill-base XP table bring-up for AutoCore combat awards.
```

---

## 5. Open questions

1. Diff sample levels vs XP.md table.

**Verdict:** **accept-with-gaps**
