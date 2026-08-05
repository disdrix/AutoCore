# Review A (reconstruction fidelity): `aa_004a8b90` CVOGTerrain_SampleExploredAreaId

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8b90` |
| **VA** | `0x004a8b90` |
| **Canonical name** | `CVOGTerrain_SampleExploredAreaId` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004a8b90_CVOGTerrain_SampleExploredAreaId.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Purpose

World (x,z) → explored **area id** 0..32 from terrain tile buffer. `half = gridSize(+0x18)*0.5`; `cell = (pos-half)/gridSize`; bounds vs width **+0x10** / height **+0x14**; sample `tileBuf[+0x3dc][height*cellX+cellZ] >> 3` (G high 5 bits). OOB → **0**. Low 3 bits are tile layer (GetTileIndex). Used by `Client_LocalDiscoveryTick` + explore bit system.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a8b90_CVOGTerrain_SampleExploredAreaId.md` |
| Annotated | `docs/reconstruction/raw/aa_004a8b90_CVOGTerrain_SampleExploredAreaId.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_SampleExploredAreaId.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a8b90_CVOGTerrain_SampleExploredAreaId.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `gridSize at +0x18; half via DAT_00a0f298` | **High** | 0.5 * grid |
| `cellX/Z from world via inv grid` | **High** | Body |
| `Bounds width+0x10 height+0x14` | **High** | Gate |
| `tile buffer +0x3dc column-major` | **High** | height*x+z |
| `>>3 area id (high 5 of G)` | **High** | Plate |
| `OOB returns 0` | **High** | Early |
| `Pairs GetTileIndex low 3 bits` | **High** | Same buffer |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Half origin + cells + bounds + >>3 | **Yes** |
| No invented XP | **Yes** |

---

## 5. Gaps / open

1. Confirm DAT_00a0f298 is exactly 0.5 here.
2. Area id 0 meaning (none) vs 1..32 bits.

**Verdict:** **accept**
