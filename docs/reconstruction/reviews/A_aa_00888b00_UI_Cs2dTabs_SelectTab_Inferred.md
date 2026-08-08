# Review A (reconstruction fidelity): `aa_00888b00` UI_Cs2dTabs_SelectTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00888b00` |
| **VA** | `0x00888b00` |
| **Canonical name** | `UI_Cs2dTabs_SelectTab_Inferred` |
| **Review date** | `2026-08-05` (R11-031 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` |
| **System** | inventory-transfer (UI Cs2d R&D / Memorization tabs) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Select the active tab on the client **Cs2d** dual-tab host: **0 = R&D**, **1 = Memorization**. Gate on window visibility + force/same-tab, write selected index at `+0x534`, swap content panels (`+0x510`/`+0x514`), expand/collapse tab controls (`+0x51c`/`+0x520`) via `FUN_00822cb0` + `FUN_00756c90`, and vcall `+0x94` on the newly active tab.

Parent partition: residual under dualed `UI_Window_OnCommand_Class8_Inferred` (`0x0082f510`) case-5 dialog family (`DAT_00d1b870`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x00888b00)` 2026-08-05 ≡ frozen raw CF |
| Body / epilogue | `disassemble_function` + `read_memory` 512 B; `RET 8` @ `00888c7c` |
| ABI | entry `MOV EBP,[ESP+8]`; `MOV ESI,EAX`; force via `[ESP+14]` after pushes |
| Call sites | `read_memory` at PollBoundActions / parent / memorize-success / ctor |
| Ctor strings | `FUN_00888e50` XML `i_d_tabs_cs_2d_tab_randd/memorization` + cmd **0x9c43/0x9c44** |
| Callers | 5 named + neighbor OnCommand sites (10 xrefs) |
| Raw / annotated / clean / records | R11-031 trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of `FUN_00822cb0` / `FUN_00756c90`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw CF | **Confirmed** | gate + tab0/tab1 arms |
| EAX = tabIndex; stack window+force; `RET 8` | **Confirmed** | disasm + call-site immediates |
| Not ECX thiscall | **Confirmed** | `MOV EBP,[ESP+8]` not ECX |
| selected @ `+0x534` / `[0x14d]` | **Confirmed** | `MOV [EBP+0x534],ESI` |
| panels @ `+0x510`/`+0x514` | **Confirmed** | disasm |
| tabs @ `+0x51c`/`+0x520` | **Confirmed** | disasm + ctor assign |
| tab0 show panel0 / hide panel1 | **Confirmed** | |
| tab1 reverse panel swap | **Confirmed** | |
| `FUN_00822cb0` ESI+BL expand/collapse | **Confirmed** | disasm `MOV BL,1` / `XOR BL,BL` |
| Active tab vcall `+0x94` | **Confirmed** | |
| R&D / Mem XML + cmd 0x9c43/0x9c44 | **Confirmed** | ctor `FUN_00888e50` |
| Product window class English name | **Open** | keep `_Inferred` |
| Full semantics of `FUN_00822cb0` / `00756c90` | **Open** | residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Visible gate `vtbl+0x3d8` | **Yes** |
| force \|\| tab ≠ selected | **Yes** |
| store selected | **Yes** |
| tab 0 panel show/hide | **Yes** |
| tab 1 panel show/hide | **Yes** |
| expand active / collapse inactive chrome | **Yes** (disasm; decomp incomplete on ESI/BL) |
| No inventory C2S packets | **Yes** |

### Sealed CF sketch

```
UI_Cs2dTabs_SelectTab_Inferred(window, force, tabIndex@EAX):
  if !window.IsVisible(+0x3d8): return
  if !force && tabIndex == window.selected(+0x534): return
  window.selected = tabIndex
  if tabIndex == 0:   // R&D
    Show panel0; Hide panel1
    Expand tabR&D (+0x94); Collapse tabMem
  else if tabIndex == 1: // Memorization
    Hide panel0; Show panel1
    Collapse tabR&D; Expand tabMem (+0x94)
```

---

## 5. Gaps

1. Product / RTTI name of Cs2d host class owning `DAT_00d1b870`.
2. Residual duals: `FUN_00822cb0`, `FUN_00756c90`, sibling tab selectors `00889410` / `00889fb0`.
3. Exact product meaning of vtbl `+0x94` activate tail.
4. Runtime tab-switch capture; bit-exact image.

**Verdict:** **accept-with-gaps** — ABI, offsets, tab0/1 CF, XML/cmd evidence sealed; product labels + chrome helpers residual.
