# Review A (reconstruction fidelity): `aa_005c01e0` CVOGTerrainChunk_BuildVertexBuffer

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c01e0` |
| **VA** | `0x005c01e0` |
| **Canonical name** | `CVOGTerrainChunk_BuildVertexBuffer` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c01e0_CVOGTerrainChunk_BuildVertexBuffer.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill chunk vertex buffer (VOGTerrainChunker.cpp). `param_3` = LOD step (**1** = full detail). Calls `FUN_005bf920` then if LOD==1 allocates VB via `FUN_00414bc0`/`FUN_00414c20` (stride **0x20**, index count `(size/LOD)^2 * 6`). Per cell: four `CVOGTerrainChunk_GetCornerData` samples; **Y = height16 * (param_2+0x44)** (HeightScale/256). Four corner tile indices (3 bits each) form 12-bit combo → UV LUT at **`DAT_00b45520`** (`combo * 0x80` = 4 stages × 4 corners U then V). If all four corners share one tile, random `(rand&3)*0.125` U offset picks solid variant column (`CVOGReaction_RandomUnitScalar`). LOD>1 path writes continuous cheap UV. Blend in **NDDiffTerrainLayered2.fx**. Client mesh only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c01e0_CVOGTerrainChunk_BuildVertexBuffer.md` |
| Annotated | `docs/reconstruction/raw/aa_005c01e0_CVOGTerrainChunk_BuildVertexBuffer.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrainChunk_BuildVertexBuffer.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c01e0_CVOGTerrainChunk_BuildVertexBuffer.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `param_3 LOD step; 1 = full detail` | **High** | Branch gate |
| `FUN_005bf920 pre-pass then VB alloc path` | **High** | Entry |
| `Index/tri count (size/LOD)^2 * 6` | **High** | iVar2 math |
| `GetCornerData ×4 per cell` | **High** | Loop body |
| `Y = height16 * *(param_2+0x44)` | **High** | Plate + stores |
| `12-bit tile combo → DAT_00b45520 + combo*0x80` | **High** | Index math |
| `All-equal tiles → (rand&3)*0.125 U jitter` | **High** | RandomUnitScalar |
| `LOD>1 continuous UV far path` | **High** | Plate |
| `Sets chunk flag +0xbc bit0; +0xe8 =1 on lock` | **High** | Body |
| `Not server heightfield sim` | **High** | No gameplay callees |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Pre-pass + LOD1 VB fill vs LOD>1 path | **Yes** |
| GetCornerData + UV LUT + height scale present | **Yes** |
| No invented physics | **Yes** |

---

## 5. Gaps / open

1. Full vertex stride layout (normals at +0x14 source, color slot, stage UV offsets).
2. FUN_005bf920 / FUN_00414bc0 / FUN_00414c20 / FUN_00746520 identities.
3. LOD>1 UV formula bit-exact residual.
4. Index buffer fill path completeness vs unreachable-block warning.

**Verdict:** **accept-with-gaps**
