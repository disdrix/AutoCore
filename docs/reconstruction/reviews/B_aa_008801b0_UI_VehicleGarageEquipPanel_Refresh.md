# Review B (skeptical / adversarial): `aa_008801b0` UI_VehicleGarageEquipPanel_Refresh

| Field | Value |
|---|---|
| **Stable ID** | `aa_008801b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008801b0_UI_VehicleGarageEquipPanel_Refresh.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on UI refresh role + empty/selected CF; **reject** drive-physics or inventory-mutation claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Drive-control / vehicle physics tick | **Falsified** — no steer/throttle/RB; pure UI text/bind |
| 2 | Mutates equipped hardpoints / cargo | **Falsified** — reads vehicle slots; no equip helpers |
| 3 | Network send / equip request | **Falsified** — no BitStream / opcode builders |
| 4 | Always requires selected vehicle | **Falsified** — empty path clears UI when `vehicle==0` or global null |
| 5 | Mode is boolean Garage-only | **Falsified** — explicit 0/1 string branches Vehicle vs Garage |
| 6 | Same as `Client_RecvInventoryEquip` body | **Falsified** — equip applies; this only refreshes UI after |
| 7 | Scaffold name `Drive_Vehicle_*` is accurate | **Falsified** — string "Vehicle" ≠ drive system |
| 8 | Ready for bit-exact seal | **Fail** — runtime/diff open; decompiler widget-ptr glitches |

---

## 2. Decisive dataflow (SEALED)

```
dialog = stack arg
FUN_007a69d0()                         // UI frame / time context
if !dialog->IsVisible(+0x3d8): return

if dialog.selectedVehicle==0 || DAT_00d1b6d8==0:
  set title "Vehicle/Garage - \"No Vehicle Selected\""
  clear/hide all hardpoint + companion widgets
  goto trailing-status path
else:
  title = Localize(Vehicle|Garage) + " - \"" + vehicle.name(+0x1b0) + "\""
  for each hardpoint widget pair:
    bind to vehicle slot occupant (or empty placeholder)
    update labels (kit/mount size)
  update bars / race icon widgets
```

Live decompile ≡ raw. Entry bytes seal large frame (`sub esp,0x108`) and visibility call.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI-only refresh | **High** | Porting equip into wrong layer |
| Empty vs selected | **High** | Stuck "No Vehicle Selected" / ghost widgets |
| Hardpoint offset map | **High** | Wrong icon after equip |
| Widget vfunc ordinals | **Probable** | Wrong show/hide |
| Decompiler empty-path hide targets for some companions | **Low-Med** | May hide wrong widgets if taken literally |
| Runtime | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `param_1[0x145]` is character not vehicle | Compatible? | **No** — name @ `+0x1b0` + hardpoint array `+0x260` is vehicle layout |
| Clears inventory cargo | Hidden? | **No** — no grid Place/Find calls |
| Mode `+0x510` is inventoryType | Compatible? | **No** — only Vehicle/Garage string select |
| Must run on server | Hidden? | **No** — client UI strings + vfuncs |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `Client_RecvInventoryEquip` `0x00813f40` | Calls this on `client+0x1078` and `+0x104c` after local equip |
| `Client_RecvInventoryUnequipNotify` `0x00813bf0` | Calls this + `vtable+0x34c` redraw |
| `Vehicle_EquipPowerPlant` / AttachWeapon / etc. | **Data source** for hardpoint widgets — not callees here |
| `FUN_008c2940` / `FUN_008c3120` | Sibling inventory-sheet cursor helpers on equip path |

---

## 6. Verdict

**accept-with-gaps.** Role as Vehicle/Garage equip-panel refresh is **sealed** by strings, caller context, and hardpoint bind map. Do **not** treat as drive or equip logic. Decompiler glitches on a few empty-path hide targets and full widget taxonomy remain open.
