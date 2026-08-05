# Annotated low-level: thunk_FUN_0040d9c0

| Field | Value |
|---|---|
| Stable ID | `aa_0040fd50` |
| VA | `0x0040fd50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040fd50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void thunk_FUN_0040d9c0(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x10);
  while (iVar2 != 0) {
    if ((*(int *)(unaff_ESI + 0x10) != 0) &&
       (iVar2 = *(int *)(unaff_ESI + 0x10) + -1, *(int *)(unaff_ESI + 0x10) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    iVar2 = *(int *)(unaff_ESI + 0x10);
  }
  iVar2 = *(int *)(unaff_ESI + 8);
  while (iVar2 != 0) {
    pvVar1 = *(void **)(*(int *)(unaff_ESI + 4) + -4 + iVar2 * 4);
    iVar2 = iVar2 + -1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 4) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
