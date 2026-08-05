# Review B (skeptical / adversarial): `aa_004a86f0` CVOGTerrain_ApplyTilesetTextures

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a86f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004a86f0_CVOGTerrain_ApplyTilesetTextures.md` |
| **Verdict** | **accept-with-gaps** on CF; enum residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Crashes on unknown | **Falsified — defaults Universal** |
| 2 | Loads DDS here | **Falsified — pointer table only** |
| 3 | Finished tileset enum | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Default Universal | High | Wrong biome textures |
| Eight slot map | High | Missing layer |
| Table stride 0x15 | High | OOB table read |

---

## 3. Cross-check against raw

```
scan table for +0x1c; else Universal; write 8 tex ids+ptrs.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
ApplyTilesetTextures:
  bind tileset id → 8 terrain texture slots
  unknown id → Universal (logged)
  after StreamMapHeader m_ucTileSet
  client rendering; server N/A
```

---

## 5. Open questions

1. Document tileset id enum.
2. Dump DAT_00aefb88 names if present.

**Verdict:** **accept-with-gaps** on CF; enum residual
