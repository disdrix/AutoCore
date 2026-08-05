# Review B (skeptical / adversarial): `aa_004a9c70` CVOGTerrain_ReloadRandomTintFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a9c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004a9c70_CVOGTerrain_ReloadRandomTintFile.md` |
| **Verdict** | **accept-with-gaps** on CF; table residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Replaces height map | **Falsified — tint only** |
| 2 | No tileset in name | **Falsified — FUN_004a8fd0(+0x1c)** |
| 3 | Finished table layout | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| verttint 8px rule | High | Reject/wrong sample |
| Tileset-based filename | High | Missing file |
| Table offsets | Tentative | Bad vertex colors |

---

## 3. Cross-check against raw

```
FUN_004a8fd0(tileset); load verttint; decode into random tint tables.
Clean ≡ raw CF outline.
```

---

## 4. Surviving contract for AutoCore

```
ReloadRandomTintFile:
  random vertex tint variation (_verttint, 8px tall)
  after LoadTintMap in map load chain
  AutoCore rendering fidelity only
```

---

## 5. Open questions

1. Name FUN_004a8fd0 + table fields.
2. Confirm png dimension check in body.

**Verdict:** **accept-with-gaps** on CF; table residual
