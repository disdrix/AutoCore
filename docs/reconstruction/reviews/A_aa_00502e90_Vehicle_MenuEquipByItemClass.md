# Review A (reconstruction fidelity): `aa_00502e90` Vehicle_MenuEquipByItemClass

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502e90` |
| **VA** | `0x00502e90` |
| **Canonical name** | `Vehicle_MenuEquipByItemClass` (**INFERRED**) |
| **Aliases** | `FUN_00502e90`, `Inv_menu_equip_powerplant` (string family) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00502e90_Vehicle_MenuEquipByItemClass.md` |
| **System** | `inventory-transfer` (local equip / menu path) |
| **Evidence pass** | Live Ghidra full decompile; callees dual-mapped hardpoint helpers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Local / menu equip dispatcher** on vehicle: switch on item clonebase type `*(item_clonebase+0x38)` and call the matching hardpoint helper + UI SFX + optional net dirty bits + graphics show.

Entry:

1. Null item → return 0.
2. `vehicle[+0x1d5] |= 4` (equip-dirty / mode flag).
3. Clonebase via `item + 0x2a*4` MI chase (`param_2 + 0x2a`).
4. `bLocalGfx = (vehicle[+0x4e] != 0)` gates extra vfunc `+0x100` show path.
5. **switch (type)**:

| Type | Sound key | Net mask (if ghost) | Helper |
|---:|---|---|---|
| **6** | `menu_equip_item` | sub10 → mask `0x40` | sub **10** → `Vehicle_SetEquippedOrnament` (`0x004fe620`); sub **0xb** → `Vehicle_SetEquippedRaceItem`; else 0 |
| **10** | `menu_equip_powerplant` | — | `Vehicle_EquipPowerPlant` → prev in local |
| **0xc** | `menu_equip_weapon` | melee `0x20` / slot bits `4/8/0x10` | subtype 9 → melee `0x004fe800`; else flag `+0x536` → `Vehicle_EquipWeaponSlot` slots 0/1/2 |
| **0x10** | `menu_equip_wheelset` | mask `1` | `Vehicle_EquipWheelset` (`0x004ff510`) |
| **0x1c** | `menu_equip_armor` | mask `0x40000000` (arg order) | `Vehicle_EquipArmor` (`0x00502180`) |
| default | — | — | return 0 |

Post: many arms RTTI-cast to graphics, scale/show (`vfunc 0 / +0x20 / +0x18`), optional `+0x100`; return previous-item graphics base or 0.

Primary local caller: `Client_RecvInventoryEquip` after cargo/hand resolve; also UI equip paths.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00502e90_FUN_00502e90.md` |
| Annotated | `docs/reconstruction/raw/aa_00502e90_FUN_00502e90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00502e90.cpp` |
| Function record | `docs/reconstruction/functions/aa_00502e90_FUN_00502e90.md` |
| Class map | `docs/reconstruction/systems/inventory-transfer.md` |
| Counterpart B | `reviews/B_aa_00502e90_Vehicle_MenuEquipByItemClass.md` |

---

## 3. Signature

```c
// __thiscall ECX = vehicle
void * Vehicle_MenuEquipByItemClass(
    void *vehicle,
    void *item);   // CVOGClonedObjectBase* (non-null required)
// returns previous equip graphics base* or null (arm-dependent)
```

### Control flow seal (high level)

| Stage | Match | Confidence |
|---|---|---|
| Null item → 0 | **Yes** | **High** |
| Flag `+0x1d5 \|= 4` | **Yes** | **High** |
| Switch on clonebase `+0x38` | **Yes** | **High** |
| Type→helper map matches Recv class map | **Yes** | **High** |
| Named UI sound strings | **Confirmed** | plate family |
| NetObject_SetMaskBits dirty | **Yes** | **Medium** mask semantics |
| RTTI casts to typed equip objects | **Yes** | **High** symbols |
| Full return-value matrix every arm | **Medium** | decompiler `unaff_retaddr` noise on type-6 tail |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Local equip hub for hardpoint classes | **High** | callers + switch |
| Helper mapping 6/10/0xc/0x10/0x1c | **High** | sealed callees |
| Weapon slot flags at blob `+0x536` | **High** CF | bits 2/0x10/4 → slots 0/1/2 |
| Melee subtype 9 via short `+0x3f4` | **High** | matches melee helper |
| Race item subtype 0xb | **High** CF | calls named SetEquippedRaceItem |
| Product English for `+0x1d5` bit 2 | **Tentative** | only seen as \|=4 |
| Every return edge exact | **Medium** | type-6 complex / decompiler residue |

---

## 5. Gaps / open

1. Exact product name (Menu vs LocalEquip vs ApplyItemToHardpoint).
2. Type-6 return path (`unaff_retaddr`) — re-seal with image if porting return value.
3. Net mask bit dictionary beyond equip dirty.

**Verdict:** **accept-with-gaps**
