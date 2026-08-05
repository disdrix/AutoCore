# Annotated low-level: FUN_008bdb10

| Field | Value |
|---|---|
| Stable ID | `aa_008bdb10` |
| VA | `0x008bdb10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bdb10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008bdb10(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  
  FUN_00410420(0,0);
  if (DAT_00d1b6d8 != 0) {
    if (*(char *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xf5)
        != '\0') {
      FUN_008bd250(in_EAX);
    }
    if (*(int *)(DAT_00d1b6d8 + 0x250) != 0) {
      FUN_008bd250(in_EAX);
    }
  }
  iVar3 = *(int *)(in_EAX + 0x550);
  if ((iVar3 == 0) || ((uint)(*(int *)(in_EAX + 0x554) - iVar3 >> 2) < 5)) {
    *(undefined4 *)(in_EAX + 0x548) = 0;
    if (*(int **)(in_EAX + 0x544) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x544) + 0x454))(0,0);
      (**(code **)(**(int **)(in_EAX + 0x544) + 0x460))(0x3f800000);
      (**(code **)(**(int **)(in_EAX + 0x544) + 0xd4))(0);
    }
  }
  else {
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_EAX + 0x554) - iVar3 >> 2;
    }
    if (iVar3 - 4U < *(uint *)(in_EAX + 0x548)) {
      if (*(int *)(in_EAX + 0x550) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_EAX + 0x554) - *(int *)(in_EAX + 0x550) >> 2;
      }
      *(int *)(in_EAX + 0x548) = iVar3 + -4;
    }
    if (*(int **)(in_EAX + 0x544) != (int *)0x0) {
      if (*(int *)(in_EAX + 0x550) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_EAX + 0x554) - *(int *)(in_EAX + 0x550) >> 2;
      }
      fVar1 = (float)(iVar3 + -4);
      if (iVar3 + -4 < 0) {
        fVar1 = fVar1 + _DAT_00aaa5dc;
      }
      (**(code **)(**(int **)(in_EAX + 0x544) + 0x460))(g_flOne / fVar1);
      (**(code **)(**(int **)(in_EAX + 0x544) + 0xd4))(1);
      if (*(int *)(in_EAX + 0x550) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_EAX + 0x554) - *(int *)(in_EAX + 0x550) >> 2;
      }
      fVar1 = (float)*(int *)(in_EAX + 0x548);
      if (*(int *)(in_EAX + 0x548) < 0) {
        fVar1 = fVar1 + _DAT_00aaa5dc;
      }
      fVar2 = (float)(iVar3 + -4);
      if (iVar3 + -4 < 0) {
        fVar2 = fVar2 + _DAT_00aaa5dc;
      }
      (**(code **)(**(int **)(in_EAX + 0x544) + 0x454))(fVar1 / fVar2,0);
      FUN_008bd070(1);
      FUN_008bda60();
      return;
    }
  }
  FUN_008bd070(1);
  FUN_008bda60();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
