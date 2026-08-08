# Dual A/B report — MEGA-097 OWN-ONLY (`0x0090dab0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-097**  
**Scope:** VA `0x0090dab0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_callees` + `get_xrefs_to` + `get_function_xrefs` + `get_function_signature` + `get_function_hash` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Nested OnKeyDown helper; partition parent context `0x0090d390` / system input-drive-control.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090dab0` Client_Input_DismissUiWindowTable5_Inferred | **accept-with-gaps** — CF/ABI/EAX-host/5-slot table/ESC call sites/callee sealed; product window/vtbl English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): true-void / ECX-thiscall / window*-as-host / RET4 / unbounded walk / product scaffold / merge-with-d390-or-keybind-scan claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090dab0` — sealed facts

1. **Body:** `0x0090dab0`–`0x0090dad5` inclusive (**38 B** / `0x26`); pad `CC` ×10 before leaf `0x0090dae0`.
2. **ABI:** **EAX** = client host → EDI; no stack args; void; **bare RET** (`C3`).
3. **Semantics:** walk global UI window* table **`DAT_00d09a38`** exclusive end **`0xd09a4c`** (**5** dwords):
   - each slot: `ESI = *slot`; `CALL FUN_0090d400` (dismiss-if-active + host notify).
   - Decompiler omits EAX/EDI and ESI load — disasm authority.
4. **Callees:** `FUN_0090d400` only.
5. **Callers / xrefs:** `Client_Input_OnKeyDown_MatchAction` — **2** UNCONDITIONAL_CALL (`0x00911075`, `0x00911893`); both **`MOV EAX,EBX`** then CALL.
6. **Parent path:** ESC (`0x1b`) + client vtbl+`0x3d8` + `*(client+0x50d)==0` → set flag → if `FUN_0090d390()!=0` → this → return 1.
7. **Table init evidence:** `FUN_0093e7e0` writes five UI objects (sizes `0x554/0x5d8/0x604/0x54c/0x588`) into the five slots.
8. **Name:** `Client_Input_DismissUiWindowTable5_Inferred` (Ghidra `FUN_0090dab0`). Product window English open → `_Inferred`. Scaffold `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090dab0` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.
10. **Hash:** `85eba3a5607c2d050e7ad06d4d91c1b972c0ad3068bf2b9e0afb7aed66ca8961`.

### Gaps

- Product English for the five UI window types.  
- Product names for vtbl slots used by `FUN_0090d400` (`+0x3d8/+0xcc/+0x440` window; host `+0xb0/+0x3bc/+0x3f4`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_DismissUiWindowTable5_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090dab0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090dab0.cpp` |
| Function | `docs/reconstruction/functions/aa_0090dab0_FUN_0090dab0.md` |
| Function named | `docs/reconstruction/functions/aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_Input_OnKeyDown_MatchAction  0x00911030  [parent dual earlier / WI-INP-004]
  ESC + vtbl+0x3d8 + flag+0x50d:
    FUN_0090d390  find first active in DAT_00d09a38[5]   [sibling residual]
    if nonzero:
      MOV EAX, EBX  (client host)
      FUN_0090dab0  Client_Input_DismissUiWindowTable5_Inferred  [OWN MEGA-097]
        └─ FUN_0090d400 ×5  per-slot dismiss-if-active (ESI/EDI)  [residual]
    else: other ESC cancel branches (menus / special events / …)

FUN_0093e7e0  init writes DAT_00d09a38..48  [evidence]
FUN_00935a30  teardown nulls same table     [evidence]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090dab0-mega-097-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090dab0` | Port as **5-slot UI window table dismiss walker** for ESC cancel. **EAX = client host** (custom; not ECX thiscall), bare RET, void. Call **after** any-active gate (`0090d390`). Per-slot work is **`FUN_0090d400`** (ESI=window, EDI=host). Do **not** pass the found window* as host. Keep distinct from keybind scan table `DAT_00d1bc18` and from finder `0090d390`. |
| Pair with | parent `Client_Input_OnKeyDown_MatchAction` `00911030`; residual `FUN_0090d390`, `FUN_0090d400`; table `DAT_00d09a38[5]`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when integrating MEGA-097  
- retire any residual `Named_CalleeOf_*_0090dab0` index rows in favor of `Client_Input_DismissUiWindowTable5_Inferred`
