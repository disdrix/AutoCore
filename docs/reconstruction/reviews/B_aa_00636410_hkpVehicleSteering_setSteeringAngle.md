# Review B (skeptical / adversarial): `aa_00636410` hkpVehicleSteering_setSteeringAngle

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00636410_hkpVehicleSteering_setSteeringAngle.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Implements AbsoluteTopSpeed clamp | Falsified — pure store |
| 2 | Called for throttle | Falsified — mode-0x02 steer final |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x50 is steer command | High | Steer dead if wrong |
| No hidden math | High | Port overfit |

---

## 3. Cross-check against raw

```
setSteeringAngle(steerComp, angle):
  *(steerComp+0x50) = angle;
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Thin setter from applyAction VA+0x28 → steering component.
  AutoCore: map to same field as hkDefaultSteering_update input.
```

---

## 5. Open questions

1. Xref all writers of +0x50.

**Verdict:** **accept**
