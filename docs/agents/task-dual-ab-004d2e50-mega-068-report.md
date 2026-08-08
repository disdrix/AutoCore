# Dual A/B report — MEGA-068 OWN-ONLY (`0x004d2e50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-068**  
**Scope:** VA `0x004d2e50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_assembly_context` + `get_function_by_address` + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual partition — child of dualed **`CVOGObject_EvalInteractStateFromChildren`** (`0x004d7640`): child active/complete mission interact eval.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004d2e50` CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred | **accept-with-gaps** — CF/ABI/RET8/return-set/sole-parent type-0x25 sealed; product English for code 3 + child field names open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG_DEBUG_STOP-name / thiscall-ECX-this / RET4 / bool-only / merge-with-004d5aa0-or-004d3ef0 / multi-caller / state-mutating claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004d2e50` — sealed facts

1. **Body:** `0x004d2e50`–`0x004d319e` inclusive (**847 B** / `0x34F`); pad `CC` then `FUN_004d31a0`.
2. **ABI:** **`__stdcall`** two stack args (child, character); **`RET 8`** (`C2 08 00`) ×3 exits (`0x004d3077`, `0x004d3174`, `0x004d319c`). Parent `MOV ECX,EDI` unused by body.
3. **Semantics:** child active/complete mission interact eval:
   - Path A: non-empty child mission-id vec `@+0x244` → region hash / completed hash / requirements → return **3** or **6/7**.
   - Path B: non-empty child byte-filter vec `@+0x234` → locked traverse character hash `@+0x540` matching `mission[+0x86]` → **6/7** or flag→**3**.
   - Else **0**.
4. **Returns:** AL ∈ {**0**, **3**, **6**, **7**}; 6/7 = `6 + (mission[+0x169] != 0)`.
5. **Callees:** `FUN_0053fff0`, `CVOGCharacter_HasCompletedMission` (`0x0052aa20`), `CVOGCharacter_CheckMissionRequirements` (`0x005462b0`), `FUN_00547920`, `FUN_00402c40`, `FUN_007a4480`.
6. **Callers:** **1** — `CVOGObject_EvalInteractStateFromChildren` @ `0x004d7640`; **2** UNCONDITIONAL_CALL xrefs @ `0x004d7823`, `0x004d7830` (type-`0x25` branch, state `< 6`).
7. **Strings:** TraversalLock / TraverseToNext / `VOG_DEBUG_STOP` — diagnostics only (retired string-seed names).
8. **Name:** `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` (Ghidra `FUN_004d2e50`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + parent assembly context.
10. **Classification:** worker; 261 insn; 71 BB; cyclomatic 39.

### Gaps

- Product English for return code **3** and child vector field names.  
- Full role of `FUN_00547920`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004d2e50_CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004d2e50_CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004d2e50_FUN_004d2e50.md` |
| Annotated | `docs/reconstruction/raw/aa_004d2e50_FUN_004d2e50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004d2e50.cpp` |
| Function | `docs/reconstruction/functions/aa_004d2e50_FUN_004d2e50.md` |
| Function named | `docs/reconstruction/functions/aa_004d2e50_CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.md` |
| Retired scaffolds | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004d2e50.cpp`, `Mission_VOG_DEBUG_STOP_004d2e50.cpp` |

---

## Chain context (not dualled; evidence only)

```text
CVOGObject_EvalInteractStateFromChildren  0x004d7640  [parent dualed earlier; not OWN here]
  ├─ type 0x1e GiveMission → states 6/7
  ├─ type 0x1f active objective → state 4
  └─ type 0x25:
        ├─ FUN_004d3ba0                         [residual sibling]
        ├─ FUN_004d2e50  CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred  [OWN MEGA-068]
        └─ CVOGObject_EvalOfferableMissionInteractState  0x004d5aa0  [peer]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004d2e50-mega-068-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004d2e50` | Port as **child active/complete mission interact-state helper**. **`__stdcall` RET 8**; args `(child_reaction*, character*)`. Returns **0/3/6/7** only. Do **not** treat as thiscall despite parent `MOV ECX`. Do **not** name after `VOG_DEBUG_STOP`. |
| Pair with | Parent `CVOGObject_EvalInteractStateFromChildren` `004d7640`; peer offerable `004d5aa0`; sibling `004d3ba0`; dualed `HasCompletedMission` / `CheckMissionRequirements`. |
| UI | Aggregate max with parent priority table; this helper only consulted when current state `< 6` on type-0x25 children. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` interaction-activation residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004d2e50`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; retired `Named_VOG_DEBUG_STOP_*` / `Mission_VOG_DEBUG_STOP_*` scaffolds.  
- Odd behavior preserved: parent sets unused ECX; return 3 mid-priority; hash lock diagnostics; decompiler void/unaff_EDI noise corrected via assembly.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
