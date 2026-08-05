# Function record: Object_RefreshActiveSkillEffects_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516a00` |
| **Canonical name** | `Object_RefreshActiveSkillEffects_Inferred` |
| **Address** | `0x00516a00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills / activate |
| **Ghidra symbol** | `FUN_00516a00` |
| **Completion status** | **Dual A/B present** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Type-gated dual-collection skill walk (hash + vfunc array); for each active skill matching rank filter, call `FUN_00514e70(skillId@+0x5fc)`. ActivateEnterWorld uses `param_2=0`.

## Signature

```c
void __thiscall Object_RefreshActiveSkillEffects_Inferred(Object* obj, char includeZeroRank);
```

## Artifacts

- Raw / annotated / clean: `raw/aa_00516a00_*`, `reconstructed-exact/FUN_00516a00.cpp`
- Dual A/B: `reviews/A_aa_00516a00_Object_RefreshActiveSkillEffects_Inferred.md`, `B_aa_00516a00_*`
- Legacy: `functions/aa_00516a00_FUN_00516a00.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `Vehicle_ActivateEnterWorld`, creature post-create, several FUN_* |
| Callee | `FUN_00514e70`, `NDError_Log` (lock asserts) |

## Confidence

| Claim | Level |
|---|---|
| Dual collection CF | High |
| Product names / 00514e70 | Tentative–Probable |
