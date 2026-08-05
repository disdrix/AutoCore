# Review A (reconstruction fidelity): `aa_007ca4e0` Inv_tLootTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ca4e0` |
| **VA** | `0x007ca4e0` |
| **Canonical name** | `Inv_tLootTable` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007ca4e0_Inv_tLootTable.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tLootTable/row` (loot table definitions). Large ~856-line DBReader with heavy `FUN_004231d0` column binds and unreachable blocks. Feeds loot generation (`Inv_GenerateLootItem*`, `CVOGLootGenerator_*`). Plate string `DBReader: %u against %s` on fail.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007ca4e0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007ca4e0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_tLootTable.cpp` |
| Function record | `docs/reconstruction/functions/aa_007ca4e0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tLootTable row loader | High | Embedded path |
| DBReader error path | High | String |
| Feeds loot generation pipeline | High | Domain |
| Full schema sealed | Medium | Large residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open/bind/read loot table rows; error logging | Yes |

---

## 5. Gaps / open

1. Seal primary key + drop list column layout.
2. Link consumers GenerateLootItem / weights / rarity.

**Verdict:** **accept-with-gaps**
