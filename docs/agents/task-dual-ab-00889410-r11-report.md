# Dual A/B report — R11-032 OWN-ONLY (`0x00889410`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-032**  
**Scope:** VA `0x00889410` (`aa_00889410`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + `get_assembly_context` + `read_memory` + `batch_decompile` (callees/siblings). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-032**.  
**Work item:** Residual dual seal — inventory-transfer `i_d_tabs_c` active-tab setter; parent score `0x0082f510`.  
**Hint retired:** `Named_CalleeOf_Client_Input_PollBoundActions_00889410` chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00889410` UI_TabsC_SetActiveTab_Inferred | **accept-with-gaps** — hybrid ABI EAX tabIndex + stack dialog/force + RET 8 / 3-tab char·ach·locker matrix / XML map / 14 xrefs sealed; product English + vtbl names + helper duals open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / stack-only-2-arg-complete / param2-as-tabIndex / 2-tab-merge / linear-pane-order / packet-builder / sole-caller / scaffold-product / mode1-fallthrough claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00889410` — sealed facts

1. **Body:** `0x00889410`–`0x008896f3` inclusive (**740 B** / `0x2E4`); terminal **`C2 08 00`**; pad `CC`.
2. **ABI:** hybrid **`__usercall`** — **EAX=tabIndex** `{0,1,2}`; stack **dialog\*** + **force**; **RET 0x8**; void. **Not** thiscall.
3. **Semantics:** **`i_d_tabs_c` dialog active-tab switch**:
   - Gate: host vtbl `+0x3d8` visible **and** (`force || tabIndex != dialog+0x530`).
   - Store active at **`dialog+0x530`**.
   - **0 char:** show `+0x50c`; hide `+0x510`,`+0x514`; select `+0x518`+vtbl`+0x94`; deselect `+0x51c`,`+0x520`.
   - **1 achievements:** show `+0x514`; hide `+0x50c`,`+0x510`; select `+0x520`+vtbl`+0x94`; deselect others; **early RET**.
   - **2 locker:** show `+0x510`; hide `+0x50c`,`+0x514`; select `+0x51c`+vtbl`+0x94`; deselect others.
4. **XML map (ctor `FUN_00889960`):**  
   `i_d_tabs_c_2d_tab_char.xml` / `…tab_locker.xml` / `…tab_achievements.xml` → slots `+0x518` / `+0x51c` / `+0x520`.
5. **Callees:** `FUN_00822cb0` (**ESI** widget, **BL** selected, stack force); `FUN_00756c90` (**EDI** widget); child vtbls `+0x3d8`/`+0x43c`/`+0x440`/`+0x4`/`+0x94`.
6. **Callers:** **14** `UNCONDITIONAL_CALL` — `FUN_00889960`, `FUN_0082f510` (class-8 case 4 → tab 0), `Client_Input_PollBoundActions` (tabs 0/1/2), residual cmd/input sites.
7. **Host global:** `DAT_00d1b874`.
8. **Name:** `UI_TabsC_SetActiveTab_Inferred` (Ghidra `FUN_00889410`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI + mode matrix sealed via `disassemble_function` + `read_memory` + call-site context (decompiler arity incomplete, not CF conflict).
10. **Partition parent** `0x0082f510` is wave score parent (class-8 OnCommand); live callers also include ctor + input poll.

### Gaps

- Product / PDB method English for dialog class and this setter.  
- Official vtbl method names (`+0x3d8`/`+0x43c`/`+0x440`/`+0x94`/`+0x4`).  
- Full C++ types.  
- Dual of residual helpers `FUN_00822cb0` / `FUN_00756c90` / ctor `FUN_00889960`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00889410_FUN_00889410.md` |
| Annotated | `docs/reconstruction/raw/aa_00889410_FUN_00889410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_TabsC_SetActiveTab_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00889410.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_PollBoundActions_00889410.cpp` |
| Function | `docs/reconstruction/functions/aa_00889410_FUN_00889410.md` |
| Function named | `docs/reconstruction/functions/aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_Window_OnCommand_Class8_Inferred  0x0082f510  [dualed parent score]
  case 4 (cmdClass==8): if DAT_00d1b874 visible → FUN_00889410(dialog, force=1) with EAX=0

FUN_00889960  i_d_tabs_c child ctor  [residual]
  builds panes/tabs from XML; ends with CALL 0x00889410 (force=1, EAX=current +0x530)

Client_Input_PollBoundActions  0x00925d60  [named residual]
  hotkey paths: EAX=0 / 1 / 2 → CALL 0x00889410 on DAT_00d1b874

FUN_00889410  UI_TabsC_SetActiveTab_Inferred  [OWN R11-032]
  ├─ FUN_00822cb0  tab-button select chrome  [residual; ESI/BL ABI]
  └─ FUN_00756c90  remove widget from group  [residual; EDI ABI]

Siblings (2-tab; do not merge):
  FUN_00888b00  DAT_00d1b870  [R11-031 residual]
  FUN_00889fb0  DAT_00d1b880  [R11-033 residual]
```

Partition host "inventory-transfer" names the **host system** (char/locker inventory UI), not a packet opcode.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00889410-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00889410` | Port as **`i_d_tabs_c` active-tab setter**. Hybrid: **EAX=tabIndex**, stack **dialog\*** + **force**, **RET 8**, void. Tabs **0=char / 1=achievements / 2=locker**. Preserve mode-1 early return; preserve ESI/BL and EDI register ABI into residual helpers. Do **not** treat as thiscall, packet builder, or 2-tab merge with `00888b00`/`00889fb0`. |
| Host | Global `DAT_00d1b874`; pair with residual ctor `00889960` and dualed parent OnCommand `0082f510` case 4. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `UI_TabsC_SetActiveTab_Inferred` @ `0x00889410` / `aa_00889410`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00889410`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + call-site context + ctor/parent evidence. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (EAX tabIndex; RET 8; register helpers).
- Odd behavior preserved: mode-1 early RET; pane index ≠ tabIndex for locker; out-of-range store-only.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
