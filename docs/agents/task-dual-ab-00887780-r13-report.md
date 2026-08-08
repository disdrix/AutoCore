# Dual A/B report — R13-012 OWN-ONLY (`0x00887780`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-012** (dual start **2686**)  
**Scope:** VA `0x00887780` (`aa_00887780`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual ctor `00887c70`, siblings R13-009/010/011).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory` + `list_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-012**.  
**System:** inventory-transfer (partition assignment; unit role is pure client UI tab switch — **no inventory wire**).  
**Parent dual:** `0x00756c90` `UI_Widget_MoveToFrontInParentGroup_Inferred` (R12-003) — **live structural callee**.  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00887780` UI_TabsSo_SetActiveTab_Inferred | **accept-with-gaps** — hybrid ABI EAX tabIndex + stack dialog/force + RET 8 / 3-tab friends·clan·enemies matrix / XML map / 9 xrefs sealed; product English + vtbl names open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / stack-only-2-arg-complete / param2-as-tabIndex / TabsC-merge / inventory-wire / sole-caller / scaffold-product / mode2-fallthrough / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00887780` — sealed facts

1. **Body:** `0x00887780`–`0x00887a63` inclusive (**740 B** / `0x2E4`); terminal **`C2 08 00`**; pad `CC`.
2. **ABI:** hybrid **`__usercall`** — **EAX=tabIndex** `{0,1,2}`; stack **dialog\*** + **force**; **RET 0x8**; void. **Not** thiscall.
3. **Semantics:** **`i_d_tabs_so` dialog active-tab switch**:
   - Gate: host vtbl `+0x3d8` visible **and** (`force || tabIndex != dialog+0x534`).
   - Store active at **`dialog+0x534`**.
   - **0 friends:** show `+0x50c`; hide `+0x510`,`+0x514`; select `+0x518`+vtbl`+0x94`; deselect `+0x51c`,`+0x520`.
   - **1 clan:** show `+0x510`; hide `+0x50c`,`+0x514`; select `+0x51c`+vtbl`+0x94`; deselect others.
   - **2 enemies:** show `+0x514`; hide `+0x50c`,`+0x510`; select `+0x520`+vtbl`+0x94`; deselect others; **early RET**.
4. **XML map (ctor `FUN_00887c70`):**  
   `i_d_tabs_so_2d_tab_friends.xml` / `…tab_clan.xml` / `…tab_enemies.xml` → slots `+0x518` / `+0x51c` / `+0x520` (cmds `0x9c42` / `0x9c43` / `0x9c44`).
5. **Callees:** dualed `FUN_00822cb0` (**ESI** widget, **BL** selected, stack force); dualed `FUN_00756c90` (**EDI** widget); child vtbls `+0x3d8`/`+0x43c`/`+0x440`/`+0x4`/`+0x94`.
6. **Callers:** **9** `UNCONDITIONAL_CALL` — `FUN_00887c70` (CreateChildWidgets force), `Client_Input_PollBoundActions` ×3 (tabs 0/1/2), residual cmd/toggle ×5.
7. **Host global:** `DAT_00d1b878`.
8. **Name:** `UI_TabsSo_SetActiveTab_Inferred` (Ghidra `FUN_00887780`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI + mode matrix sealed via `disassemble_function` + `read_memory` + call-site context (decompiler arity incomplete, not CF conflict).
10. **Partition parent** `0x00756c90` is wave score parent and **live structural callee** (deselect MoveToFront) — not a caller of this VA.

### Gaps

- Product / PDB method English for dialog class and this setter.  
- Official vtbl method names (`+0x3d8`/`+0x43c`/`+0x440`/`+0x94`/`+0x4`).  
- Full C++ types; content-pane product identity.  
- Residual dual of ctor `FUN_00887c70` / cmd dispatcher (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00887780_UI_TabsSo_SetActiveTab_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00887780_UI_TabsSo_SetActiveTab_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00887780_FUN_00887780.md` |
| Annotated | `docs/reconstruction/raw/aa_00887780_FUN_00887780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_TabsSo_SetActiveTab_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00887780.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_PollBoundActions_00887780.cpp` |
| Function | `docs/reconstruction/functions/aa_00887780_FUN_00887780.md` |
| Function named | `docs/reconstruction/functions/aa_00887780_UI_TabsSo_SetActiveTab_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00887c70  UI_tabs_so CreateChildWidgets  [residual plate UI_tabs_so_tab_enemies]
  └─ builds i_d_tabs_so_2d_* tree; force CALL 0x00887780 (EAX=current +0x534)

Client_Input_PollBoundActions  0x00925d60  [named residual]
  hotkey paths on DAT_00d1b878: EAX=0 / 1 / 2 → CALL 0x00887780 force=1

residual cmd/toggle @ 0x00887a70-ish
  cases force=0; EAX 0/1/2 / cycle

FUN_00887780  UI_TabsSo_SetActiveTab_Inferred  [OWN R13-012]
  ├─ FUN_00822cb0  UI_TabChrome_SetSelected_Inferred  [dualed R12-002]
  └─ FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [dualed R12-003; parent]

Sibling SetActiveTab (do not merge):
  FUN_00889410  UI_TabsC_SetActiveTab_Inferred  [dualed R11-032; DAT_00d1b874]
```

Partition system **inventory-transfer** names residual queue membership (UI host proximity to inventory chrome helpers), **not** an inventory packet role for this unit.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00887780-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00887780` | Port as **`i_d_tabs_so` active-tab setter**. Hybrid: **EAX=tabIndex**, stack **dialog\*** + **force**, **RET 8**, void. Tabs **0=friends / 1=clan / 2=enemies** (linear panes). Preserve mode-2 early return; preserve ESI/BL and EDI register ABI into dualed helpers. Do **not** treat as thiscall, packet builder, or merge with TabsC `00889410`. |
| Host | Global `DAT_00d1b878`; pair with residual ctor `00887c70` and dualed helpers `00822cb0` / `00756c90`. |
| Distinct from | TabsC setter `00889410` (different global/active-slot/XML/pane map); inventory grab/drop senders. |
| Naming caution | **Not** inventory transfer wire. **Not** Runtime Confirmed. Keep `_Inferred` until RTTI. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (UI tab switch — not inventory wire)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

Name to register: `UI_TabsSo_SetActiveTab_Inferred` @ `0x00887780` / `aa_00887780`.  
Retire scaffold product: `Named_CalleeOf_Client_Input_PollBoundActions_00887780`.  
Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00887780`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly_context + list_strings. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (hybrid EAX; plain RET 8; linear friends/clan/enemies matrix).
- Odd behavior preserved: mode-2 early RET; out-of-range store-only; decompiler-hidden ESI/EDI/BL helper ABI.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
