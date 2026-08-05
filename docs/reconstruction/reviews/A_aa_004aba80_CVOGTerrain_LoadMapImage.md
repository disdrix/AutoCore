# Review A (reconstruction fidelity): `aa_004aba80` CVOGTerrain_LoadMapImage

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aba80` |
| **VA** | `0x004aba80` |
| **Canonical name** | `CVOGTerrain_LoadMapImage` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004aba80_CVOGTerrain_LoadMapImage.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Load `<map>.tga` (32bpp BGRA). Builds path; opens image; sets width/height; alloc **tile buffer +0x3dc** (u8 per cell) and **height16 buffer +0x3e0** (u16 per cell). Per cell: `height16 = (A<<8)|B` (16-bit height; B low byte **not** noise); tile G stored (low 3 = layer, high 5 = area). Version gate `*this < 0x13` uses legacy `FUN_004a8960`. Then chains **LoadTintMap** + **ReloadRandomTintFile**. Core map image ingest for explore + mesh.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004aba80_CVOGTerrain_LoadMapImage.md` |
| Annotated | `docs/reconstruction/raw/aa_004aba80_CVOGTerrain_LoadMapImage.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_LoadMapImage.cpp` |
| Function record | `docs/reconstruction/functions/aa_004aba80_CVOGTerrain_LoadMapImage.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Path build + image open helpers` | **High** | FUN_007b6a20/7250 |
| `Alloc tile +0x3dc and height16 +0x3e0` | **High** | operator_new |
| `height16 = (alpha<<8)|B` | **High** | Plate |
| `tile byte = G channel` | **High** | Plate |
| `Legacy path version < 0x13` | **High** | Branch |
| `Calls LoadTintMap + ReloadRandomTintFile` | **High** | Tail family |
| `Return 1 on open/load failure paths` | **High** | Early returns |
| `World Y scale residual (HeightScale/256)` | **Probable** | Plate note |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Open + alloc + per-cell decode + tint chain | **Yes** |
| Matches plate height16 encoding | **Yes** |

---

## 5. Gaps / open

1. Exact HeightScale location and world Y formula.
2. param_2 char meaning.
3. Full modern vs legacy decode loops.

**Verdict:** **accept-with-gaps**
