# Review A (reconstruction fidelity): `aa_00504f60` Vehicle_UnequipEquippedItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504f60` |
| **VA** | `0x00504f60` |
| **Canonical name** | `Vehicle_UnequipEquippedItem_Inferred` |
| **Prior names** | `FUN_00504f60`, `Inv_menu_unequip_weapon_00504f60`, `Inv_menu_unequip_item` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00504f60_Vehicle_UnequipEquippedItem_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Vehicle-local unequip detach** for an equipped item: mark dirty, class-switch on `item.clonebase+0x38`, play `menu_unequip_*` audio where applicable, clear the vehicle slot (mirror of equip helpers), and return a **COM-style item interface** pointer for hand/cursor use — or null on failure / unsupported class.

```
if item == null → null
*(vehicle+0x1d5) |= 4
switch (type = *(item[0x2a]+0x38)):  // item+0xa8 → clonebase+0x38
  6  race/ornament subtypes 10 / 0xb
  10 power plant → FUN_005034a0(1)
  0xc weapon (melee vs bitfield slots)
  0x10 wheelset → FUN_005034a0(2)
  0x1c armor → FUN_005034a0(3)
  default → null
// after clear helpers that leave out-param item:
  tear off interface via +4/+4 COM adjust; vtbl+0x1cc → vtbl+0x18(0); return iface
```

**Inverse** of local equip dispatcher class map (`FUN_00502e90` / RecvInventoryEquip dual).

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | vehicle (this) | prologue `mov esi, ecx` |
| stack0 | `Item*` equipped | `mov ecx, [esp+0xc]` after two pushes |
| EAX | returned interface / null | `xor eax,eax` early fail |
| Epilogue | `ret 4` | `c2 04 00` |

Live UnequipNotify site `0x00813cbb`:

- `ECX = *(*(client+0xe98)+0x250)` (character → vehicle)
- `push item` (resolved TFID)
- `call 0x00504f60` → `EBX=eax` then optional `vtbl+0x2ac(client+0xd34)`

Second caller `FUN_009440e0` CompletelyDestroyObject path: thiscall vehicle, item when destroy detects equip parent.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00504f60_*`, `reconstructed-exact/FUN_00504f60.cpp`, `Inv_menu_unequip_weapon_00504f60.cpp` |
| Function record | `functions/aa_00504f60_FUN_00504f60.md` |
| Live decompile | Ghidra `0x00504f60` (2026-07-29) |
| Live bytes | `read_memory` prologue: `push ebx; push esi; mov esi,ecx; … or [esi+0x1d5],4; mov eax,[ecx+0xa8]` |
| Callers | `Client_RecvInventoryUnequipNotify`, `FUN_009440e0` |
| Sibling map | dual A/B `aa_00813f40` Client_RecvInventoryEquip class table |
| Strings | `"menu_unequip_item"`, `"menu_unequip_weapon"` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null item → null | **Yes** |
| `vehicle+0x1d5 \|= 4` | **Yes** — `or byte [esi+0x1d5], 4` |
| Type from `*(item+0xa8)+0x38` (`param_2[0x2a]`) | **Yes** — `mov eax,[ecx+0xa8]; mov edx,[eax+0x38]` |
| Switch normalized (`type-6`, range check) | **Yes** — `add edx,-6; cmp edx,0x16` |
| Class 6 / subtype 10: sound + Net mask `0x40` + `FUN_004fe620` clear ornament | **Yes** |
| Class 6 / subtype 0xb: sound + `Vehicle_SetEquippedRaceItem(...,0,...)` early return iface | **Yes** |
| Class 6 other subtype → null | **Yes** |
| Class 10 / 0x10 / 0x1c → `FUN_005034a0(1/2/3)` return | **Yes** |
| Class 0xc: item `vtbl+0x1e0` then def probe `FUN_0040da70` | **Yes** |
| 0xc melee (`*(def+0x3f4)==9`): sound + mask `0x20` + `FUN_004fe800` | **Yes** |
| 0xc bits on `def+0x536`: bit2→slot0 mask4; bit0x10→slot1 mask8; bit4→slot2 mask0x10; else null | **Yes** — `FUN_004fe110(0, slot, &out)` |
| Shared post-clear COM tearoff + `vtbl+0x1cc` / `+0x18(0)` | **Yes** |
| default unsupported type → null | **Yes** |

### 4.1 Class map (unequip ↔ equip dual)

| Class | Gate | Clear helper | Net mask (when set) | Audio |
|---:|---|---|---|---|
| 6 | subtype **10** | `FUN_004fe620` (ornament) | `0x40` | `menu_unequip_item` |
| 6 | subtype **0xb** | `Vehicle_SetEquippedRaceItem` clear | — | `menu_unequip_item` |
| 10 | — | `FUN_005034a0(1)` (PP path) | — | (via helper) |
| 0xc | subtype **9** melee | `FUN_004fe800` | `0x20` | `menu_unequip_weapon` |
| 0xc | `+0x536` bit **2** | `FUN_004fe110(0,0,…)` | `4` | `menu_unequip_weapon` |
| 0xc | `+0x536` bit **0x10** | `FUN_004fe110(0,1,…)` | `8` | `menu_unequip_weapon` |
| 0xc | `+0x536` bit **4** | `FUN_004fe110(0,2,…)` | `0x10` | `menu_unequip_weapon` |
| 0x10 | — | `FUN_005034a0(2)` wheelset | — | |
| 0x1c | — | `FUN_005034a0(3)` armor | — | |

NetObject host: `*( *( *(vehicle+4)+4 ) + 0x18 + vehicle )` when non-null — same COM adjust pattern as other vehicle net masks.

---

## 5. Offsets (body-backed)

| Offset | Role |
|--------|------|
| vehicle `+0x1d5` bit **2** (`\|4`) | unequip dirty / pending flag |
| item `+0xa8` (`[0x2a]`) | clonebase* |
| clonebase `+0x38` | item class |
| clonebase `+0x3c` | def blob* |
| def `+0x3f4` | subtype (class6 short; class0xc char==9 melee) |
| def `+0x536` | weapon mount flags (bits 2 / 0x10 / 4) |

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = vehicle equipped-item detach + return iface | **High** |
| Name `Vehicle_UnequipEquippedItem_Inferred` | **Probable** (no PDB; string-backed UI) |
| Mirrors equip class map | **High** (cross dual equip) |
| `FUN_005034a0` product English | **Open** |

---

## 7. Gaps

- Formal product names for `FUN_004fe620` / `004fe800` / `004fe110` / `005034a0` (roles sealed via equip dual + strings).
- Exact meaning of `+0x1d5` bit 2 beyond “set on unequip”.
- Race subtype 0xb only on this local path (equip dual already notes race local-only).
- Runtime / bit-exact open.

---

## 8. Verdict

**accept-with-gaps** — thiscall ABI, class/subtype CF, audio, and mask map sealed. Keep `_Inferred` until PDB/helper renames.
