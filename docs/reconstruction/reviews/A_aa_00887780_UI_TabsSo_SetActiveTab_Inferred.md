
# Review A (reconstruction fidelity): `aa_00887780` UI_TabsSo_SetActiveTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00887780` |
| **VA** | `0x00887780` |
| **Body** | `0x00887780`–`0x00887a63` inclusive (**740 B** / `0x2E4`); terminal `C2 08 00`; pad `CC` |
| **Canonical name** | `UI_TabsSo_SetActiveTab_Inferred` (**Inferred**); Ghidra `FUN_00887780` |
| **Review date** | `2026-08-05` (R13-012 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00887780_UI_TabsSo_SetActiveTab_Inferred.md` |
| **System** | inventory-transfer / `i_d_tabs_so_*` social dialog tab switch |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `get_assembly_context`, `read_memory`, `list_strings` — **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** — CF/ABI/tab matrix/XML map/9 xrefs sealed; product English + vtbl names open |
| **Dual status** | **Present (R13-012)** |

---

## 1. Purpose

Host-dialog **active-tab setter** for the client social `i_d_tabs_so` window (global `DAT_00d1b878`):

```text
gate: host visible (vtbl+0x3d8) && (force || tabIndex != dialog+0x534)
dialog+0x534 = tabIndex
switch tabIndex:
  0 friends  → show +0x50c; hide +0x510,+0x514; select +0x518; deselect +0x51c,+0x520
  1 clan     → show +0x510; hide +0x50c,+0x514; select +0x51c; deselect +0x518,+0x520
  2 enemies  → show +0x514; hide +0x50c,+0x510; select +0x520; deselect +0x518,+0x51c; RET
  else       → store only
```

**ABI:** hybrid `__usercall` — **EAX=tabIndex**, stack **dialog*** + **force**, **`RET 0x8`**, void.

**No C2S / inventory packet send** — pure client UI pane/tab chrome (same family as dualed `UI_TabsC_SetActiveTab_Inferred` `0x00889410`).

Partition parent residual: dualed `UI_Widget_MoveToFrontInParentGroup_Inferred` (`0x00756c90`) is a **live callee** (deselect path) — not a caller of this VA.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x00887780)` 2026-08-05 ≡ frozen raw CF (2026-07-23) |
| Complete analysis | `analyze_function_complete` — callers/callees/xrefs/phantom `in_EAX` |
| Body / epilogue | `get_function_by_address` + `disassemble_function` + `read_memory`; body `00887780`–`00887a63`; `RET 8` (`C2 08 00`) |
| ABI | entry `PUSH EBP; MOV EBP,[ESP+8]; PUSH ESI; MOV ESI,EAX` (`55 8B 6C 24 08 56 8B F0`) |
| Call-site context | `get_assembly_context` on all **9** xrefs |
| Ctor evidence | `disassemble_function(0x00887c70)` — XML tab strings + slot assignments + force re-apply |
| Strings | `list_strings` filter `i_d_tabs_so` |
| Dualed callees | `UI_TabChrome_SetSelected_Inferred` (`00822cb0`); `UI_Widget_MoveToFrontInParentGroup_Inferred` (`00756c90`) |
| Sibling pattern | dualed `UI_TabsC_SetActiveTab_Inferred` (`00889410`) — same hybrid ABI family; different dialog/XML |
| Scaffold | raw append + annotated/clean/function refresh R13-012 |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of residual ctor `00887c70` / other VAs.

---

## 3. Machine seal

| Claim | Evidence | Conf |
|---|---|---|
| Prolog usercall | `55 8B 6C 24 08 56 8B F0` — EBP←stack dialog, ESI←EAX tabIndex | **High** |
| Force load | `MOV EBX,[ESP+0x14]` after two more pushes = original stack force | **High** |
| Visible gate | `CALL [vtbl+0x3d8]; TEST AL,AL; JZ epilogue` | **High** |
| Same-tab skip | `TEST BL,BL; JNZ do; CMP ESI,[EBP+0x534]; JZ epilogue` | **High** |
| Store active | `MOV [EBP+0x534],ESI` | **High** |
| 3-way mode | `SUB EAX,0; JZ mode0; SUB EAX,1; JZ mode1; SUB EAX,1; JNZ epilogue` → mode2 | **High** |
| Mode2 early RET | `RET 8` @ `0x008878b3` after selecting enemies | **High** |
| Stack cleanup | all exits `C2 08 00` | **High** |
| Pane show/hide | vtbl `+0x43c`+`+0x4(1)` / `+0x4(0)`+`+0x440` per matrix | **High** |
| Tab select refresh | selected path ends `CALL [vtbl+0x94]` | **High** |
| 00822cb0 reg ABI | `MOV ESI,widget; MOV/XOR BL; PUSH force; CALL 00822cb0` | **High** |
| 00756c90 reg ABI | `MOV EDI,widget; CALL 00756c90` | **High** |
| XML tab map | ctor loads friends/clan/enemies into `+0x518/+0x51c/+0x520` | **High** |
| 9 xrefs | `get_function_xrefs` | **High** |
| Decompile ≡ raw CF | live decompile matches raw panel/tab arms | **High** |
| Entry/exit bytes | `read_memory` | **High** |
| Host global | `DAT_00d1b878` via `Client_Input_PollBoundActions` | **High** |
| Product RTTI / English | open | **Open** |
| Runtime / bit-exact | no Launcher — **never** Runtime Confirmed | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Visible gate + force/same-tab skip | **Yes** |
| Store `dialog+0x534` | **Yes** |
| Mode 0 friends show/select | **Yes** |
| Mode 1 clan show/select + shared deselect-enemies tail | **Yes** |
| Mode 2 enemies show/select + early RET | **Yes** |
| Out-of-range store-only | **Yes** |
| No inventory C2S packets | **Yes** |

### Sealed CF sketch

```
UI_TabsSo_SetActiveTab_Inferred(tabIndex@EAX, dialog@stack, force@stack):
  if !host.visible: return
  if !force && tabIndex == dialog[+0x534]: return
  dialog[+0x534] = tabIndex
  if tabIndex == 0:  // friends
    show +0x50c; hide +0x510,+0x514
    SetSelected(+0x518,1)+vtbl+0x94; SetSelected(+0x51c,0)+MoveToFront
    fall: SetSelected(+0x520,0)+MoveToFront
  elif tabIndex == 1:  // clan
    hide +0x50c; show +0x510; hide +0x514
    SetSelected(+0x518,0)+MoveToFront; SetSelected(+0x51c,1)+vtbl+0x94
    jmp shared: SetSelected(+0x520,0)+MoveToFront
  elif tabIndex == 2:  // enemies
    hide +0x50c,+0x510; show +0x514
    SetSelected(+0x518,0)+MoveToFront; SetSelected(+0x51c,0)+MoveToFront
    SetSelected(+0x520,1)+vtbl+0x94; RET 8
  else: return  // store only
```

---

## 5. Naming

| Proposed | Status |
|---|---|
| `UI_TabsSo_SetActiveTab_Inferred` | **Accept INFERRED** — `i_d_tabs_so_*` domain + 3-tab matrix + sibling TabsC pattern |
| `UI_tabs_so_tab_enemies` | **Reject as canonical** — enemies is one tab; plate is ctor alias |
| `Named_CalleeOf_Client_Input_PollBoundActions_00887780` | **Reject as product** — scaffold chain only |
| `Client_SendInventory*` / social net host | **Reject** — no wire |
| `FUN_00887780` | Keep Ghidra residual synonym |

---

## 6. Gaps

1. Product / RTTI demangle of host class / method English.
2. Official names of vtbl `+0x3d8` / `+0x43c` / `+0x440` / `+0x94` / `+0x4`.
3. Full C++ types of dialog / panes / tab buttons; content-pane XML (not loaded by this body).
4. Residual dual of ctor `FUN_00887c70` / cmd dispatcher sites (not OWN).
5. Runtime capture; bit-exact image; differential.

**Verdict:** **accept-with-gaps** — hybrid ABI, body bounds, 3-tab friends/clan/enemies matrix, XML map, 9 callers sealed statically; product labels open. Terminal **false**.
