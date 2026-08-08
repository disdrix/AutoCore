# Dual A/B report — MEGA-096 OWN-ONLY (`0x0090d390`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-096**  
**Scope:** VA `0x0090d390` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_xrefs_to` + `get_assembly_context` + `read_memory` + `get_function_by_address` + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Post-match branch callee of OnKeyDown; partition parent context `0x00911030` / system input-drive-control.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090d390` Client_Input_FindFirstActiveUiWindowTable5_Inferred | **accept-with-gaps** — CF/ABI/EAX-return/5-slot table/vtbl+0x3d8/ESC call site sealed; product window English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): keybind-table / dismiss-merge / void-return / ECX-host thiscall / RET4 / unbounded / product-scaffold claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090d390` — sealed facts

1. **Body:** `0x0090d390`–`0x0090d3c4` inclusive (**53 B** / `0x35`); pad `CC` from `0x0090d3c5`.
2. **ABI:** no stack args; void formals; **EAX** = window* or 0; **bare RET** (`C3` ×2). ESI = index (PUSH/POP).
3. **Semantics:** scan global UI window* table **`DAT_00d09a38`** exclusive end **`0xd09a4c`** (**5** dwords):
   - skip null slots;
   - thiscall `window->vtbl+0x3d8` → `char`;
   - first non-zero → return that window*;
   - else return 0.
4. **Callees:** none named; one **indirect** vtbl call at `+0x3d8`.
5. **Callers / xrefs:** **2** UNCONDITIONAL_CALL:
   - `Client_Input_OnKeyDown_MatchAction` @ `0x0091106a` (ESC path: flag+`0x50d` → find → if nz dismiss `0x0090dab0` → return 1)
   - `FUN_0092cef0` @ `0x0092cf32` (if nz `JMP [vtbl+0x94]` on returned window*)
6. **Parent path:** ESC (`0x1b`) + client vtbl+`0x3d8` + `*(client+0x50d)==0` → set flag → **this** → if nonzero sibling dismiss.
7. **Table peers (evidence only):** `FUN_0093e7e0` WRITE five UI objects into slots; `FUN_00935a30` teardown nulls; dualed dismiss `FUN_0090dab0` (MEGA-097).
8. **Name:** `Client_Input_FindFirstActiveUiWindowTable5_Inferred` (Ghidra `FUN_0090d390`). Product window English open → `_Inferred`. Scaffold `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090d390` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for the five UI window types.  
- Product names for vtbl slots (`+0x3d8` active gate; secondary `+0x94`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090d390_FUN_0090d390.md` |
| Annotated | `docs/reconstruction/raw/aa_0090d390_FUN_0090d390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_FindFirstActiveUiWindowTable5_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090d390.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090d390.cpp` |
| Function | `docs/reconstruction/functions/aa_0090d390_FUN_0090d390.md` |
| Function named | `docs/reconstruction/functions/aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_Input_OnKeyDown_MatchAction  0x00911030  [parent dual earlier / WI-INP-004]
  ESC + vtbl+0x3d8 + flag+0x50d:
    FUN_0090d390  Client_Input_FindFirstActiveUiWindowTable5_Inferred  [OWN MEGA-096]
    if nonzero:
      MOV EAX, EBX  (client host)
      FUN_0090dab0  Client_Input_DismissUiWindowTable5_Inferred  [MEGA-097]
        └─ FUN_0090d400 ×5  per-slot dismiss-if-active  [residual]
    else: other ESC cancel branches (menus / special events / …)

FUN_0092cef0  [residual]
  └─ FUN_0090d390  → if nonzero JMP window.vtbl+0x94

FUN_0093e7e0  init writes DAT_00d09a38..48  [evidence]
FUN_00935a30  teardown nulls same table     [evidence]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090d390-mega-096-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090d390` | Port as **5-slot UI window table any-active finder**. No stack args; bare RET; **EAX = window* or null**. Call **before** dismiss walker on ESC. Do **not** pass found window* as host to `0090dab0` (host is client in EAX). Keep distinct from keybind scan table `DAT_00d1bc18` and from dismiss walker `0090dab0`. |
| Pair with | parent `Client_Input_OnKeyDown_MatchAction` `00911030`; dualed dismiss `Client_Input_DismissUiWindowTable5_Inferred` `0090dab0`; residual per-slot `FUN_0090d400`; table `DAT_00d09a38[5]`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when integrating MEGA-096  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_*_0090d390` → `Client_Input_FindFirstActiveUiWindowTable5_Inferred`)  
- `systems/input-drive-control` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0090d390`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; Ghidra twin kept; Named_CalleeOf scaffold retired.  
- Odd behavior preserved: returns first match only (not all actives); null slots skipped without vcall; secondary caller uses result for `vtbl+0x94` not dismiss.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
