# Review A (reconstruction fidelity): `aa_005fc840` Vehicle_BuildTransmissionDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc840` |
| **VA** | `0x005fc840` |
| **Canonical name** | `Vehicle_BuildTransmissionDescriptor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fc840_Vehicle_BuildTransmissionDescriptor.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill transmission descriptor for `hkDefaultTransmission_ctor` (size **0x60**). Uses wheel count, gear ratio tables from clonebase/vehicle data (incl. fields around **+0x6d0** gear array path), entity scalar **+0x1fc**, and `FUN_005b3300` array growth. Called from `buildHavokVehicleFramework` after wheel-collide. Critical for gear-ratio / speed coupling with tail **+0x110** precompute.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fc840_Vehicle_BuildTransmissionDescriptor.md` (or `aa_005fc840_FUN_005fc840.md`) |
| Annotated | `docs/reconstruction/raw/aa_005fc840_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_BuildTransmissionDescriptor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fc840_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Transmission desc for hkDefaultTransmission` | High | Framework order |
| `Gear array from vehicle data` | High | Body +0x6d0 path |
| `entity+0x1fc scalar use` | High | Body |
| `Array grow FUN_005b3300` | High | Callee |
| `Exact gear count / reverse gear map` | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Fill gear/ratio desc → return | Yes |
| No invented thr axis | Yes |

---

## 5. Gaps / open

1. Seal full gear ratio table offsets.
2. Relation to entity+0x110 precompute.

**Verdict:** **accept-with-gaps**
