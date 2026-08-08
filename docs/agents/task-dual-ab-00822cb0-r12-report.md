# Dual A/B report — R12-002 OWN-ONLY (`0x00822cb0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-002**  
**Scope:** VA `0x00822cb0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — callee of dualed **UI_Cs2dTabs_SelectTab_Inferred** (parent `0x00888b00`); UI tab chrome set-selected helper.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-002.  
**System:** inventory-transfer (UI chrome helper; no inventory wire).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00822cb0` UI_TabChrome_SetSelected_Inferred | **accept-with-gaps** — ESI+BL+force/`RET 4` / selected@+0x4FC / dual select-unselect CF / children+deltas sealed; product names + child vtbl English residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-wire / thiscall / pure-resize / sole-caller / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00822cb0` — sealed facts

1. **Body:** `0x00822cb0`–`0x00822ea8` inclusive (**505 B** / `0x1F9`); epilogue `88 9E FC 04 00 00 5F 83 C4 18 C2 04 00` (`MOV [ESI+0x4FC],BL; POP EDI; ADD ESP,0x18; RET 4`).
2. **ABI:** **ESI** = widget*; **BL** = selected (`1`/`0`); **stack force** (1 dword); **`RET 4`**. **Not** ECX thiscall.
3. **Semantics:** Tab chrome **set selected state**:
   - Early-out if `!force && widget[+0x4FC] == BL`.
   - Optional childA `@+0x818`: restyle (full scale byte `@+0x4FD` when selected; `>>1` when unselected) via vtbls `+0xF0/+0xE8/+0x164/+0x15C`, then `+0x34C`.
   - Optional childB `@+0x814`: vtbl `+0x3C8` with args `(1, selected)` — show/hide companion chrome.
   - If prior selected state differed: GetSize vtbl `+0x120`, adjust by deltas `@+0x80C` (X) / `@+0x810` (Y) — **select subtracts**, **unselect adds** — SetSize vtbl `+0x110`.
   - Store `BL` → `widget[+0x4FC]`.
4. **Does not** send inventory packets; does not touch parent group list (that is dualed `FUN_00756c90`).
5. **Callees:** all **indirect vcalls** (no direct FUN_* leaves in body).
6. **Callers:** **45** xrefs / **10** named — `FUN_00888b00`, `FUN_00889410`, `FUN_00889fb0`, `FUN_00887780`, `FUN_0086b9b0`, `FUN_00878300`, `FUN_00879ea0`, `FUN_008b84a0`, `FUN_008e1020`, `FUN_008e6b50`.
7. **Call pattern:** `MOV ESI, ctrl; MOV BL,1` / `XOR BL,BL; PUSH force; CALL 00822cb0`. After BL=0, parent often `MOV EDI, ctrl; CALL 00756c90`.
8. **Name:** `UI_TabChrome_SetSelected_Inferred` (Ghidra `FUN_00822cb0`). Product map open → `_Inferred`.
9. **Decompile ≡ raw CF**; register ABI sealed via `disassemble_function` + parent call-site `read_memory` (decomp shows `unaff_ESI`/`unaff_BL`).

### Gaps

- Product / RTTI English names of tab chrome class and method.  
- Product English for childA/childB vtbl ordinals.  
- Exact channel of byte `@+0x4FD` (font size vs alpha vs other).  
- Product policy for why selected chrome is smaller by deltas.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00822cb0_FUN_00822cb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00822cb0_FUN_00822cb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_TabChrome_SetSelected_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00822cb0.cpp` |
| Function | `docs/reconstruction/functions/aa_00822cb0_FUN_00822cb0.md` |
| Function named | `docs/reconstruction/functions/aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Parent dual (R11-031 / partition parent):
  FUN_00888b00  UI_Cs2dTabs_SelectTab_Inferred  [dualed]
    ├─ FUN_00822cb0  tab chrome set-selected  [OWN R12-002]
    └─ FUN_00756c90  move collapsed tab to front of parent group  [dualed R12-003]

This unit (R12-002):
  FUN_00822cb0  UI_TabChrome_SetSelected_Inferred  [OWN]
    └─ (vcalls only) childA@+0x818, childB@+0x814, self size +0x120/+0x110

Other dualed callers (evidence):
  FUN_00889410  UI_TabsC_SetActiveTab_Inferred
  FUN_00889fb0  UI_CarTabs_ApplyPanelMode_Inferred
  FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  (post-collapse pair)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00822cb0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00822cb0` | Port as **tab chrome set-selected**. **ESI=widget**, **BL=selected**, **force@stack**, **`RET 4`**. selected@**+0x4FC**, scale@**+0x4FD**, childB@**+0x814**, childA@**+0x818**, deltas@**+0x80C/+0x810**. Select shrinks; unselect grows. |
| Do **not** | Treat as ECX thiscall; invent inventory C2S; merge with `FUN_00756c90`; invert size delta sign; claim Runtime Confirmed. |
| Pair with | dualed parent `UI_Cs2dTabs_SelectTab_Inferred` `00888b00`; dualed sibling `UI_Widget_MoveToFrontInParentGroup_Inferred` `00756c90`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.
