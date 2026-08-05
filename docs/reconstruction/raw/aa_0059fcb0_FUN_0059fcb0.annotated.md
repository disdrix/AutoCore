# Annotated low-level: FUN_0059fcb0

| Field | Value |
|---|---|
| Stable ID | `aa_0059fcb0` |
| VA | `0x0059fcb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0059fcb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0059fcb0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a5fbc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(*(int *)(param_1 + 0x1a8) + 0xa4) == '\0') {
    if ((*(byte *)(param_1 + 0xb4) & 1) == 0) {
      ExceptionList = &pvStack_c;
      FUN_00780980(1);
      FUN_00781530();
    }
    else {
      ExceptionList = &pvStack_c;
      FUN_00780a30(1);
    }
  }
  puVar4 = malloc(0x98);
  *puVar4 = 0x5000;
  *(undefined1 *)(puVar4 + 1) = 2;
  puVar4[2] = *(undefined4 *)(param_1 + 0x250);
  puVar4[4] = *(undefined4 *)(param_1 + 600);
  puVar4[5] = *(undefined4 *)(param_1 + 0x25c);
  puVar5 = operator_new(0x18);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[2] = 0;
  }
  puVar5[1] = *(undefined4 *)(param_1 + 0x238);
  *puVar5 = 0;
  puVar6 = operator_new(0x18);
  local_4 = 0;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_0042b250();
    *puVar6 = &PTR_LAB_009d7b00;
    puVar6[4] = 0;
    puVar6[3] = 0;
    *(undefined1 *)(puVar6 + 5) = 0;
  }
  piVar2 = (int *)puVar5[2];
  local_4 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 2;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar2 + 8))();
    }
  }
  puVar5[2] = puVar6;
  if (puVar6 != (undefined4 *)0x0) {
    puVar6[2] = puVar6[2] + 1;
  }
  iVar3 = puVar5[2];
  if (*(char *)(iVar3 + 0x14) != '\0') {
    *(undefined1 *)(iVar3 + 0x14) = 0;
    free(*(void **)(iVar3 + 0xc));
  }
  *(undefined4 **)(iVar3 + 0xc) = puVar4;
  *(undefined1 *)(iVar3 + 0x14) = 1;
  *(undefined4 *)(iVar3 + 0x10) = 0x98;
  puVar5[3] = *(undefined4 *)(puVar5[2] + 0xc);
  puVar5[4] = 0x98;
  FUN_00419190(puVar5);
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
