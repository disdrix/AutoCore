# Review A (reconstruction fidelity): `aa_007c4920` Inv_tItemTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c4920` |
| **VA** | `0x007c4920` |
| **Canonical name** | `Inv_tItemTemplate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007c4920_Inv_tItemTemplate.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tItemTemplate/row` — core item template definitions (stats, slots, requirements). ~520-line DBReader. Foundation for inventory, equip validation, and loot instantiation beyond clonebase wad paths.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007c4920_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007c4920_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_tItemTemplate.cpp` |
| Function record | `docs/reconstruction/functions/aa_007c4920_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tItemTemplate loader | High | Path family |
| Item template foundation | High | Domain |
| Large bind cascade | High | Body size |
| Full schema sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read item template rows | Yes |

---

## 5. Gaps / open

1. Seal key columns vs AutoCore item template model.
2. Relation to clonebase.wad SimpleObject fields.

**Verdict:** **accept-with-gaps**
