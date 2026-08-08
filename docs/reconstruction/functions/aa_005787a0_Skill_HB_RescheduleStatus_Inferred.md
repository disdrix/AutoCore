# Function record: Skill_HB_RescheduleStatus_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005787a0` |
| **Canonical name** | `Skill_HB_RescheduleStatus_Inferred` |
| **Ghidra name** | `FUN_005787a0` |
| **Address** | `0x005787a0`–`0x0057882d` inclusive (**142 B** / `0x8E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Dual** | A/B **accept-with-gaps** (MEGA-004, 2026-08-05) |
| **Parent** | `CVOGHBSkill_SharedOnHeartBeat_Inferred` (`0x0061b6f0`) residual leaf |
| **Bit-for-bit / runtime / diff** | Open — terminal **false** |

## Purpose

```
if (required_short@+0x2e != 0):
  obj = ResolveObjectTarget(TFID@+0x658..+0x660 via manager+0xe4e8)
  cre = dynamic_cast<CVOGCreature>(obj)
  if !cre || cre.short@+0x12c < required:
    this.vtbl+0x40()          // stop/cancel
    *pOut = DAT_00af31e8      // 0x10
    return pOut               // no AfterFire
  cre.vtbl+0xb0(required)     // apply/set status
CVOGHBBase_RescheduleAfterFire(this, pOut)
return pOut
```

## Signature

```c
uint32_t * __thiscall Skill_HB_RescheduleStatus_Inferred(
    void *thisHb, uint32_t *pOutStatus);
// RET 4
```

## Key constants / offsets

| Item | Value |
|---|---|
| Required short | `this+0x2e` |
| TFID | `+0x658`, `+0x65c`, `+0x660` |
| Manager | `+0x688` → resolve ctx `+0xe4e8` |
| Creature compare | `+0x12c` |
| Fail status | `DAT_00af31e8` = **0x10** |
| RTTI to | `.?AVCVOGCreature@@` @ `0x00af8d0c` |
| RTTI from | `.?AVCVOGClonedObjectBase@@` @ `0x00af8e10` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005787a0_FUN_005787a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005787a0_FUN_005787a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_RescheduleStatus_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005787a0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_005787a0_FUN_005787a0.md` |
| Report | `docs/agents/task-dual-ab-005787a0-mega-004-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET4 | **High** |
| RTTI / offsets / fail status 0x10 | **High** |
| Name product English | **Inferred** |
| Runtime | **Open** |

## Gaps

- Product English for `+0x2e`, creature `+0x12c`, `vtbl+0xb0`, `vtbl+0x40`.
- Full DATA vtbl host RTTI census.
- Runtime / bit-exact / differential.
