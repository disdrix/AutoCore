# Review A (reconstruction fidelity): `aa_00810670` Inv_LootCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810670` |
| **VA** | `0x00810670` |
| **Canonical name** | `Inv_LootCredits` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00810670_Inv_LootCredits.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client/server path handling **loot credits** awards/display (plate `loot_credits`). ~347-line unit with multiple uint locals — credit amount plumbing distinct from item generate. Part of loot economy alongside item drops and GiveCredits packets.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00810670_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00810670_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_LootCredits.cpp` |
| Function record | `docs/reconstruction/functions/aa_00810670_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loot credits path (plate loot_credits) | High | String evidence |
| Distinct from item GenerateLootItem | High | Domain split |
| Full credit formula sealed | Medium | Large residual body |
| Packet vs local UI role | Medium | Needs call-site map |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| credit amount path through locals/helpers | Yes |

---

## 5. Gaps / open

1. Seal formula / packet opcode for loot credits.
2. Relate to Mission_ComputeObjectiveCredits / GiveCredits.

**Verdict:** **accept-with-gaps**
