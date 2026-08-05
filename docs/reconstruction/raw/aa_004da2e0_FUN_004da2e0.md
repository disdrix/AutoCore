# Raw capture: FUN_004da2e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da2e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004da2e0` |
| **Canonical name** | `FUN_004da2e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_004da2e0(int param_1,TFID_16 *param_2,uint param_3,int *param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,uint param_8,uint param_9,undefined4 param_10,
            undefined4 param_11,undefined4 *param_12)

{
  TFID_16 *pTfid;
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  TFID_16 *pTVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a2290;
  pvStack_c = ExceptionList;
  puVar7 = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (0 < (int)param_3) {
    pTVar8 = param_2 + 1;
    ExceptionList = &pvStack_c;
    do {
      pTfid = pTVar8 + -1;
      piVar3 = Object_ResolveFromTFID(pTfid);
      if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x198))(), cVar1 == '\0')) {
        uStack_2c = *(undefined4 *)((int)&pTVar8->dwCoidHi + 2);
        uStack_28._0_1_ = pTVar8->bPad1;
        uStack_28._1_1_ = pTVar8->bPad2;
        uStack_28._2_1_ = pTVar8->bPad3;
        uStack_28._3_1_ = pTVar8->bPad4;
        uStack_24 = CONCAT31(uStack_24._1_3_,pTVar8->bPad5);
        uVar2 = FUN_004d78e0(*(undefined1 *)((int)&pTVar8->dwCoidHi + 1),pTVar8->dwCoidLo,param_4,
                             piVar3,param_6,param_7,param_8,param_9,param_10,param_11,&uStack_2c);
        *(undefined1 *)&pTVar8->dwCoidHi = uVar2;
        param_2 = pTfid;
        if ((local_18 == (undefined4 *)0x0) ||
           ((uint)(local_10 - (int)local_18 >> 2) <= (uint)((int)puVar7 - (int)local_18 >> 2))) {
          FUN_004e39d0(puVar7,1,&param_2);
          puVar7 = local_14;
        }
        else {
          *puVar7 = pTfid;
          local_14 = puVar7 + 1;
          puVar7 = local_14;
        }
      }
      pTVar8 = pTVar8 + 2;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    param_3 = 0;
  }
  if (*(char *)(param_1 + 0x7e) == '\0') goto LAB_004da600;
  if (local_18 == (undefined4 *)0x0) {
    ExceptionList = pvStack_c;
    return;
  }
  uVar9 = (int)puVar7 - (int)local_18 >> 2;
  param_3 = uVar9;
  if (uVar9 == 0) goto LAB_004da600;
  puVar4 = operator_new(0x28);
  piVar3 = param_4;
  puVar7 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[9] = 0;
    puVar7 = puVar4;
  }
  *(undefined1 *)(puVar7 + 8) = (undefined1)param_6;
  if (param_4 == (int *)0x0) {
    piVar3 = &DAT_009cbf68;
LAB_004da529:
    puVar7[4] = *piVar3;
    puVar7[5] = piVar3[1];
    puVar7[6] = piVar3[2];
LAB_004da53e:
    iVar5 = piVar3[3];
  }
  else {
    piVar6 = param_4;
    if (*(int *)(param_4[0x2a] + 0x38) != 0x12) {
      piVar3 = param_4 + 0x58;
      uVar9 = param_3;
      goto LAB_004da529;
    }
    while (*(int *)(piVar6[0x2a] + 0x38) == 0x12) {
      iVar5 = (**(code **)(*piVar6 + 0x1d8))();
      uStack_2c = *(undefined4 *)(iVar5 + 0x228);
      uStack_28 = *(undefined4 *)(iVar5 + 0x22c);
      uStack_24 = *(undefined4 *)(iVar5 + 0x230);
      uStack_20 = *(undefined4 *)(iVar5 + 0x234);
      iVar5 = FUN_004bb070(&uStack_2c);
      if ((iVar5 == 0) ||
         (piVar6 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5), piVar6 == (int *)0x0))
      goto LAB_004da4c7;
    }
    if (*(int *)(piVar6[0x2a] + 0x38) == 0x14) {
      piVar3 = piVar6 + 0x58;
      puVar7[4] = *piVar3;
      puVar7[5] = piVar6[0x59];
      puVar7[6] = piVar6[0x5a];
      uVar9 = param_3;
      goto LAB_004da53e;
    }
LAB_004da4c7:
    puVar7[4] = piVar3[0x58];
    puVar7[5] = piVar3[0x59];
    puVar7[6] = piVar3[0x5a];
    iVar5 = piVar3[0x5b];
    uVar9 = param_3;
  }
  puVar4 = puVar7 + 4;
  puVar7[7] = iVar5;
  if (((param_8 & param_9) != 0xffffffff) || ((char)param_10 != '\0')) {
    puVar4 = &param_8;
  }
  *puVar7 = *puVar4;
  puVar7[1] = puVar4[1];
  puVar7[2] = puVar4[2];
  puVar7[3] = puVar4[3];
  *(short *)((int)puVar7 + 0x22) = (short)uVar9;
  puVar4 = operator_new__((uVar9 & 0xffff) << 5);
  puVar7[9] = puVar4;
  if (uVar9 == 0) {
    puVar4 = (undefined4 *)FUN_004e0eb0();
  }
  puVar10 = (undefined4 *)*local_18;
  for (uVar9 = ((uint)*(ushort *)((int)puVar7 + 0x22) << 5) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar4 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar4 = *(undefined1 *)puVar10;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  if (param_12 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar7[9] + 0x1c) = *(undefined1 *)((int)param_12 + 6);
    *(undefined1 *)(puVar7[9] + 0x1d) = *(undefined1 *)((int)param_12 + 7);
    *(undefined1 *)(puVar7[9] + 0x1e) = *(undefined1 *)(param_12 + 2);
    iVar5 = puVar7[9];
    *(undefined4 *)(iVar5 + 0x16) = *param_12;
    *(undefined2 *)(iVar5 + 0x1a) = *(undefined2 *)(param_12 + 1);
  }
  FUN_004e1600(puVar7);
LAB_004da600:
  if (local_18 == (undefined4 *)0x0) {
    ExceptionList = pvStack_c;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(local_18);
}
```
