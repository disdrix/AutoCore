# Review A (reconstruction fidelity): `aa_007da570` Inv_vLootBaseItems

| Field | Value |
|---|---|
| **Stable ID** | `aa_007da570` |
| **VA** | `0x007da570` |
| **Canonical name** | `Inv_vLootBaseItems` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007da570_Inv_vLootBaseItems.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **vector/table loader** for `vLootBaseItems` base-item pool used by loot generation. ~455-line DBReader-style unit. Supplies candidate CBIDs/templates before rarity/weight filters.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007da570_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007da570_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_vLootBaseItems.cpp` |
| Function record | `docs/reconstruction/functions/aa_007da570_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| vLootBaseItems loader | High | Name / domain |
| Base pool for generate pipeline | High | Domain |
| Schema sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| load base item vector/table | Yes |

---

## 5. Gaps / open

1. Seal element struct (CBID, filters, level gates).

**Verdict:** **accept-with-gaps**
