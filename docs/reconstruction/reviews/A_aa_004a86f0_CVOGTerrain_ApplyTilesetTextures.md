# Review A (reconstruction fidelity): `aa_004a86f0` CVOGTerrain_ApplyTilesetTextures

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a86f0` |
| **VA** | `0x004a86f0` |
| **Canonical name** | `CVOGTerrain_ApplyTilesetTextures` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004a86f0_CVOGTerrain_ApplyTilesetTextures.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Map `m_ucTileSet` byte at **terrain+0x1c** through global tileset table **`DAT_00aefb88`** (stride **0x15** dwords) to eight texture slot indices stored at **+0x364..+0x380** and resolved texture pointers **+0x344..+0x360** via `DAT_00aefb60[index]`. Unknown tileset logs and **defaults to Universal** (first/zero entry path). Client material bind after header stream.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a86f0_CVOGTerrain_ApplyTilesetTextures.md` |
| Annotated | `docs/reconstruction/raw/aa_004a86f0_CVOGTerrain_ApplyTilesetTextures.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_ApplyTilesetTextures.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a86f0_CVOGTerrain_ApplyTilesetTextures.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Read tileset id +0x1c` | **High** | Body |
| `Scan DAT_00aefb88 stride 0x15` | **High** | Loop bound 0xaf06b0 |
| `Invalid → log Universal default` | **High** | String path |
| `Eight slots +0x364.. and ptrs +0x344..` | **High** | Stores |
| `Resolve via DAT_00aefb60[texId]` | **High** | Indirection |
| `No file I/O here` | **High** | Table only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Scan + default + eight assigns | **Yes** |
| No invented I/O | **Yes** |

---

## 5. Gaps / open

1. Tileset enum names vs +0x1c values.
2. Full DAT_00aefb88 record layout.
3. Whether server needs any of this.

**Verdict:** **accept-with-gaps**
