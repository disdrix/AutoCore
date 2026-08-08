# Review B (skeptical / adversarial): `aa_00888b00` UI_Cs2dTabs_SelectTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00888b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-031) |
| **Counterpart** | `reviews/A_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ABI/CF/tab map; **falsify** inventory-wire / thiscall / 3-tab / force-only claims |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Inventory transfer / grab-drop packet sender | Body has **no** C2S opcodes; only UI vcalls + two helpers | **Falsified** as inventory wire |
| 2 | `__thiscall` ECX = window | Entry `MOV EBP,[ESP+8]`; ECX loaded from EBP later for vcalls only | **Falsified** |
| 3 | `in_EAX` is decompiler garbage / unused | Call sites `XOR EAX,EAX` / `MOV EAX,1` immediately before CALL; body `MOV ESI,EAX` | **Falsified** — EAX is real formal |
| 4 | `force` alone selects tab | force only bypasses same-tab early-out; tab comes from EAX | **Falsified** |
| 5 | Three-tab selector like `FUN_00889410` | Only arms for 0 and 1; no `in_EAX==2` path | **Falsified** |
| 6 | Always expands both tabs | Active gets BL=1 + `+0x94`; inactive BL=0 + `FUN_00756c90` | **Falsified** as dual-expand |
| 7 | Decompiler `FUN_00822cb0(param_2)` is complete ABI | Disasm sets ESI + BL independently of force stack arg | **Falsified** as complete |
| 8 | Product name Confirmed | No RTTI on VA; XML family only | **Open** — keep `_Inferred` |
| 9 | Runtime Confirmed | No Launcher this pass | **Open** |
| 10 | Parent `0x0082f510` is sole caller | 10 xrefs incl. input poll, memorize success, ctor, OnCommand | **Falsified** as sole |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX tabIndex + RET 8 | **High** | Wrong call sites / stack cleanup |
| selected @ +0x534 | **High** | Wrong state field |
| tab0=R&D / tab1=Mem | **High** (XML+cmd) | Swapped UI surface |
| Panel swap CF | **High** | Wrong visibility |
| FUN_00822cb0 product role | **Tentative** | Mis-port chrome layout |
| Host class product name | **Open** | Mis-attributed UI |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

- Frozen raw 2026-07-23 CF ≡ live 2026-08-05 decompile.
- Ctor `FUN_00888e50` binds `[0x147]`→`tab_randd` cmd **0x9c43**, `[0x148]`→`tab_memorization` cmd **0x9c44**, then calls this unit — naming evidence independent of decompiler.
- Neighbor OnCommand `@0x00888c80` maps cmd **0x9c44→EAX=1**, **0x9c43→EAX=0** (force 0).
- Sibling `FUN_00889410` is a **3-way** selector on a different host (`[0x14c]`, three panels) — same pattern family, different layout; do not merge names.
- Parent dual `UI_Window_OnCommand_Class8_Inferred` case 5 already documented this VA as `DAT_00d1b870` helper — consistent.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_Cs2dTabs_SelectTab_Inferred` | **Accept INFERRED** — XML `i_d_tabs_cs_2d_*` + 2-tab select CF |
| `Named_CalleeOf_Client_Input_PollBoundActions_00888b00` | **Reject** as canonical — true but under-specific (multi-caller) |
| `Client_SendInventory*` | **Reject** — no wire |
| `UI_Window_OnCommand_Class8_Inferred` | **Reject** — parent only |
| `FUN_00888b00` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// custom ABI: EAX=tabIndex; stack(window*, force); RET 8
if !window.IsVisible(): return
if !force && tabIndex == window.selected: return
window.selected = tabIndex
if tabIndex==0: show panelR&D; hide panelMem; expand tabR&D; collapse tabMem
if tabIndex==1: hide panelR&D; show panelMem; collapse tabR&D; expand tabMem
// not an inventory transfer path; UI only
```

**Verdict:** **accept-with-gaps**.
