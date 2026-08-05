# Review A (reconstruction fidelity): `aa_00598320` VehicleAction_airStabilization

| Field | Value |
|---|---|
| **Stable ID** | `aa_00598320` |
| **VA** | `0x00598320` |
| **Canonical name** | `VehicleAction_airStabilization` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00598320_VehicleAction_airStabilization.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Air-stabilization / airborne attitude correction path on VehicleAction (large body). Distinct from continuous handbrake flag (`SetHandbrake` +0x61c) — air-stab is physics action-side when airborne / brake-edge paths fire. Residual: exact trigger conditions, torque/impulse formulas, and interaction with chassis angular damper. Medium-high value for drive feel parity.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00598320_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00598320_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleAction_airStabilization.cpp` |
| Function record | `docs/reconstruction/functions/aa_00598320_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Airborne stabilization action path` | High | Name + physics family |
| `Distinct from HB +0x61c store` | High | Drive-control docs |
| `Large CF with residual math` | High | Body size |
| `Exact trigger / impulse seal` | Medium | Open |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| airborne gate → apply stab forces | Yes |
| No invent HB store | Yes |

---

## 5. Gaps / open

1. Seal airborne predicate.
2. Document relationship to AngularVelocityDamper component.

**Verdict:** **accept-with-gaps**
