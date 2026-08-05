# Review A (reconstruction fidelity): `aa_006c3f90` hkVehicleFrictionSolver_circleProjection

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c3f90` |
| **VA** | `0x006c3f90` |
| **Canonical name** | `hkVehicleFrictionSolver_circleProjection` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006c3f90_hkVehicleFrictionSolver_circleProjection.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Projects/clamps a 2D friction force pair onto the unit circle when scaled magnitude would exceed **1**. Walks scale table (max 16 steps) then linear blend between under/over radii. Fields on param_1: **+0x80/+0x84** force pair rewritten; **+0x90/+0x94** input scales; **+0x98** residual; output side-channel **param_2+0x08**. `unaff_ESI` scale table is decompiler residue. ~101-line clean (refined notes).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006c3f90_*.md` |
| Annotated | `docs/reconstruction/raw/aa_006c3f90_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFrictionSolver_circleProjection.cpp` |
| Function record | `docs/reconstruction/functions/aa_006c3f90_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Unit-circle clamp of friction pair` | High | Refined clean |
| `Table walk ≤16 + blend` | High | Body |
| `Field map +0x80..+0x98` | High | Plate |
| `Scale table pointer recovery` | Medium | unaff_ESI |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if mag>1 project else residual0 | Yes |

---

## 5. Gaps / open

1. Recover scale table symbol (global vs arg).

**Verdict:** accept-with-gaps
