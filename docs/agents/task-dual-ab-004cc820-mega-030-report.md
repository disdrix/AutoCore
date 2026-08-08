# Dual A/B report — MEGA-030 OWN-ONLY (`0x004cc820`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-030**  
**Scope:** VA `0x004cc820` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-030**.  
**Work item:** Mega residual dual seal — MatchTarget eval stub default (missions-progression).  
**Hint retired:** “MatchTarget eval stub default” → sealed as `MatchTargetEval_DefaultReturnFalse_Inferred`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cc820` MatchTargetEval_DefaultReturnFalse_Inferred | **accept-with-gaps** — CF/ABI/RET8/always-false/shared-default sealed; product demangle + exhaustive slot map open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): always-true / bare-RET / EmptyDtor-merge / UseItem-MatchTarget-merge / direct-CALL-caller / decompiler-void-authoritative claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004cc820` — sealed facts

1. **Body:** `0x004cc820`–`0x004cc824` inclusive (**5 B** / `0x5`); pad `CC` follows.
2. **Bytes:** `32 C0 C2 08 00` → `XOR AL, AL` ; `RET 0x8`.
3. **ABI:** **`__thiscall`** shape; **ECX** = evaluator this (**unused**); stack two formals (**unused**, **8 B** cleaned); **AL = 0**; **`RET 8`**.
4. **Semantics:** shared **default MatchTarget evaluator** virtual — **always false** / no side effects / leaf.
5. **Callees:** none.
6. **Callers (function graph):** none. **6** MSVC MI **adjustor JMP** thunks re-base ECX then jump here (`004cc819`, `0053be89`, `005a9bc9`, `005c9523`, `00605fc6`, `00608d89`).
7. **Xrefs:** **86** total — **80 DATA** vtbl installs + **6** code JMP.
8. **Consumer family (dualed, evidence):** `CVOGObjective_MatchTargetEvaluators` `0x0059d9c0` (`CALL [vtbl+0x40]`, test AL); Slot44 sibling `0x0059da10`. Collect/Kill/Deliver sample: **+0x40 = this stub**. UseItem real MatchTarget is **`0x0060d7f0` @ +0x38** — **do not merge**.
9. **Name:** `MatchTargetEval_DefaultReturnFalse_Inferred` (Ghidra `FUN_004cc820`). Product demangle open → `_Inferred`.
10. **Decompile ≡ raw CF**; decompiler under-types arity — ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product / PDB English for evaluator interface method.  
- Exhaustive per-vtbl slot-offset inventory across all 80 DATA sites.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cc820_FUN_004cc820.md` |
| Annotated | `docs/reconstruction/raw/aa_004cc820_FUN_004cc820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MatchTargetEval_DefaultReturnFalse_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cc820.cpp` |
| Function | `docs/reconstruction/functions/aa_004cc820_FUN_004cc820.md` |
| Function named | `docs/reconstruction/functions/aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGCharacter_FindActiveObjectiveIdForInteract  [dualed]
  └─ CVOGObjective_MatchTargetEvaluators  0x0059d9c0  [dualed]
        for e in [obj+0x158, obj+0x15c):
          CALL [e->vtbl + 0x40](argA, argB)   // RET 8 thiscall; test AL
            ├─ real override (type-specific)
            └─ FUN_004cc820  MatchTargetEval_DefaultReturnFalse_Inferred  [OWN MEGA-030]
                  XOR AL,AL ; RET 8

CVOGObjective_MatchTargetEvaluators_Slot44  0x0059da10  [dualed]
  └─ same ABI at vtbl+0x44  (may also install this stub)

Client_FindObjectiveMatchingTarget  0x00525bd0  [dualed]
  └─ vtbl+0x38 path  — different slot; not this stub

CVOGObjectiveRequirement_UseItem_MatchTarget  0x0060d7f0  [dualed]
  └─ real +0x38 MatchTarget  — do not merge with 004cc820
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cc820-mega-030-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cc820` | Port as **always-false MatchTarget evaluator default**. **`__thiscall` + RET 8**; ignore this/args; return `false`. |
| Install sites | Many objective/eval vtbls; MI adjustors may JMP here after `this` fixup. |
| Do **not** | Merge with EmptyDtor / bare RET / UseItem MatchTarget `0060d7f0` / +0x38 UseObject path. |
| Pair with | dualed MatchTargetEvaluators `0059d9c0` / Slot44 `0059da10`; residual real +0x40 implementers (non-stub types). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/missions-progression.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004cc820`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI correction (thiscall RET 8).  
- Odd behavior preserved: formals unused; always false; JMP adjustors not CALL.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
