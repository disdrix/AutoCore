# Function record: Character_MaybeRefreshCombatState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005355e0` |
| **Canonical name** | `Character_MaybeRefreshCombatState_Inferred` |
| **Address** | `0x005355e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / character state (INFERRED) |
| **Completion status** | **Clean human-refined (light)** — name INFERRED; not kill XP; dual review open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Post-regen combat-pool tick helper: accumulate a 64-bit elapsed counter, set dirty bit `+0x634|=1`, restamp `GetTickCount` at `+0x8dc`, and optionally call `CVOGCharacter_EvaluatePendingObjectives(..., kind=7, elapsedMs, 0, 0)` when a linked object exists at vbase+0xa8.

## Signature (decompiler-derived)

```c
void __thiscall Character_MaybeRefreshCombatState_Inferred(void* pCharacter, uint32_t nDeltaMs);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005355e0_Character_MaybeRefreshCombatState_Inferred.md`
- Annotated: `docs/reconstruction/raw/aa_005355e0_Character_MaybeRefreshCombatState_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_MaybeRefreshCombatState_Inferred.cpp`

## Callers / callees

- Caller: `VehicleCombatPool_OnTick` (when owner character present)
- Callee: `GetTickCount`, `CVOGCharacter_EvaluatePendingObjectives`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| 64-bit accumulator at +0x928/+0x92c | High |
| Role name "MaybeRefreshCombatState" | Tentative / INFERRED |
| Objective kind 7 meaning | Tentative |
