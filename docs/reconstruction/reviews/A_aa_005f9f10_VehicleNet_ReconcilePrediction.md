# Review A (reconstruction fidelity): `aa_005f9f10` VehicleNet_ReconcilePrediction

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f9f10` |
| **VA** | `0x005f9f10` |
| **Canonical name** | `VehicleNet_ReconcilePrediction` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005f9f10_VehicleNet_ReconcilePrediction.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client vehicle prediction reconcile entry (`__fastcall`). Consumes correction / replay state (pairs `TriggerReplay`, `PostCorrectionEvent`) to realign predicted vehicle pose/state with authoritative updates. Large body (~450 lines) with residual queue walk and snap-vs-blend policy open. High value for netcode parity; not ghost initial unpack (`UnpackGhostVehicle`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005f9f10_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005f9f10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleNet_ReconcilePrediction.cpp` |
| Function record | `docs/reconstruction/functions/aa_005f9f10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Prediction reconcile entry` | High | Name + net family |
| `Pairs TriggerReplay / PostCorrection` | High | Call graph |
| `Not ghost unpack` | High | Separate VA UnpackGhostVehicle |
| `Snap/blend policy residual` | Medium | Open |
| `Queue walk residual FUN_*` | Medium | Partial |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| consume correction → adjust prediction state | Yes |
| No invent full ghost unpack | Yes |

---

## 5. Gaps / open

1. Seal snap threshold vs blend.
2. Document interaction with server pose stream.

**Verdict:** **accept-with-gaps**
