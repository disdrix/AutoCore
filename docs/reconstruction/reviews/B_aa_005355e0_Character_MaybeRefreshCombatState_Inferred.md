# Review B (skeptical / adversarial): `aa_005355e0` Character_MaybeRefreshCombatState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005355e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005355e0_Character_MaybeRefreshCombatState_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Awards kill XP | Falsified — elapsed/objectives only |
| 2 | Is pool regen math itself | Falsified — post-tick refresh |
| 3 | Always evaluates objectives | Falsified — needs +0xa8 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Elapsed acc offsets | High | Broken objective timers |
| Type-7 objective path | Medium | Missed mission progress |

---

## 3. Cross-check against raw

```
MaybeRefreshCombatState(char, deltaMs):
  acc64 += delta; dirty|=1; stamp tick
  if linked@vbase+0xa8: EvaluatePendingObjectives(kind=7, float(delta))
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Post-regen character combat/objective refresh; keep separate from XP.
```

---

## 5. Open questions

1. Name objective kind 7 in mission docs.

**Verdict:** **accept-with-gaps**
