# Review B (skeptical / adversarial): `aa_005c1940` CVOGTerrainChunker_SubmitForRendering

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c1940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c1940_CVOGTerrainChunker_SubmitForRendering.md` |
| **Verdict** | **accept-with-gaps** on CF; LOD-table residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server sector streaming | **Falsified — client submit/LOD** |
| 2 | No LOD table | **Falsified — DAT_00af3f98 6 bands** |
| 3 | Always draws every chunk | **Falsified — +0xd4 hide + dist cull** |
| 4 | Finished band thresholds sealed | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hide + LOD per chunk | High | Wrong density/cull pops |
| Camera-driven range window | High | Miss/overdraw |
| Submit vcall chain | Tentative | Missing draws |
| LOD table constants | Tentative | Wrong LOD switch dist |

---

## 3. Cross-check against raw

```
scope; cam floats; budget; LOD calculations grid set hide/LOD;
scope end; Submit chunks list vcalls FUN_0075c960 + vtbl.
Clean ≡ raw CF outline; helper residual.
```

---

## 4. Surviving contract for AutoCore

```
SubmitForRendering(chunker, sceneCtx):
  client LOD cull + submit terrain chunks
  +0xd4 hide; +0xd8 lod from DAT_00af3f98 bands
  pairs BuildVertexBuffer on dirty/max detail (FUN_005c18a0 path)
  AutoCore server: N/A
  do not use as physics stream radius
```

---

## 5. Open questions

1. Dump LOD band floats at 0xaf3f98.
2. Name FUN_005c18a0 / FUN_0075c960.
3. Map when VB rebuild triggers from submit.
4. Document chunker this layout.

**Verdict:** **accept-with-gaps** on CF; LOD-table residual
