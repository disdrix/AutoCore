# Review A (reconstruction fidelity): `aa_0064b2b0` hkVehicleFramework_initFromDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064b2b0` |
| **VA** | `0x0064b2b0` |
| **Canonical name** | `hkVehicleFramework_initFromDescriptor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064b2b0_hkVehicleFramework_initFromDescriptor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Precomputes inertia/geometry constants from setup descriptor; called from `hkVehicleFramework_ctor`. Key stores: **fw+0x310/314/318** per-axis real inverse inertia `1/((|R|·RVInertia)·mass)` from desc vehicleData **+0x5dc..0x5e4** (raw also **+0x350..**); solver-facing inverse inertia **+0x320..** from RVSpinTorque/RVInertia ratios; per-wheel loop aggregates axle rest contact geometry into **fw+0x1fc** via FUN_006c4150 (two-pseudo-contact friction setup). ~443-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064b2b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064b2b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFramework_initFromDescriptor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064b2b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Ctor-time inertia precompute` | High | Plate + body |
| `fw+0x310 family inverse inertia` | High | Body |
| `Per-wheel axle contact aggregate → +0x1fc` | High | Plate |
| `Full mass/R field semantics sealed` | Medium | DAT residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| read desc → write fw inertia/geometry → wheel loop | Yes |
| No per-tick force apply | Yes |

---

## 5. Gaps / open

1. Seal RVInertia vs RVSpinTorque column names from clonebase.
2. Document FUN_006c4150 pseudo-contact layout.

**Verdict:** accept-with-gaps
