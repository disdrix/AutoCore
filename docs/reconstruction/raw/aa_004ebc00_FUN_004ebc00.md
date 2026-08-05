# Raw capture: FUN_004ebc00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ebc00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ebc00` |
| **Canonical name** | `FUN_004ebc00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004ebc00(int param_1,undefined4 *param_2,float *param_3)

{
  undefined4 uVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90 [4];
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c [9];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  void *local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a27a8;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x90) == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  FUN_004f3230(*(int *)(param_1 + 0x90));
  local_4 = 0;
  if ((_DAT_00b03e88 & 1) == 0) {
    _DAT_00b03e88 = _DAT_00b03e88 | 1;
  }
  _DAT_00b03e7c = param_3[1];
  _DAT_00b03e80 = param_3[2];
  _DAT_00b03e78 = *param_3;
  _DAT_00b03e84 = param_3[3];
  local_98 = _DAT_00b03e7c * _DAT_00b03e7c * g_flLevelUpUiBase_Inferred;
  local_94 = _DAT_00b03e80 * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;
  fVar7 = _DAT_00b03e78 * _DAT_00b03e7c * g_flLevelUpUiBase_Inferred;
  fVar5 = _DAT_00b03e80 * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;
  local_90[0] = (g_flOne - local_98) - local_94;
  local_90[1] = fVar7 - fVar5;
  fVar9 = _DAT_00b03e7c * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;
  fVar8 = _DAT_00b03e78 * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;
  local_90[2] = fVar9 + fVar8;
  local_90[3] = fVar5 + fVar7;
  fVar7 = _DAT_00b03e78 * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;
  fVar6 = g_flOne - _DAT_00b03e78 * _DAT_00b03e78 * g_flLevelUpUiBase_Inferred;
  fVar5 = _DAT_00b03e7c * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;
  local_80 = fVar6 - local_94;
  local_7c = fVar5 - fVar7;
  local_78 = fVar8 - fVar9;
  local_74 = fVar7 + fVar5;
  local_70 = fVar6 - local_98;
  if ((_DAT_00b03e74 & 1) == 0) {
    _DAT_00b03e74 = _DAT_00b03e74 | 1;
  }
  _DAT_00b03e70 = param_2[2];
  _DAT_00b03e6c = param_2[1];
  _DAT_00b03e68 = *param_2;
  pfVar3 = local_90;
  pfVar4 = local_6c;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  local_a0 = 0;
  local_9c = _DAT_00b03e84;
  local_48 = _DAT_00b03e68;
  local_44 = _DAT_00b03e6c;
  local_40 = _DAT_00b03e70;
  FUN_004cf860(&local_a0,local_6c);
  uVar1 = local_a0;
  if (local_1c != (void *)0x0) {
    free(local_1c);
  }
  ExceptionList = local_c;
  return uVar1;
}
```
