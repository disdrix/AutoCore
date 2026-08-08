# Function record: CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617df0` |
| **Canonical name** | `CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred` |
| **Prior** | `FUN_00617df0` |
| **Address** | `0x00617df0` |
| **Body** | `0x00617df0`–`0x00617f2c` inclusive (**317 B** / `0x13D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | Class **Confirmed** RTTI `.?AVCVOGHBSkill_OnHit@@`; method role **High**; product method English **Inferred** |
| **Completion status** | Dual A/B sealed R11-013 2026-08-05 — **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

Virtual **multi-target spawn** for `CVOGHBSkill_OnHit` heartbeat actions (vtbl `PTR_FUN_009d0f1c` **+0x2c**):

- Iterate target descriptors (stride `0x10`) until terminator `{-1,-1,type0}`.
- Resolve each via `CVOGReaction_ResolveObjectTarget` (`this = *(world+0xe4e8)`).
- Construct `0x6d0` OnHit HB: `CVOGHBSkillBase_ctor` + install OnHit vtbl + optional period from skill float `+0x4c`.
- On attach success (`pOwner@+0x18`): Enqueue `*(world+0xe4ec)` then `CVOGHBBase_Start`.
- On reject: scalar-deleting dtor `vtbl[0](1)` → `FUN_00651190`.

## Signature

```c
uint32_t __stdcall CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred(
    void *pSourceObj,     // base ctor source
    void *pSkillBlob,     // float +0x4c → period
    void *pWorld,         // +0xe4e8 reaction; +0xe4ec HB list
    TargetEntry16 *pList, // {id0,id1,type} stride 0x10
    void *pTfid16,
    uint32_t arg7);
// Virtual ECX this ignored. RET 0x18. EAX = 1 on terminator.
```

### TargetEntry16

| Off | Type | Role |
|----:|------|------|
| +0 | i32 | id0 |
| +4 | i32 | id1 |
| +8 | u8 | type (Resolve gate) |
| terminator | | id0=id1=-1 and type=0 |

### Spawned action layout (touched here)

| Off | Type | Role |
|----:|------|------|
| +0x00 | ptr | vtbl → `PTR_FUN_009d0f1c` |
| +0x18 | ptr | `pOwnerObject` (attach gate) |
| +0x6c0 | i32 | period ms (trunc float) |
| +0x6c4 | u8 | period enable |
| size | | **0x6d0** |

## Sealed control flow

```
index = 0
loop:
  e = pList + index*0x10
  if terminator: return 1
  t = ResolveObjectTarget(*(pWorld+0xe4e8), e.type, e.id0, e.id1)
  if t:
    a = operator_new(0x6d0)
    if a:
      CVOGHBSkillBase_ctor(a, source, skill, world, t, tfid, arg7)
      a.vtbl = OnHit
      if skill.float(+0x4c)==0: a[+0x6c4]=0
      else: a[+0x6c4]=1; a[+0x6c0]=(int)trunc(float)
    if a.owner(+0x18): Enqueue(*(pWorld+0xe4ec), a); Start(a)
    else: a.vtbl[0](a, 1)
  index++
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00617df0_FUN_00617df0.md`
- Annotated: `docs/reconstruction/raw/aa_00617df0_FUN_00617df0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00617df0.cpp`
- Dual A/B: `docs/reconstruction/reviews/A|B_aa_00617df0_CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.md`
- Report: `docs/agents/task-dual-ab-00617df0-r11-report.md`

## Callers / callees

- **Callers:** virtual only (DATA `0x009d0f48`).
- **Sibling ctor (not OWN):** `FUN_00617ad0` — same vtbl + period pattern.
- **Base (partition parent):** `CVOGHBSkillBase_ctor` `0x005788d0`.
- **Callees:** ResolveObjectTarget, operator_new, CVOGHBSkillBase_ctor, CVOGHBList_Enqueue, CVOGHBBase_Start, FUN_00651190.

## Confidence

| Claim | Level |
|---|---|
| Product class `CVOGHBSkill_OnHit` | **Confirmed** (RTTI) |
| Multi-target spawn CF / ABI | **Confirmed** |
| Period offsets | **Confirmed** |
| Method product English | Inferred |
| Runtime | Open |

## Gaps

1. Product method name.  
2. List producers / virtual invokers.  
3. Null-new UB path.  
4. Runtime / bit-exact.
