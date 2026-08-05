# Review A (reconstruction fidelity): `aa_0064f840` hkDefaultSteering_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064f840` |
| **VA** | `0x0064f840` |
| **Canonical name** | `hkDefaultSteering_update` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064f840_hkDefaultSteering_update.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Steering child update: scales input (`*(fw+0x14)+0x14` * **this+0x24** max angle path), transforms via chassis, writes per-wheel steer angles into array **this+0x14** using **doesWheelSteer** flags at **this+0x2c** loop **this+0x30** count (zero angle if flag clear). Downstream of applyAction stage-1 / setSteeringAngle. ~91-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064f840_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064f840_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultSteering_update.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064f840_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Per-wheel angle write with doesWheelSteer mask` | High | Body |
| `Uses framework steer input path` | High | fn_0064f840 / steering-spec |
| `Called as child of tickSubsystems` | High | Order |
| `Exact inverse-speed reduction if any here vs setSteeringAngle` | Medium | Split residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| scale input → write wheel angles / zeros | Yes |

---

## 5. Gaps / open

1. Confirm maxAngle field this+0x24 vs desc builder.

**Verdict:** accept-with-gaps
