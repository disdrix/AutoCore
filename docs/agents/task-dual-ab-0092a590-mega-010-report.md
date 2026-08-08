# Dual A/B report — MEGA-010 OWN-ONLY (`0x0092a590`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-010**  
**Scope:** VA `0x0092a590` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `analyze_control_flow` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-010**.  
**Work item:** residual dual seal — **Tracker_SetActiveMissionObjective** (missions-progression; parent `0x0092fd00`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092a590` Tracker_SetActiveMissionObjective_Inferred | **accept-with-gaps** — CF/ABI/ECX-tracker/EAX-id/AL-bool/offsets/sole-caller binder role sealed; product tracker/objective English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): full-bind-merge / stack-thiscall / void-return / multi-caller / scaffold-product / stale-id-on-miss / journal-mutate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092a590` — sealed facts

1. **Body:** `0x0092a590`–`0x0092a5fe` inclusive (**111 B** / `0x6F`); pad `CC` @ `0x0092a5ff`.
2. **ABI:** **ECX** = MissionTracker* (this); **EAX** = missionId (0 = clear); **AL** = bool; bare **`RET`** (`C3`) ×3 exits. Dual-register, not cdecl / not stack thiscall.
3. **Semantics:** bind/clear active mission objective on tracker:
   - Always `tracker+0x10 = id`, `tracker+0x6 = 1`.
   - **id==0:** `FUN_0092a3d0` (EDI) + `FUN_00929c00` (EAX); zero `+0x10`/`+0xc`; return **1**.
   - **id!=0:** character via `(*tracker)+0xe98`; `CNDHash_LookupByKey(char+0x548, id)`; hit → `tracker+0xc = **(node+0x14c)`, `tracker+0x4 = 1`, return **1**.
   - Miss/null character: same clear, return **0**.
4. **Callees:** `FUN_0092a3d0`, `FUN_00929c00`, `CNDHash_LookupByKey` @ `0x005b0920`.
5. **Callers (1):** dualed `Client_TryBindActiveMissionTracker` (`FUN_0092fd00`) @ `0x0092fd4c` — `MOV ECX,[EDI+0x4d0]; MOV EAX,EBX; CALL`.
6. **Xrefs:** 1× UNCONDITIONAL_CALL.
7. **Name:** `Tracker_SetActiveMissionObjective_Inferred` (Ghidra `FUN_0092a590`). Scaffold `Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590` **retired**. Product English open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **System:** `missions-progression`.

### Gaps

- Product English for tracker class at `client+0x4d0`.  
- Product English for `node+0x14c` objective-head payload.  
- Residual duals for clear helpers `FUN_0092a3d0` / `FUN_00929c00`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092a590_FUN_0092a590.md` |
| Annotated | `docs/reconstruction/raw/aa_0092a590_FUN_0092a590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tracker_SetActiveMissionObjective_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092a590.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590.cpp` |
| Function | `docs/reconstruction/functions/aa_0092a590_FUN_0092a590.md` |
| Function named | `docs/reconstruction/functions/aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_TryBindActiveMissionTracker  FUN_0092fd00  [dualed W21-Q]
  ├─ character = client+0xe98
  ├─ missionId != 0:
  │     node = CNDHash_LookupByKey(char+0x548, id)
  │     gate FUN_0059dc50(node, char)             [residual MEGA-025]
  ├─ missionId == 0 && tracker+0x10 == 0: return 1 (idle)
  ├─ FUN_0092a590  Tracker_SetActiveMissionObjective_Inferred  [OWN MEGA-010]
  │     ├─ FUN_0092a3d0  clear objective vector (EDI)   [residual]
  │     ├─ FUN_00929c00  reset display fields (EAX)     [residual]
  │     └─ CNDHash_LookupByKey  0x005b0920              [shared]
  └─ on success && client+0x107c:
        ui.vtbl+0x3d8() → ui.vtbl+0x448()

Sibling getter @ 0x0092fd90: reads tracker+0x10 → same hash → node+0x14c head
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092a590-mega-010-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092a590` | Port as **tracker active-mission-objective bind/clear**. ABI: **ECX=tracker**, **EAX=missionId**, **AL=bool**, bare RET. Always stamp `+0x10`/`+0x6`. Zero-id clear always returns 1. Non-zero requires character hash hit; stamp `+0xc` from `**(node+0x14c)` and `+0x4=1`. Miss zeros id/head after clear helpers. Do **not** merge parent gate/UI into this leaf. Keep clear helpers' custom EDI/EAX ABI. |
| Pair with | dualed parent `Client_TryBindActiveMissionTracker` `0092fd00`; residual gate `FUN_0059dc50` `0059dc50` (MEGA-025); residual clears `0092a3d0` / `00929c00`; shared `CNDHash_LookupByKey` `005b0920`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history (retire scaffold → `Tracker_SetActiveMissionObjective_Inferred`)
- `systems/*` missions-progression residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0092a590`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + control_flow + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_0092a590.cpp` kept; Named_CalleeOf scaffold retired.  
- Odd behavior preserved: zero-id clear returns **success**; fail path zeros the id that was just written; clear helpers use EDI/EAX not pure ECX-thiscall.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
