# Review B (skeptical / adversarial): `aa_00598040` VehicleAction_calcWheelTorque

| Field | Value |
|---|---|
| **Stable ID** | `aa_00598040` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00598040_VehicleAction_calcWheelTorque.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Delegates to hkDefaultEngine | Falsified |
| 2 | Cosmetic only | Falsified — physics torque |
| 3 | Finished field map | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Torque pipeline identity | High | No drive force |
| Curve sampling | High | Wrong power curve |
| Gear scale fields | Medium | Wrong gear feel |

---

## 3. Cross-check against raw

```
rpm/thr → torqueCurve2D → gear-scale → wheel torques.
Clean outline ≡ raw; fields residual.
```

---

## 4. Surviving contract for AutoCore

```
calcWheelTorque(action, …):
  AA engine torque; pair torqueCurve2D + framework tick
  AutoCore vehicle physics critical
```

---

## 5. Open questions

1. Live-diff wheel torque samples.
2. Name residual FUN_*.

**Verdict:** **accept-with-gaps**
