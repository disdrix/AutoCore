# Annotated low-level: FUN_0059aef0

| Field | Value |
|---|---|
| Stable ID | `aa_0059aef0` |
| VA | `0x0059aef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0059aef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0059aef0(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a5b88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_009d5710;
  local_4 = 1;
  if ((void *)param_1[0x146] != (void *)0x0) {
    operator_delete__((void *)param_1[0x146]);
  }
  param_1[0x146] = 0;
  piVar4 = *(int **)param_1[0x148];
  if (piVar4 != (int *)param_1[0x148]) {
    do {
      if ((void *)piVar4[5] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)piVar4[5]);
      }
      piVar4[5] = 0;
      piVar4[6] = 0;
      piVar4[7] = 0;
      if (*(char *)((int)piVar4 + 0x21) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x21);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x21);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != (int *)param_1[0x148]);
  }
  FUN_0059d5e0(*(undefined4 *)(param_1[0x148] + 4));
  *(undefined4 *)(param_1[0x148] + 4) = param_1[0x148];
  param_1[0x149] = 0;
  *(undefined4 *)param_1[0x148] = param_1[0x148];
  *(undefined4 *)(param_1[0x148] + 8) = param_1[0x148];
  local_4 = local_4 & 0xffffff00;
  FUN_0059d620(local_10,*(undefined4 *)param_1[0x148],(undefined4 *)param_1[0x148]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)param_1[0x148]);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
