# Annotated low-level: FUN_007f9cc0

| Field | Value |
|---|---|
| Stable ID | `aa_007f9cc0` |
| VA | `0x007f9cc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007f9cc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007f9cc0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  int *unaff_EDI;
  int *local_4;
  
  if ((-1 < unaff_ESI) && (unaff_ESI < 8)) {
    param_1[0x13c] = unaff_ESI;
    local_4 = param_1;
    if (*(char *)((int)param_1 + 0x489) == '\0') {
      param_1[0xa5] = param_1[unaff_ESI + 0x13d];
      *(undefined1 *)((int)param_1 + 0xbb) = 0;
      (**(code **)(*param_1 + 0x34c))();
      return;
    }
    if (DAT_00d1b213 == '\0') {
      piVar4 = (int *)param_1[unaff_ESI + 0x13d];
      iVar3 = unaff_ESI * 2 + 0x129;
    }
    else {
      piVar4 = (int *)param_1[unaff_ESI + 0x145];
      iVar3 = unaff_ESI * 2 + 0x150;
    }
    iVar1 = (param_1 + iVar3)[1];
    iVar3 = param_1[iVar3];
    if (piVar4 == (int *)0x0) {
      (**(code **)(*param_1 + 4))(0);
      return;
    }
    if (((DAT_00d1b6d8 != 0) && (DAT_00d1b213 != '\0')) && ((unaff_ESI == 0 || (unaff_ESI == 7)))) {
      param_1[0x160] = -1;
    }
    iVar2 = (**(code **)(**(int **)(*piVar4 + 0x10) + 0x48))(*(int **)(*piVar4 + 0x10),0,&local_4);
    if (iVar2 < 0) {
      FUN_007a4480(0,"Failed to access level 0 surface of icon #%d.\n");
      return;
    }
    iVar3 = (**(code **)(*(int *)*DAT_00d1f044 + 0x28))((int *)*DAT_00d1f044,iVar3,iVar1);
    if (iVar3 < 0) {
      FUN_007a4480(0,"Failed to set cursorproperties with surface of icon #%d.\n");
      if (unaff_EDI != (int *)0x0) {
        (**(code **)(*unaff_EDI + 8))(unaff_EDI);
        return;
      }
    }
    else if (unaff_EDI != (int *)0x0) {
      (**(code **)(*unaff_EDI + 8))(unaff_EDI);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
