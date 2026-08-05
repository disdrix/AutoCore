# Review A (reconstruction fidelity): `aa_00504480` Vehicle_EquipFromCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504480` |
| **VA** | `0x00504480` |
| **Canonical name** | `Vehicle_EquipFromCreate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00504480_Vehicle_EquipFromCreate.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Nested hardpoint equip during CreateVehicle (**0x201D**). Reads wheel CBID at packet **`+0x45c`**, may `CVOGReaction_GiveItemByCbid` then `Vehicle_SetWheelset`; also nests weapons/armor equip helpers (`Vehicle_SetEquippedArmor`, `Vehicle_AttachWeapon`, …). Gate on vehicle special flag **`+0x2ac`**. High-value create-time equip orchestration for player/NPC vehicles.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00504480_Vehicle_EquipFromCreate.md` (or `aa_00504480_FUN_00504480.md`) |
| Annotated | `docs/reconstruction/raw/aa_00504480_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_EquipFromCreate.cpp` |
| Function record | `docs/reconstruction/functions/aa_00504480_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `CreateVehicle nest equip` | High | Plate + 0x201D |
| `Wheel CBID packet+0x45c` | High | Plate |
| `GiveItemByCbid then SetWheelset` | High | Callees |
| `Skip when +0x2ac special` | High | Body |
| `Weapons/armor nested equip` | High | Callees |
| `Full packet hardpoint table` | Medium | Partial |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Optional give → set hardpoints | Yes |
| No invented thr/steer | Yes |

---

## 5. Gaps / open

1. Complete 0x201D hardpoint offset table.
2. bKeepPreviousAttached / param_4–6 roles.

**Verdict:** **accept-with-gaps**
