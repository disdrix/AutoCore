# Review B (skeptical / adversarial): `aa_007ce130` Inv_tLootRarity

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ce130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007ce130_Inv_tLootRarity.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime rarity roll only — no table | Falsified — table loader |
| 2 | Is tItemTemplate | Falsified — rarity table |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Rarity id map | Medium | Wrong rarity on drops |

---

## 3. Cross-check against raw

```
Inv_tLootRarity: load //tLootRarity/row
Residual COM.
```

---

## 4. Surviving contract for AutoCore

```
Loot rarity tier bring-up.
```

---

## 5. Open questions

1. Link to GenerateLootItem rarity selection.

**Verdict:** **accept-with-gaps**
