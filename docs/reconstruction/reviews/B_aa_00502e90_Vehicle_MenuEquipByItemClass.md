# Review B (skeptical / adversarial): `aa_00502e90` Vehicle_MenuEquipByItemClass

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502e90` |
| **VA** | `0x00502e90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00502e90_Vehicle_MenuEquipByItemClass.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Only equips power plant | **Falsified** | Full class switch; PP is one arm |
| 2 | Same as RecvInventoryEquip non-local switch | **Partial** | Same helpers; **this** unit also plays menu SFX + gfx show + dirty bits |
| 3 | Silent if unknown type | **Confirmed** | default → 0 |
| 4 | Always returns previous item | **Falsified** | Many arms return 0 / graphics base / complex type-6 |
| 5 | Weapon always slot 0 | **Falsified** | `+0x536` bit decode → 0/1/2 or melee |
| 6 | Decompiler return on type 6 is clean | **Attack holds** | `unaff_retaddr` residue — do not trust that edge blindly |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class → helper dispatch | **High** | Wrong hardpoint on local equip |
| SFX string keys | **High** | UI audio only |
| Net dirty masks | **Medium** | Missed replication |
| Type-6 return value | **Low–Medium** | Wrong previous destroy |
| Flag `+0x1d5\|=4` | **High** CF / open English | State machine desync |

---

## 3. Cross-check spine

```
MenuEquipByItemClass(veh, item):
  if !item: return 0
  veh[+0x1d5] |= 4
  switch item.CloneBase.type:
    6  → ornament(sub10) / race(sub0xb) + menu_equip_item
    10 → EquipPowerPlant + menu_equip_powerplant
    0xc → melee or EquipWeaponSlot(slot) + menu_equip_weapon
    0x10 → EquipWheelset + menu_equip_wheelset
    0x1c → EquipArmor + menu_equip_armor
    else → 0
  + graphics show / optional net mask
```

---

## 4. Surviving contract for AutoCore

```
Vehicle.MenuEquipByItemClass(item) -> prevGfx?
  local equip hub: type switch → sealed hardpoint helpers
  pair Client_RecvInventoryEquip local path + UI menu equip
```

Port: reuse same class map as non-local Recv; add client-only SFX/show/dirty.

---

## 5. Open questions

1. Image-seal type-6 return edges.
2. Full `+0x536` weapon flag enum.
3. Who clears `+0x1d5` bit 2.

**Verdict:** **accept-with-gaps**
