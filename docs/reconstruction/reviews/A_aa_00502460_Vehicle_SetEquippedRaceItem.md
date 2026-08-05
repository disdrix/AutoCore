# Review A (reconstruction fidelity): `aa_00502460` Vehicle_SetEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502460` |
| **VA** | `0x00502460` |
| **Canonical name** | `Vehicle_SetEquippedRaceItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00502460_Vehicle_SetEquippedRaceItem.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set vehicle race-item hardpoint **`this+0x270`**. Optional previous-out; unbind prior via vfunc **`+0x158(0)`**; type-check clonebase **`+0x38==6`** AND subtype `*(clonebase+0x3c)+0x3f4 == 0xb`; bind new; post-attach **`+0x218`**; `Vehicle_RecalcCombatPools`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00502460_Vehicle_SetEquippedRaceItem.md` (or `aa_00502460_FUN_00502460.md`) |
| Annotated | `docs/reconstruction/raw/aa_00502460_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_SetEquippedRaceItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_00502460_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Hardpoint +0x270` | High | Plate |
| `Type 6 + subtype 0xb race item` | High | Plate |
| `RecalcCombatPools after` | High | Callee |
| `vfunc bind +0x158/+0x218` | High | Plate |
| `Subtype path residual detail` | Medium | Pointer chase |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Unbind prev → store → typecheck → bind → recalc | Yes |
| No power plant path | Yes |

---

## 5. Gaps / open

1. Race item combat pool effects.
2. Unequip null path.

**Verdict:** **accept-with-gaps**
