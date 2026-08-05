# Annotated low-level: FUN_0053afa0

| Field | Value |
|---|---|
| Stable ID | `aa_0053afa0` |
| VA | `0x0053afa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053afa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_0053afa0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 local_408 [4];
  int local_404;
  undefined4 local_400 [127];
  undefined4 local_204 [128];
  
  puVar5 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar5[1] + 0x20d) == '\0') {
    puVar1 = (undefined4 *)puVar5[1];
    do {
      if ((int)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar5 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x20d) == '\0');
  }
  if ((puVar5 != *(undefined4 **)(param_1 + 4)) && ((int)puVar5[3] <= *param_2)) {
    return puVar5 + 4;
  }
  puVar1 = local_204;
  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  local_404 = *param_2;
  puVar1 = local_204;
  puVar2 = local_400;
  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  piVar3 = (int *)FUN_0053aa50(local_408,puVar5,&local_404);
  return (undefined4 *)(*piVar3 + 0x10);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
