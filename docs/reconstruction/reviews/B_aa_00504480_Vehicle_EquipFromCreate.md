# Review B (skeptical / adversarial): `aa_00504480` Vehicle_EquipFromCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00504480_Vehicle_EquipFromCreate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only cosmetic paint | Falsified — hardpoints |
| 2 | Runtime inventory equip only | Falsified — create nest |
| 3 | Finished all offsets | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wheel +0x45c path | High | Missing wheels on create |
| +0x2ac skip | High | Wrong cargo/special vehicles |
| Full hardpoint map | Tentative | Missing armor/weapon |

---

## 3. Cross-check against raw

```
if !special: resolve/give wheel & nested equip; SetWheelset/Armor/Weapons.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
Vehicle_EquipFromCreate(veh, createPkt, …):
  hardpoints from CreateVehicle; pair SetWheelset/Armor/PowerPlant
  AutoCore create-vehicle equip critical
```

---

## 5. Open questions

1. Seal full packet hardpoint offsets.
2. Document special +0x2ac vehicles.

**Verdict:** **accept-with-gaps**
