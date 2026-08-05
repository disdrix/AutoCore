# Annotated low-level: FUN_005ccbd0

| Field | Value |
|---|---|
| Stable ID | `aa_005ccbd0` |
| VA | `0x005ccbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ccbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005ccbd0(int *param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  iVar1 = __RTDynamicCast(*(undefined4 *)(param_1[6] + 0xa0),0,
                          &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                          &CVOGPhysicsBase::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) == 0) {
      pfVar2 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);
    }
    else {
      pfVar2 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);
    }
    local_20 = *pfVar2;
    local_1c = pfVar2[1];
    local_18 = pfVar2[2];
    local_14 = pfVar2[3];
    pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +
                                           param_1[0x19]) + 0x1a0))();
    local_20 = local_20 - *pfVar2;
    local_1c = local_1c - pfVar2[1];
    local_18 = local_18 - pfVar2[2];
    fVar3 = local_18 * local_18 + local_1c * local_1c + local_20 * local_20;
    fVar4 = 0.0;
    if (fVar3 != 0.0) {
      fVar4 = g_flOne / SQRT(fVar3);
    }
    local_20 = fVar4 * local_20 * DAT_00aaa668 * DAT_00aaa7ac;
    local_1c = fVar4 * local_1c * DAT_00aaa668 * DAT_00aaa7ac;
    local_18 = local_18 * fVar4 * DAT_00aaa668 * DAT_00aaa7ac;
    local_14 = (local_14 - pfVar2[3]) * fVar4 * DAT_00aaa668 * DAT_00aaa7ac;
    pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +
                                           param_1[0x19]) + 0x1a0))();
    local_20 = local_20 + *pfVar2;
    local_1c = pfVar2[1] + local_1c;
    local_18 = pfVar2[2] + local_18;
    local_14 = pfVar2[3] + local_14;
    if (SQRT(fVar3) < DAT_00aaa884) {
      (**(code **)(*param_1 + 0x4c))(&local_20,1);
    }
    return;
  }
  pfVar2 = (float *)(**(code **)(*(int *)param_1[6] + 0x1a4))();
  local_20 = (pfVar2[3] * pfVar2[1] + pfVar2[2] * *pfVar2) * g_flLevelUpUiBase_Inferred *
             DAT_00aaa7ac;
  local_1c = (pfVar2[2] * pfVar2[1] - pfVar2[3] * *pfVar2) * g_flLevelUpUiBase_Inferred *
             DAT_00aaa7ac;
  local_18 = (g_flOne - (*pfVar2 * *pfVar2 + pfVar2[1] * pfVar2[1]) * g_flLevelUpUiBase_Inferred) *
             DAT_00aaa7ac;
  local_14 = 0.0;
  pfVar2 = (float *)(**(code **)(*(int *)param_1[6] + 0x1a0))();
  local_20 = *pfVar2 + local_20;
  local_1c = pfVar2[1] + local_1c;
  local_18 = pfVar2[2] + local_18;
  local_14 = pfVar2[3] + local_14;
  (**(code **)(*param_1 + 0x4c))(&local_20,1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
