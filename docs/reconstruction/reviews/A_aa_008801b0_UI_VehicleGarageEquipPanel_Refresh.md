# Review A (reconstruction fidelity): `aa_008801b0` UI_VehicleGarageEquipPanel_Refresh

| Field | Value |
|---|---|
| **Stable ID** | `aa_008801b0` |
| **VA** | `0x008801b0` |
| **Canonical name** | `UI_VehicleGarageEquipPanel_Refresh` |
| **Prior names** | `FUN_008801b0`, `Drive_Vehicle_008801b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_008801b0_UI_VehicleGarageEquipPanel_Refresh.md` |
| **System** | `inventory-transfer` (vehicle equip UI) |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Refresh a Vehicle / Garage equipment dialog** after equip/unequip or vehicle-selection changes.

1. Early-out if panel not visible (`vtable+0x3d8` → 0).
2. If no selected vehicle (`this+0x514` / `param_1[0x145]`) **or** global `DAT_00d1b6d8==0`: show **"No Vehicle Selected"** title (mode-dependent `Vehicle -` / `Garage -` prefix) and **clear/hide** hardpoint + stat widgets.
3. Else: set title from selected vehicle name (`vehicle+0x1b0`), label hardpoint widgets by mount/kit class, bind each hardpoint UI slot to the equipped occupant (or empty placeholder), update race icon / HP / power bars.

**Calling convention:** MSVC stack `param_1` = dialog/`this` pointer (`mov ebp,[esp+…]` after `sub esp,0x108`). Not a pure thiscall in the decompiler plate.

**Side effects:** UI widget text/visibility/bind only — **no** inventory mutation, **no** network send.

---

## 2. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008801b0_FUN_008801b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008801b0_FUN_008801b0.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/Drive_Vehicle_008801b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008801b0_FUN_008801b0.md` |
| Live re-decompile | Ghidra MCP `batch_decompile` @ `0x008801b0` (2026-07-29) ≡ raw CF |
| Bytes | `read_memory` entry: `81 EC 08 01 00 00` (`sub esp,0x108`); visibility call `[ebp]+0x3d8` |
| Callers | `Client_RecvInventoryEquip` (`client+0x1078`, `client+0x104c`); `Client_RecvInventoryUnequipNotify`; `Client_RefreshOpenMissionUiWindows`; `Client_OnVehicleSwitchFailure`; many UI self-calls |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Visibility gate `vtable+0x3d8` → early return | **Yes** |
| Empty path: `vehicle==0` **or** `DAT_00d1b6d8==0` | **Yes** (`param_1[0x145]`, dword compare) |
| Mode `param_1[0x144]`: 0 → `"Vehicle -"`, 1 → `"Garage -"` | **Yes** (string literals) |
| Empty title + `"No Vehicle Selected"` + clear hardpoint widgets | **Yes** |
| Selected path: localize `"Vehicle"`/`"Garage"` + append name @ `vehicle+0x1b0` | **Yes** |
| Per-hardpoint bind from vehicle slots (`+0x260` array, `+0x270` kit, `+0x26c` ornament, `+0x264` melee, `+0x268` plant, `+0x254` armor, `+0x258` wheelset, etc.) | **Yes** (body) |
| Empty occupant → placeholder text + show “empty” affordance widgets | **Yes** |
| Kit label by race subtype @ clonebase path `…+0x532` (Shield/HEART/Hazard/Internal) | **Yes** |
| Turret/front mount size labels via `…+0x714` | **Yes** |

### 3.1 Mode + selection offsets (body-backed)

| Offset (dialog) | Role | Evidence |
|---|---|---|
| `+0x510` (`[0x144]`) | Mode: 0 Vehicle / 1 Garage | string branch |
| `+0x514` (`[0x145]`) | Selected vehicle object* | empty gate; name source |
| `+0x584` (`[0x161]`) | Title label widget | set-text vfunc `+0x1d8` |
| `+0x588`…`+0x5AC` (`[0x162]`…`[0x16b]`) | Hardpoint slot widgets | bind `+0x3b0` / empty `+0x3b0(0)` |
| `+0x52C`…`+0x558` (`[0x14b]`…`[0x156]`) | Companion empty/icon widgets | show/hide vfunc `+4` |

### 3.2 Hardpoint source map (selected vehicle)

| Vehicle offset | UI pair | Role (from equip vertical) |
|---|---|---|
| `+0x260[0]` | front weapon widget | `Vehicle_AttachWeapon` slot 0 |
| `+0x260[1]` | turret widget | weapon array |
| `+0x260[2]` | third weapon | weapon array |
| `+0x270` | kit widget | internal kit |
| `+0x26c` | ornament | class 6 |
| `+0x264` | melee | class 0xc subtype 9 |
| `+0x268` | power plant | `Vehicle_EquipPowerPlant` |
| `+0x258` (600) | wheelset | `Vehicle_SetWheelset` |
| `+0x254` | armor | `Vehicle_SetEquippedArmor` |

---

## 4. Naming

| Claim | Confidence |
|---|---|
| Vehicle/Garage equipment **panel refresh** (not drive physics) | **High** — strings + widget binds |
| Canonical `UI_VehicleGarageEquipPanel_Refresh` | **Probable** (behavior); PDB unknown |
| Prior `Drive_Vehicle_008801b0` | **Misleading** — not drive-control; UI only |

---

## 5. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / large body | **High** |
| Visibility early-out | **High** |
| Empty vs selected CF | **High** (live ≡ raw) |
| Mode Vehicle/Garage | **High / Sealed** (strings) |
| Hardpoint bind map | **High** (offsets match equip vertical) |
| Widget vfunc ordinal semantics | **Probable** |
| Original symbol | **Open** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## 6. Gaps

- Full clean human-refine of ~500-line body (scaffold only)
- Exact product dialog class name (CDlg*)
- Decompiler glitch: empty path uses wrong widget ptrs for some `+0x14d`…`+0x150` hide calls (uses `+0x164`…`+0x167`) — note in B
- Runtime golden after equip/unequip
