# Review B (skeptical / adversarial): `aa_004aba80` CVOGTerrain_LoadMapImage

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aba80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004aba80_CVOGTerrain_LoadMapImage.md` |
| **Verdict** | **accept-with-gaps** on CF; HeightScale residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Height is float in TGA | **Falsified — u16 (A<<8)|B** |
| 2 | B is noise only | **Falsified — low height byte** |
| 3 | No tint follow-up | **Falsified — LoadTint + ReloadRandom** |
| 4 | Finished scale formula | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| height16 encoding | High | Flat/wrong terrain |
| G → tile+area | High | Explore/tile wrong |
| Dual buffer alloc | High | OOM/null later |
| HeightScale | Tentative | Vertical scale wrong |

---

## 3. Cross-check against raw

```
open TGA; alloc tile+height; decode BGRA→height16+G; legacy if ver<0x13;
LoadTintMap; ReloadRandomTintFile.
Clean ≡ raw CF outline.
```

---

## 4. Surviving contract for AutoCore

```
LoadMapImage:
  16-bit height from A|B; G dual-use tile/area
  AutoCore map pipeline must preserve this packing
  pair SampleExploredAreaId / GetTileIndex / StreamMapHeader
  failure returns non-zero status
```

---

## 5. Open questions

1. Seal HeightScale world Y.
2. Document legacy <0x13 path.
3. Live load one .tga vs buffers.

**Verdict:** **accept-with-gaps** on CF; HeightScale residual
