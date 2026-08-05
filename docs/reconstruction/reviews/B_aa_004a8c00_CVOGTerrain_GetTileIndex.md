# Review B (skeptical / adversarial): `aa_004a8c00` CVOGTerrain_GetTileIndex

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004a8c00_CVOGTerrain_GetTileIndex.md` |
| **Verdict** | **accept** (short CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns full G byte | **Falsified — &7** |
| 2 | Uses >>3 | **Falsified — opposite of SampleExplored** |
| 3 | Row-major buffer | **Falsified — height*x+y** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| &7 layer | High | Wrong atlas row |
| Shared buffer +0x3dc | High | Explore vs tile split |
| OOB 0 | High | Edge artifacts |

---

## 3. Cross-check against raw

```
if in bounds return tileBuf[h*x+y]&7 else 0.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
GetTileIndex:
  low 3 bits of G = tile layer 0..7
  pair SampleExploredAreaId (high 5) + BuildTileUVTable
  AutoCore rendering only unless server reads layer
```

---

## 5. Open questions

1. Confirm server never needs tile layer.

**Verdict:** **accept** (short CF clear)
