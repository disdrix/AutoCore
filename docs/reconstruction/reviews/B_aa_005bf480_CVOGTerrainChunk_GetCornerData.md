# Review B (skeptical / adversarial): `aa_005bf480` CVOGTerrainChunk_GetCornerData

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bf480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005bf480_CVOGTerrainChunk_GetCornerData.md` |
| **Verdict** | **accept** (CF clear); color helper residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Tile sampled at same (x,y) as height | **Falsified — (x-1,y-1)** |
| 2 | Returns full float height | **Falsified — u16 height16 only** |
| 3 | Server physics height authority | **Falsified — render corner pack** |
| 4 | No clamp | **Falsified — dims−1 clamp** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| height16 + tile G&7 pack | High | Wrong VB Y/blend |
| (x-1,y-1) tile offset | High | Seam / wrong tile |
| FUN_004a8c40 color semantics | Tentative | Bad vertex tint |
| DAT_00b03650 scale | Tentative | Misaligned chunk origin |

---

## 3. Cross-check against raw

```
scale x,y by chunk origin; clamp; *out=height16; tile=GetTileIndex(x-1,y-1);
color=FUN_004a8c40(x-1,y-1); return.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
GetCornerData(chunk, out, x, y):
  corner sample for BuildVertexBuffer
  height at vertex grid; tile+tint at (x-1,y-1)
  pair BuildVertexBuffer + GetTileIndex + BuildTileUVTable
  AutoCore server: N/A (client mesh); keep height16 packing notes for map load
```

---

## 5. Open questions

1. Name FUN_004a8c40 (likely SampleTint/color).
2. Publish corner record C struct.
3. Confirm DAT_00b03650 literal.

**Verdict:** **accept** (CF clear); color helper residual
