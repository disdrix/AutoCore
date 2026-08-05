# Review B (skeptical / adversarial): `aa_00598650` VehicleAction_applyAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00598650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00598650_VehicleAction_applyAction.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | VA+0x24 is brake float | Falsified — steer stage-1 ramp (verified) |
| 2 | speedFactor divisor is 0.6 | Falsified — DAT_00af3388 = 20.0 |
| 3 | Integrates rigid body itself | Falsified — drives framework + impulses only |
| 4 | Service brake applied here | Falsified — no brake torque; see calcWheelTorque / brake-spec |
| 5 | tickSubsystems this = VehicleAction | Falsified — ECX = framework at VA+0x40 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Order of tick vs steer vs torque | High | Wrong substep feel / sink / steer lag |
| Stage-1 offset map +0x618/+0x24/+0x1c | High | Steer input ignored |
| Mode 0x02 vs upright branch | High | Wrong turn model |
| Anti-sink minComp scan | High | Chassis buried in ground |
| Dead-boost tail constants | Medium | Boost edge wrong |

---

## 3. Cross-check against raw

```
applyAction(VA, {dt, thr}):
  early-outs; tickSubsystems(fw=VA+0x40);
  anti-sink min wheel+0xB0; stage-1 steer 0x618→VA+0x24→+0x1c;
  mode0x02 setSteeringAngle(VA+0x28) OR upright impulse;
  calcWheelTorque; airStabilization; grounded/anim/dead tail.
Clean CF ≡ verified order; residual FUN_* names.
```

---

## 4. Surviving contract for AutoCore

```
applyAction is the sole per-substep vehicle physics driver:
  AutoCore VehicleActionSim / port must preserve order and offsets
  (entity+0x618, VA+0x20/24/28/2c/30/34/3c/40/44).
```

---

## 5. Open questions

1. Live-diff stage-1 ramp rate vs client feel.
2. Confirm idle 0x77A1 gate never fires in normal drive.
3. Document interaction with server ghost pose (not this client phys path).

**Verdict:** accept-with-gaps
