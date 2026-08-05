# Annotated low-level: FUN_0083eff0

| Field | Value |
|---|---|
| Stable ID | `aa_0083eff0` |
| VA | `0x0083eff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0083eff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0083eff0(void)

{
  int iVar1;
  int *piVar2;
  char *unaff_EBX;
  int *unaff_ESI;
  undefined4 uVar3;
  
  if ((((unaff_EBX == (char *)0x0) || (*unaff_EBX == '\0')) || (unaff_ESI == (int *)0x0)) ||
     (DAT_00d1ad30 == 0)) {
    return 0;
  }
  iVar1 = (**(code **)(*unaff_ESI + 0x1b8))
                    ((int)((float)DAT_00d1e818 * DAT_00aaa7b8),
                     (int)((float)DAT_00d1e81c * _DAT_00aaa7b4));
  if ((iVar1 != 0) && (piVar2 = (int *)(**(code **)(*unaff_ESI + 0x1b8))(), *piVar2 != 0)) {
    (**(code **)(*unaff_ESI + 0x1b8))();
  }
  if (*unaff_EBX != 'd') {
    return 0;
  }
  iVar1 = strncmp(unaff_EBX,"dmg_icon_physical",0x11);
  if (iVar1 == 0) {
    FUN_00976e10(DAT_00d1ad30,unaff_ESI,0);
    return 1;
  }
  iVar1 = strncmp(unaff_EBX,"dmg_icon_fire",0xd);
  if (iVar1 == 0) {
    uVar3 = 1;
  }
  else {
    iVar1 = strncmp(unaff_EBX,"dmg_icon_corrosive",0x12);
    if (iVar1 == 0) {
      FUN_00976e10(DAT_00d1ad30,unaff_ESI,3);
      return 1;
    }
    iVar1 = strncmp(unaff_EBX,"dmg_icon_contamination",0x16);
    if (iVar1 == 0) {
      FUN_00976e10(DAT_00d1ad30,unaff_ESI,4);
      return 1;
    }
    iVar1 = strncmp(unaff_EBX,"dmg_icon_energy",0xf);
    if (iVar1 != 0) {
      return 0;
    }
    uVar3 = 5;
  }
  FUN_00976e10(DAT_00d1ad30,unaff_ESI,uVar3);
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
