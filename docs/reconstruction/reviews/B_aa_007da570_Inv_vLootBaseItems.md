# Review B (skeptical / adversarial): `aa_007da570` Inv_vLootBaseItems

| Field | Value |
|---|---|
| **Stable ID** | `aa_007da570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007da570_Inv_vLootBaseItems.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime inventory grid | Falsified — data load |
| 2 | Is rarity table | Falsified — base items |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base item element layout | High | Wrong drop candidates |

---

## 3. Cross-check against raw

```
Inv_vLootBaseItems: load base loot item pool
Residual COM/FUN_*. Clean ≡ raw shape.
```

---

## 4. Surviving contract for AutoCore

```
Base item pool for AutoCore loot rolls.
```

---

## 5. Open questions

1. Join to GenerateLootItem candidate pick.

**Verdict:** **accept-with-gaps**
