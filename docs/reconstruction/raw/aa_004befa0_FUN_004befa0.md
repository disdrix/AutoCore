# Raw capture: FUN_004befa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004befa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004befa0` |
| **Canonical name** | `FUN_004befa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004befa0(int param_1,undefined4 param_2,float *param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  bool bVar15;
  
  *(undefined1 *)(param_1 + 0x5a4) = 1;
  iVar1 = *(int *)(*(int *)(param_1 + 0x5d4) + 0xe894);
  iVar12 = param_1 + 0x444;
  if (*(char *)(param_1 + 0x5c4) == '\0') {
    iVar12 = param_1 + 0x474;
  }
  iVar12 = FUN_0075c960(iVar12,&DAT_00d1eb60);
  bVar15 = iVar12 != -1;
  if (bVar15) {
    *(int *)(iVar1 + 0x114) = *(int *)(iVar1 + 0x114) + 1;
  }
  iVar13 = FUN_0075c960(param_1 + 0x414,&DAT_00d1eb60);
  if (iVar13 != -1) {
    *(int *)(iVar1 + 0x118) = *(int *)(iVar1 + 0x118) + 1;
  }
  if ((bVar15) || (iVar13 != -1)) {
    if ((iVar12 != 0) || (bVar10 = false, iVar13 != 0)) {
      bVar10 = true;
    }
    FUN_004bef20();
    thunk_FUN_0076c4d0();
    fVar8 = *(float *)(param_1 + 0x5a0) - param_3[2];
    fVar9 = *(float *)(param_1 + 0x598) - *param_3;
    fVar8 = SQRT(fVar8 * fVar8 + fVar9 * fVar9);
    FUN_004bdf80();
    ceil((double)((float)*param_5 * g_flMultiKillCountBlend));
    FUN_004beb10();
    iVar12 = FUN_0076c3c0();
    *param_5 = *param_5 - iVar12;
    FUN_004bdf80();
    if (((bVar15) && (*(char *)(param_1 + 0x5b0) != '\0')) && (*(char *)(iVar1 + 0x81) != '\0')) {
      if (DAT_00b03740 != '\0') {
        (**(code **)(*(int *)(param_1 + 0x2c8) + 0x3c))();
        (**(code **)(*(int *)(param_1 + 0x2c8) + 0x40))(param_2);
      }
      if ((*(char *)(iVar1 + 0x80) != '\0') && (fVar8 < DAT_00aef954 + _DAT_00aefa4c)) {
        (**(code **)(*(int *)(param_1 + 0x30) + 0x3c))();
        (**(code **)(*(int *)(param_1 + 0x30) + 0x40))(param_2);
        cVar11 = FUN_004bd640();
        if (cVar11 == '\0') {
          (**(code **)(*(int *)(param_1 + 0x17c) + 0x3c))();
        }
      }
    }
    if ((*(char *)(param_1 + 0x5b0) != '\0') || (DAT_00aef954 + _DAT_00aefa4c <= fVar8)) {
      bVar15 = false;
    }
    else {
      bVar15 = true;
    }
    if ((DAT_00b03740 == '\0') || (bVar15)) {
      iVar12 = param_1 + 0x10;
    }
    else {
      iVar12 = param_1 + 0x20;
    }
    iVar13 = *(int *)(iVar12 + 4);
    while (*(int *)(iVar12 + 8) = iVar13, iVar13 != 0) {
      piVar2 = *(int **)(iVar13 + 0xc);
      iVar13 = piVar2[1];
      if ((iVar13 == 0) ||
         ((((*(char *)(*(int *)(param_1 + 0x5d4) + 0x7d) == '\0' ||
            ((((iVar3 = *(int *)(*(int *)(param_1 + 0x5d4) + 0xe898),
               *(char *)(iVar3 + 0x4e) != '\0' ||
               (*(int *)(*(int *)(iVar13 + 0xac + *(int *)(*(int *)(iVar13 + 4) + 4)) + 0x38) !=
                0x36)) &&
              ((*(char *)(iVar3 + 0x4f) != '\0' ||
               (*(int *)(*(int *)(piVar2[1] + 0xac + *(int *)(*(int *)(piVar2[1] + 4) + 4)) + 0x38)
                != 0x38)))) &&
             ((*(char *)(iVar3 + 0x51) != '\0' ||
              ((*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(piVar2[1] + 4) + 4) + 0xac + piVar2[1]
                                           ) + 0x3c) + 0x3f2) & 0x20) == 0)))))) &&
           ((*(char *)(iVar1 + 0x84) != '\0' ||
            ((*(uint *)(*(int *)(*(int *)(piVar2[1] + 4) + 4) + 0x180 + piVar2[1]) >> 5 & 1) == 0)))
           ) && ((*(char *)(iVar1 + 0x83) != '\0' ||
                 ((*(uint *)(*(int *)(*(int *)(piVar2[1] + 4) + 4) + 0x180 + piVar2[1]) >> 5 & 1) !=
                  0)))))) {
        if ((int *)*piVar2 == (int *)0x0) {
          if (*(char *)(iVar13 + 0xf) == '\0') {
            iVar13 = piVar2[1];
            iVar3 = *(int *)(*(int *)(iVar13 + 4) + 4);
            uVar4 = *(undefined4 *)(*(int *)(iVar3 + 0xac + iVar13) + 0x34);
            uVar5 = *(undefined4 *)(iVar3 + 0x168 + iVar13);
            uVar6 = *(undefined4 *)(iVar3 + iVar13 + 0x164);
            uVar14 = (**(code **)(*(int *)(iVar3 + iVar13 + 4) + 0x160))();
            FUN_007a4480(1,"Body for object is missing! %d %I64d %s",uVar4,uVar6,uVar5,uVar14);
          }
        }
        else if ((bVar10) &&
                ((*(int *)(iVar1 + 0xc0) == 0 ||
                 (iVar13 = (**(code **)(*(int *)*piVar2 + 0x68))(), iVar13 == -1)))) {
          if ((DAT_00aefa54 != '\0') && (iVar13 = FUN_0096da40(), iVar13 != -1)) {
            (**(code **)(*(int *)*piVar2 + 0x40))();
          }
        }
        else {
          FUN_004506a0();
          piVar7 = (int *)piVar2[1];
          if ((piVar7 != (int *)0x0) && ((char)piVar7[3] != '\0')) {
            iVar13 = *piVar7;
            FUN_0079a110();
            (**(code **)(iVar13 + 0x28))();
            (**(code **)(*(int *)*piVar2 + 0x10))(3);
          }
        }
      }
      if ((*(int *)(iVar12 + 8) == 0) || (iVar13 = *(int *)(*(int *)(iVar12 + 8) + 4), iVar13 == 0))
      break;
    }
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x5d4) + 0xe898) + 0x4d) != '\0') {
      FUN_004506a0();
    }
  }
  return;
}
```
