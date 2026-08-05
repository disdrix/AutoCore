# Function record: CVOGHBWakeupSkill_Fire_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606180` |
| **Canonical name** | `CVOGHBWakeupSkill_Fire_Inferred` |
| **Ghidra name** | `FUN_00606180` |
| **Address** | `0x00606180`–`0x006061de` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / heartbeat |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W18-I OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

`CVOGHBWakeupSkill` virtual at **vtbl+0x14**: when the delayed skill HB is removed from `CVOGHBList` (EndOrDestroy with onEnd flag), validate local cast and apply embedded skill effects to the stored target. Class RTTI **Confirmed**.

## Signature (byte-sealed)

```c
void __thiscall CVOGHBWakeupSkill_Fire_Inferred(void* thisHb /* ECX */);
// no stack args; tails via empty FUN_005081f0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00606180_FUN_00606180.md`
- Annotated: `docs/reconstruction/raw/aa_00606180_FUN_00606180.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBWakeupSkill_Fire_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_00606180.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_00606180_FUN_00606180.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | virtual only | DATA `0x009de7c8` vtbl+0x14; via `CVOGHBBase_EndOrDestroy` |
| Callee | `FUN_00514e00` | when `+0x658==0`; ECX=owner |
| Callee | `Skill_LocalCastValidate` | owner, skipBusy=`+0x658`, skill=NULL, 0 |
| Callee | `Skill_ApplyEffectsOnTarget_Inferred` | skill=`this+0x24`, … |
| Callee | `FUN_005081f0` | empty tail |

## Confidence

| Claim | Level |
|---|---|
| CF + call targets from bytes | **Confirmed** |
| Class `CVOGHBWakeupSkill` RTTI | **Confirmed** |
| Vtbl slot +0x14 install | **Confirmed** |
| Method product English name | **Inferred** (`_Inferred` retained) |
| HB field map used by body | **High** (ctor + body) |
| Runtime / image diff | Open |
