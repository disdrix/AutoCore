# Review A (reconstruction fidelity): `aa_0040ba20` Combat_rlWeaponHeatMultiplier

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ba20` |
| **VA** | `0x0040ba20` |
| **Canonical name** | `Combat_rlWeaponHeatMultiplier` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040ba20_Combat_rlWeaponHeatMultiplier.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Map **insert/manage** path for `rlWeaponHeatMultiplier` keyed table (plate strings `rlWeaponHeatMultiplier`, `map/set<T> too long`). `__thiscall` ~226 lines with tree insert helpers `FUN_0040be60` / `FUN_0040bec0` / `FUN_0040bf20`. Not the fire-heat apply path (`Weapon_ApplyShotHeatAndPowerCost`); this is the **multiplier table** structure manager.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040ba20_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0040ba20_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Combat_rlWeaponHeatMultiplier.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040ba20_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| rlWeaponHeatMultiplier map ops | High | Embedded string |
| Tree insert helpers | High | Callees |
| map/set too long throw path | High | String |
| Not Weapon_ApplyShotHeatAndPowerCost | High | Distinct VA/role |
| Value type / key layout sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| insert/lookup heat mult entries; throw if map too long | Yes |

---

## 5. Gaps / open

1. Seal key (weapon/group?) and float multiplier field.
2. Find consumers in heat apply / weapon fire.

**Verdict:** **accept-with-gaps**
