# Annotated low-level: FUN_004bd3a0

| Field | Value |
|---|---|
| Stable ID | `aa_004bd3a0` |
| VA | `0x004bd3a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bd3a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004bd3a0(int *param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a179a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0076cf00("Speed Tree updates");
  local_4 = 0;
  local_14 = 0.0;
  if (DAT_00af0a5c != '\0') {
    iVar3 = (**(code **)(*param_1 + 0xc))();
    iVar1 = *(int *)(*(int *)(param_2 + 0x30) + 8);
    fVar6 = *(float *)(iVar3 + 0x90) - *(float *)(iVar1 + 0x90);
    fVar7 = *(float *)(iVar3 + 0x94) - *(float *)(iVar1 + 0x94);
    fVar8 = *(float *)(iVar3 + 0x98) - *(float *)(iVar1 + 0x98);
    fVar6 = SQRT(fVar6 * fVar6 + fVar7 * fVar7 + fVar8 * fVar8) / _DAT_00af0a60;
    if (((fVar6 <= g_flZero) || (local_14 = g_flOne, fVar6 < g_flOne)) &&
       (local_14 = fVar6, fVar6 <= 0.0)) {
      local_14 = 0.0;
    }
    local_14 = g_flOne - local_14;
  }
  FUN_00687150(local_14);
  FUN_00688b20(1,1,1);
  fVar5 = (float10)FUN_00687130();
  *(float *)(param_1[0x54] + 0x28) = (float)fVar5;
  if (*(int *)(param_1[0x54] + 0xc) != 0) {
    FUN_0076cf00("ST Branchbody->Submit");
    local_4._0_1_ = 1;
    uVar2 = FUN_005b4c10(param_1[0x55]);
    *(undefined1 *)(*(int *)(param_1[0x54] + 0xc) + 0xcc) = uVar2;
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0076cef0();
  }
  if (*(int *)(param_1[0x54] + 0x10) != 0) {
    FUN_0076cf00("ST m_pFrondBody->Submit");
    local_4._0_1_ = 2;
    uVar2 = FUN_005b4de0();
    *(undefined1 *)(*(int *)(param_1[0x54] + 0x10) + 0xcc) = uVar2;
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0076cef0();
  }
  FUN_0076cf00("ST m_pLeafBody->Submit");
  local_4._0_1_ = 3;
  FUN_005b4f90();
  local_4._0_1_ = 0;
  FUN_0076cef0();
  FUN_0076cf00("ST m_pBillboardBody->Submit");
  local_4._0_1_ = 4;
  FUN_005b5490();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0076cef0();
  uVar4 = FUN_00763820(param_2);
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return uVar4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
