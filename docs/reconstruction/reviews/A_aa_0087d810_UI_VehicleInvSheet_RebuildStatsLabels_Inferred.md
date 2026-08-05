# Review A (reconstruction fidelity): `aa_0087d810` UI_VehicleInvSheet_RebuildStatsLabels_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087d810` |
| **VA** | `0x0087d810`–`0x008800ce` (**~0x28be** bytes) |
| **Canonical name** | `UI_VehicleInvSheet_RebuildStatsLabels_Inferred` |
| **Ghidra name** | `FUN_0087d810` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md` |
| **System** | `inventory-transfer` / vehicle combat-pool UI text |
| **Verdict** | **accept-with-gaps** — sheet arg, gates, empty vs full rebuild, widget slot table, sealed string roles; not bit-exact full body |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Heavy vehicle inventory sheet text/stats rebuild**: fill or clear NDUI label children from the sheet's bound vehicle/item (`sheet+0x514`) and local player combat pools (`DAT_00d1b6d8`), using locale helper `FUN_007a6de0` + `sprintf`.

**Not** a network handler. **Not** hardpoint mode recompute (that is `00862b70`). Invoked after hardpoint mode refresh (`008800e0` tail) and from other UI open paths (`FUN_00802b70`, `FUN_00802c80`).

---

## 2. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| stack arg0 | sheet* (`param_1`) | entry `mov ebp,[esp+…]` after `sub esp,0x144`; callers `push esi/call` or `push global` |
| locals | large `0x144` frame | `81 ec 44 01 00 00` |
| return | void | multiple early `return` |

```c
void UI_VehicleInvSheet_RebuildStatsLabels_Inferred(VehicleInvSheet* sheet);
```

---

## 3. Top-level control flow (sealed)

```
FUN_007a69d0()                         // locale/thread guard family
if DAT_00d1b644 == 0: return           // UI/game global
if DAT_00d1b6d8 == 0: return           // local player host
if *(sheet + 0x514) == 0:
  // EMPTY BIND: for each present label widget in +0x55c..+0x580:
  //   locale empty string + vtbl+0x1d8 clear-ish + vtbl+0x34c
  return
// FULL REBUILD: for each non-null label slot, vtbl+0x268 begin, fill text, +0x34c end
```

### 3.1 Label widget offsets on sheet (`param_1+n`)

| Off | Role (from body usage) |
|----:|---|
| `+0x514` | bound vehicle/item* (gate for empty vs full) |
| `+0x55c` | name / restriction line (weapon size strings) |
| `+0x560` | (cleared in empty path; used in full path neighborhood) |
| `+0x564` | DPS / damage block ("Weapon Base", "Class Bonus", "Total Dmg:") |
| `+0x568` | secondary name line |
| `+0x56c` | tertiary name line |
| `+0x570` | another name/desc line |
| `+0x574` | power/heat readout (`Vehicle_GetPowerRegenRate`, `Vehicle_CalcHeatMaximum`, `Vehicle_GetCoolRate`, `")\\nHeat: "`) |
| `+0x578` | range / min-max helper block (`FUN_0087d690`) |
| `+0x57c` | resists block ("Resist ", damage-type names, skips `"Ice-REMOVE"`) |
| `+0x580` | size/class footer (switch on bound object `+0x714` size class 0..3) |

Empty path walks the same set with clear/hide vfuncs (`+0x1d8` + `+0x34c`).

---

## 4. Notable sealed strings / callees

| Evidence | Role |
|---|---|
| `"(Small Weapons Only)"` | size class 1 restriction |
| `"(Medium & Large Weapons Only)"` | size class 2/3 (and default branch) |
| `"Weapon Base"`, `"Class Bonus"`, `"Total Dmg: "` | DPS block |
| `")\\nHeat: "` | power/heat label |
| `"Resist "` | resist lines |
| `"Physical"` table walk; skip `"Ice-REMOVE"` | damage-type labels |
| `Vehicle_GetPowerRegenRate` `0x004f3870` | power regen display |
| `Vehicle_CalcHeatMaximum` `0x004f7360` | heat max |
| `Vehicle_GetCoolRate` `0x004f3840` | cool rate (⅓ display scale path) |
| `DAT_00a110d8` = **10.0f** (`read_memory` `00 00 20 41`) | scale factor in damage math |
| `DAT_00a1e3f0` float table | class bonus mults (**1.35, 1.15, 1.0, 1.23**, …) indexed by player byte `+0x531` |
| `DAT_00aaa664` ≈ **1e-4f** | near-1 class-bonus threshold vs `g_flOne` |
| `FUN_007a6de0` | locale string resolve |
| `FUN_00514050` | text post-process / measure family |
| colors `0xffbbbbbb`, `−1`, `−0xdf00e0`, `−0xdfe0` | label tint ints |

Size class byte: deep path `*(*(*(*(bound+4)+4)+0xac+bound)+0x3c)+0x714`.

---

## 5. Callers

| Parent | Site | Arg |
|---|---|---|
| `FUN_008800e0` | `0x008801a3` | `push esi` sheet |
| `FUN_00802b70` | `0x00802c58` | `push [DAT_00d1b8b8]` |
| `FUN_00802c80` | `0x00802d7c` | sibling open path |

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| Sheet stack arg + large frame | **Confirmed** |
| Gates `d1b644` / `d1b6d8` / `+0x514` | **Confirmed** |
| Empty clears vs full fills label slots | **High** |
| Widget offset table `+0x55c..+0x580` | **Confirmed** presence |
| Power/heat/resist/DPS string roles | **High** |
| Full per-line numeric formulas bit-exact | **Open** (decompiler noise on unaff regs / stack) |
| Product window class name | **Open** |

---

## 7. Gaps

1. Bit-exact clean of entire ~10KB body (decompiler stack aliasing).
2. Complete localization key catalog.
3. Exact mapping of each `+0x55c..` child to XML control id.
4. Full damage formula with all short fields at bound `+0x124..+0x13a`.
5. Runtime / differential open.

**Verdict:** **accept-with-gaps** — architecture + gates + widget map + string roles sealed; formulas residual.
