# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Patrol_Action` @ `0x0060e120`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060e120_CVOGObjectiveRequirement_Patrol_Action.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Action mutates slot | **Falsified — read-only ratio** |
| 2 | param_3 is a raw float progress | **Falsified — used as pointer base** |
| 3 | Unclamped ratio can exceed 1 | **Falsified — clamp to g_flOne** |
| 4 | Zero denom returns 0 | **Falsified — returns 1.0** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fraction CF | High | Wrong progress bar |
| Vtable slot identity +0x20 | Probable | Mis-wire evaluator interface |

---

## 3. Surviving contract for AutoCore

```
Patrol_Action(req,_,state):
  d = required*weight
  if d==0: return 1.0
  return min(1.0, state.slotFloat[slot]/d)
```

---

## 4. Open questions

1. Confirm vtable index from requirement vtable dump.
2. Whether UI multiplies again by 100.

**Verdict:** accept-with-gaps.
