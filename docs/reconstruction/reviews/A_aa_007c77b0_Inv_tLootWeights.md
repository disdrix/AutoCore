# Review A (reconstruction fidelity): `aa_007c77b0` Inv_tLootWeights

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c77b0` |
| **VA** | `0x007c77b0` |
| **Canonical name** | `Inv_tLootWeights` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007c77b0_Inv_tLootWeights.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tLootWeights/row` — weight entries driving weighted random loot selection. DBReader cascade ~449 lines. Pairs with tLootTable / tLootRarity for drop rolls.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007c77b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007c77b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_tLootWeights.cpp` |
| Function record | `docs/reconstruction/functions/aa_007c77b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tLootWeights loader | High | Path family |
| Weighted selection input | High | Domain |
| Schema sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read weight rows | Yes |

---

## 5. Gaps / open

1. Seal weight column types and join keys to loot table.

**Verdict:** **accept-with-gaps**
