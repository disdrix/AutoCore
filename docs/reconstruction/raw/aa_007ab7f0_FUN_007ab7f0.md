# Raw capture: FUN_007ab7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ab7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ab7f0` |
| **Canonical name** | `FUN_007ab7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007ab7f0(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uStack_64;
  int *piStack_60;
  undefined4 uStack_5c;
  int *piStack_58;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  int aiStack_28 [2];
  int iStack_20;
  int iStack_1c;
  int local_18;
  int local_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar1 = param_1[0x69];
  if (*(char *)((int)param_1 + 0xd6) == '\0') {
    param_1[0x93] = (int)(float)param_1[0x68];
    param_1[0x94] = (int)(float)iVar1;
    fVar3 = (float)(param_1[0x6a] - param_1[0x68]);
    param_1[0x95] = (int)fVar3;
    param_1[0x98] = (int)((float)param_1[0x6d] / (float)(param_1[0x6b] - iVar1));
    param_1[0x96] = (int)(float)(param_1[0x6b] - iVar1);
    param_1[0x97] = (int)((float)param_1[0x6c] / fVar3);
    local_18 = (int)((float)param_1[0x54] * (float)DAT_00d1e818 * DAT_00aaa67c);
    local_14 = (int)((float)param_1[0x55] * (float)DAT_00d1e81c * DAT_00aaa678);
    (**(code **)(*param_1 + 0x294))();
    if (*(char *)((int)param_1 + 0x1c9) == '\0') {
      fVar3 = (float)DAT_00d1e818 * (float)param_1[0x93];
      fStack_38 = (float)DAT_00d1e81c * (float)param_1[0x94];
    }
    else {
      fVar3 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * (float)param_1[0x93];
      fStack_38 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * (float)param_1[0x94];
    }
    fStack_38 = fStack_38 * DAT_00aaa678;
    fVar3 = fVar3 * DAT_00aaa67c;
    if (*(char *)((int)param_1 + 0x1ca) == '\0') {
      fStack_34 = (float)DAT_00d1e818 * (float)param_1[0x95];
      fStack_30 = (float)DAT_00d1e81c * (float)param_1[0x96];
    }
    else {
      fStack_34 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * (float)param_1[0x95];
      fStack_30 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * (float)param_1[0x96];
    }
    fStack_30 = fStack_30 * DAT_00aaa678;
    fStack_34 = fStack_34 * DAT_00aaa67c;
    iStack_c = (int)fStack_34;
    local_14 = (int)fVar3;
    iStack_10 = (int)fStack_38;
    iStack_8 = (int)fStack_30;
    if ((iStack_c < 1) && (g_flZero < fStack_34)) {
      iStack_c = 1;
    }
    if ((iStack_8 < 1) && (g_flZero < fStack_30)) {
      iStack_8 = 1;
    }
    iStack_c = iStack_c + local_14;
    iStack_8 = iStack_8 + iStack_10;
    piStack_58 = (int *)0x7abc1c;
    (**(code **)(*param_1 + 0x108))();
    fVar7 = DAT_00aaa67c;
    fVar4 = DAT_00aaa678;
    fVar5 = (float)param_1[0x6e] * (float)DAT_00d1e818 * DAT_00aaa67c;
    param_1[0x5d] = (int)((float)param_1[0x6f] * (float)DAT_00d1e81c * DAT_00aaa678);
    iVar2 = DAT_00d17944;
    param_1[0x5c] = (int)fVar5;
    iVar1 = *(int *)(*(int *)(iVar2 + 0x2c) + 0x80);
    param_1[0x59] =
         (int)((float)*(int *)(*(int *)(iVar2 + 0x2c) + 0x84) * (float)param_1[0x57] * fVar4);
    param_1[0x58] = (int)((float)iVar1 * (float)param_1[0x56] * fVar7);
    if (((float)param_1[0x97] != 0.0) || ((float)param_1[0x98] != 0.0)) {
      fStack_30 = (float)(int)ROUND(fVar3);
      aiStack_28[0] = (int)ROUND((float)param_1[0x98] * fStack_34);
      iStack_1c = (int)fStack_30 - aiStack_28[0];
      iStack_20 = (int)ROUND(fStack_40) - (int)ROUND((float)param_1[0x97] * fStack_38);
      piStack_58 = &iStack_20;
      uStack_5c = 0x7abd55;
      (**(code **)(*param_1 + 0x118))();
      return;
    }
  }
  else {
    if (DAT_00d17944 == 0) {
      fVar3 = 0.0;
      fVar4 = 0.0;
    }
    else {
      fVar3 = ((float)param_1[0x68] * DAT_00aaa674) / (float)DAT_00d1e818;
      fVar4 = ((float)iVar1 * DAT_00aaa670) / (float)DAT_00d1e81c;
    }
    fVar7 = (float)(param_1[0x6a] - param_1[0x68]);
    if (DAT_00d17944 == 0) {
      fVar5 = 0.0;
      fVar6 = 0.0;
    }
    else {
      fVar5 = (fVar7 * DAT_00aaa674) / (float)DAT_00d1e818;
      fVar6 = ((float)(param_1[0x6b] - iVar1) * DAT_00aaa670) / (float)DAT_00d1e81c;
    }
    param_1[0x93] = (int)fVar3;
    param_1[0x97] = (int)((float)param_1[0x6c] / fVar7);
    param_1[0x94] = (int)fVar4;
    param_1[0x95] = (int)fVar5;
    param_1[0x96] = (int)fVar6;
    param_1[0x98] = (int)((float)param_1[0x6d] / (float)(param_1[0x6b] - iVar1));
    piStack_58 = (int *)0x7ab907;
    (**(code **)(*param_1 + 0x294))();
    uStack_5c = 0x7ab912;
    piStack_58 = param_1 + 0x68;
    (**(code **)(*param_1 + 0x108))();
    param_1[0x5c] = param_1[0x6e];
    param_1[0x59] = param_1[0x57];
    param_1[0x5d] = param_1[0x6f];
    param_1[0x58] = param_1[0x56];
    if (((float)param_1[0x97] != 0.0) || ((float)param_1[0x98] != 0.0)) {
      uStack_5c = 1;
      piStack_60 = aiStack_28;
      uStack_64 = 0x7ab97c;
      (**(code **)(*param_1 + 0x140))();
      uStack_64 = 0;
      (**(code **)(*param_1 + 0x120))(&fStack_38,1);
      (**(code **)(*param_1 + 0x140))(&stack0xffffffac,1);
      (**(code **)(*param_1 + 0x120))(&uStack_64,1,0);
      (**(code **)(*param_1 + 0x118))(&stack0xffffffb8);
    }
  }
  return;
}
```
