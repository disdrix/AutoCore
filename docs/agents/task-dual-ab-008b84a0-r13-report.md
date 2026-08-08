# Dual A/B report — R13-013 OWN-ONLY (`0x008b84a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-013**  
**Scope:** VA `0x008b84a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R13 residual dual seal — mail 2d panel chrome builder; caller of dualed **UI_Widget_MoveToFrontInParentGroup_Inferred** (parent residual `0x00756c90`) and dualed **UI_TabChrome_SetSelected_Inferred** (`0x00822cb0`).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` row R13-013.  
**System:** inventory-transfer (mail UI chrome; no inventory wire authority).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008b84a0` UI_Mail2dPanel_BuildChrome_Inferred | **accept-with-gaps** — ECX thiscall / dual-tab build / mode@+0x510 receive-vs-send / dualed tab helpers / vtable dispatch sealed; product English + `FUN_00980250` wire residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-transfer authority / scaffold deposit-only name / sealed C2S opcode / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008b84a0` — sealed facts

1. **Body:** `0x008b84a0`–`0x008b8b76` inclusive (**1751 B** / `0x6D7`); epilogue SEH restore + **`RET`** (`C3`).
2. **ABI:** **ECX = this** (`MOV EBP,ECX`); **no** stack args; plain **`RET`**. Thiscall (not ESI/EDI primary).
3. **Semantics:** **Mail 2d panel chrome builder**:
   - Shared children via vtbl `+0x404` (`bg_fill`, `bg_texture`, `icon`, `icon_cover`, `title`).
   - Close button vtbl `+0x408`, id **`0x9c40`**, slot `@+0x504`.
   - Receive tab: `operator_new(0x81c)` → `FUN_008230b0` → `@+0x55c`, plate `i_d_mail_2d_tab_receive.xml`, id **`0x9c43`**.
   - Send tab: same ctor path → `@+0x558`, plate `i_d_mail_2d_tab_send.xml`, id **`0x9c42`**.
   - **Mode gate** `@+0x510 == 1`:
     - **Receive:** frames + list (`operator_new(0x560)` → `FUN_008b7240` → `@+0x5a4`); select receive / collapse send (`00822cb0` + `00756c90`); if `GetTickCount − @+0x50c ≥ 0x2710` → `FUN_00980250` payload **3**, store tick.
     - **Send:** deposit/credits/postage/compose/item-drop chrome; ids `0x9c41`/`0x9c44`/`0x9c46`–`0x9c49`; collapse receive / select send; clear `@+0x518`/`@+0x51c` = `-1`.
   - Final layout vtbl `+0x34c`.
4. **Does not** own inventory item transfer authority; attachment drop is UI surface only.
5. **Callees (direct named):** `FUN_00792600`, `operator_new`, `FUN_008230b0`, `FUN_008b7240`, `FUN_008b6d50`, dualed `FUN_00822cb0`, dualed `FUN_00756c90`, `GetTickCount`, `FUN_00980250`, `FUN_007a69d0`, `FUN_007a6de0`, `FUN_00977a30` (+ vcalls).
6. **Callers:** **0** UNCONDITIONAL_CALL; **1** DATA xref `@0x00a475b0` (vtable slot → `0x008b84a0`).
7. **Call pattern (dualed helpers inside body):**
   - Select: `MOV ESI, tab; MOV BL,1` / `XOR BL,BL; PUSH 1; CALL 00822cb0`
   - Move front after collapse: `MOV EDI, tab; CALL 00756c90`
8. **Name:** `UI_Mail2dPanel_BuildChrome_Inferred` (Ghidra `FUN_008b84a0`). Product map open → `_Inferred`.  
   **Rejected:** scaffold `UI_mail_bg_frame_deposit` (one send-arm plate only).
9. **Decompile ≡ raw CF**; register ABI for dualed callees sealed via `disassemble_function` (decomp omits ESI/EDI/BL setup).

### Gaps

- Product / RTTI English names of panel class and method.  
- Exact wire family of `FUN_00980250` payload `3`.  
- Product English for vtbl ordinals `+0x404/+0x408/+0x410/+0x34c`.  
- Residual dual of tab ctor / list / postage helpers.  
- Vtable owner type for slot `@0x00a475b0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008b84a0_FUN_008b84a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008b84a0_FUN_008b84a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Mail2dPanel_BuildChrome_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008b84a0.cpp` |
| Function | `docs/reconstruction/functions/aa_008b84a0_FUN_008b84a0.md` |
| Function named | `docs/reconstruction/functions/aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Partition parent residual (R12 dualed):
  FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [dualed R12-003]
  FUN_00822cb0  UI_TabChrome_SetSelected_Inferred            [dualed R12-002]

This unit (R13-013):
  FUN_008b84a0  UI_Mail2dPanel_BuildChrome_Inferred  [OWN]
    ├─ FUN_008230b0  tab chrome ctor              [residual]
    ├─ FUN_008b7240  receive list ctor            [residual]
    ├─ FUN_008b6d50  list setup                   [residual]
    ├─ FUN_00822cb0  tab select/collapse          [dualed]
    ├─ FUN_00756c90  move collapsed tab to front  [dualed]
    └─ FUN_00980250  throttled helper payload 3   [residual]

Dispatch:
  vtable @0x00a475b0 → FUN_008b84a0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008b84a0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008b84a0` | Port as **client mail 2d panel chrome builder**. **ECX=this**, no stack args, **`RET`**. Mode@**+0x510** (`1`=receive). Tabs@**+0x55c** receive / **+0x558** send. List@**+0x5a4**. Close@**+0x504** id `0x9c40`. |
| Do **not** | Treat as server inventory transfer; invent C2S from `FUN_00980250`; use scaffold name `UI_mail_bg_frame_deposit`; claim Runtime Confirmed; dual other VAs. |
| Pair with | dualed `UI_TabChrome_SetSelected_Inferred` `00822cb0`; dualed `UI_Widget_MoveToFrontInParentGroup_Inferred` `00756c90`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.
