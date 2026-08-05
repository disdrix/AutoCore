# Annotated low-level: FUN_0094bfe0

| Field | Value |
|---|---|
| Stable ID | `aa_0094bfe0` |
| VA | `0x0094bfe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094bfe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0094bfe0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int unaff_EBX;
  char *unaff_ESI;
  undefined4 *puVar5;
  undefined4 local_170 [4];
  char acStack_160 [51];
  char acStack_12d [17];
  char acStack_11c [20];
  char local_108 [2];
  undefined4 local_106 [64];
  
  local_108[0] = '\0';
  local_108[1] = '\0';
  puVar5 = local_106;
  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  if (unaff_ESI != (char *)0x0) {
    pcVar2 = unaff_ESI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 != unaff_ESI + 1) {
      iVar4 = -2 - (int)unaff_ESI;
      do {
        cVar1 = *unaff_ESI;
        unaff_ESI[(int)local_106 + iVar4] = cVar1;
        unaff_ESI = unaff_ESI + 1;
      } while (cVar1 != '\0');
      goto LAB_0094c08e;
    }
  }
  if ((*(int **)(unaff_EBX + 0x3048) != (int *)0x0) &&
     (iVar4 = (**(code **)(**(int **)(unaff_EBX + 0x3048) + 0x210))(0), iVar4 != 0)) {
    iVar4 = (**(code **)(**(int **)(unaff_EBX + 0x3048) + 0x210))(0);
    pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))
                               ();
    pcVar2 = local_108;
    do {
      cVar1 = *pcVar3;
      *pcVar2 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
LAB_0094c08e:
  puVar5 = local_170;
  for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_170[2] = param_1;
  local_170[0] = 0x8038;
  local_170[3] = param_2;
  pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 0xe98) + 4) + 4) + 4
                                        + *(int *)(unaff_EBX + 0xe98)) + 0x160))();
  pcVar2 = acStack_12d;
  do {
    cVar1 = *pcVar3;
    *pcVar2 = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = 0;
  do {
    cVar1 = *(char *)((int)local_106 + iVar4 + -2);
    acStack_11c[iVar4] = cVar1;
    iVar4 = iVar4 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)(*(int *)(unaff_EBX + 0x31f0) + 4);
  iVar4 = -(int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(acStack_160 + iVar4)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((*(int *)(unaff_EBX + 0xc7c) != 0) &&
     (cVar1 = (**(code **)(**(int **)(unaff_EBX + 0xc7c) + 8))(), cVar1 != '\0')) {
    (**(code **)(**(int **)(unaff_EBX + 0xc7c) + 0x18))(0xffffffff,local_170,0x68,0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
