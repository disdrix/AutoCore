# Function record: CVOGHBSkill_OnDoHit_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621700` |
| **Canonical name** | `CVOGHBSkill_OnDoHit_Execute_Inferred` |
| **Prior scaffold** | `FUN_00621700` |
| **Address** | `0x00621700`–`0x00621807` (**264 B** / `0x108`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | `CVOGHBSkill_OnDoHit` (RTTI **Confirmed**) |
| **Vtbl** | `PTR_FUN_009d15c4 + 0x2C` @ `0x009d15f0` |
| **Completion status** | **Dual accept-with-gaps** — R11-018 2026-08-05 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | **false** |

## Purpose

Multi-target arm for `CVOGHBSkill_OnDoHit`: walk a stride-`0x10` TFID table, resolve each object, construct a same-class `0x6c0` skill HB (`CVOGHBSkillBase_ctor` + OnDoHit vtbl), and Enqueue+Start on the world HB list — or deleting-dtor when ValidateTarget leave owner null. Always returns **1** at table sentinel.

## Signature (image-sealed)

```c
// Six stack formals; ret 0x18; ECX (this) unused if called as virtual
uint32_t CVOGHBSkill_OnDoHit_Execute_Inferred(
    void *pSourceObj,    // → CVOGHBSkillBase_ctor source
    void *pSkillBlob,    // → skill runtime blob
    int   pWorldCtx,     // +0xe4e8 resolve ctx; +0xe4ec HB list; base arg4
    int   pTargetTable,  // TFID entries {lo,hi,bGlobal}, stride 0x10
    void *pTfid16,       // → base +0x690
    uint32_t arg7);      // → base arg7
// returns 1
```

## Sealed control flow

```
index = 0
loop:
  entry = table + index*0x10
  if entry is sentinel {-1,-1,bGlobal==0}: return 1
  target = ResolveObjectTarget(world+0xe4e8, bGlobal, lo, hi)
  if target:
    pAction = new(0x6c0)
    if pAction:
      CVOGHBSkillBase_ctor(pAction, source, skill, world, target, tfid16, arg7)
      pAction.vtbl = PTR_FUN_009d15c4
    if pAction.owner(+0x18):
      Enqueue(world+0xe4ec, pAction); Start(pAction)
    else:
      pAction.vtbl[0](1)   // deleting dtor
  index++
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00621700_FUN_00621700.md` |
| Annotated | `docs/reconstruction/raw/aa_00621700_FUN_00621700.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnDoHit_Execute_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00621700.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00621700_FUN_00621700.md` |
| Report | `docs/agents/task-dual-ab-00621700-r11-report.md` |

## Callers / callees

- **Callers:** none direct — DATA vtbl slot `@0x009d15f0` only.
- **Callees:** `CVOGReaction_ResolveObjectTarget` `004bae70`, `operator_new`, `CVOGHBSkillBase_ctor` `005788d0`, `CVOGHBList_Enqueue` `005078f0`, `CVOGHBBase_Start` `005081c0`, dtor path `FUN_00651190`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / sizes | **Confirmed** |
| Class RTTI name | **Confirmed** |
| Method English "Execute" | **Inferred** |
| Param roles via base ctor | **Probable** |
| Runtime | Open |

## Gaps

1. Product method demangle for vtbl+0x2C.
2. Dispatch site of the virtual slot (not dualled here).
3. Runtime / bit-exact / differential.
