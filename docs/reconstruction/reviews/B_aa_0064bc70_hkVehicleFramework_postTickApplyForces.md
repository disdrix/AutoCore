# Review B (skeptical / adversarial): `aa_0064bc70` hkVehicleFramework_postTickApplyForces

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064bc70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064bc70_hkVehicleFramework_postTickApplyForces.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses transmission +0x1c as drive | Falsified — WI-MOV-004 |
| 2 | Is the AA calcWheelTorque function | Falsified — consumes its outputs |
| 3 | Runs before suspension update | Falsified — postTick after children |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| wheel+0x28 drive source | High | No propulsion |
| Order after children | High | Stale contacts |
| Large force math fidelity | Medium | Handling drift |

---

## 3. Cross-check against raw

```
postTickApplyForces(fw, dt):
  for each wheel: contact normal force + drive from wheel+0x28 → chassis.
Clean large ≡ raw CF; residual naming.
```

---

## 4. Surviving contract for AutoCore

```
Sole post-tick force applier for vehicle framework.
  AutoCore: feed wheel torques into +0x28 before this.
```

---

## 5. Open questions

1. Diff against hkVehicleFrictionSolver_solve call sites.

**Verdict:** accept-with-gaps
