# Annotated low-level: FUN_007fdba0

| Field | Value |
|---|---|
| Stable ID | `aa_007fdba0` |
| VA | `0x007fdba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fdba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fdba0(void)

{
  char cVar1;
  int unaff_EBX;
  int *piVar2;
  int iVar3;
  undefined1 auStack_8 [8];
  
  piVar2 = (int *)(unaff_EBX + 0x1030);
  iVar3 = 0x3a;
  do {
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0x10c))();
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  DAT_00af9210 = 0xffffffff;
  piVar2 = *(int **)(unaff_EBX + 0x109c);
  DAT_00af9214 = -1;
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x3d8))();
    if (cVar1 != '\0') {
      if (piVar2[0x14d] != 0) {
        if (DAT_00af9214 == -1) {
          iVar3 = (**(code **)(*(int *)piVar2[0x14d] + 0x124))(auStack_8);
          DAT_00af9214 = (int)*(float *)(iVar3 + 4);
        }
        FUN_008f6990();
      }
      FUN_008f7040();
      FUN_008f6f60();
      FUN_008f6b70(piVar2);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
