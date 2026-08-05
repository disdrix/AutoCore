# Review A (reconstruction fidelity): `aa_00933650` Inv_ValidateEquippedClonebaseSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933650` |
| **VA** | `0x00933650` |
| **Canonical name** | `Inv_ValidateEquippedClonebaseSlots` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00933650_Inv_ValidateEquippedClonebaseSlots.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Validate equipped clonebase IDs across character equip slots. For each slot (Character body, Front/Turret/Drop Weapon, PowerPlant, Armor, Wheelset, Race item, Melee, Ornament, Trailer, Trailer Wheelset): if cbid ∉ {0, 0xFFFFFFFF}, `CNDHash_LookupByKey` on clonebase table (`*(char+0xd30)+0xf10`) and require expected type code at clonebase `+0x38` (e.g. Character **0x14**, weapon families **0xe**, …). Mismatch logs `Invalid clonebase ID (%d) for %s` via `FUN_007a4480`. Register `unaff_ESI` = equip blob; weapon slots cluster `+0x180/+0x184/+0x188`. Debug/integrity — not equip mutation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00933650_Inv_ValidateEquippedClonebaseSlots.md` (or `aa_00933650_FUN_00933650.md`) |
| Annotated | `docs/reconstruction/raw/aa_00933650_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_ValidateEquippedClonebaseSlots.cpp` |
| Function record | `docs/reconstruction/functions/aa_00933650_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Slot walk with expected type codes` | High | Strings + +0x38 checks |
| `Skip cbid 0 and 0xFFFFFFFF` | High | Empty slot |
| `Clonebase hash *(+0xd30)+0xf10` | High | Lookup path |
| `Log Invalid clonebase ID for %s` | High | String evidence |
| `Character type 0x14 at +0x38` | High | Body check |
| `Weapon type 0xe family` | High | Front weapon path |
| `No equip grant/remove` | High | Validate only |
| `unaff_ESI equip base residual` | Medium | Decomp register |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Per-slot lookup + type assert CF | Yes |
| No invented inventory ops | Yes |

---

## 5. Gaps / open

1. Full slot offset table for all 13 equip positions.
2. All expected type codes beyond Character/weapon samples.
3. Caller context (load vs debug).

**Verdict:** **accept-with-gaps**
