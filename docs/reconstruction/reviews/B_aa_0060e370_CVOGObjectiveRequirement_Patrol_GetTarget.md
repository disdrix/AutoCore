# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Patrol_GetTarget` @ `0x0060e370`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060e370_CVOGObjectiveRequirement_Patrol_GetTarget.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns waypoint index only | **Falsified — fills out blob** |
| 2 | Done uses required alone | **Falsified — multiplies weight** |
| 3 | Index uses weight in modulo | **Falsified — modulo required only** |
| 4 | Progress kept as float in compare | **Falsified — (int) cast before compare** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Waypoint indexing | High | Wrong target / infinite patrol |
| Out offsets 0xea / 0x3b | High | Corrupt target blob |
| Server parity of absolute float | Medium | Desync range checks |

---

## 3. Surviving contract for AutoCore

```
Patrol_GetTarget(req, out, state):
  if !state: return 0
  p = (int)state.slotFloat[slot]
  if weight*required <= p: return 0
  i = p % required
  write TFID[i], flags, primary into out
  return 1
```

---

## 4. Open questions

1. Seal out-target type name.
2. Live AutoPatrol range vs client GetTarget.

**Verdict:** accept-with-gaps.
