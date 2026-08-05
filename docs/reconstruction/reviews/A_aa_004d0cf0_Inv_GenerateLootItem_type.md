# Review A (reconstruction fidelity): `aa_004d0cf0` Inv_GenerateLootItem_type

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0cf0` |
| **VA** | `0x004d0cf0` |
| **Canonical name** | `Inv_GenerateLootItem_type` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d0cf0_Inv_GenerateLootItem_type.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Runtime **GenerateLootItem (type)** path — type-keyed loot generation sibling of id path. Plate `GenerateLootItem (type)`. Callees include `FUN_0050b6c0`, `FUN_005e0580`, `FUN_005e1030`, and `GenerateLootItem`. ~173 lines. Used when drop specification is by type/category rather than concrete id.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d0cf0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d0cf0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_GenerateLootItem_type.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d0cf0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Type-keyed generate entry | High | Plate |
| Distinct from id path 004d0df0 | High | Sibling |
| Delegates to GenerateLootItem helpers | High | Callees |
| Full type→item algorithm sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| type resolve → helper generate | Yes |

---

## 5. Gaps / open

1. Document type enum / category ids.
2. Diff CF vs id path shared tail.

**Verdict:** **accept-with-gaps**
