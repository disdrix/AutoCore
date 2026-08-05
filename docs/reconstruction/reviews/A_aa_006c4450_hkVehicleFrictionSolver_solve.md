# Review A (reconstruction fidelity): `aa_006c4450` hkVehicleFrictionSolver_solve

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c4450` |
| **VA** | `0x006c4450` |
| **Canonical name** | `hkVehicleFrictionSolver_solve` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006c4450_hkVehicleFrictionSolver_solve.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Main vehicle friction solver (~1055-line clean). Takes contact/force state arrays and dt-related params; iterates contacts/wheels, builds lateral/longitudinal friction forces, calls **circleProjection**, writes results consumed by **postTickApplyForces**. Core of grounded handling feel. Large residual FUN_* / register pressure in decompile.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006c4450_*.md` |
| Annotated | `docs/reconstruction/raw/aa_006c4450_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFrictionSolver_solve.cpp` |
| Function record | `docs/reconstruction/functions/aa_006c4450_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Primary friction solve for vehicle contacts` | High | Name + size + call graph |
| `Uses circleProjection` | High | Callee |
| `Feeds postTick force path` | High | Physics graph |
| `Bit-exact iteration / pivot order` | Medium | Decomp noise |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| setup → iterate contacts → project → write forces | Yes |
| No invent AA steer ramp | Yes |

---

## 5. Gaps / open

1. Human-refine register pressure / loop bounds.
2. Map param_1..4 to framework buffers.

**Verdict:** accept-with-gaps
