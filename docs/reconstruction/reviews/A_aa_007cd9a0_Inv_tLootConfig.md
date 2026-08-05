# Review A (reconstruction fidelity): `aa_007cd9a0` Inv_tLootConfig

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cd9a0` |
| **VA** | `0x007cd9a0` |
| **Canonical name** | `Inv_tLootConfig` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007cd9a0_Inv_tLootConfig.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tLootConfig/row` — global/config knobs for loot generation (mode, scalars, limits). DBReader family sibling of tLootTable. ~364 lines. Distinct from per-table rows and rarity/weights tables.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007cd9a0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007cd9a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_tLootConfig.cpp` |
| Function record | `docs/reconstruction/functions/aa_007cd9a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tLootConfig loader | High | Name / plate path family |
| Config vs table separation | High | Domain |
| Full knobs sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read loot config rows | Yes |

---

## 5. Gaps / open

1. Seal config field list vs AutoCore loot settings.

**Verdict:** **accept-with-gaps**
