# Review B (skeptical / adversarial): `aa_0064cf20` hkVehicleFramework_preUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064cf20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064cf20_hkVehicleFramework_preUpdate.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes throttle into wheel+0x20 | Falsified — contact hardpoint |
| 2 | Is postTick force apply | Falsified — preUpdate only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hardpoint offsets | High | Torque curve wrong args |
| Order before children | High | Stale geometry |

---

## 3. Cross-check against raw

```
preUpdate(fw, dt):
  for wheels: contact hardpoint @ +0x20..+0x2c; spin +0x8c.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Must run before suspension/steer/torque consumers each substep.
```

---

## 5. Open questions

1. Unit-test hardpoint vs chassis pose.

**Verdict:** accept-with-gaps
