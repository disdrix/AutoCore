# Review B (skeptical / adversarial): `aa_004a9750` VehicleEngine_torqueCurve2D

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a9750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004a9750_VehicleEngine_torqueCurve2D.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses stock Havok engine curve | Falsified — AA table |
| 2 | Returns raw Nm | Falsified — normalized factor |
| 3 | Finished bin edge seal | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Table layout +0x3dc/+0x344 | High | Wrong torque |
| Enabled gate | High | Always flat 1.0 or crash |
| Bin math | Medium | Gear feel wrong |

---

## 3. Cross-check against raw

```
if !enabled: 1.0; else index 2D byte table → float[byte&7].
Clean ≡ raw outline; edge clamp residual.
```

---

## 4. Surviving contract for AutoCore

```
torqueCurve2D(engine, rpm, thr) → [0..1]:
  AA engine torque; pair calcWheelTorque / buildHavokVehicleFramework
  AutoCore vehicle physics torque
```

---

## 5. Open questions

1. Unit-test disabled / OOR bins.
2. Document DAT_00a0f298=0.5 role.

**Verdict:** **accept-with-gaps**
