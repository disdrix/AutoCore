# Function record: CVOGHBSkill_HitCharge_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621f50` |
| **Canonical name** | `CVOGHBSkill_HitCharge_Execute_Inferred` |
| **Prior scaffold** | `FUN_00621f50` |
| **Address** | `0x00621f50`–`0x0062205d` (**270 B** / `0x10E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | `CVOGHBSkill_HitCharge` (RTTI **Confirmed**) |
| **Vtbl** | `PTR_FUN_009d1624 + 0x2C` @ `0x009d1650` |
| **Parent ctor** | `CVOGHBSkill_OnDoHit_Ctor` @ `0x00621350` (called per target) |
| **Completion status** | **Dual accept-with-gaps** — R12-005 2026-08-05 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | **false** |

## Purpose

Multi-target arm for `CVOGHBSkill_HitCharge`: walk a stride-`0x10` TFID table, resolve each object, construct a `0x6d0` skill HB via `CVOGHBSkill_OnDoHit_Ctor` then upgrade vtbl to HitCharge and zero tail fields, and Enqueue+Start on the world HB list — or deleting-dtor when owner attach fails. Always returns **1** at table sentinel.

## Signature (image-sealed)

```c
// Six stack formals; ret 0x18; ECX (this) unused if called as virtual
uint32_t CVOGHBSkill_HitCharge_Execute_Inferred(
    void *pSourceObj,    // → OnDoHit/base ctor source
    void *pSkillBlob,    // → skill runtime blob
    int   pWorldCtx,     // +0xe4e8 resolve ctx; +0xe4ec HB list; ctor arg4
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
    pAction = new(0x6d0)
    if pAction:
      CVOGHBSkill_OnDoHit_Ctor(pAction, source, skill, world, target, tfid16, arg7)
      pAction.vtbl = PTR_FUN_009d1624   // HitCharge (overwrites OnDoHit)
      *(dword*)(pAction+0x6c0) = 0
      *(float*)(pAction+0x6c4) = 0.0f
    if pAction.owner(+0x18):
      Enqueue(world+0xe4ec, pAction); Start(pAction)
    else:
      pAction.vtbl[0](1)   // deleting dtor
  index++
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00621f50_FUN_00621f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00621f50_FUN_00621f50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_HitCharge_Execute_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00621f50.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00621f50_FUN_00621f50.md` |
| Report | `docs/agents/task-dual-ab-00621f50-r12-report.md` |

## Callers / callees

- **Callers:** none direct — DATA vtbl slot `@0x009d1650` only.
- **Callees:** `CVOGReaction_ResolveObjectTarget` `004bae70`, `operator_new`, `FUN_00621350` / `CVOGHBSkill_OnDoHit_Ctor`, `CVOGHBList_Enqueue` `005078f0`, `CVOGHBBase_Start` `005081c0`, dtor path `FUN_00651190`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / sizes | **Confirmed** |
| Class RTTI name HitCharge | **Confirmed** |
| Method English "Execute" | **Inferred** |
| Param roles via parent/base ctor | **Probable** |
| Runtime | Open |

## Gaps

1. Product method demangle for vtbl+0x2C.
2. HitCharge tail field English at `+0x6c0` / `+0x6c4`.
3. Dispatch site of the virtual slot (not dualled here).
4. Runtime / bit-exact / differential.
