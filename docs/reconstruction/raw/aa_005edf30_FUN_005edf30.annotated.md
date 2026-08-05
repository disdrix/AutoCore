# Annotated low-level: FUN_005edf30

| Field | Value |
|---|---|
| Stable ID | `aa_005edf30` |
| VA | `0x005edf30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005edf30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_005edf30(int *param_1,float param_2,float param_3,float param_4,float param_5,int *param_6,
            int *param_7,int *param_8)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = *param_1;
  iVar4 = param_1[1] - iVar2 >> 0x1f;
  uVar5 = 0;
  if ((param_1[1] - iVar2) / 0xc + iVar4 != iVar4) {
    iVar4 = 0;
    do {
      fVar1 = param_2 * *(float *)(iVar4 + iVar2) +
              param_3 * *(float *)(iVar4 + 4 + iVar2) + param_4 * *(float *)(iVar4 + 8 + iVar2) +
              param_5;
      if (fVar1 < (float)_DAT_009dcfb0) {
        iVar2 = 2;
      }
      else if (fVar1 <= (float)_DAT_009dcfa8) {
        iVar2 = 3;
      }
      else {
        iVar2 = 1;
      }
      piVar3 = param_7;
      if (iVar2 == 1) {
LAB_005edfcf:
        *piVar3 = *piVar3 + 1;
      }
      else if (iVar2 == 2) {
        *param_8 = *param_8 + 1;
      }
      else {
        piVar3 = param_6;
        if (iVar2 == 3) goto LAB_005edfcf;
      }
      iVar2 = *param_1;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0xc;
    } while (uVar5 < (uint)((param_1[1] - iVar2) / 0xc));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
