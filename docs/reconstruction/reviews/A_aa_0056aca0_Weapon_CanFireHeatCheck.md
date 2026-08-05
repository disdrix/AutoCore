# Review A (reconstruction fidelity): `aa_0056aca0` Weapon_CanFireHeatCheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056aca0` |
| **VA** | `0x0056aca0` |
| **Canonical name** | `Weapon_CanFireHeatCheck` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056aca0_Weapon_CanFireHeatCheck.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Pre-fire **heat gate**. Resolves owner character (vtbl **+0x214**) then vehicle (vtbl **+0x1dc** / char **+0x250**). Returns `vehicle.CurrentHeat(+0x150) < vehicle.MaxHeat(+0x244)`. If no vehicle, **true** (allow). Overheat (`heat >= max`) blocks all weapon fire.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056aca0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0056aca0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weapon_CanFireHeatCheck.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056aca0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Compare +0x150 < +0x244 on vehicle | High | Body |
| Vehicle via character +0x250 | High | Body |
| Null vehicle → true | High | Body |
| Does not add heat | High | Pure predicate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| resolve vehicle → compare heat < max → bool | Yes |

---

## 5. Gaps / open

1. Confirm MaxHeat source (CalcHeatMaximum / equip).
2. Pair with IsAnyWeaponFiring cool slow.

**Verdict:** **accept**
