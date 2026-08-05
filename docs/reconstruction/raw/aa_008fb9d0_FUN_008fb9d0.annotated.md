# Annotated low-level: FUN_008fb9d0

| Field | Value |
|---|---|
| Stable ID | `aa_008fb9d0` |
| VA | `0x008fb9d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fb9d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008fb9d0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int unaff_EBX;
  int *piVar5;
  int iVar6;
  
  *(int *)(param_1 + 0x660) = unaff_EBX;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x164))(0);
  piVar5 = (int *)(param_1 + 0x548);
  iVar6 = 6;
  do {
    *(undefined1 *)(iVar2 + 3) = 0x32;
    *(undefined4 *)(*piVar5 + 0xf8) = 0x32;
    (**(code **)(*(int *)*piVar5 + 0x154))(0,iVar2);
    (**(code **)(*(int *)*piVar5 + 0x34c))();
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined1 *)(iVar2 + 3) = 0x96;
  *(undefined4 *)(*(int *)(param_1 + 0x548 + unaff_EBX * 4) + 0xf8) = 0x96;
  (**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x154))(0,iVar2);
  (**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x34c))();
  pcVar3 = (char *)(**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x1dc))();
  pcVar4 = pcVar3 + 1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (pcVar3 != pcVar4) {
    pcVar3 = (char *)(**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x1dc))();
    pcVar4 = (char *)(param_1 + 0x560);
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
