# Review A (reconstruction fidelity): `aa_004aa0f0` CVOGTerrain_StreamMapHeader

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aa0f0` |
| **VA** | `0x004aa0f0` |
| **Canonical name** | `CVOGTerrain_StreamMapHeader` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004aa0f0_CVOGTerrain_StreamMapHeader.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bidirectional VOG stream of `.fam/.fat` **header only** (not height grid). Forces `*this=0x3e` (MapVersion **62**); streams IterationVersion, Width **+0x10**, Height **+0x14**, GridSize **+0x18**, TileSet **+0x1c**, UseRoad, Music[3], UseClouds, UseTimeOfDay, SkyboxName, CullingScale, NumImports. Scoped log `CVOGTerrain::StreamMapHeader`. Height/tile images loaded elsewhere.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004aa0f0_CVOGTerrain_StreamMapHeader.md` |
| Annotated | `docs/reconstruction/raw/aa_004aa0f0_CVOGTerrain_StreamMapHeader.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_StreamMapHeader.cpp` |
| Function record | `docs/reconstruction/functions/aa_004aa0f0_CVOGTerrain_StreamMapHeader.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `MapVersion constant 0x3e=62` | **High** | Store *param_1 |
| `FUN_00498740 int fields / 00498800 floats / 00498980 bools` | **High** | Stream helpers |
| `Width/Height/GridSize/TileSet offsets match plate` | **High** | +0x10..+0x1c |
| `Music array + skybox string helpers` | **High** | FUN_0079ce30/cd30 |
| `Header only — no height load` | **High** | No image callees |
| `IterationVersion increments before stream` | **High** | param_1[1]++ |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Version + field stream list | **Yes** |
| No invented height path | **Yes** |

---

## 5. Gaps / open

1. Full absolute offsets for music/skybox block.
2. Read vs write mode of VOG stream (caller).
3. Compatibility when MapVersion ≠ 62.

**Verdict:** **accept-with-gaps**
