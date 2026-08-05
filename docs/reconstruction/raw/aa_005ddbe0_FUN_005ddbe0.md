# Raw capture: FUN_005ddbe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ddbe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ddbe0` |
| **Canonical name** | `FUN_005ddbe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005ddbe0(int param_1,void *param_2,int param_3,int param_4)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  uint extraout_ECX;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009a7250;
  local_10 = ExceptionList;
  iVar7 = *(int *)(param_1 + 4);
  uVar5 = param_4 - param_3 >> 3;
  if (iVar7 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc) - iVar7 >> 3;
  }
  uVar8 = CONCAT44(iVar7,iVar1);
  if (uVar5 != 0) {
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(param_1 + 8) - iVar7 >> 3;
    }
    uVar6 = uVar5;
    ExceptionList = &local_10;
    if (0x1fffffffU - iVar7 < uVar5) {
      ExceptionList = &local_10;
      uVar8 = FUN_00418130();
      uVar6 = extraout_ECX;
    }
    iVar7 = (int)((ulonglong)uVar8 >> 0x20);
    uVar2 = (uint)uVar8;
    if (iVar7 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 8) - iVar7 >> 3;
    }
    if (uVar2 < iVar1 + uVar6) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar7 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 8) - iVar7 >> 3;
      }
      if (uVar2 < iVar1 + uVar6) {
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(param_1 + 8) - iVar7 >> 3;
        }
        uVar2 = iVar7 + uVar6;
      }
      _Dst = operator_new(uVar2 * 8);
      _Size = ((int)param_2 - (int)*(void **)(param_1 + 4) >> 3) * 8;
      local_8 = 0;
      pvVar3 = memmove(_Dst,*(void **)(param_1 + 4),_Size);
      pvVar3 = (void *)FUN_006a2be0(param_3,param_4,(void *)((int)pvVar3 + _Size),param_1,param_3);
      memmove(pvVar3,param_2,(*(int *)(param_1 + 8) - (int)param_2 >> 3) * 8);
      pvVar3 = *(void **)(param_1 + 4);
      if (pvVar3 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(param_1 + 8) - (int)pvVar3 >> 3;
      }
      if (pvVar3 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar3);
      }
      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 8 + (int)_Dst);
      *(void **)(param_1 + 8) = (void *)((int)_Dst + (uVar5 + iVar7) * 8);
      *(void **)(param_1 + 4) = _Dst;
      ExceptionList = local_10;
      return;
    }
    iVar7 = *(int *)(param_1 + 8);
    if ((uint)(iVar7 - (int)param_2 >> 3) < uVar6) {
      FUN_004190b0(param_2,iVar7,(void *)(uVar6 * 8 + (int)param_2));
      iVar7 = param_3 + (*(int *)(param_1 + 8) - (int)param_2 >> 3) * 8;
      local_8 = 2;
      FUN_006a2be0(iVar7,param_4,*(int *)(param_1 + 8),param_1,param_3);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar6 * 8;
      FUN_005dd960(param_3,iVar7,param_2);
      ExceptionList = local_10;
      return;
    }
    iVar1 = iVar7 + uVar6 * -8;
    uVar4 = FUN_004190b0(iVar1,iVar7,iVar7);
    *(undefined4 *)(param_1 + 8) = uVar4;
    FUN_004190e0(param_2,iVar1,iVar7);
    FUN_005dd960(param_3,param_4,param_2);
  }
  ExceptionList = local_10;
  return;
}
```
