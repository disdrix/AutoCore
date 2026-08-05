# Review B (skeptical / adversarial): `aa_004aa0f0` CVOGTerrain_StreamMapHeader

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aa0f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004aa0f0_CVOGTerrain_StreamMapHeader.md` |
| **Verdict** | **accept-with-gaps** on CF; peripheral field offsets residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Loads heightfield | **Falsified — header only** |
| 2 | Version free/any | **Falsified — writes 0x3e** |
| 3 | Finished all field offsets | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Version 62 | High | Map load fail |
| Width/Height/GridSize | High | Bad grid |
| TileSet feeds ApplyTilesetTextures | High | Wrong textures |
| Music/skybox offsets | Tentative | Audio/sky glitch |

---

## 3. Cross-check against raw

```
scope log; ver=0x3e; stream iteration/w/h/grid/tileset/flags/music/sky/cull/imports.
Clean ≡ raw field list.
```

---

## 4. Surviving contract for AutoCore

```
StreamMapHeader:
  .fam header MapVersion 62; dims + grid + tileset critical
  height/tile TGA separate (LoadMapImage)
  AutoCore map tools must emit compatible header
  pair LoadMapImage + ApplyTilesetTextures
```

---

## 5. Open questions

1. Publish full header layout doc.
2. Confirm stream direction at call sites.

**Verdict:** **accept-with-gaps** on CF; peripheral field offsets residual
