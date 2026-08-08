# Function record: CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617fc0` |
| **Canonical name** | `CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred` |
| **Prior** | `FUN_00617fc0` |
| **Address** | `0x00617fc0` |
| **Body** | `0x00617fc0`–`0x006180fb` inclusive (**316 B** / `0x13C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | Class **Confirmed** RTTI `.?AVCVOGHBSkill_Reflect@@`; method role **High**; product method English **Inferred** |
| **Completion status** | Dual A/B sealed R12-039 2026-08-05 — **accept-with-gaps** |
| **Terminal** | **false** |
| **Partition** | R12-039; parent dual `0x00617ad0` (`CVOGHBSkill_OnHit_ctor`) |
| **Dual start** | 2646 |

## Purpose

Virtual **multi-target spawn** for `CVOGHBSkill_Reflect` heartbeat actions (vtbl `PTR_FUN_009d0f7c` **+0x2c**):

- Iterate target descriptors (stride `0x10`) until terminator `{-1,-1,type0}`.
- Resolve each via `CVOGReaction_ResolveObjectTarget` (`this = *(world+0xe4e8)`).
- If target clone type `*(*(t+0xa8)+0x38) == 0xe` (vehicle): RTDynamicCast to `CVOGVehicle`, remap to host `*(*(*(veh+4)+4)+veh+0xb0)`.
- Construct `0x6d0` Reflect HB: `CVOGHBSkill_OnHit_ctor` + install Reflect vtbl (period seeded inside OnHit ctor).
- On attach success (`pOwner@+0x18`): Enqueue `*(world+0xe4ec)` then `CVOGHBBase_Start`.
- On reject: scalar-deleting dtor `vtbl[0](1)` → `FUN_00651190`.

## Signature

```c
uint32_t __stdcall CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred(
    void *pSourceObj,     // base/OnHit ctor source
    void *pSkillBlob,     // float +0x4c → period (via OnHit_ctor)
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
| +0x00 | ptr | vtbl → `PTR_FUN_009d0f7c` |
| +0x18 | ptr | `pOwnerObject` (attach gate) |
| +0x6c0 | i32 | period ms (via OnHit_ctor) |
| +0x6c4 | u8 | period enable (via OnHit_ctor) |
| size | | **0x6d0** |

## Sealed control flow

```
index = 0
loop:
  e = pList + index*0x10
  if terminator: return 1
  t = ResolveObjectTarget(*(pWorld+0xe4e8), e.type, e.id0, e.id1)
  if t:
    if *(*(t+0xa8)+0x38) == 0xe:
      v = RTDynamicCast(t, CVOGClonedObjectBase → CVOGVehicle)
      t = *(*(*(v+4)+4) + v + 0xb0)
    a = operator_new(0x6d0)
    if a:
      CVOGHBSkill_OnHit_ctor(a, source, skill, world, t, tfid, arg7)
      a.vtbl = Reflect
    if a.owner(+0x18): Enqueue(*(pWorld+0xe4ec), a); Start(a)
    else: a.vtbl[0](a, 1)
  index++
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00617fc0_FUN_00617fc0.md`
- Annotated: `docs/reconstruction/raw/aa_00617fc0_FUN_00617fc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00617fc0.cpp`
- Dual A/B: `docs/reconstruction/reviews/A|B_aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md`
- Report: `docs/agents/task-dual-ab-00617fc0-r12-report.md`

## Callers / callees

- **Callers:** virtual only (DATA `0x009d0fa8`).
- **Parent dual (callee, not OWN):** `CVOGHBSkill_OnHit_ctor` `0x00617ad0`.
- **Contrast (not OWN):** OnHit spawn `FUN_00617df0` (vtbl `009d0f1c` +0x2c; no vehicle remap).
- **Callees:** ResolveObjectTarget, __RTDynamicCast, operator_new, OnHit_ctor, CVOGHBList_Enqueue, CVOGHBBase_Start, FUN_00651190.

## Confidence

| Claim | Level |
|---|---|
| Product class `CVOGHBSkill_Reflect` | **Confirmed** (RTTI) |
| Multi-target spawn CF / ABI | **Confirmed** |
| Vehicle 0xe → host +0xb0 | **Confirmed** (static) |
| Method product English | Inferred |
| Runtime | Open |

## Gaps

1. Product method name.  
2. List producers / virtual invokers.  
3. Null-new / null-cast UB paths.  
4. Runtime / bit-exact.
