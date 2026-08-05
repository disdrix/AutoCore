# Annotated low-level: FUN_0083abf0

| Field | Value |
|---|---|
| Stable ID | `aa_0083abf0` |
| VA | `0x0083abf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0083abf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0083abf0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  
  iVar2 = (int)param_3;
  if (((((-1 < param_2) && (*(int *)((int)param_3 + 0x508) != 0)) && (-1 < param_1)) &&
      ((param_1 < 5 && (iVar1 = *(int *)((int)param_3 + 0x50c + param_1 * 4), iVar1 != 0)))) &&
     (*(int *)(*(int *)((int)param_3 + 0x508) + 0x50) != 0)) {
    param_3 = (int *)0x0;
    cVar4 = FUN_00427d20(param_2,&param_3);
    piVar3 = param_3;
    if (((cVar4 != '\0') && (param_3 != (int *)0x0)) &&
       ((iVar5 = (**(code **)(*param_3 + 0x1d4))(), iVar5 != 0 &&
        ((*(int *)(iVar1 + 0x508) == 0 ||
         (iVar1 = *(int *)(iVar1 + 0x50c), iVar5 = (**(code **)(*piVar3 + 0x1d4))(), iVar1 != iVar5)
         ))))) {
      (**(code **)(*piVar3 + 0x1d4))();
      FUN_0083ab90(iVar2);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
