# Raw capture: FUN_0041fae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041fae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0041fae0` |
| **Canonical name** | `FUN_0041fae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall
FUN_0041fae0(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,uint param_5)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  uint extraout_ECX;
  undefined4 *puVar6;
  undefined4 local_3ec [245];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009bcdf0;
  local_10 = ExceptionList;
  puVar6 = local_3ec;
  for (iVar5 = 0xf5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *param_2;
    param_2 = param_2 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar5 = *(int *)(param_3 + 4);
  if (iVar5 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = (*(int *)(param_3 + 0xc) - iVar5) / 0x3d4;
  }
  if (param_5 != 0) {
    if (iVar5 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(param_3 + 8) - iVar5) / 0x3d4;
    }
    ExceptionList = &local_10;
    local_14 = &stack0xfffffc08;
    if ((uint)((int)&LAB_0042df9b - iVar2) < param_5) {
      ExceptionList = &local_10;
      local_14 = &stack0xfffffc08;
      FUN_004540b0();
      local_18 = extraout_ECX;
    }
    if (iVar5 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(param_3 + 8) - iVar5) / 0x3d4;
    }
    if (local_18 < iVar2 + param_5) {
      if ((int)&LAB_0042df9b - (local_18 >> 1) < local_18) {
        local_18 = 0;
      }
      else {
        local_18 = local_18 + (local_18 >> 1);
      }
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (*(int *)(param_3 + 8) - iVar5) / 0x3d4;
      }
      if (local_18 < iVar5 + param_5) {
        iVar5 = FUN_0041afc0();
        local_18 = iVar5 + param_5;
      }
      local_18 = local_18 * 0x3d4;
      pvVar3 = operator_new(local_18);
      local_8 = 0;
      FUN_00422770(param_4);
      FUN_004220f0(param_4);
      FUN_00422770(param_4);
      pvVar1 = *(void **)(param_3 + 4);
      if (pvVar1 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (*(int *)(param_3 + 8) - (int)pvVar1) / 0x3d4;
      }
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      *(uint *)(param_3 + 0xc) = local_18 + (int)pvVar3;
      *(void **)(param_3 + 8) = (void *)((int)pvVar3 + (param_5 + iVar5) * 0x3d4);
      *(void **)(param_3 + 4) = pvVar3;
      ExceptionList = local_10;
      return;
    }
    if ((uint)((*(int *)(param_3 + 8) - param_4) / 0x3d4) < param_5) {
      FUN_00422770(param_4);
      local_8 = 2;
      FUN_0041cb10(param_3);
      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + param_5 * 0x3d4;
    }
    else {
      uVar4 = FUN_00422770(param_4);
      *(undefined4 *)(param_3 + 8) = uVar4;
      FUN_004222f0(param_4);
    }
    FUN_00421fa0();
  }
  ExceptionList = local_10;
  return;
}
```
