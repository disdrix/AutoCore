# Function record: CVOGHBMissionEscort_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_006508d0` |
| **Canonical name** | `CVOGHBMissionEscort_OnHeartBeat` |
| **Ghidra name** | `FUN_006508d0` |
| **Address** | `0x006508d0` |
| **Body** | `0x006508d0`–`0x00650cf6` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / heartbeat |
| **Completion status** | **Dual A/B sealed** (WQ7R-H 2026-08-04); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Purpose

Escort mission **OnHeartBeat** (`CVOGHBBase` `vtable+0x0C`): track escort target TFID/distance; **FailMission**+drain if lost; **CompleteObjective(force=1)** if player in complete zone; else reschedule. Primary residual **CompleteObjective** (and FailMission) caller on WQ-007 escort HB path.

## Signature

```c
EHBStatus* __thiscall
CVOGHBMissionEscort_OnHeartBeat(
    CVOGHBMissionEscort* this,  // ECX
    EHBStatus* pOutStatus);     // stack+4; often written 16=Remove
// ret 4
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006508d0_FUN_006508d0.md` |
| Annotated | `docs/reconstruction/raw/aa_006508d0_FUN_006508d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMissionEscort_OnHeartBeat.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006508d0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` |
| Scratch | `docs/reconstruction/tmp/a_006508d0.md` |
| Function FUN | `docs/reconstruction/functions/aa_006508d0_FUN_006508d0.md` |

## Callers / callees

| Direction | Symbol | VA | Notes |
|---|---|---|---|
| Caller | (dynamic) `CVOGHBBase_TryFire` | `0x005082c0` | `vtable+0x0C` call; no static CALL |
| Bind | `PTR_FUN_009e52c4` | `0x009e52d0` | DATA xref |
| Callee | `CVOGReaction_CompleteObjective` | `0x00533f90` | force=1 |
| Callee | `CVOGReaction_FailMission` | `0x0052da30` | lost arm |
| Callee | `FUN_005307e0` | `0x005307e0` | end-quest drain (**yes**) |
| Callee | `CVOGHBBase_RescheduleAfterFire` | `0x00508350` | still escorting |
| Callee | `Object_ResolveFromTFID` | `0x004bb950` | target resolve |
| Callee | `CVOGReaction_ResolveObjectTarget` | `0x004bae70` | complete-zone |

## Confidence

| Claim | Level |
|---|---|
| OnHeartBeat role + Escort RTTI | **High** |
| CompleteObjective / FailMission CF arms | **High** |
| Drain-after-fail | **High** (cross-sealed with FailMission dual) |
| Distance/field English | **Probable** / **Tentative** |
| Runtime / bit-exact | **Open** |
