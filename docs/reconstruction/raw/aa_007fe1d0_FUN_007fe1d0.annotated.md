# Annotated low-level: FUN_007fe1d0

| Field | Value |
|---|---|
| Stable ID | `aa_007fe1d0` |
| VA | `0x007fe1d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fe1d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fe1d0(char param_1)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int unaff_ESI;
  
  if (*(char *)(DAT_00d1b6d8 + 0x4f1) == '\0') {
    piVar1 = *(int **)(unaff_ESI + 0x1030 + in_EAX * 4);
    if (piVar1 == (int *)0x0) {
      FUN_007a4480(1,"Attempting to toggle visibility of null dialog %i.");
    }
    else {
      cVar2 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar2 != '\0') {
        if (((param_1 == '\0') &&
            ((cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\0' ||
             (cVar2 = (**(code **)(*piVar1 + 0xf8))(), cVar2 != '\0')))) &&
           ((cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\x01' ||
            (iVar3 = (**(code **)(*piVar1 + 0xe8))(), iVar3 != -1)))) {
          FUN_007fc9b0();
          return;
        }
        if ((((piVar1[0x140] != 1) || (*(int *)(unaff_ESI + 0xe98) == 0)) ||
            (iVar3 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar3 == 0)) ||
           (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x194))()
           , cVar2 == '\0')) {
          (**(code **)(*piVar1 + 0xfc))(1,0x3f000000);
          FUN_0092f000();
          return;
        }
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
