# Function record: CVOGHBSkillBase_dtor_Thunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00548f90` |
| **Canonical name** | `CVOGHBSkillBase_dtor_Thunk_Inferred` |
| **Prior scaffold** | `thunk_FUN_00578a60` |
| **Address** | `0x00548f90`–`0x00548f94` inclusive (**5 B** / `0x5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / CVOGHBSkillBase lifecycle |
| **Agent** | R13-006 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept**) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Parent** | `0x00578a60` `CVOGHBSkillBase_dtor` (R12-026 **accept-with-gaps**) |

## Purpose

Pure **JMP thunk** alias of the dualed MSVC complete destructor body for `CVOGHBSkillBase`.

```text
ECX = CVOGHBSkillBase* this
JMP → CVOGHBSkillBase_dtor @ 0x00578a60
        restore PTR_FUN_009d3fdc
        delete[] +0x6a0; delete buffer +0x6b0; zero triad
        tail JMP CVOGHBBase_dtor
```

Retail keeps this 5 B alias for CALL density from shared subclass scalar dtor + EH tables; base-class scalar dtor `0x00578de0` CALLs the parent VA directly.

## Signature

```c
// ECX = this; void; parent tails base dtor
void __thiscall CVOGHBSkillBase_dtor_Thunk_Inferred(void *thisHb);
```

| Item | Value |
|---|---|
| Body bytes | `E9 CB FA 02 00` |
| Target | `0x00578a60` (`0x00548f90 + 5 + 0x0002FACB`) |
| Twin FUN | `FUN_00548f90` / Ghidra `thunk_FUN_00578a60` |

## Port note (AutoCore)

```csharp
// Prefer single implementation:
void CVOGHBSkillBase_dtor(CVOGHBSkillBase* thisHb /* retail: ECX */);
// This VA is a pure alias — no second complete-dtor body required.
// Shared subclass scalar dtor may CALL this alias then free(this) on flags&1.
```

Pair with dualed `CVOGHBSkillBase_dtor` @ `0x00578a60`, `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` @ `0x00651190`, base scalar `0x00578de0`, ctor `0x005788d0`.

## Artifacts

| Kind | Path |
|---|---|
| Raw + re-verify | `docs/reconstruction/raw/aa_00548f90_thunk_FUN_00578a60.md` |
| Annotated | `docs/reconstruction/raw/aa_00548f90_thunk_FUN_00578a60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_dtor_Thunk_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00548f90.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00548f90_thunk_FUN_00578a60.md` |
| Report | `docs/agents/task-dual-ab-00548f90-r13-report.md` |

## Confidence

| Claim | Level |
|---|---|
| JMP-only body | **Confirmed** |
| Target parent complete dtor | **Confirmed** |
| Parent semantics | **Confirmed** (R12-026; gaps on field English inherited) |
| Product thunk demangle | **Tentative** (`_Inferred`) |
| Runtime | **Open** (never Runtime Confirmed) |
