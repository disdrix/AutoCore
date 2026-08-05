# Raw capture: FUN_0099dbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099dbf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099dbf0` |
| **Canonical name** | `FUN_0099dbf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0099dbf0(int param_1,int param_2)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  float afStack_50 [4];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0044b930(0);
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_0043f4b0();
  }
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x34) == 0) {
    FUN_00967150(*(int *)(param_1 + 0x14) + 0x24);
  }
  FUN_00734550();
  piVar1 = *(int **)(param_2 + 0x10);
  if ((*(byte *)(piVar1 + 0x2f) & 1) != 0) {
    (**(code **)(*piVar1 + 0x5c))();
  }
  if (((piVar1[0x16] != 0) && (piVar1[0x17] != 0)) &&
     (*(int *)(piVar1[0x17] + 0x1c) != piVar1[0x18])) {
    (**(code **)(*piVar1 + 0x80))();
  }
  pfVar2 = (float *)piVar1[0x19];
  if (((uint)pfVar2[0x2f] & 1) != 0) {
    pfVar2 = (float *)FUN_00972e50();
  }
  pfVar4 = afStack_50;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  fStack_60 = ((float)piVar1[0x12] + (float)piVar1[0xf]) * DAT_00a0f298;
  fStack_5c = ((float)piVar1[0x13] + (float)piVar1[0x10]) * DAT_00a0f298;
  fStack_58 = ((float)piVar1[0x14] + (float)piVar1[0x11]) * DAT_00a0f298;
  uStack_54 = 0;
  FUN_0076f240(&fStack_60);
  fStack_20 = fStack_20 + fStack_60;
  fStack_1c = fStack_1c + fStack_5c;
  fStack_18 = fStack_18 + fStack_58;
  fVar7 = (float)piVar1[0x12] - (float)piVar1[0xf];
  fVar5 = (float)piVar1[0x14] - (float)piVar1[0x11];
  fVar6 = (float)piVar1[0x13] - (float)piVar1[0x10];
  afStack_50[0] = afStack_50[0] * fVar7;
  afStack_50[1] = afStack_50[1] * fVar7;
  afStack_50[2] = afStack_50[2] * fVar7;
  fStack_40 = fStack_40 * fVar6;
  fStack_3c = fStack_3c * fVar6;
  fStack_38 = fStack_38 * fVar6;
  fStack_30 = fStack_30 * fVar5;
  fStack_2c = fStack_2c * fVar5;
  fStack_28 = fStack_28 * fVar5;
  if (((piVar1[0x16] != 0) && (piVar1[0x17] != 0)) &&
     (*(int *)(piVar1[0x17] + 0x1c) != piVar1[0x18])) {
    (**(code **)(*piVar1 + 0x80))();
  }
  if ((*(uint *)(piVar1[0x19] + 0xbc) >> 2 & 1) == 0) {
    iVar3 = piVar1[0x19] + 0xa8;
  }
  else {
    iVar3 = FUN_00972b20();
  }
  FUN_00752df0(*(undefined4 *)(param_2 + 4),afStack_50,1,iVar3,0,0);
  return;
}
```
