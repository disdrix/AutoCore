# Annotated low-level: FUN_006fc5c0

| Field | Value |
|---|---|
| Stable ID | `aa_006fc5c0` |
| VA | `0x006fc5c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fc5c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006fc5c0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  float *pfVar9;
  int local_7c;
  int local_78;
  float local_74;
  int local_6c;
  int local_68;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [32];
  float local_20;
  
  if ((param_1[1] == 3) && (iVar6 = 0, 0 < *param_1)) {
    piVar7 = param_1 + 8;
    do {
      iVar4 = FUN_006fb890(piVar7,param_1 + 0x28,0);
      if (iVar4 == 0xe) {
        iVar6 = iVar6 + 2;
        param_1[8] = param_1[iVar6 * 4];
        param_1[9] = param_1[iVar6 * 4 + 1];
        param_1[10] = param_1[iVar6 * 4 + 2];
        param_1[0xb] = param_1[iVar6 * 4 + 3];
        *param_1 = 1;
        return;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 4;
    } while (iVar6 < *param_1);
  }
  if ((*param_1 == 3) && (iVar6 = 0, 0 < param_1[1])) {
    piVar7 = param_1 + 0x28;
    do {
      iVar4 = FUN_006fb890(piVar7,param_1 + 8,0);
      if (iVar4 == 0xe) {
        iVar4 = iVar6 + 0xe;
        param_1[0x38] = param_1[iVar4 * 4];
        param_1[0x39] = param_1[iVar4 * 4 + 1];
        param_1[0x3a] = param_1[iVar4 * 4 + 2];
        param_1[0x3b] = param_1[iVar4 * 4 + 3];
        iVar6 = iVar6 + 10;
        param_1[0x28] = param_1[iVar6 * 4];
        param_1[0x29] = param_1[iVar6 * 4 + 1];
        param_1[0x2a] = param_1[iVar6 * 4 + 2];
        param_1[0x2b] = param_1[iVar6 * 4 + 3];
        param_1[1] = 1;
        return;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 4;
    } while (iVar6 < param_1[1]);
  }
  local_74 = 3.4028235e+38;
  local_6c = 0;
  iVar2 = (uint)(*param_1 == 3) * 2;
  iVar6 = iVar2 + 1;
  iVar3 = (uint)(param_1[1] == 3) * 2;
  iVar4 = iVar3 + 1;
  local_68 = 0;
  local_78 = 0;
  if (iVar2 != -1) {
    pfVar9 = (float *)(param_1 + 8);
    do {
      local_7c = 0;
      if (iVar3 != -1) {
        pfVar8 = (float *)(param_1 + 0x2a);
        do {
          pfVar5 = (float *)(param_1 + ((char)(&DAT_00a0eefe)[local_78] + 2) * 4);
          local_50 = *pfVar5 - *pfVar9;
          local_4c = pfVar5[1] - pfVar9[1];
          local_48 = pfVar5[2] - pfVar9[2];
          local_44 = pfVar5[3] - pfVar9[3];
          pfVar5 = (float *)(param_1 + ((char)(&DAT_00a0eefe)[local_7c] + 10) * 4);
          local_60 = *pfVar5 - pfVar8[-2];
          local_5c = pfVar5[1] - pfVar8[-1];
          local_58 = pfVar5[2] - *pfVar8;
          local_54 = pfVar5[3] - pfVar8[1];
          FUN_006f6ef0(pfVar9,&local_50,pfVar8 + -2,&local_60,local_40);
          if (local_20 < local_74) {
            local_74 = local_20;
            local_6c = local_78;
            local_68 = local_7c;
          }
          local_7c = local_7c + 1;
          pfVar8 = pfVar8 + 4;
        } while (local_7c < iVar4);
      }
      local_78 = local_78 + 1;
      pfVar9 = pfVar9 + 4;
    } while (local_78 < iVar6);
  }
  if (iVar6 == 3) {
    iVar6 = *param_1;
    *param_1 = iVar6 + -1;
    iVar6 = iVar6 + 1;
    piVar7 = param_1 + ((char)(&DAT_00a0eefc)[local_6c] + 2) * 4;
    *piVar7 = param_1[iVar6 * 4];
    piVar7[1] = param_1[iVar6 * 4 + 1];
    piVar7[2] = param_1[iVar6 * 4 + 2];
    piVar7[3] = param_1[iVar6 * 4 + 3];
  }
  if (iVar4 == 3) {
    iVar4 = param_1[1];
    param_1[1] = iVar4 + -1;
    cVar1 = (&DAT_00a0eefc)[local_68];
    iVar4 = iVar4 + 0xd;
    iVar6 = cVar1 + 0xe;
    param_1[iVar6 * 4] = param_1[iVar4 * 4];
    param_1[iVar6 * 4 + 1] = param_1[iVar4 * 4 + 1];
    param_1[iVar6 * 4 + 2] = param_1[iVar4 * 4 + 2];
    param_1[iVar6 * 4 + 3] = param_1[iVar4 * 4 + 3];
    iVar6 = param_1[1] + 10;
    piVar7 = param_1 + (cVar1 + 10) * 4;
    *piVar7 = param_1[iVar6 * 4];
    piVar7[1] = param_1[iVar6 * 4 + 1];
    piVar7[2] = param_1[iVar6 * 4 + 2];
    piVar7[3] = param_1[iVar6 * 4 + 3];
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
