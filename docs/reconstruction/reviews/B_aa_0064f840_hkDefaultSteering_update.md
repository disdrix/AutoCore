# Review B (skeptical / adversarial): `aa_0064f840` hkDefaultSteering_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064f840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064f840_hkDefaultSteering_update.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is stage-1 entity+0x618 ramp | Falsified — applyAction owns stage-1 |
| 2 | Ignores doesWheelSteer bits | Falsified — flag loop |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wheel steer flags | High | Rear steer wrong |
| Input scale path | High | Oversteer |

---

## 3. Cross-check against raw

```
steer.update:
  angle = input * max; for i in wheels: out[i]=flag?angle:0.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Physical wheel angles after VA command; AutoCore steering descriptor bits.
```

---

## 5. Open questions

1. Match sinVehicleFlags bits 2/3 fan-out.

**Verdict:** accept-with-gaps
