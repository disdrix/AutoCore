# Review A (reconstruction fidelity): `aa_0064dae0` hkDefaultAerodynamics_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064dae0` |
| **VA** | `0x0064dae0` |
| **Canonical name** | `hkDefaultAerodynamics_update` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064dae0_hkDefaultAerodynamics_update.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Havok child aero update (ticked from tickSubsystems). Reads framework backptr **+8**, chassis/RB, applies drag/lift from descriptor coefficients loaded via `Vehicle_BuildAerodynamicsDescriptor` (clonebase **0x59c–0x5b4**). Does **not** live inside applyAction body — applyAction only schedules via tickSubsystems. ~185-line clean; residual float pipeline.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064dae0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064dae0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAerodynamics_update.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064dae0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Child update via framework +8` | High | Body |
| `Separate from applyAction inline math` | High | 0.6-aerodynamics |
| `Uses BuildAerodynamicsDescriptor coeffs` | High | Prior dual |
| `Exact lift sign / drag formula bit-exact` | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| read state → compute aero force → apply | Yes |
| No invent stage-1 steer here | Yes |

---

## 5. Gaps / open

1. Seal formula vs 0.6-aerodynamics.md constants.

**Verdict:** accept-with-gaps
