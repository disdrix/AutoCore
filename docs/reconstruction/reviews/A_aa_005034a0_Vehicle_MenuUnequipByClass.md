# Review A (reconstruction fidelity): `aa_005034a0` Vehicle_MenuUnequipByClass

| Field | Value |
|---|---|
| **Stable ID** | `aa_005034a0` |
| **VA** | `0x005034a0` |
| **Canonical name** | `Vehicle_MenuUnequipByClass` |
| **Aliases** | `FUN_005034a0`, `Inv_menu_unequip_powerplant` (string family; cases 1–9) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Unequip callee residual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005034a0_Vehicle_MenuUnequipByClass.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Menu / local unequip dispatcher** keyed by **class enum** (not clonebase type). Plays `menu_unequip_*` interface audio, optionally sets NetObject mask bits, clears the vehicle equipment slot via the same helpers Equip/Unequip duals use, and returns a **COM-adjusted item interface** (or null).

Called from `Vehicle_UnequipEquippedItem` (`0x00504f60`) for powerplant / wheelset / armor (**cases 1/2/3**). Body also implements weapon slots 4–7, race item 8, ornament 9 for other menu paths.

---

## 2. Class map (body-sealed)

| Case | Audio string | Clear helper | Net mask (when host non-null) | Return path |
|---:|---|---|---|---|
| 1 | `menu_unequip_powerplant` | `Vehicle_EquipPowerPlant(veh, 0, &out, false)` | — | COM iface from out or null |
| 2 | `menu_unequip_wheelset` | `FUN_004ff510(0,&out,0)` | mask bits `(0,1)` | COM iface |
| 3 | `menu_unequip_armor` | `Vehicle_SetEquippedArmor(veh,0,0)` | mask `0x40000000` | COM from prior `veh+0x254` |
| 4 | `menu_unequip_weapon` | `FUN_004fe110(0, slot0, &out)` | mask `(0,4)` | shared weapon path |
| 5 | `menu_unequip_weapon` | `FUN_004fe110(0, slot1, &out)` | mask `(0,8)` | |
| 6 | `menu_unequip_weapon` | `FUN_004fe110(0, slot2, &out)` | mask `(0,0x10)` | |
| 7 | `menu_unequip_weapon` | `FUN_004fe800(0,&out,0)` melee | mask `(0,0x20)` | |
| 8 | `menu_unequip_item` | `Vehicle_SetEquippedRaceItem(veh,0,&out,0)` | — | |
| 9 | `menu_unequip_item` | `FUN_004fe620(0,&out,0)` ornament | mask `(0,0x40)` | |
| default | — | — | — | return prior `piVar4` (often null) |

Post-clear (when out non-null): COM tearoff `*( *(out+4)+4 ) + 4 + out`, then `vtbl+0x1cc` → `vtbl+0x18(0)`.

Audio path: `Client_GetMissionCompleteAudioTable(name,0,−1,−1,0,0,0x1e,0)` then `Client_PlayNamedInterfaceSound(...)` — same pattern every case.

---

## 3. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | vehicle (this) | `__thiscall`; equip/unequip duals |
| stack0 | class enum 1..9 | switch(param_2); callers push 1/2/3 from `00504f60` |
| **EAX** | returned interface* / null | early returns 0 |

Callers (xrefs): only `0x00504fa4`, `0x00504fb3`, `0x00504fc2` inside `Vehicle_UnequipEquippedItem` dual.

---

## 4. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_005034a0_*`, `reconstructed-exact/FUN_005034a0.cpp`, `Inv_menu_unequip_powerplant_005034a0.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw switch |
| Parent dual | `A_aa_00504f60_Vehicle_UnequipEquippedItem_Inferred` |
| Clear helpers dual | `004fe110`, `004fe800`, `004fe620`, `004ff510`, `00502180`, EquipPowerPlant |
| Unequip notify | `aa_00813bf0` uses parent `00504f60`, not this unit directly |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| switch(param_2) cases 1–9 + default | **Yes** |
| Audio table + play each case | **Yes** |
| NetObject host via COM `vehicle+4/+4/+0x18` | **Yes** |
| Case3 armor uses `veh+0x254` prior ptr | **Yes** |
| Shared COM tearoff + `+0x1cc/+0x18(0)` | **Yes** |
| default returns null-ish | **Yes** |

---

## 6. Gaps

1. Full set of **direct** callers for cases 4–9 (xrefs only show 1–3 from `00504f60`; other cases may be dead or menu-vcall indexed).
2. `NetObject_SetMaskBits` second-arg polarity / bit meanings beyond raw immediates.
3. Product names for some clear helpers (roles sealed).
4. Runtime / bit-exact open.

**Verdict:** Menu unequip class table sealed against equip dual map. **accept-with-gaps.**
