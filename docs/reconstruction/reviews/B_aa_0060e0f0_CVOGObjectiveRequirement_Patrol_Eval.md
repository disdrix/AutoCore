# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Patrol_Eval` @ `0x0060e0f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e0f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (residual refresh `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Threshold is requiredVisits alone | **Falsified — multiplies by +0x24** |
| 2 | Eval advances waypoints | **Falsified — pure compare; GetTarget/Action separate** |
| 3 | Weight is float | **Falsified — int multiply then cast** |
| 4 | `+0x24` is generic “visitWeight” only | **Falsified as English — field is Laps** (GetFlags XML + image) |
| 5 | Slot float is 0..1 ratio | **Falsified — absolute pad count** (GetTarget `(int)` + Action divide by product) |
| 6 | Laps always 1 so product == targets | **Overstated — multi-lap is real; data often 1** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product formula | High | Patrol never completes |
| `+0x24` = Laps | **High** (residual) | Wrong threshold / UI needed |
| Absolute slot float | **High** (residual) | Desync mid-route targets |
| Weight field name “visitWeight” | **Retracted** | Prefer Laps |

---

## 3. Surviving contract for AutoCore

```
Patrol_Eval(req,_,state):
  needed = req.targets(+0xd0) * req.Laps(+0x24)   // int
  return (float)needed <= state.slotFloat[req.slot] ? 1 : 0
```

Zero product: returns complete for `slotFloat >= 0`. Action sibling returns `1.0` for denom 0. Server `MissionPatrolProgress.NeededCount` may normalize Laps/targets differently — do not assume server mirrors zero-product Eval.

---

## 4. Residual disposition

| Prior open | Disposition |
|---|---|
| Confirm +0x24 Laps vs weight | **Sealed High** = Laps |
| Absolute float convention | **Sealed High** |
| 0-required / 0-weight edge | **Sealed** client CF; server normalize documented |
| Runtime / bit-exact | Still open |

**Verdict:** accept-with-gaps
