# Review A (reconstruction fidelity): `aa_00598040` VehicleAction_calcWheelTorque

| Field | Value |
|---|---|
| **Stable ID** | `aa_00598040` |
| **VA** | `0x00598040` |
| **Canonical name** | `VehicleAction_calcWheelTorque` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00598040_VehicleAction_calcWheelTorque.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

AA wheel-torque computation used instead of stock hkDefaultEngine. Consumes engine `torqueCurve2D(rpm, throttle)` factor and transmission/gear context to produce per-wheel torque for the framework. Sole meaningful torque producer paired with `buildHavokVehicleFramework` (no engine component). Body ~mid size with residual FUN_* and exact gear/rpm input field map still open.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00598040_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00598040_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleAction_calcWheelTorque.cpp` |
| Function record | `docs/reconstruction/functions/aa_00598040_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `AA torque path (no hk engine)` | High | Framework notes |
| `Calls torqueCurve2D` | High | Callee |
| `Feeds wheel torque into framework` | High | Physics graph |
| `Full gear/rpm field seal` | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| sample curve → scale by gear/context → wheel torques | Yes |
| No invent hk engine component | Yes |

---

## 5. Gaps / open

1. Seal rpm/throttle sources from driver input.
2. Document per-wheel distribution.

**Verdict:** **accept-with-gaps**
