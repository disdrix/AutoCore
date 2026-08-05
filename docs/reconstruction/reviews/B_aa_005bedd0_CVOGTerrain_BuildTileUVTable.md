# Review B (skeptical / adversarial): `aa_005bedd0` CVOGTerrain_BuildTileUVTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bedd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005bedd0_CVOGTerrain_BuildTileUVTable.md` |
| **Verdict** | **accept-with-gaps** on CF; bit-exact residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime per-frame rebuild | **Overstated — startup LUT** |
| 2 | No rotation | **Falsified — rot LUT** |
| 3 | Finished float bit-exact | **Overstated without dump** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4096×0x80 layout | High | Bad blend seams |
| Lowest-as-base rule | High | Wrong solid tile |
| UV inset constants | High | Atlas bleeding |
| Bit-exact table | Tentative | Subpixel seams |

---

## 3. Cross-check against raw

```
for a,b,c,d in 0..7: compute stages/UV; write DAT_00b45520[idx].
Clean ≡ raw CF outline; float residual for bit-exact.
```

---

## 4. Surviving contract for AutoCore

```
BuildTileUVTable:
  global blend LUT for terrain corners
  AutoCore if rendering terrain must match LUTs/constants
  pair GetTileIndex + chunk VB build
  not needed for server sim
```

---

## 5. Open questions

1. Optional dump compare to DAT_00b45520.
2. Link TerrainChunk_BuildVertexBuffer dual later.

**Verdict:** **accept-with-gaps** on CF; bit-exact residual
