# Review A (reconstruction fidelity): `aa_007ce130` Inv_tLootRarity

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ce130` |
| **VA** | `0x007ce130` |
| **Canonical name** | `Inv_tLootRarity` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007ce130_Inv_tLootRarity.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tLootRarity/row` — rarity tiers used in loot generation / coloring. DBReader ~349 lines. Sibling of weights/table/config.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007ce130_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007ce130_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_tLootRarity.cpp` |
| Function record | `docs/reconstruction/functions/aa_007ce130_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tLootRarity loader | High | Path family |
| Rarity tier data | High | Domain |
| Schema sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read rarity rows | Yes |

---

## 5. Gaps / open

1. Seal rarity id → display/color/weight modifiers.

**Verdict:** **accept-with-gaps**
