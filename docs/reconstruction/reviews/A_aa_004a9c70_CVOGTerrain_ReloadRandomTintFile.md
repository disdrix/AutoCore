# Review A (reconstruction fidelity): `aa_004a9c70` CVOGTerrain_ReloadRandomTintFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a9c70` |
| **VA** | `0x004a9c70` |
| **Canonical name** | `CVOGTerrain_ReloadRandomTintFile` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004a9c70_CVOGTerrain_ReloadRandomTintFile.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Load **`<map>_verttint.png`** (plate: must be **8px tall**) for random vertex tint variation. Resolves name via tileset/helper `FUN_004a8fd0(tilesetId,+path)`; image load/decode into terrain random-tint tables; validates dimensions. Complements LoadTintMap static tint. Client visual only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a9c70_CVOGTerrain_ReloadRandomTintFile.md` |
| Annotated | `docs/reconstruction/raw/aa_004a9c70_CVOGTerrain_ReloadRandomTintFile.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_ReloadRandomTintFile.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a9c70_CVOGTerrain_ReloadRandomTintFile.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Uses tileset byte +0x1c for name helper FUN_004a8fd0` | **High** | Entry |
| `Loads verttint / random tint file` | **High** | Plate + body |
| `8px height constraint (plate)` | **High** | VOGTerrain note |
| `Fills random tint tables on terrain` | **High** | Decode loops |
| `Chained after LoadMapImage` | **High** | Caller graph |
| `Client-only cosmetics` | **High** | No sim writes |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Name resolve + load + decode tables | **Yes** |
| No invented height path | **Yes** |

---

## 5. Gaps / open

1. Exact table offsets for random tint.
2. PNG vs TGA path variants.
3. Validation fail behavior.

**Verdict:** **accept-with-gaps**
