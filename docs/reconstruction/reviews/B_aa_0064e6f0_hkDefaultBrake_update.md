# Review B (skeptical / adversarial): `aa_0064e6f0` hkDefaultBrake_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064e6f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064e6f0_hkDefaultBrake_update.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only handbrake, no service pedal | Falsified — uses pedal +0x10 |
| 2 | Is SetHandbrake entity store | Falsified — hk component |
| 3 | Writes entity+0x61c | Falsified — brake component fields |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pedal/HB source offsets | High | No brakes |
| Lock timer | Medium | Skid lock feel |
| AA interaction | High | Double brake / none |

---

## 3. Cross-check against raw

```
hkDefaultBrake_update(br, {dt,…}):
  pedal/HB from status; per-wheel torque+lock; timer.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Stock service/hand brake torques in framework tick.
  Distinct from VehicleEntity_SetHandbrake (+0x61c).
```

---

## 5. Open questions

1. Live: brake pedal while AA thr on.

**Verdict:** **accept-with-gaps**
