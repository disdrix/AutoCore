# Annotated low-level: FUN_004bfcb0

| Field | Value |
|---|---|
| Stable ID | `aa_004bfcb0` |
| VA | `0x004bfcb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bfcb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004bfcb0(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)(param_1 + 8);
  iVar3 = 9;
  while( true ) {
    piVar5 = *(int **)*piVar4;
    if (piVar5 != (int *)*piVar4) {
      do {
        if ((undefined4 *)piVar5[2] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar5[2])(1);
        }
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)*piVar4);
    }
    puVar1 = (undefined4 *)*piVar4;
    pvVar2 = (void *)*puVar1;
    *puVar1 = puVar1;
    *(int *)(*piVar4 + 4) = *piVar4;
    piVar4[1] = 0;
    if (pvVar2 != (void *)*piVar4) break;
    piVar4 = piVar4 + 3;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
