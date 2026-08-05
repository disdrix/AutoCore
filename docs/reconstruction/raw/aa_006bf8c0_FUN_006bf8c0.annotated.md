# Annotated low-level: FUN_006bf8c0

| Field | Value |
|---|---|
| Stable ID | `aa_006bf8c0` |
| VA | `0x006bf8c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bf8c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bf8c0(undefined4 param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_844;
  int local_840;
  undefined4 *local_83c;
  uint local_838;
  uint local_834;
  undefined4 local_830 [3];
  char local_824 [4];
  int local_820;
  int local_81c;
  int local_818;
  int local_814;
  int local_410;
  int local_40c;
  int local_408;
  int local_404;
  
  iVar5 = 0;
  local_840 = param_4 + 1;
  local_844 = 0;
  iVar2 = param_3;
  if (3 < local_840 - param_3) {
    pfVar3 = (float *)(param_3 * 0x10 + 0x1c + *param_2);
    iVar1 = ((local_840 - param_3) - 4U >> 2) + 1;
    iVar2 = param_3 + iVar1 * 4;
    do {
      iVar5 = iVar5 + (uint)(pfVar3[-4] == g_flZero) + (uint)(*pfVar3 == g_flZero) +
              (uint)(pfVar3[4] == g_flZero) + (uint)(pfVar3[8] == g_flZero);
      pfVar3 = pfVar3 + 0x10;
      iVar1 = iVar1 + -1;
      local_844 = iVar5;
    } while (iVar1 != 0);
  }
  if (iVar2 < local_840) {
    pfVar3 = (float *)(iVar2 * 0x10 + 0xc + *param_2);
    iVar2 = local_840 - iVar2;
    do {
      local_844 = local_844 + (uint)(*pfVar3 == g_flZero);
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (local_844 < 4) {
    *param_5 = *param_2;
    puVar6 = local_830;
    uVar4 = 0x80000003;
    local_838 = 0;
    local_834 = 0x80000003;
    local_83c = puVar6;
    if (param_3 < local_840) {
      iVar2 = param_3 << 4;
      do {
        if (*(float *)(iVar2 + 0xc + *param_2) == g_flZero) {
          if (local_838 == (uVar4 & 0x7fffffff)) {
            FUN_005b3370(&local_83c,4);
            puVar6 = local_83c;
          }
          puVar6[local_838] = param_3;
          local_838 = local_838 + 1;
          uVar4 = local_834;
          puVar6 = local_83c;
        }
        param_3 = param_3 + 1;
        iVar2 = iVar2 + 0x10;
      } while (param_3 < local_840);
    }
    if (local_844 != 0) {
      if (local_844 == 1) {
        FUN_006c0020(*puVar6);
        uVar4 = local_834;
        puVar6 = local_83c;
      }
      else if (local_844 == 2) {
        FUN_006c0080(*puVar6,puVar6[1]);
        uVar4 = local_834;
        puVar6 = local_83c;
      }
      else {
        FUN_006c0130(*puVar6,puVar6[1],puVar6[2]);
        uVar4 = local_834;
        puVar6 = local_83c;
      }
    }
    if (-1 < (int)uVar4) {
      (**(code **)(*DAT_00b05060 + 0x14))(puVar6,uVar4 << 2,0x12);
    }
  }
  else {
    iVar2 = (param_3 + param_4) / 2;
    FUN_006c0520();
    local_410 = *param_2;
    FUN_006c0520();
    local_820 = *param_2;
    local_844._0_1_ = '\x01';
    do {
      do {
        local_408 = 0;
        FUN_006bf8c0(param_1,param_2,param_3,iVar2,&local_410);
        FUN_006bc990(&local_410,param_3,iVar2,param_1,&local_844);
      } while ((char)local_844 != '\0');
      local_844._0_1_ = '\x01';
      do {
        local_818 = 0;
        FUN_006bf8c0(param_1,param_2,iVar2 + 1,param_4,&local_820);
        FUN_006bc990(&local_820,iVar2 + 1,param_4,param_1,&local_844);
      } while ((char)local_844 != '\0');
      local_824[0] = '\x01';
      FUN_006bc990(&local_410,param_3,param_4,param_1,local_824);
      local_840 = CONCAT31(local_840._1_3_,1);
      FUN_006bc990(&local_820,param_3,param_4,param_1,&local_840);
      if ((local_824[0] == '\0') && ((char)local_840 == '\0')) {
        local_844._0_1_ = '\0';
      }
      else {
        local_844._0_1_ = '\x01';
      }
    } while ((char)local_844 != '\0');
    if (local_408 == 0) {
      iVar2 = 0;
      if (0 < local_818) {
        do {
          puVar6 = (undefined4 *)(local_81c + iVar2 * 8);
          if (param_5[2] == (param_5[3] & 0x7fffffffU)) {
            FUN_005b3370(param_5 + 1,8);
          }
          iVar5 = param_5[2];
          iVar1 = param_5[1];
          *(undefined4 *)(iVar1 + iVar5 * 8) = *puVar6;
          *(undefined4 *)(iVar1 + 4 + iVar5 * 8) = puVar6[1];
          iVar2 = iVar2 + 1;
          param_5[2] = param_5[2] + 1;
        } while (iVar2 < local_818);
      }
    }
    else if (local_818 == 0) {
      iVar2 = 0;
      if (0 < local_408) {
        do {
          puVar6 = (undefined4 *)(local_40c + iVar2 * 8);
          if (param_5[2] == (param_5[3] & 0x7fffffffU)) {
            FUN_005b3370(param_5 + 1,8);
          }
          iVar5 = param_5[2];
          iVar1 = param_5[1];
          *(undefined4 *)(iVar1 + iVar5 * 8) = *puVar6;
          *(undefined4 *)(iVar1 + 4 + iVar5 * 8) = puVar6[1];
          iVar2 = iVar2 + 1;
          param_5[2] = param_5[2] + 1;
        } while (iVar2 < local_408);
      }
    }
    else {
      FUN_006bee60(param_1,&local_410,&local_820,param_5);
    }
    if (param_5[2] == 0) {
      FUN_006bda60(&local_40c);
    }
    if (-1 < local_814) {
      (**(code **)(*DAT_00b05060 + 0x14))(local_81c,local_814 << 3,0x12);
    }
    if (-1 < local_404) {
      (**(code **)(*DAT_00b05060 + 0x14))(local_40c,local_404 << 3,0x12);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
