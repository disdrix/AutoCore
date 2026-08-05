# Annotated low-level: FUN_004dbbb0

| Field | Value |
|---|---|
| Stable ID | `aa_004dbbb0` |
| VA | `0x004dbbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004dbbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004dbbb0(int param_1,undefined4 param_2,uint param_3)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe5c8) + 0x10) +
                           (*(uint *)(*(int *)(param_1 + 0xe5c8) + 8) & param_3) * 4) + 4);
  if (iVar2 == 0) {
LAB_004dbbe4:
    iVar2 = 0;
  }
  else {
    do {
      if (param_3 == *(uint *)(iVar2 + 0x10)) {
        if (iVar2 == 0) goto LAB_004dbbe4;
        iVar2 = *(int *)(iVar2 + 8);
        goto LAB_004dbbeb;
      }
      iVar2 = *(int *)(iVar2 + 0xc);
    } while (iVar2 != 0);
    iVar2 = 0;
  }
LAB_004dbbeb:
  if ((iVar2 != 0) &&
     (pvVar1 = CNDHash_LookupByKey(*(void **)(param_1 + 0xe5cc),param_3), pvVar1 == (void *)0x0)) {
    FUN_004e7c30(param_3,iVar2,0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
