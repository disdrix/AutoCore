# Review A (reconstruction fidelity): `aa_005bedd0` CVOGTerrain_BuildTileUVTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bedd0` |
| **VA** | `0x005bedd0` |
| **Canonical name** | `CVOGTerrain_BuildTileUVTable` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005bedd0_CVOGTerrain_BuildTileUVTable.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Startup LUT at **`DAT_00b45520`**: for every combo of 4 corner tile indices (**8^4=4096**, index `a*512+b*64+c*8+d`), compute 4 texture-stage atlas UVs per corner (**0x80 bytes**: 16 floats U + 16 floats V). Lowest tile = solid base (atlas col 4) stage 3; higher tiles alpha-blend stages 2..0. Corner-equal 4-bit mask → column LUT `0xaf3fc8` and rotation LUT `0xaf4008`. Atlas UV = `cell*0.125 + 0.0078125 + local*0.109375`. Client terrain blend — not gameplay.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005bedd0_CVOGTerrain_BuildTileUVTable.md` |
| Annotated | `docs/reconstruction/raw/aa_005bedd0_CVOGTerrain_BuildTileUVTable.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrain_BuildTileUVTable.cpp` |
| Function record | `docs/reconstruction/functions/aa_005bedd0_CVOGTerrain_BuildTileUVTable.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `4096 combos 8^4 corner indices` | **High** | Plate |
| `LUT base DAT_00b45520; entry 0x80 bytes` | **High** | Plate |
| `Index a*512+b*64+c*8+d` | **High** | Plate |
| `Lowest tile solid base stage 3` | **High** | Plate |
| `Mask→column LUT 0xaf3fc8 + rot 0xaf4008` | **High** | Plate |
| `UV cell*0.125 + 1/128 + local*0.109375` | **High** | Plate |
| `Atlas row=layer 0..7 col=pattern` | **High** | Plate |
| `No map instance this (global void)` | **High** | Signature |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Nested corner loops + LUT write | **Yes** |
| Matches annotated plate math | **Yes** |

---

## 5. Gaps / open

1. Bit-exact float dump vs retail table.
2. When table rebuilt (startup only?).
3. Chunker consumption of LUT.

**Verdict:** **accept-with-gaps**
