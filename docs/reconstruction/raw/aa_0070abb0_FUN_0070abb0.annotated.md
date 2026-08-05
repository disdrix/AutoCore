# Annotated low-level: FUN_0070abb0

| Field | Value |
|---|---|
| Stable ID | `aa_0070abb0` |
| VA | `0x0070abb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0070abb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0070abb0(undefined4 *param_1,float param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iStack_4;
  
  puVar3 = param_1;
  switch(param_2) {
  case 4.2039e-45:
    *param_3 = param_1[2];
    return 0;
  case 5.60519e-45:
    iVar4 = *param_3;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (10 < iVar4) {
      iVar4 = 10;
    }
    uVar2 = *(undefined4 *)(*(int *)*param_1 + 0x6c + iVar4 * 4);
    param_1[0x40] = uVar2;
    param_1[0x41] = uVar2;
    return 0;
  default:
    FUN_007031b0(s_Unknown_nb_ctl_request__00af6d7c,param_2);
    return 0xffffffff;
  case 8.40779e-45:
  case 1.12104e-44:
    iVar4 = *param_3;
    param_1[0x40] = iVar4;
    param_1[0x41] = iVar4;
    return 0;
  case 9.80909e-45:
  case 1.26117e-44:
    *param_3 = param_1[0x40];
    return 0;
  case 1.68156e-44:
    param_1[0x34] = *param_3;
    return 0;
  case 1.82169e-44:
    *param_3 = param_1[0x34];
    return 0;
  case 1.96182e-44:
    param_1[0x32] = *param_3;
    return 0;
  case 2.10195e-44:
    *param_3 = param_1[0x32];
    return 0;
  case 2.24208e-44:
    iVar4 = *param_3;
    param_1[0x3c] = iVar4;
    if (iVar4 < 1) {
      param_1[0x3c] = 1;
      return 0;
    }
    break;
  case 2.38221e-44:
    *param_3 = param_1[0x3c];
    return 0;
  case 2.52234e-44:
    iVar4 = *param_3;
    param_2 = 1.4013e-44;
    while( true ) {
      FUN_00702f90(puVar3,4,&param_2);
      FUN_00702f90(puVar3,0x13,&param_1);
      if ((int)param_1 <= iVar4) break;
      param_2 = (float)((int)param_2 + -1);
      if ((int)param_2 < 0) {
        return 0;
      }
    }
    break;
  case 2.66247e-44:
    iVar4 = *(int *)(param_1[0x3f] + param_1[0x40] * 4);
    if (iVar4 != 0) {
      *param_3 = (*(int *)(iVar4 + 0x3c) * param_1[0x3d]) / (int)param_1[2];
      return 0;
    }
    *param_3 = (param_1[0x3d] * 5) / (int)param_1[2];
    return 0;
  case 3.36312e-44:
    param_1[0x3d] = *param_3;
    return 0;
  case 3.50325e-44:
    *param_3 = param_1[0x3d];
    return 0;
  case 3.64338e-44:
    param_1[0xb] = 1;
    param_1[1] = 1;
    iVar4 = 0;
    if (0 < (int)param_1[6]) {
      do {
        iVar1 = iVar4 + 1;
        *(float *)(param_1[0x22] + iVar4 * 4) =
             ((float)iVar1 * (float)_DAT_00a0f190) / (float)(param_1[6] + 1);
        iVar4 = iVar1;
      } while (iVar1 < (int)param_1[6]);
    }
    iVar4 = 0;
    if (0 < (int)param_1[6]) {
      do {
        *(undefined4 *)(param_1[0x2f] + iVar4 * 4) = 0;
        *(undefined4 *)(param_1[0x2c] + iVar4 * 4) = 0;
        *(undefined4 *)(param_1[0x2e] + iVar4 * 4) = 0;
        *(undefined4 *)(param_1[0x2d] + iVar4 * 4) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_1[6]);
    }
    iVar4 = 0;
    if (0 < (int)param_1[7]) {
      do {
        *(undefined4 *)(param_1[0x18] + iVar4 * 4) = 0;
        *(undefined4 *)(param_1[0x14] + iVar4 * 4) = 0;
        *(undefined4 *)(param_1[0x1a] + iVar4 * 4) = 0;
        *(undefined4 *)(param_1[0x16] + iVar4 * 4) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_1[7]);
      return 0;
    }
    break;
  case 4.06377e-44:
    *param_3 = param_1[0x33];
    break;
  case 4.2039e-44:
    param_1[0x35] = *param_3;
    return 0;
  case 4.34403e-44:
    *param_3 = param_1[0x35];
    return 0;
  case 4.48416e-44:
    param_1[0x38] = *param_3;
    param_1[0x34] = 1;
    iVar4 = *param_3;
    param_1 = (undefined4 *)0xa;
    do {
      FUN_00702f90(puVar3,4,&param_1);
      FUN_00702f90(puVar3,0x13,&iStack_4);
      if (iStack_4 <= iVar4) break;
      param_1 = (undefined4 *)((int)param_1 + -1);
    } while (-1 < (int)param_1);
    param_2 = (float)(int)param_1;
    if ((float)(int)param_1 < g_flZero) {
      param_2 = 0.0;
    }
    FUN_00702f90(puVar3,0xe,&param_2);
    puVar3[0x3b] = 0;
    puVar3[0x39] = 0;
    puVar3[0x3a] = 0;
    return 0;
  case 4.62428e-44:
    *param_3 = param_1[0x38];
    return 0;
  case 4.76441e-44:
    param_1[0x36] = *param_3;
    return 0;
  case 4.90454e-44:
    *param_3 = param_1[0x36];
    return 0;
  case 5.04467e-44:
    param_1[0x3e] = *param_3;
    return 0;
  case 5.1848e-44:
    *param_3 = param_1[0x3e];
    return 0;
  case 1.4013e-43:
    iVar4 = 0;
    if (0 < (int)param_1[4]) {
      do {
        param_3[iVar4] = *(int *)(param_1[0x30] + iVar4 * 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_1[4]);
      return 0;
    }
    break;
  case 1.41531e-43:
    iVar4 = 0;
    if (0 < (int)param_1[2]) {
      do {
        param_3[iVar4] = *(int *)(param_1[0x17] + iVar4 * 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_1[2]);
      return 0;
    }
    break;
  case 1.42932e-43:
    iVar4 = 0;
    if (0 < (int)param_1[2]) {
      do {
        param_3[iVar4] = *(int *)(param_1[0x1c] + iVar4 * 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_1[2]);
      return 0;
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
