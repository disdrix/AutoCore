# Review B (skeptical / adversarial): `aa_005fe0b0` hkDefaultAnalogDriverInput_calcReverse

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe0b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fe0b0_hkDefaultAnalogDriverInput_calcReverse.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets throttle float | Falsified — char reverse flag |
| 2 | Is calcWheelTorque | Falsified — driver input |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reverse false positive | High | Wrong gear feel |
| AA vs hk ownership | High | Dead code assumption |

---

## 3. Cross-check against raw

```
calcReverse(input, &flag): chassis/vel tests → flag.
Companion to calcStatus.
```

---

## 4. Surviving contract for AutoCore

```
Stock hk reverse bit; verify vs AutoCore AA driver path.
```

---

## 5. Open questions

1. Check if VehicleAction ticks this component.

**Verdict:** **accept-with-gaps**
