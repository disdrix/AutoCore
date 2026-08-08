# Function record: MatchTargetEval_DefaultReturnFalse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc820` |
| **Canonical name** | `MatchTargetEval_DefaultReturnFalse_Inferred` (**Inferred** role) |
| **Ghidra symbol** | `FUN_004cc820` |
| **Address** | `0x004cc820`–`0x004cc824` inclusive (**5 B** / `0x5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body epilogue** | `RET 0x8` (`C2 08 00` @ `0x004cc822`) |
| **Body hex** | `32 C0 C2 08 00` |
| **System** | `missions-progression` (MatchTarget evaluator default) |
| **Partition** | MEGA-030 — residual under dualed MatchTargetEvaluators family |
| **Agent** | MEGA-030 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Shared **default MatchTarget evaluator** virtual method. Always returns **false** (`XOR AL,AL`). Ignores `this` and both stack formals; cleans **8** stack bytes (`RET 8`).

Used when an objective/eval type has no useful MatchTarget implementation for a given vtbl slot (commonly **`vtbl+0x40`**, often paired with **`+0x44`**). Dualed `CVOGObjective_MatchTargetEvaluators` (`0x0059d9c0`) walks `[obj+0x158, obj+0x15c)` and invokes `CALL [vtbl+0x40]` with this ABI; Collect/Kill/Deliver samples install this stub → interact path never matches via those types.

MSVC **multiple-inheritance adjustor thunks** (6 sites) re-base `ECX` then `JMP` here so derived vtables share one body.

## Signature

```c
// Machine: 32 C0 C2 08 00
std::uint8_t __thiscall MatchTargetEval_DefaultReturnFalse_Inferred(
    void* evaluator_this,  // ECX — unused
    void* argA,            // stack — unused (walker: character*)
    void* argB);           // stack — unused (walker: world/object*)
// RET 0x8; AL = 0 always
```

## Call graph

| Role | Target |
|---|---|
| **Callees** | none (leaf) |
| **JMP adjustors** | `0x004cc819` (Δ`0x3f0`), `0x0053be89` (Δ`0xc90`), `0x005a9bc9` (Δ`0xa0`), `0x005c9523`, `0x00605fc6` (Δ`0x10`), `0x00608d89` (Δ`0x1a0`) |
| **DATA vtbls** | 80 installs (sample: `009ce2b4/b8`, `009d92c0…`, `009dfaa8…`, `009dfc30…`, `009e0418…`) |
| **Consumer (dualed)** | `CVOGObjective_MatchTargetEvaluators` `0x0059d9c0` (+0x40); sibling Slot44 `0x0059da10` |
| **Contrast** | UseItem MatchTarget `0x0060d7f0` @ **+0x38**; FindObjectiveMatchingTarget `0x00525bd0` @ **+0x38** |

## Evidence summary

- Live decompile ≡ raw CF (`return 0`).
- `read_memory` + `disassemble_function` seal `XOR AL,AL; RET 8` (decompiler under-types arity).
- Dualed parent A/B already name this VA as the always-false +0x40 default stub.
- Partition hint “MatchTarget eval stub default” matches.
- Product/PDB demangle open → `_Inferred`.

## Gaps

- Product/PDB English for evaluator interface.
- Exhaustive per-type slot inventory (not every DATA xref dualled).
- Runtime / bit-exact / differential.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/MatchTargetEval_DefaultReturnFalse_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_004cc820.cpp`
- Raw: `docs/reconstruction/raw/aa_004cc820_FUN_004cc820.md`
- Annotated: `docs/reconstruction/raw/aa_004cc820_FUN_004cc820.annotated.md`
- FUN record: `docs/reconstruction/functions/aa_004cc820_FUN_004cc820.md`
- Review A: `docs/reconstruction/reviews/A_aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md`
- Report: `docs/agents/task-dual-ab-004cc820-mega-030-report.md`
