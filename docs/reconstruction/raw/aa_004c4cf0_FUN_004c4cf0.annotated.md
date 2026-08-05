# Annotated low-level: FUN_004c4cf0

| Field | Value |
|---|---|
| Stable ID | `aa_004c4cf0` |
| VA | `0x004c4cf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c4cf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __thiscall FUN_004c4cf0(int param_1,short *param_2)

{
  short *psVar1;
  int iVar2;
  
  psVar1 = param_2;
  if (param_2 == (short *)0x0) {
    return (float10)g_flZero;
  }
  param_2 = (short *)0x0;
  iVar2 = 0;
  while ((iVar2 == 2 || (psVar1[iVar2] < 1))) {
    iVar2 = iVar2 + 1;
    if (5 < iVar2) {
LAB_004c4d35:
      if ((0 < *psVar1) && ((float)param_2 < *(float *)(param_1 + 0x164))) {
        param_2 = (short *)*(float *)(param_1 + 0x164);
      }
      if ((0 < psVar1[1]) && ((float)param_2 < *(float *)(param_1 + 0x168))) {
        param_2 = (short *)*(float *)(param_1 + 0x168);
      }
      if ((0 < psVar1[3]) && ((float)param_2 < *(float *)(param_1 + 0x170))) {
        param_2 = (short *)*(float *)(param_1 + 0x170);
      }
      if ((0 < psVar1[4]) && ((float)param_2 < *(float *)(param_1 + 0x174))) {
        param_2 = (short *)*(float *)(param_1 + 0x174);
      }
      if ((0 < psVar1[5]) && ((float)param_2 < *(float *)(param_1 + 0x178))) {
        param_2 = (short *)*(float *)(param_1 + 0x178);
      }
      return (float10)(float)param_2;
    }
  }
  param_2 = *(short **)(param_1 + 0x164 + iVar2 * 4);
  goto LAB_004c4d35;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
