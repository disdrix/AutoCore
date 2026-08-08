# Review A (reconstruction fidelity): `aa_004cc820` MatchTargetEval_DefaultReturnFalse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc820` |
| **VA** | `0x004cc820` |
| **Body** | `0x004cc820`–`0x004cc824` inclusive (**5 B** / `0x5`) |
| **Canonical name** | `MatchTargetEval_DefaultReturnFalse_Inferred` |
| **Ghidra symbol** | `FUN_004cc820` |
| **Review date** | `2026-08-05` (MEGA-030 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md` |
| **System** | `missions-progression` (MatchTarget evaluator default) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra — `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_xrefs` + `get_function_callers` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Shared leaf virtual that is the **default MatchTarget evaluator**: always return **false**, clean two stack formals (`RET 8`). Installed across many objective/eval vtables; MI adjustors JMP here after rebasing `this`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-030 re-verify) | `docs/reconstruction/raw/aa_004cc820_FUN_004cc820.md` |
| Annotated | `docs/reconstruction/raw/aa_004cc820_FUN_004cc820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MatchTargetEval_DefaultReturnFalse_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004cc820.cpp` |
| Function records | `docs/reconstruction/functions/aa_004cc820_FUN_004cc820.md` + named twin |
| Live body | `disassemble_function` + `read_memory` @ `0x004cc820` → `32 C0 C2 08 00` |
| Parent dual | `A/B_aa_0059d9c0_CVOGObjective_MatchTargetEvaluators` (documents this stub) |
| Adjustor context | `get_assembly_context` on 6 JMP sites |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 5 B: `XOR AL,AL; RET 8` | **Confirmed** | `read_memory` + disasm |
| Return always 0 (false) in AL | **Confirmed** | `32 C0`; decompile `return 0` |
| Two stack formals cleaned | **Confirmed** | `C2 08 00` |
| Leaf / no callees | **Confirmed** | analyze + body |
| No function-graph CALL callers | **Confirmed** | callers empty; 6 JMP adjustors |
| 80 DATA vtbl installs | **Confirmed** | xref_count 86 − 6 code = 80 DATA |
| MatchTarget eval default role | **High** | dualed +0x40 walker ABI + parent dual text + partition hint |
| Formal types (char*, world*) | **Probable** | from dualed walker binding, not this body |
| Product/PDB demangle | **Open** | `_Inferred` |
| Exhaustive per-vtbl slot map | **Open** | sample +0x40 sealed via parent dual |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Constant false return | **Yes** |
| No branches / no memory | **Yes** |
| Epilogue RET 8 | **Yes** (bytes/disasm; decompiler elides — ABI note only) |

### Full body listing

```text
004cc820  XOR AL, AL
004cc822  RET 0x8
```

---

## 5. ABI seal

| Claim | Evidence | Conf |
|---|---|---|
| Ignores ECX / stack | no loads | **High** |
| AL return 0 | `XOR AL,AL` | **High** |
| `RET 0x8` | hex + disasm | **High** |
| Compatible with MatchTargetEvaluators call | parent pushes 2 args, `TEST AL,AL` | **High** |

Canonical:

```c
std::uint8_t __thiscall MatchTargetEval_DefaultReturnFalse_Inferred(
    void* this, void* argA, void* argB);  // RET 8; always 0
```

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Always false (AL=0) | **Yes** |
| RET-8 two-formal eval ABI | **Yes** |
| Shared default across vtbls | **Yes** (80 DATA + 6 adjustors) |
| Dualed parent labels this as +0x40 default stub | **Yes** (`aa_0059d9c0` A/B) |
| Product/PDB English | **No** |

**Decision:** promote **`MatchTargetEval_DefaultReturnFalse_Inferred`**.

Reject:

- bare `EmptyRet` / `EmptyDtorStub` merge (different VA/epilogue; this is **RET 8** bool false)
- always-true / identity claims
- inventing a product class method name without demangle
- equating to UseItem MatchTarget `0060d7f0` (+0x38 real implementation)
- treating Ghidra “UNCONDITIONAL_CALL” xrefs as direct CALL sites (live = **JMP** adjustors)

---

## 7. Gaps

1. Product/PDB symbol for evaluator interface method.
2. Full slot-offset inventory for all 80 DATA sites (not OWN to dual every host type).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
