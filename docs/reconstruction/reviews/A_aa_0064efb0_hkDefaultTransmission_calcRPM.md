# Review A (reconstruction fidelity): `aa_0064efb0` hkDefaultTransmission_calcRPM

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064efb0` |
| **VA** | `0x0064efb0` |
| **Canonical name** | `hkDefaultTransmission_calcRPM` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064efb0_hkDefaultTransmission_calcRPM.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Computes transmission RPM from wheel spin samples (wheels array via framework). Aggregates wheel speeds (uses **wheel+0x8c** spin / related offsets) with gearing context; returns float10 RPM. Called on the transmission update path. Note: AA drive torque path uses `VehicleEngine_torqueCurve2D` from **calcWheelTorque**, not stock hkDefaultEngine — RPM still maintained for gauges/logic. ~155-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064efb0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064efb0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultTransmission_calcRPM.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064efb0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `RPM from wheel spins` | High | Body + 0.7-transmission |
| `Not the AA torque producer` | High | Architecture |
| `Exact wheel weight / driven-axle filter` | Medium | Loop residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| sample wheels → combine → return rpm | Yes |

---

## 5. Gaps / open

1. Seal driven-wheel mask vs doesWheelSteer/drive bits.

**Verdict:** accept-with-gaps
