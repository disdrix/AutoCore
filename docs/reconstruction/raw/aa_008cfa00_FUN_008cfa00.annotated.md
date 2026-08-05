# Annotated low-level: FUN_008cfa00

| Field | Value |
|---|---|
| Stable ID | `aa_008cfa00` |
| VA | `0x008cfa00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cfa00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cfa00(int *param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  char acStack_c0 [63];
  char cStack_81;
  char acStack_80 [128];
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 == '\0') {
    return;
  }
  FUN_007a69d0();
  if ((param_1[0x202] != param_1[0x209]) && (param_1[0x1b8] != 0)) {
    pcVar3 = (char *)FUN_007a6de0("Body Type",0xffffffff);
    pcVar7 = acStack_80;
    do {
      cVar1 = *pcVar3;
      *pcVar7 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (param_1[0x210] < 2) {
      if (((int *)param_1[0x1c7] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1c7] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1c7] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1c7] + 0x34c))();
      }
      if (((int *)param_1[0x1c8] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1c8] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008cfb68;
      }
    }
    else {
      sprintf(acStack_c0," %d",param_1[0x209] + 1);
      pcVar7 = acStack_c0;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar7 - (int)acStack_c0;
      pcVar7 = &cStack_81;
      do {
        pcVar3 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = acStack_c0;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      if (((int *)param_1[0x1c7] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1c7] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1c7] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1c7] + 0x34c))();
      }
      if (((int *)param_1[0x1c8] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1c8] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008cfb68:
        (**(code **)(*(int *)param_1[0x1c8] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1c8] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1b8] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1b8] + 0x34c))();
    param_1[0x202] = param_1[0x209];
  }
  if ((param_1[0x1fd] != param_1[0x204]) && (param_1[0x1bb] != 0)) {
    if (param_1[0x204] == param_1[0x20b] + -1) {
      pcVar3 = (char *)FUN_007a6de0("No Helmet",0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    else {
      pcVar3 = (char *)FUN_007a6de0("Helmet",0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    if (param_1[0x20b] < 2) {
      if (((int *)param_1[0x1cd] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cd] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1cd] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1cd] + 0x34c))();
      }
      if (((int *)param_1[0x1ce] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1ce] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008cfd20;
      }
    }
    else {
      if (param_1[0x204] != param_1[0x20b] + -1) {
        sprintf(acStack_c0," %d",param_1[0x204] + 1);
        pcVar7 = acStack_c0;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        uVar4 = (int)pcVar7 - (int)acStack_c0;
        pcVar7 = &cStack_81;
        do {
          pcVar3 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar3 != '\0');
        pcVar3 = acStack_c0;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
      if (((int *)param_1[0x1cd] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cd] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1cd] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1cd] + 0x34c))();
      }
      if (((int *)param_1[0x1ce] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1ce] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008cfd20:
        (**(code **)(*(int *)param_1[0x1ce] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1ce] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1bb] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1bb] + 0x34c))();
    param_1[0x1fd] = param_1[0x204];
  }
  if ((param_1[0x1fc] != param_1[0x203]) && (param_1[0x1b9] != 0)) {
    pcVar3 = (char *)FUN_007a6de0("Hair Style",0xffffffff);
    pcVar7 = acStack_80;
    do {
      cVar1 = *pcVar3;
      *pcVar7 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar5 = param_1[0x224];
    if ((((iVar5 == 0) || (param_1[0x225] - iVar5 >> 2 == 0)) ||
        (iVar5 = *(int *)(iVar5 + param_1[0x204] * 4), iVar5 == 0)) ||
       ((*(int *)(iVar5 + 0x94) != 0 || (param_1[0x20a] < 2)))) {
      if (((int *)param_1[0x1c9] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1c9] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1c9] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1c9] + 0x34c))();
      }
      if (((int *)param_1[0x1ca] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1ca] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008cfee8;
      }
    }
    else {
      sprintf(acStack_c0," %d",param_1[0x203] + 1);
      pcVar7 = acStack_c0;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar7 - (int)acStack_c0;
      pcVar7 = &cStack_81;
      do {
        pcVar3 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = acStack_c0;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      if (((int *)param_1[0x1c9] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1c9] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1c9] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1c9] + 0x34c))();
      }
      if (((int *)param_1[0x1ca] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1ca] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008cfee8:
        (**(code **)(*(int *)param_1[0x1ca] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1ca] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1b9] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1b9] + 0x34c))();
    param_1[0x1fc] = param_1[0x203];
  }
  if ((param_1[0x1fe] != param_1[0x205]) && (param_1[0x1bc] != 0)) {
    if (param_1[0x205] == param_1[0x20c] + -1) {
      pcVar3 = (char *)FUN_007a6de0("No Accessory",0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    else {
      pcVar3 = (char *)FUN_007a6de0("Accessory",0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    if (param_1[0x20c] < 2) {
      if (((int *)param_1[0x1cf] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cf] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1cf] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1cf] + 0x34c))();
      }
      if (((int *)param_1[0x1d0] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d0] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008d00a0;
      }
    }
    else {
      if (param_1[0x205] != param_1[0x20c] + -1) {
        sprintf(acStack_c0," %d",param_1[0x205] + 1);
        pcVar7 = acStack_c0;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        uVar4 = (int)pcVar7 - (int)acStack_c0;
        pcVar7 = &cStack_81;
        do {
          pcVar3 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar3 != '\0');
        pcVar3 = acStack_c0;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
      if (((int *)param_1[0x1cf] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cf] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1cf] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1cf] + 0x34c))();
      }
      if (((int *)param_1[0x1d0] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d0] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008d00a0:
        (**(code **)(*(int *)param_1[0x1d0] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1d0] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1bc] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1bc] + 0x34c))();
    param_1[0x1fe] = param_1[0x205];
  }
  if (((param_1[0x1ff] != param_1[0x206]) || (param_1[0x168] != param_1[0x169])) &&
     (param_1[0x1bd] != 0)) {
    if (param_1[0x206] == param_1[0x20d] + -1) {
      pcVar7 = "No Jewelry";
      if (param_1[0x169] != 0) {
        pcVar7 = "No Facial Hair";
      }
      pcVar3 = (char *)FUN_007a6de0(pcVar7,0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    else {
      pcVar7 = "Jewelry";
      if (param_1[0x169] != 0) {
        pcVar7 = "Facial Hair";
      }
      pcVar3 = (char *)FUN_007a6de0(pcVar7,0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    if (param_1[0x20d] < 2) {
      if (((int *)param_1[0x1d1] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d1] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1d1] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1d1] + 0x34c))();
      }
      if (((int *)param_1[0x1d2] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d2] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008d0288;
      }
    }
    else {
      if (param_1[0x206] != param_1[0x20d] + -1) {
        sprintf(acStack_c0," %d",param_1[0x206] + 1);
        pcVar7 = acStack_c0;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        uVar4 = (int)pcVar7 - (int)acStack_c0;
        pcVar7 = &cStack_81;
        do {
          pcVar3 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar3 != '\0');
        pcVar3 = acStack_c0;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
      if (((int *)param_1[0x1d1] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d1] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1d1] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1d1] + 0x34c))();
      }
      if (((int *)param_1[0x1d2] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d2] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008d0288:
        (**(code **)(*(int *)param_1[0x1d2] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1d2] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1bd] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1bd] + 0x34c))();
    param_1[0x1ff] = param_1[0x206];
    param_1[0x168] = param_1[0x169];
  }
  if ((param_1[0x201] != param_1[0x208]) && (param_1[0x1bf] != 0)) {
    if (param_1[0x208] == param_1[0x20f] + -1) {
      pcVar3 = (char *)FUN_007a6de0("No Mouthpiece",0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    else {
      pcVar3 = (char *)FUN_007a6de0("Mouthpiece",0xffffffff);
      pcVar7 = acStack_80;
      do {
        cVar1 = *pcVar3;
        *pcVar7 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
    if (param_1[0x20f] < 2) {
      if (((int *)param_1[0x1d5] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d5] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1d5] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1d5] + 0x34c))();
      }
      if (((int *)param_1[0x1d6] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d6] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008d0450;
      }
    }
    else {
      if (param_1[0x208] != param_1[0x20f] + -1) {
        sprintf(acStack_c0," %d",param_1[0x208] + 1);
        pcVar7 = acStack_c0;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        uVar4 = (int)pcVar7 - (int)acStack_c0;
        pcVar7 = &cStack_81;
        do {
          pcVar3 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar3 != '\0');
        pcVar3 = acStack_c0;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
      if (((int *)param_1[0x1d5] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d5] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1d5] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1d5] + 0x34c))();
      }
      if (((int *)param_1[0x1d6] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d6] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008d0450:
        (**(code **)(*(int *)param_1[0x1d6] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1d6] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1bf] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1bf] + 0x34c))();
    param_1[0x201] = param_1[0x208];
  }
  if ((param_1[0x211] != param_1[0x218]) && (param_1[0x1ba] != 0)) {
    pcVar3 = (char *)FUN_007a6de0("Hair Color",0xffffffff);
    pcVar7 = acStack_80;
    do {
      cVar1 = *pcVar3;
      *pcVar7 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if ((((param_1[0x224] == 0) || (param_1[0x225] - param_1[0x224] >> 2 == 0)) ||
        (iVar5 = *(int *)(param_1[0x224] + param_1[0x204] * 4), iVar5 == 0)) ||
       ((*(int *)(iVar5 + 0x94) != 0 || (*(int *)(*(int *)param_1[0x220] + 0x90) < 2)))) {
      if (((int *)param_1[0x1cb] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cb] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1cb] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1cb] + 0x34c))();
      }
      if (((int *)param_1[0x1cc] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cc] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008d0628;
      }
    }
    else {
      sprintf(acStack_c0," %d",param_1[0x218]);
      pcVar7 = acStack_c0;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar7 - (int)acStack_c0;
      pcVar7 = &cStack_81;
      do {
        pcVar3 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = acStack_c0;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      if (((int *)param_1[0x1cb] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cb] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1cb] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1cb] + 0x34c))();
      }
      if (((int *)param_1[0x1cc] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1cc] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008d0628:
        (**(code **)(*(int *)param_1[0x1cc] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1cc] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1ba] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1ba] + 0x34c))();
    param_1[0x211] = param_1[0x218];
  }
  if ((param_1[0x215] != param_1[0x21c]) && (param_1[0x1be] != 0)) {
    pcVar3 = (char *)FUN_007a6de0("Eye Color",0xffffffff);
    pcVar7 = acStack_80;
    do {
      cVar1 = *pcVar3;
      *pcVar7 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (param_1[0x230] == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = param_1[0x231] - param_1[0x230] >> 2;
    }
    if ((param_1[0x207] < iVar5) &&
       (1 < *(int *)(*(int *)(param_1[0x230] + param_1[0x207] * 4) + 0x90))) {
      sprintf(acStack_c0," %d",param_1[0x21c]);
      pcVar7 = acStack_c0;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar7 - (int)acStack_c0;
      pcVar7 = &cStack_81;
      do {
        pcVar3 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = acStack_c0;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      if (((int *)param_1[0x1d3] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d3] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1d3] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1d3] + 0x34c))();
      }
      if (((int *)param_1[0x1d4] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d4] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008d07da:
        (**(code **)(*(int *)param_1[0x1d4] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1d4] + 0x34c))();
      }
    }
    else {
      if (((int *)param_1[0x1d3] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d3] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1d3] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1d3] + 0x34c))();
      }
      if (((int *)param_1[0x1d4] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1d4] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008d07da;
      }
    }
    (**(code **)(*(int *)param_1[0x1be] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1be] + 0x34c))();
    param_1[0x215] = param_1[0x21c];
  }
  if ((param_1[0x163] != param_1[0x164]) && (param_1[0x1c6] != 0)) {
    pcVar3 = (char *)FUN_007a6de0("Wheels",0xffffffff);
    pcVar7 = acStack_80;
    do {
      cVar1 = *pcVar3;
      *pcVar7 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (param_1[0x162] < 2) {
      if (((int *)param_1[0x1db] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1db] + 0xd8))(), cVar1 != '\0')) {
        (**(code **)(*(int *)param_1[0x1db] + 0xd4))(0);
        (**(code **)(*(int *)param_1[0x1db] + 0x34c))();
      }
      if (((int *)param_1[0x1dc] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1dc] + 0xd8))(), cVar1 != '\0')) {
        uVar8 = 0;
        goto LAB_008d0968;
      }
    }
    else {
      sprintf(acStack_c0," %d",param_1[0x164] + 1);
      pcVar7 = acStack_c0;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar7 - (int)acStack_c0;
      pcVar7 = &cStack_81;
      do {
        pcVar3 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = acStack_c0;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
      if (((int *)param_1[0x1db] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1db] + 0xd8))(), cVar1 == '\0')) {
        (**(code **)(*(int *)param_1[0x1db] + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x1db] + 0x34c))();
      }
      if (((int *)param_1[0x1dc] != (int *)0x0) &&
         (cVar1 = (**(code **)(*(int *)param_1[0x1dc] + 0xd8))(), cVar1 == '\0')) {
        uVar8 = 1;
LAB_008d0968:
        (**(code **)(*(int *)param_1[0x1dc] + 0xd4))(uVar8);
        (**(code **)(*(int *)param_1[0x1dc] + 0x34c))();
      }
    }
    (**(code **)(*(int *)param_1[0x1c6] + 0x1d8))(acStack_80,1,1);
    (**(code **)(*(int *)param_1[0x1c6] + 0x34c))();
    param_1[0x163] = param_1[0x164];
  }
  if (param_1[0x152] == 0) {
    return;
  }
  if (param_1[0x165] == (uint)*(byte *)(param_1[0x152] + 0x288)) {
    return;
  }
  if (param_1[0x1c3] == 0) {
    return;
  }
  pcVar3 = (char *)FUN_007a6de0("Paint Scheme",0xffffffff);
  pcVar7 = acStack_80;
  do {
    cVar1 = *pcVar3;
    *pcVar7 = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  bVar2 = FUN_004fcb50();
  if (bVar2 < 2) {
    if (((int *)param_1[0x1dd] != (int *)0x0) &&
       (cVar1 = (**(code **)(*(int *)param_1[0x1dd] + 0xd8))(), cVar1 != '\0')) {
      (**(code **)(*(int *)param_1[0x1dd] + 0xd4))(0);
      (**(code **)(*(int *)param_1[0x1dd] + 0x34c))();
    }
    if (((int *)param_1[0x1de] == (int *)0x0) ||
       (cVar1 = (**(code **)(*(int *)param_1[0x1de] + 0xd8))(), cVar1 == '\0')) goto LAB_008d0b24;
    uVar8 = 0;
  }
  else {
    sprintf(acStack_c0," %d",*(byte *)(param_1[0x152] + 0x288) + 1);
    pcVar7 = acStack_c0;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar7 - (int)acStack_c0;
    pcVar7 = &cStack_81;
    do {
      pcVar3 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar3 != '\0');
    pcVar3 = acStack_c0;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    }
    if (((int *)param_1[0x1dd] != (int *)0x0) &&
       (cVar1 = (**(code **)(*(int *)param_1[0x1dd] + 0xd8))(), cVar1 == '\0')) {
      (**(code **)(*(int *)param_1[0x1dd] + 0xd4))(1);
      (**(code **)(*(int *)param_1[0x1dd] + 0x34c))();
    }
    if (((int *)param_1[0x1de] == (int *)0x0) ||
       (cVar1 = (**(code **)(*(int *)param_1[0x1de] + 0xd8))(), cVar1 != '\0')) goto LAB_008d0b24;
    uVar8 = 1;
  }
  (**(code **)(*(int *)param_1[0x1de] + 0xd4))(uVar8);
  (**(code **)(*(int *)param_1[0x1de] + 0x34c))();
LAB_008d0b24:
  (**(code **)(*(int *)param_1[0x1c3] + 0x1d8))(acStack_80,1,1);
  (**(code **)(*(int *)param_1[0x1c3] + 0x34c))();
  param_1[0x165] = (uint)*(byte *)(param_1[0x152] + 0x288);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
