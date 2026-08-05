# Review B (skeptical / adversarial): `aa_0052a9b0` Vehicle_GetSkillCooldownModifier

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a9b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0052a9b0_Vehicle_GetSkillCooldownModifier.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always returns 1.0 | Falsified — plant scale |
| 2 | Mutates CD map | Falsified — query scale |
| 3 | Finished miss path | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Plant +0xCC scale | High | Wrong cast-again duration |
| Map +0xc70 | High | Category scale wrong |
| Miss/default path | Tentative | NaN/0 scale |

---

## 3. Cross-check against raw

```
lookup category scale; if plant: *= plant+0xCC; return.
Clean outline; multiply path needs re-verify.
```

---

## 4. Surviving contract for AutoCore

```
GetSkillCooldownModifier(ctx, categoryScale) → float:
  cast-again / QB scale; pair GetCategoryCooldownRemaining / UpdateSlotCooldownOverlay
  AutoCore skill CD UX
```

---

## 5. Open questions

1. Re-decompile full multiply return.
2. Live cast-again with/without plant.

**Verdict:** **accept-with-gaps**
