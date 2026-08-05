# Review A (reconstruction fidelity): `aa_004ab100` CVOGTerrain_LoadTintMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ab100` |
| **VA** | `0x004ab100` |
| **Canonical name** | `CVOGTerrain_LoadTintMap` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004ab100_CVOGTerrain_LoadTintMap.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Load companion **`_tint.tga`** for map: derive path from map name (strip ext, append `_tint.tga`); open; alloc **RGBA buffer at +0x3a4** sized `width*height*4`, default fill **0xFFFFFFFF**; decode tint samples into buffer (scale/helpers). Missing file still leaves white/default buffer. Vertex color multiplier source for terrain mesh.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ab100_CVOGTerrain_LoadTintMap.md` |
| Annotated | `docs/reconstruction/raw/aa_004ab100_CVOGTerrain_LoadTintMap.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_LoadTintMap.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ab100_CVOGTerrain_LoadTintMap.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Path: strip ext + append _tint.tga` | **High** | strrchr + string |
| `Alloc +0x3a4 width*height*4` | **High** | operator_new |
| `Default fill 0xFFFFFFFF` | **High** | Loop |
| `Open via FUN_007b6a20/7250 family` | **High** | Same as map image |
| `Decode into tint buffer` | **High** | Body |
| `Called from LoadMapImage chain` | **High** | Caller |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Path + alloc + fill + decode | **Yes** |
| No height mutation | **Yes** |

---

## 5. Gaps / open

1. Exact channel mapping and float scale in decode.
2. Behavior when file missing (status vs silent white).
3. Interaction with ReloadRandomTintFile.

**Verdict:** **accept-with-gaps**
