# Annotated low-level: FUN_007fee30

| Field | Value |
|---|---|
| Stable ID | `aa_007fee30` |
| VA | `0x007fee30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fee30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007fee30(int param_1)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int unaff_EBX;
  int iVar3;
  
  if (in_EAX == 4) {
    piVar1 = *(int **)(param_1 + 0x1040);
    if (piVar1 == (int *)0x0) {
      return;
    }
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 == '\0') {
      return;
    }
    if (piVar1[0x143] == 0) {
      return;
    }
    cVar2 = (**(code **)(*(int *)piVar1[0x143] + 0x3d8))();
    if (cVar2 == '\0') {
      return;
    }
    if ((*(int **)(param_1 + 0x1098) != (int *)0x0) &&
       (cVar2 = (**(code **)(**(int **)(param_1 + 0x1098) + 0x3d8))(), cVar2 != '\0')) {
      FUN_008bf020();
    }
    iVar3 = *(int *)(piVar1[0x143] + 0x580);
  }
  else {
    if (in_EAX != 0xb) {
      if (in_EAX != 0xc) {
        return;
      }
      piVar1 = *(int **)(param_1 + 0x1060);
      if (piVar1 == (int *)0x0) {
        return;
      }
      cVar2 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar2 == '\0') {
        return;
      }
      if (piVar1[0x183] != 0) {
        FUN_0085fd20();
      }
      if (piVar1[0x169] != unaff_EBX) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x007fee8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar1 + 0x448))();
      return;
    }
    piVar1 = *(int **)(param_1 + 0x105c);
    if (piVar1 == (int *)0x0) {
      return;
    }
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 == '\0') {
      return;
    }
    iVar3 = piVar1[0x16b];
  }
  if (iVar3 != 0) {
    FUN_0085fd20();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
