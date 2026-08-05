# Review A (reconstruction fidelity): `aa_005a8a90` Drive_CVOGVehicle_UpdateWaterFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a8a90` |
| **VA** | `0x005a8a90` |
| **Canonical name** | `Drive_CVOGVehicle_UpdateWaterFX` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005a8a90_Drive_CVOGVehicle_UpdateWaterFX.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client vehicle water FX tick (`CVOGVehicle::UpdateWaterFX`). Samples vehicle/body state and drives splash/wake visual helpers (`FUN_004b7550`, `FUN_004b8dc0`, speed SQRT/ABS paths). Not physics buoyancy authority; cosmetic water interaction for player/AI vehicles. `thiscall` with extra timing/state params.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a8a90_Drive_CVOGVehicle_UpdateWaterFX.md` (or `aa_005a8a90_FUN_005a8a90.md`) |
| Annotated | `docs/reconstruction/raw/aa_005a8a90_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CVOGVehicle_UpdateWaterFX.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a8a90_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String CVOGVehicle::UpdateWaterFX` | High | Rename |
| `Visual FX helpers called` | High | Callees |
| `Speed/height samples in body` | High | SQRT/ABS |
| `Not thr/steer writer` | High | No PushDriveAxes |
| `Client cosmetic` | High | FX only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| State sample → FX update CF preserved | Yes |
| No invented drive axes | Yes |

---

## 5. Gaps / open

1. Exact water plane source (map water vs river FX).
2. Full FUN_004b* names.

**Verdict:** **accept-with-gaps**
