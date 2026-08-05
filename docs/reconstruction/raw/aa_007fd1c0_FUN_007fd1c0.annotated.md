# Annotated low-level: FUN_007fd1c0

| Field | Value |
|---|---|
| Stable ID | `aa_007fd1c0` |
| VA | `0x007fd1c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fd1c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fd1c0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *in_EAX;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  
  if (*(int *)(unaff_EDI + 0x30b0) != 0) {
    if ((in_EAX != (char *)0x0) && (*in_EAX != '\0')) {
      cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1168) + 0xd0))();
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(unaff_EDI + 0x30b0) + 0x444))();
        FUN_0083e810(unaff_ESI,unaff_retaddr,param_1,param_2);
        *(undefined1 *)(unaff_EDI + 0x30be) = 0;
        *(undefined1 *)(unaff_EDI + 0x30bf) = 1;
        return;
      }
    }
    *(undefined1 *)(unaff_EDI + 0x30be) = 1;
    *(undefined1 *)(unaff_EDI + 0x30bf) = 0;
    if (*(int **)(unaff_EDI + 0x30b0) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EDI + 0x30b0) + 4))(0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
