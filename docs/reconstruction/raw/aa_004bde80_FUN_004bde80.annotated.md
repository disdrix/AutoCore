# Annotated low-level: FUN_004bde80

| Field | Value |
|---|---|
| Stable ID | `aa_004bde80` |
| VA | `0x004bde80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bde80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_004bde80(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xc0) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;
  }
  if (0 < iVar2) {
    piVar4 = *(int **)(param_1 + 0xc0);
    do {
      iVar3 = *(int *)(*piVar4 + 0x14);
      if (iVar3 == 0) {
        iVar5 = 0;
LAB_004bded3:
        iVar3 = 0;
      }
      else {
        iVar5 = *(int *)(iVar3 + 0x18);
        if (*(int *)(iVar3 + 0x10) == 0) goto LAB_004bded3;
        iVar3 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
      }
      iVar1 = iVar1 + iVar3 * iVar5;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
