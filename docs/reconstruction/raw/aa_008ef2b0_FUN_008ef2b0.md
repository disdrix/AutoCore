# Raw capture: FUN_008ef2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ef2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ef2b0` |
| **Canonical name** | `FUN_008ef2b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_008ef2b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvVar6;
  void *pvVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  uint uVar13;
  undefined1 auStack_4a8 [3];
  char cStack_4a5;
  uint local_4a4;
  int local_4a0;
  int iStack_49c;
  int local_498;
  int iStack_494;
  undefined1 *puStack_490;
  undefined1 auStack_48c [128];
  char acStack_40c [1024];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b3a93;
  local_c = ExceptionList;
  local_4a4 = 0;
  ExceptionList = &local_c;
  FUN_007a69d0();
  if (0x9c44 < param_3) {
    if (param_2 == 5) {
      piVar3 = (int *)FUN_008eb970(param_3);
      if (piVar3 != (int *)0x0) {
        puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x140))(&local_498,1);
        puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0x120))(auStack_4a8,1,0);
        FUN_008ec6d0(*puVar5,puVar5[1],*puVar4,puVar4[1]);
      }
      ExceptionList = local_c;
      return 1;
    }
    if (param_2 == 6) {
      FUN_008ebe60();
      ExceptionList = local_c;
      return 1;
    }
    if ((param_2 == 8) && (DAT_00d1b6d8 != 0)) {
      if (*(int *)(param_1 + 0x50c) == 0) {
        FUN_008eec60(param_3 + -0x9c45);
      }
      ExceptionList = local_c;
      return 1;
    }
  }
  switch(param_3 + -40000) {
  case 0:
    if (param_2 == 8) {
      FUN_007fca10();
      ExceptionList = local_c;
      return 1;
    }
    break;
  default:
    if (param_2 == 7) {
      if (((*(int **)(param_1 + 0x67c) != (int *)0x0) && (*(int *)(param_1 + 0x50c) == 1)) &&
         (*(int *)(DAT_00d1b644 + 0xfc) == *(int *)(param_1 + 0x540))) {
        (**(code **)(**(int **)(param_1 + 0x67c) + 0x120))(&local_4a0,1,1);
        (**(code **)(**(int **)(param_1 + 0x67c) + 0x140))(&local_4a4,1);
        if (((DAT_00d1d86c < local_4a0) || (local_498 + local_4a0 <= DAT_00d1d86c)) ||
           ((DAT_00d1d870 < iStack_49c ||
            ((iStack_494 + iStack_49c <= DAT_00d1d870 || (cVar2 = FUN_0084f810(), cVar2 == '\0')))))
           ) {
          DAT_00d1ad1c = 0;
        }
      }
    }
    else if ((param_2 == 0xe) && (*(int *)(param_1 + 0x50c) == 1)) {
      FUN_008ed8a0();
    }
    break;
  case 2:
    if (param_2 == 8) {
      if (*(int *)(param_1 + 0x50c) == 0) {
        FUN_008ec980();
      }
      ExceptionList = local_c;
      return 1;
    }
    break;
  case 3:
    if (param_2 == 8) {
      if (*(int *)(param_1 + 0x50c) == 0) {
        FUN_008ec980();
        ExceptionList = local_c;
        return 1;
      }
      if (*(int *)(param_1 + 0x50c) == 1) {
        FUN_008ed8a0();
      }
      ExceptionList = local_c;
      return 1;
    }
    break;
  case 4:
    if (param_2 == 8) {
      if (((*(int *)(param_1 + 0x50c) == 1) && (DAT_00d1b6d8 != 0)) &&
         (uVar13 = *(uint *)(param_1 + 0x540), -1 < (int)uVar13)) {
        *(undefined4 *)(param_1 + 0x548) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x54c) = 0xffffffff;
        *(uint *)(param_1 + 0x544) = uVar13;
        pvVar6 = (void *)FUN_00541a80();
        pvVar6 = CNDHash_LookupByKey(pvVar6,uVar13);
        iVar1 = DAT_00d1b644;
        if ((DAT_00d1b644 == 0) ||
           (cStack_4a5 = '\x01', *(int *)(DAT_00d1b644 + 0xfc) != *(int *)(param_1 + 0x540))) {
          cStack_4a5 = '\0';
        }
        uVar13 = *(uint *)(param_1 + 0x540);
        pvVar7 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x534),uVar13);
        if (((pvVar7 != (void *)0x0) && (*(char *)((int)pvVar7 + 4) == '\x02')) ||
           (cStack_4a5 == '\x01')) {
          if ((iVar1 == 0) || (*(uint *)(iVar1 + 0xfc) != uVar13)) {
            if (pvVar6 == (void *)0x0) {
              pcVar12 = "this location";
            }
            else {
              puVar4 = (undefined4 *)FUN_00402d50((int)pvVar6 + 0xb4);
              uStack_4 = 0;
              pcVar12 = (char *)*puVar4;
              local_4a4 = 1;
            }
            uVar11 = FUN_007a6de0(pcVar12,0xffffffff);
            uVar8 = FUN_007a6de0("is that correct?",0xffffffff);
            uVar9 = FUN_007a6de0("for a small fee",0xffffffff);
            uVar10 = FUN_007a6de0("INC will pick you up and drop you off at",0xffffffff);
            sprintf(acStack_40c,"%s %s %s, %s",uVar10,uVar11,uVar9,uVar8);
            uStack_4 = 0xffffffff;
            if (((local_4a4 & 1) != 0) && (puStack_490 != auStack_48c)) {
              free(puStack_490);
            }
          }
          else {
            uVar11 = FUN_007a6de0("is that correct?",0xffffffff);
            uVar8 = FUN_007a6de0("the nearest repair station",0xffffffff);
            uVar9 = FUN_007a6de0("INC will pick you up and drop you off at",0xffffffff);
            sprintf(acStack_40c,"%s %s, %s",uVar9,uVar8,uVar11);
          }
          FUN_007fdfb0(&DAT_00d1a840,acStack_40c,0x4e23,1,0);
          ExceptionList = local_c;
          return 1;
        }
        uVar10 = 0;
        uVar9 = 1;
        uVar8 = 0xffffffff;
        uVar11 = FUN_007a6de0("INC cannot drop you off at a location you have not been to yet!",
                              0xffffffff);
        FUN_007fdfb0(&DAT_00d1a840,uVar11,uVar8,uVar9,uVar10);
      }
      ExceptionList = local_c;
      return 1;
    }
  }
  uVar11 = FUN_0087b500(param_2,param_3);
  ExceptionList = local_c;
  return uVar11;
}
```
