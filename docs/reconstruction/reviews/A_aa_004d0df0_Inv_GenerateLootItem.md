# Review A (reconstruction fidelity): `aa_004d0df0` Inv_GenerateLootItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0df0` |
| **VA** | `0x004d0df0` |
| **Canonical name** | `Inv_GenerateLootItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d0df0_Inv_GenerateLootItem.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Runtime **GenerateLootItem (id)** path — construct/roll a loot item from an id-keyed definition. `__thiscall` ~97 lines; callees include type path helpers / `GenerateLootItem` family. Distinct from `Inv_GenerateLootItem_type` (type-keyed). Plate string `GenerateLootItem (id)`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d0df0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d0df0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_GenerateLootItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d0df0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Id-keyed loot generation entry | High | Plate string |
| Distinct from type variant | High | Sibling VA 004d0cf0 |
| Thin orchestration to helpers | High | Body size |
| Full roll algorithm sealed | Medium | Callee residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| resolve id → generate item via helpers | Yes |

---

## 5. Gaps / open

1. Seal id vs type call-site selection rules.
2. Map helper FUN_* to rarity/weight rolls.

**Verdict:** **accept-with-gaps**
