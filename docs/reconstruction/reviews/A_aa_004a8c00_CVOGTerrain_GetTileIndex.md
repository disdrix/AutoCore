# Review A (reconstruction fidelity): `aa_004a8c00` CVOGTerrain_GetTileIndex

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8c00` |
| **VA** | `0x004a8c00` |
| **Canonical name** | `CVOGTerrain_GetTileIndex` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004a8c00_CVOGTerrain_GetTileIndex.md` |
| **System** | `terrain` |
| **Verdict** | **accept** |

---

## 1. Purpose

Per-cell **tile layer** 0..7 = map TGA G channel **& 7** from buffer `+0x3dc` (column-major `height*x+y`). Bounds vs width `+0x10` / height `+0x14`. OOB → 0 (masked). Selects atlas **row** in tile2_*.dds. High 5 bits of G ignored here (area id).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a8c00_CVOGTerrain_GetTileIndex.md` |
| Annotated | `docs/reconstruction/raw/aa_004a8c00_CVOGTerrain_GetTileIndex.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_GetTileIndex.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a8c00_CVOGTerrain_GetTileIndex.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Bounds check x,y vs +0x10/+0x14` | **High** | Gate |
| `Buffer +0x3dc` | **High** | Same as explore |
| `Return byte & 7` | **High** | 0xffffff07 mask |
| `OOB → 0` | **High** | Masked return |
| `Column-major height*x+y` | **High** | Index math |
| `Atlas row not area id` | **High** | Plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Bounds + &7 sample | **Yes** |
| No invented high bits | **Yes** |

---

## 5. Gaps / open

1. Caller uses for UV/atlas only vs gameplay.

**Verdict:** **accept**
