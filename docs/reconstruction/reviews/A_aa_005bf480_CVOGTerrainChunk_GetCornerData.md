# Review A (reconstruction fidelity): `aa_005bf480` CVOGTerrainChunk_GetCornerData

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bf480` |
| **VA** | `0x005bf480` |
| **Canonical name** | `CVOGTerrainChunk_GetCornerData` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005bf480_CVOGTerrainChunk_GetCornerData.md` |
| **System** | `terrain` |
| **Verdict** | **accept** |

---

## 1. Purpose

Sample one terrain corner for chunk VB build. Transforms local (x,y) by chunk origin `this+0xcc/+0xd0` × `DAT_00b03650` (chunk cell size), clamps to terrain dims `DAT_00bc5524+0x10/+0x14` (minus one). Writes **8-byte** out record: **u16 height16** from height buffer `terrain+0x3e0` at `(width*y+x)*2`; **u8 tileIndex** via `CVOGTerrain_GetTileIndex(x-1,y-1)` (G&7); **float packedColor** via `FUN_004a8c40(x-1,y-1)`. **Critical offset:** tile/tint sampled at **(x-1,y-1)** — tile grid is one cell offset from height-vertex grid. Client render sampling helper; not server sim.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005bf480_CVOGTerrainChunk_GetCornerData.md` |
| Annotated | `docs/reconstruction/raw/aa_005bf480_CVOGTerrainChunk_GetCornerData.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrainChunk_GetCornerData.cpp` |
| Function record | `docs/reconstruction/functions/aa_005bf480_CVOGTerrainChunk_GetCornerData.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Local→world cell: +0xcc/+0xd0 * DAT_00b03650` | **High** | Entry scale |
| `Clamp to terrain dims DAT_00bc5524 +0x10/+0x14 −1` | **High** | OOB gate |
| `height16 from terrain+0x3e0 u16 grid` | **High** | Load |
| `Tile via GetTileIndex(x-1,y-1)` | **High** | Call + plate |
| `Tint/color via FUN_004a8c40(x-1,y-1)` | **High** | Call |
| `Out record {u16 h; u8 tile; pad; float color} 8 bytes` | **High** | Plate stores |
| `Tile grid offset −1 vs height vertices` | **High** | Plate note |
| `Global terrain ptr DAT_00bc5524` | **High** | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Scale + clamp + height + tile(x-1,y-1) + tint | **Yes** |
| No invented branches | **Yes** |

---

## 5. Gaps / open

1. Identity of FUN_004a8c40 (packed vertex color/tint sample).
2. Exact pad byte between tile and float (alignment).
3. DAT_00b03650 value (cells per chunk unit).
4. Whether clamp uses max-1 only on both axes consistently at 0 edge.

**Verdict:** **accept**
