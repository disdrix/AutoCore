# Review A (reconstruction fidelity): `aa_00862b70` UI_VehicleInvHardpoint_RecomputeMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862b70` |
| **VA** | `0x00862b70`–`0x00862bf6` |
| **Canonical name** | `UI_VehicleInvHardpoint_RecomputeMode_Inferred` |
| **Ghidra name** | `FUN_00862b70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md` |
| **System** | `inventory-transfer` (vehicle equip UI hardpoint widgets) |
| **Verdict** | **accept-with-gaps** — mode 0/1/2 at `+0x520`, gates, equip probe, redraw-on-change sealed |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Recompute **hardpoint slot widget mode** on the vehicle inventory sheet vs currently selected vehicle.

Called 10× from `UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred` (`0x008800e0`) with:

| Slot | Role |
|------|------|
| **EAX** | hardpoint slot widget* |
| **EDI** | selected vehicle* (`*(DAT_00d1b6d8+0xcd0)`), may be **null** |

```
if DAT_00d1b6d8 == 0: return
old = widget[+0x520]
if EDI == 0:
  mode = 0
else:
  // ESI becomes widget (mov esi,eax)
  // FUN_00862860(ECX=EDI vehicle) type-family gate; uses ESI=widget for vtbl+0x3cc
  if !FUN_00862860(EDI) || *(DAT_00d1b6d8+0x250)==0 || FUN_004fabc0(...) != 0:
    mode = 1
  else:
    mode = 2   // equip probe returned 0
widget[+0x520] = mode
if mode != old:
  widget.vtbl[+0x3b4]()
  widget.vtbl[+0x34c]()
```

Mode field: decompiler `in_EAX[0x148]` ≡ byte offset **`0x520`**.

---

## 2. Mode semantics (sealed numbers; English inferred)

| Mode | Condition | Inferred UI meaning |
|---:|---|---|
| **0** | no selected vehicle (`EDI==0`) | empty / disabled |
| **1** | vehicle present but type-compat fail **or** no `+0x250` context **or** `FUN_004fabc0` **non-zero** | incompatible / blocked |
| **2** | `FUN_004fabc0` returns **0** (and prior gates pass) | compatible / equippable |

`FUN_004fabc0` is vehicle equip / hardpoint attach probe (returns error codes 1,6,8,9,0xc,0xe,0xf…; **0 = ok path** for this unit's test).

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Raw/annotated/clean | `aa_00862b70_*` |
| Live decompile + asm | Ghidra `0x00862b70` |
| Parent dual | `A_aa_008800e0_UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred.md` |
| Callees | `FUN_00862860` (type-family gate), `FUN_004fabc0` (equip probe) |
| Sole function caller | `FUN_008800e0` (10 sites) |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| EAX=widget, EDI=vehicle | **Confirmed** (parent asm) |
| Gate `DAT_00d1b6d8` | **Confirmed** |
| Mode at `+0x520` values 0/1/2 | **Confirmed** |
| Redraw only on change (`+0x3b4` then `+0x34c`) | **Confirmed** |
| ESI=widget for nested `00862860` | **Confirmed** (`mov esi,eax` then call) |
| Mode English labels | **Probable** |
| Full `FUN_00862860` / `004fabc0` product matrix | **Open** (out of unit) |

---

## 5. Gaps

1. Slot product names (which of 10 hardpoints).
2. Whether mode 1 vs 2 map to greyed vs green chrome elsewhere.
3. Full equip error-code dictionary for `FUN_004fabc0`.
4. Runtime.

**Verdict:** **accept-with-gaps**.
