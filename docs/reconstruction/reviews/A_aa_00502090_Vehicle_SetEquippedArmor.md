# Review A (reconstruction fidelity): `aa_00502090` Vehicle_SetEquippedArmor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502090` |
| **VA** | `0x00502090` |
| **Canonical name** | `Vehicle_SetEquippedArmor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00502090_Vehicle_SetEquippedArmor.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set vehicle armor hardpoint **`this+0x254`**. Optional unbind previous; type-check clonebase **`+0x38 == 0x1c`**; bind vfunc **`+0x158`**; `Vehicle_RecalcCombatPools` (HP uses ArmorFactor). Sibling of PowerPlant (+0x268) and RaceItem (+0x270).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00502090_Vehicle_SetEquippedArmor.md` (or `aa_00502090_FUN_00502090.md`) |
| Annotated | `docs/reconstruction/raw/aa_00502090_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_SetEquippedArmor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00502090_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Hardpoint +0x254` | High | Plate |
| `Type 0x1c armor` | High | Plate |
| `RecalcCombatPools / ArmorFactor` | High | Plate |
| `vfunc +0x158 attach` | High | Plate |
| `Clonebase chase via item+4 MI` | Medium | Pointer formula |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Unbind → store → typecheck → bind → recalc | Yes |
| No wheelset path | Yes |

---

## 5. Gaps / open

1. ArmorFactor field location.
2. Notify owner chain if any.

**Verdict:** **accept-with-gaps**
