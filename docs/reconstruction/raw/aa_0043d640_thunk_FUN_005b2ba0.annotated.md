# Annotated low-level: thunk_FUN_005b2ba0

| Field | Value |
|---|---|
| Stable ID | `aa_0043d640` |
| VA | `0x0043d640` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0043d640`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall thunk_FUN_005b2ba0(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar2 != 0) {
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar2 = *(int *)(param_1 + 0x10) + -1, *(int *)(param_1 + 0x10) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x10);
  }
  iVar2 = *(int *)(param_1 + 8);
  while (iVar2 != 0) {
    pvVar1 = *(void **)(*(int *)(param_1 + 4) + -4 + iVar2 * 4);
    iVar2 = iVar2 + -1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(param_1 + 4) == (void *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
