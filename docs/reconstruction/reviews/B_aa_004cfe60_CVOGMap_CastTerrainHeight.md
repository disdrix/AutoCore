# Review B (skeptical / adversarial): `aa_004cfe60` CVOGMap_CastTerrainHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cfe60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004cfe60_CVOGMap_CastTerrainHeight.md` |
| **Verdict** | **accept** (CF + verified plate High) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Miss returns yStart | **Falsified — returns hfY** |
| 2 | Same as TtPhantom castRay wheels | **Falsified — map HF path** |
| 3 | No filter difference on flag | **Falsified — 5 vs 18** |
| 4 | endY = hfY exactly | **Falsified — +0.01** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Miss → hfY fallback | High | Spawn Y wrong |
| Filter 5/18 | High | Wrong collision set |
| +0.01 end epsilon | High | Surface acne |
| Null HF → 0 | High | Sea level snap |

---

## 3. Cross-check against raw

```
if !hf return 0; hfY=sample(x,z); ray yStart→hfY+0.01 filter 5|18;
cast; hit? lerp : hfY.
Clean ≡ raw ≡ verified plate.
```

---

## 4. Surviving contract for AutoCore

```
CastTerrainHeight(map, x, z, yStart, flag):
  HF sample + optional collision refine
  miss falls back to heightfield Y — always returns a Y
  filter flag matches creature local/non-local pattern
  AutoCore: spawn/snap/air-stab re-ground; NOT wheel suspension
  pair FindTerrainHeight + CreateCreature/CreateTemplateVehicle
```

---

## 5. Open questions

1. Name HF sample + cast wrappers.
2. Live capture vs map assets.
3. Publish in TYPE_REGISTRY map offsets +0xe4e0/+0xe4a4.

**Verdict:** **accept** (CF + verified plate High)
