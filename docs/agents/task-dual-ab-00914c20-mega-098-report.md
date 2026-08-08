# Dual A/B report — MEGA-098 OWN-ONLY (`0x00914c20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-098**  
**Scope:** VA `0x00914c20` (`aa_00914c20`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` + call-site bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual partition — input-drive-control residual **stop HB + SetLongitudinal(0)**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00914c20` Client_Vehicle_StopHbAndZeroLongitudinal_Inferred | **accept-with-gaps** — CF/ABI/RET/callers/callees/byte seals closed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-host / Engage-merge / opposite-flag / multi-caller / thr-steer-write claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00914c20` — sealed facts

1. **Body:** `0x00914c20`–`0x00914c59` inclusive (**58 B** / `0x3A`); pad `CC` before neighbor `0x00914c60`.
2. **ABI:** **EAX** = client host (register-carried); no stack args; void; bare **`RET`** (`C3`). Callers seal with `MOV EAX,EDI` then `CALL`.
3. **Semantics:**
   - Gate: `DAT_00d1a860 != 0` **and** `*(host+0xc70) != 0`.
   - `*(u8*)(host+0xa35) = 0`.
   - `CVOGHBBase_Stop` thiscall **ECX = *(host+0xc70)** (`0x005081d0`).
   - If `DAT_00d1b6d8` and vehicle `*(+0x250)`: `VehicleEntity_SetLongitudinalInput(0)` thiscall **ECX=vehicle**, stack imm `0` (`0x004f5650`).
   - No SetHandbrake / SetSteer / PushDriveAxes / `vehicle+0x101` gate.
4. **Callees:** `CVOGHBBase_Stop`, `VehicleEntity_SetLongitudinalInput` only.
5. **Callers (2 UNCONDITIONAL_CALL):**
   - `FUN_00914c60` @ `0x00914ca5`
   - `Client_InteractWorldClickHub` (`FUN_00925820`) @ `0x00925984` (`8B C7; E8…` → this leaf; drop-destroy modal path)
6. **Xrefs:** 2 UNCONDITIONAL_CALL (analyze + `get_xrefs_to`).
7. **Name:** `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` (Ghidra `FUN_00914c20`). Product map open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Polarity:** Stop runs when `DAT_00d1a860` is **set** — opposite optional-Stop polarity of dualed `Client_Vehicle_EngageHbAndPushAxes_Inferred` (`0x00915670`).

### Gaps

- Product English for `DAT_00d1a860` and latch `+0xa35`.  
- Residual sibling caller `FUN_00914c60` (not dualled here).  
- Hub early **inline** of equivalent CF is separate from this leaf (owned by hub dual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00914c20_FUN_00914c20.md` |
| Annotated | `docs/reconstruction/raw/aa_00914c20_FUN_00914c20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00914c20.cpp` |
| Function | `docs/reconstruction/functions/aa_00914c20_FUN_00914c20.md` |
| Function named | `docs/reconstruction/functions/aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_InteractWorldClickHub  FUN_00925820  [dualed W17-C]
  ├─ early INLINE: same DAT_00d1a860 / +0xc70 / +0xa35 / Stop / SetLong(0) CF
  └─ CALL FUN_00914c20 @ 00925984  (drop-destroy path; MOV EAX,EDI)
        └─ [OWN MEGA-098]

FUN_00914c60  [residual scaffold]
  └─ CALL FUN_00914c20 @ 00914ca5  (clear path; MOV EAX,EDI)

FUN_00914c20  Client_Vehicle_StopHbAndZeroLongitudinal_Inferred  [OWN MEGA-098]
  ├─ CVOGHBBase_Stop                     0x005081d0  [dual accept]
  └─ VehicleEntity_SetLongitudinalInput  0x004f5650  [dual sealed]

Contrast (not merge):
  Client_Vehicle_EngageHbAndPushAxes_Inferred  0x00915670
    HB=1 + Push; optional Stop only if DAT_00d1a860==0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00914c20-mega-098-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00914c20` | Port as **stop-HB + zero longitudinal** helper. **Host in EAX** (not ECX this). Gate on `DAT_00d1a860` **true**. Clear `+0xa35`, Stop `*(+0xc70)`, optional SetLong(0) on `*(DAT_00d1b6d8+0x250)`. |
| Do not merge with | `00915670` EngageHbAndPushAxes (opposite flag polarity; HB=1+Push). |
| Pair with | dualed `CVOGHBBase_Stop` `005081d0`; dualed `VehicleEntity_SetLongitudinalInput` `004f5650`; dualed hub `00925820`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- progress / WORK_QUEUE residual clear for MEGA-098  

**Terminal:** **false**.
