# Annotated low-level: FUN_007acfb0

| Field | Value |
|---|---|
| Stable ID | `aa_007acfb0` |
| VA | `0x007acfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007acfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __thiscall FUN_007acfb0(int *param_1,int *param_2,char param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int iVar6;
  uint uStack_20;
  int iStack_1c;
  uint uStack_18;
  undefined1 auStack_14 [12];
  undefined4 uStack_8;
  
  uVar1 = (**(code **)(*param_1 + 700))();
  if (uVar1 != 0) {
    if ((uint)param_1[0xa8] < DAT_00afa138) {
      uVar1 = (**(code **)(*param_1 + 0x60))();
    }
    if (param_1[0xa7] != 0) {
      iVar4 = param_2[1];
      iVar6 = *param_2;
      (**(code **)(*param_1 + 0x2d0))(&uStack_20);
      piVar2 = (int *)(**(code **)(*param_1 + 700))();
      iVar5 = *(int *)(*piVar2 + 0x1c);
      uVar1 = *(uint *)(*piVar2 + 0x20);
      iStack_1c = iVar5;
      uStack_18 = uVar1;
      if (param_3 != '\0') {
        piVar2 = (int *)(**(code **)(*param_1 + 0x120))(auStack_14,param_2,1);
        iVar6 = iVar6 - *piVar2;
        uVar1 = (**(code **)(*param_1 + 0x120))(&uStack_18,uStack_8,1);
        iVar4 = iVar4 - *(int *)(uVar1 + 4);
      }
      if ((((-1 < iVar6) && (-1 < iVar4)) && (iVar6 < unaff_ESI)) &&
         (uVar1 = uStack_20, iVar4 < (int)uStack_20)) {
        if ((*(char *)((int)param_1 + 0xd7) == '\0') || ((char)param_1[0x72] == '\0')) {
          iVar6 = (int)(((float)iVar5 / (float)unaff_ESI) * (float)iVar6);
          uVar1 = (uint)(((float)(int)uStack_18 / (float)(int)uStack_20) * (float)iVar4);
        }
        else {
          iVar6 = (int)(((float)(param_1[0x62] - param_1[0x60]) / (float)unaff_ESI) * (float)iVar6)
                  + param_1[0x60];
          uVar1 = (int)(((float)(param_1[99] - param_1[0x61]) / (float)(int)uStack_20) *
                       (float)iVar4) + param_1[0x61];
          iVar5 = iStack_1c;
        }
        if (((-1 < iVar6) && (-1 < (int)uVar1)) &&
           ((iVar6 < iVar5 && ((int)uVar1 < (int)uStack_18)))) {
          uVar1 = uVar1 * iVar5 + iVar6;
          uVar3 = uVar1 & 0x80000007;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
          }
          return (uint)(((uint)*(byte *)(((int)(uVar1 + ((int)uVar1 >> 0x1f & 7U)) >> 3) +
                                        param_1[0xa7]) & 1 << ((byte)uVar3 & 0x1f)) != 0);
        }
      }
      return uVar1 & 0xffffff00;
    }
  }
  return uVar1 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
