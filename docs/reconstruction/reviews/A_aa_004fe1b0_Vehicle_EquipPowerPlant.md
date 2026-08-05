# Review A (reconstruction fidelity): `aa_004fe1b0` Vehicle_EquipPowerPlant

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe1b0` |
| **VA** | `0x004fe1b0` |
| **Canonical name** | `Vehicle_EquipPowerPlant` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fe1b0_Vehicle_EquipPowerPlant.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Swap vehicle PowerPlant hardpoint **`this+0x268`**. Optional previous-out; type-check clonebase **`+0x38 == 10`**; bind via vfunc **`+0x158`**; post-attach **`+0x218`**; copy plant TFID/COID to vehicle **`+0x620/+0x624`**; `Vehicle_CalcHeatMaximum` → MaxHeat **`+0x244`**. Core equip mutator for power plants (pairs InventoryEquip).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fe1b0_Vehicle_EquipPowerPlant.md` (or `aa_004fe1b0_FUN_004fe1b0.md`) |
| Annotated | `docs/reconstruction/raw/aa_004fe1b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_EquipPowerPlant.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fe1b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Hardpoint +0x268` | High | Plate |
| `Type code 10 power plant` | High | Plate |
| `COID to +0x620/+0x624` | High | Plate |
| `MaxHeat +0x244 via CalcHeatMaximum` | High | Plate |
| `vfunc +0x158/+0x218 bind path` | High | Plate |
| `Owner notify chain residual` | Medium | vfunc cascade |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Unbind prev → store → typecheck → bind → heat | Yes |
| No invented thr axes | Yes |

---

## 5. Gaps / open

1. Exact owner notify effects.
2. Unequip-to-null path completeness.

**Verdict:** **accept-with-gaps**
