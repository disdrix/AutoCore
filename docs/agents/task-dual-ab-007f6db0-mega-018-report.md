# Dual A/B report — MEGA-018 OWN-ONLY (`0x007f6db0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-018**  
**Scope:** VA `0x007f6db0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + `get_assembly_context` + parent decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-018 / input-drive-control / ActionMap slot override lookup.  
**Hint consumed:** ActionMap slot override lookup → **this VA** is the multi-mode key+mod slot finder (override flag = mod-mismatch escape). Parent `0x00911030` is consumer only.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007f6db0` ActionMap_FindSlotByKeyMod_Inferred | **accept-with-gaps** — CF/ABI/RET0/mode JT/stride 0x34/dual-lane/override/sole caller sealed; product mode English + modes 1–3 live use open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): fastcall-only / writer / single-lane / thiscall / RET4 / multi-caller / Named_CalleeOf-canonical claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x007f6db0` — sealed facts

1. **Body:** `0x007f6db0`–`0x007f6fa3` inclusive (**756 B** / `0x2F4`); jump table `0x007f6fa4`–`0x007f6fb3`.
2. **ABI:** **EAX**=mode `0..3`; **EDI**=ActionMap*; **SI**=keyCode; **DX**=modState; return **EAX**=`&slot.key0` or NULL; bare **`RET`** (`C3`).
3. **Semantics:** leaf multi-mode ActionMap slot **lookup**:
   - Per mode: max `{5,6,0x78,0x14}`, key0 bases `{0x06,0x10A,0x242,0x1AA2}`, mod0 cursors `{0x30,0x134,0x26C,0x1ACC}`.
   - Stride **0x34**; primary + alt DIK/mod lanes.
   - Hit if key matches **and** `(modState==0)==(modN==0)` **or** override `byte[mod_cursor+6]`.
4. **Callees:** **none** (leaf).
5. **Callers (1):** `Client_Input_OnKeyDown_MatchAction` @ `0x00911030` site `0x00911429` — forces mode=0, map=`0x00d1b9ac`, DX=0/`0x2A` from shift VKs.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `ActionMap_FindSlotByKeyMod_Inferred` (Ghidra `FUN_007f6db0`).  
   Retired: `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0`.
8. **Family:** shares mode/offset tables with dualed `ActionMap_TrySetSlotBind` `0x007f72e0`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + caller context.

### Gaps

- Product English for four mode groups.  
- Override-flag product name (key0+0x30).  
- Modes 1–3 live call sites (body complete; only mode 0 observed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.md` |
| Annotated | `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_FindSlotByKeyMod_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f6db0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0.cpp` |
| Function | `docs/reconstruction/functions/aa_007f6db0_FUN_007f6db0.md` |
| Function named | `docs/reconstruction/functions/aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_Input_OnKeyDown_MatchAction  0x00911030  [parent dual / consumer]
  ├─ GetAsyncKeyState(0x10/0xA0/0xA1) → modState 0 or 0x2A
  ├─ FUN_007f6db0  ActionMap_FindSlotByKeyMod_Inferred  [OWN MEGA-018]
  │     mode=0, map=0x00d1b9ac, SI=key, DX=modState
  ├─ on hit: slot+4 held, slot+5 edge; FUN_0093a5c0(1)
  └─ on miss: inline mode-2 scan DAT_00d1bc18 / DAT_00d1bbee
              (= map+0x26c / +0x242 of same ActionMap)

ActionMap_TrySetSlotBind  0x007f72e0  [dualed; same kMax/kKey0/kMod0]
  └─ writes primary/alt binds into same slot layout
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007f6db0-mega-018-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007f6db0` | Port as **ActionMap key+mod slot finder**. Custom register ABI: **EAX=mode, EDI=map, SI=key, DX=modState**, return key0*, **no stack cleanup**. Dual primary/alt lanes; override flag allows mod-mismatch hits. Keep modes 0..3 with max `{5,6,0x78,0x14}` and stride **0x34**. |
| Pair with | dualed `ActionMap_TrySetSlotBind` `007f72e0`; parent `Client_Input_OnKeyDown_MatchAction` `00911030`; ActionMap init/display `007f9110` / `007f9160` / `007f8720`. |
| Do not | invent product mode names; model as MSVC `__fastcall`; treat as bind writer; claim runtime Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
**Not written by this agent.**
