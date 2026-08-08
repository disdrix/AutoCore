# Dual A/B report — R11-031 OWN-ONLY (`0x00888b00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-031**  
**Scope:** VA `0x00888b00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual dual seal — callee of dualed **UI_Window_OnCommand_Class8_Inferred** (parent `0x0082f510`); unit is Cs2d dual-tab selector (R&D / Memorization).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` row R11-031.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00888b00` UI_Cs2dTabs_SelectTab_Inferred | **accept-with-gaps** — ABI/RET8/EAX-tab/offsets/panel-swap/XML sealed; product name + chrome helpers residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-wire / thiscall / force-selects-tab / 3-tab / decomp-complete-ABI claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00888b00` — sealed facts

1. **Body:** `0x00888b00`–`0x00888c7c` inclusive (**125 B** / `0x7D`); epilogue `C2 08 00`.
2. **ABI:** **EAX** = tabIndex; stack window @ `[ESP+4]`, force @ `[ESP+8]`; **`RET 8`**. **Not** ECX thiscall.
3. **Semantics:** Cs2d dual-tab select:
   - Gate: window `vtbl+0x3d8` visible; `(force || tabIndex != selected@+0x534)`.
   - Store selected @ `+0x534`.
   - **tab 0 (R&D):** show panel `@+0x510`, hide `@+0x514`; expand tab `@+0x51c` (`+0x94`); collapse tab `@+0x520`.
   - **tab 1 (Mem):** reverse panels; collapse R&D; expand Mem + `+0x94`.
4. **Object layout:** selected@**+0x534**, panels@**+0x510/514**, tabs@**+0x51c/520**.
5. **Callees:** `FUN_00822cb0` (ESI+BL expand/collapse), `FUN_00756c90` (EDI inactive), UI vcalls.
6. **Callers:** **10** UNCONDITIONAL_CALL — `Client_Input_PollBoundActions`×2, `FUN_0082f510`, `FUN_0080dcc0`, `FUN_00888e50`, `FUN_00937270`, neighbor OnCommand×3, `@0089fa7d`.
7. **Evidence:** ctor `FUN_00888e50` XML `i_d_tabs_cs_2d_tab_randd/memorization` + cmd **0x9c43/0x9c44**; global `DAT_00d1b870`.
8. **Name:** `UI_Cs2dTabs_SelectTab_Inferred` (Ghidra `FUN_00888b00`). Product map open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` (decomp omits ESI/BL for chrome helpers).

### Gaps

- Product / RTTI English name of host class.  
- Residual duals `FUN_00822cb0` / `FUN_00756c90` / siblings `00889410` / `00889fb0`.  
- Exact product meaning of vtbl `+0x94`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00888b00_FUN_00888b00.md` |
| Annotated | `docs/reconstruction/raw/aa_00888b00_FUN_00888b00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Cs2dTabs_SelectTab_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00888b00.cpp` |
| Function | `docs/reconstruction/functions/aa_00888b00_FUN_00888b00.md` |
| Function named | `docs/reconstruction/functions/aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Parent dual (WQ8R-F / partition parent):
  FUN_0082f510  UI_Window_OnCommand_Class8_Inferred  [dualed]
    └─ case 5 → FUN_00888b00(DAT_00d1b870 family)

This unit (R11-031):
  FUN_00888b00  UI_Cs2dTabs_SelectTab_Inferred  [OWN]
    ├─ FUN_00822cb0  tab chrome expand/collapse  [residual]
    └─ FUN_00756c90  inactive-tab helper         [residual]

Ctor / XML evidence:
  FUN_00888e50  loads i_d_tabs_cs_2d_tab_randd / memorization
                cmd 0x9c43 / 0x9c44; calls FUN_00888b00

Siblings (same pattern family; not dualled):
  FUN_00889410  3-tab selector
  FUN_00889fb0  2-tab other host
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00888b00-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00888b00` | Port as **Cs2d dual-tab select**. **EAX=tabIndex**, stack window+force, **`RET 8`**. selected@**+0x534**, panels@**+0x510/514**, tabs@**+0x51c/520**. |
| Do **not** | Treat as ECX thiscall; invent inventory C2S; merge with 3-tab `00889410`; treat force as tab index. |
| Pair with | dualed parent `UI_Window_OnCommand_Class8_Inferred` `0082f510`; residual `FUN_00822cb0` / `FUN_00756c90`; ctor `FUN_00888e50`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.
