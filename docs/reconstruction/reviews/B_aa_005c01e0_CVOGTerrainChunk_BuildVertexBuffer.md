# Review B (skeptical / adversarial): `aa_005c01e0` CVOGTerrainChunk_BuildVertexBuffer

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c01e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c01e0_CVOGTerrainChunk_BuildVertexBuffer.md` |
| **Verdict** | **accept-with-gaps** on CF; vertex-pack residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server collision mesh builder | **Falsified — client VB / shader path** |
| 2 | No UV table link | **Falsified — DAT_00b45520 combo*0x80** |
| 3 | Always solid tile no blend | **Falsified — 4-stage UV + layered FX** |
| 4 | Finished float-bit VB dump | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| height16 * scale → Y | High | Wrong terrain height visual |
| 12-bit combo → BuildTileUVTable | High | Bad blend seams |
| Solid variant U jitter | High | Tiling artifacts |
| Full vertex packing | Tentative | GPU misalign |
| LOD continuous path | Tentative | Far pop |

---

## 3. Cross-check against raw

```
FUN_005bf920; if LOD==1 alloc VB; for each cell GetCornerData×4;
height Y; combo→b45520 UV; optional rand U; write verts; LOD>1 cheap UV path.
Clean ≡ raw CF outline; stride residual.
```

---

## 4. Surviving contract for AutoCore

```
BuildVertexBuffer(chunk, chunker/terrain, lod, ...):
  client chunk mesh; pairs BuildTileUVTable + GetCornerData
  height16*(param_2+0x44); combo*0x80 UV LUT
  solid equal-tile → (rand&3)*0.125 U column pick
  AutoCore server: N/A; rendering ports must match
  shader NDDiffTerrainLayered2.fx does blend
```

---

## 5. Open questions

1. Document vertex format offsets for port.
2. Name FUN_005bf920 / lock helpers.
3. Optional dump compare UV vs DAT_00b45520.
4. Confirm index buffer writer completeness.

**Verdict:** **accept-with-gaps** on CF; vertex-pack residual
