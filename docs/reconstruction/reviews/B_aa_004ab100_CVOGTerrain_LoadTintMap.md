# Review B (skeptical / adversarial): `aa_004ab100` CVOGTerrain_LoadTintMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ab100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004ab100_CVOGTerrain_LoadTintMap.md` |
| **Verdict** | **accept-with-gaps** on CF; decode residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes height buffer | **Falsified — +0x3a4 tint only** |
| 2 | No default fill | **Falsified — 0xFFFFFFFF** |
| 3 | Finished decode scale | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x3a4 tint buffer | High | Uninitialized colors |
| _tint.tga naming | High | Missing tints |
| Default white | High | Invisible vs washed |
| Decode formula | Tentative | Wrong tint strength |

---

## 3. Cross-check against raw

```
build _tint.tga path; alloc +0x3a4 white; open/decode if present.
Clean ≡ raw CF outline.
```

---

## 4. Surviving contract for AutoCore

```
LoadTintMap:
  optional per-map tint image → +0x3a4
  defaults opaque white if empty
  pair LoadMapImage + ReloadRandomTintFile
  client rendering
```

---

## 5. Open questions

1. Seal decode float path.
2. Missing-file status codes.

**Verdict:** **accept-with-gaps** on CF; decode residual
