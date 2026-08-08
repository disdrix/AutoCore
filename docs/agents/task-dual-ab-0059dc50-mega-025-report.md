# Dual A/B report — MEGA-025 OWN-ONLY (`0x0059dc50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-025**  
**Scope:** VA `0x0059dc50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `analyze_control_flow` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — objective-node eligibility gate for tracker (parent `Client_TryBindActiveMissionTracker` `0x0092fd00` / tracker set `0x0092a590`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0059dc50` ObjectiveNode_IsEligibleForTracker_Inferred | **accept-with-gaps** — CF/ABI/RET4/AL-bool/callers/body hex sealed; product field/band/vtbl English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): tracker-writer / evaluator-merge / swapped-this / no-RET4 / always-virtual / VOG_DEBUG_STOP product-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0059dc50` — sealed facts

1. **Body:** `0x0059dc50`–`0x0059dcb9` inclusive (**106 B** / `0x6A`).
2. **ABI:** **ECX** = objective node; stack `Character*`; **AL** = bool; **`RET 4`** ×2 exits.
3. **Semantics:** tracker eligibility predicate:
   - null character → false;
   - template short@`+0xf8` ≠ 0 and node byte@`+0x14` == 0 → false;
   - `FUN_0059db80(character) == -1` → false;
   - template id ∈ inclusive `[0xdfd, 0xe02]` and character virtual `+0x27c` < 5 → false;
   - else true.
4. **Callees:** `FUN_0059db80` only (+ virtual `+0x27c` on character this-adjust).
5. **Callers:** **5** functions / **9** UNCONDITIONAL_CALL xrefs:
   - `Client_TryBindActiveMissionTracker` `0x0092fd00` @ `0x0092fd25`
   - `FUN_009344b0` @ five sites
   - `FUN_008a8660`, `FUN_0092b020`, `FUN_008a5240`
6. **Name:** `ObjectiveNode_IsEligibleForTracker_Inferred` (Ghidra `FUN_0059dc50`). Product field English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dc50` **retired**.
7. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Decompiler `undefined4` return corrected to **AL** bool; band form integer-equivalent to asm inclusive range.

### Gaps

- Product English for template short@`+0xf8`, node flag@`+0x14`, id band, virtual `+0x27c`.  
- Sibling evaluator `FUN_0059db80` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0059dc50_FUN_0059dc50.md` |
| Annotated | `docs/reconstruction/raw/aa_0059dc50_FUN_0059dc50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectiveNode_IsEligibleForTracker_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0059dc50.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dc50.cpp` |
| Function | `docs/reconstruction/functions/aa_0059dc50_FUN_0059dc50.md` |
| Function named | `docs/reconstruction/functions/aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_TryBindActiveMissionTracker  0092fd00  [dualed W21-Q]
  ├─ CNDHash_LookupByKey(char+0x548, missionId)
  ├─ ObjectiveNode_IsEligibleForTracker_Inferred  0059dc50  [OWN MEGA-025]
  │     └─ FUN_0059db80  0059db80  [residual sibling]
  │     └─ character virtual +0x27c  [product open]
  └─ Tracker_SetActiveMissionObjective  0092a590  [parent chain]
       + optional mission-UI vtbl +0x3d8 / +0x448

FUN_009344b0 / FUN_008a8660 / FUN_0092b020 / FUN_008a5240
  └─ active-objectives hash walk
       └─ ObjectiveNode_IsEligibleForTracker_Inferred  [OWN MEGA-025]
            └─ (on pick) → Client_TryBindActiveMissionTracker
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0059dc50-mega-025-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0059dc50` | Port as **bool eligibility gate** on objective node for tracker bind/selection. **thiscall RET 4**: ECX=node, stack=character, AL=bool. Preserve four fail paths and inclusive template-id band `[0xdfd,0xe02]` with virtual `+0x27c` threshold 5. |
| Pair with | dualed `Client_TryBindActiveMissionTracker` `0092fd00`; residual sibling eval `0059db80`; tracker write `0092a590`. |
| Do not | Merge with evaluator `0059db80`; invent product names for short/flag/band/vtbl; claim runtime Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/missions-progression` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0059dc50`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + analyze_control_flow + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine ABI corrections (AL bool; inclusive band).  
- Odd behavior preserved: virtual gate only inside id band; no state stores; decompiler band form integer-equivalent.  
- `_Inferred` where English unproven. Scaffold Named_CalleeOf retired. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
