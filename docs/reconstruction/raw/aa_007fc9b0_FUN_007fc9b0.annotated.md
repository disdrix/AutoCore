# Annotated low-level: FUN_007fc9b0

| Field | Value |
|---|---|
| Stable ID | `aa_007fc9b0` |
| VA | `0x007fc9b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fc9b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fc9b0(void)

{
  char cVar1;
  int in_EAX;
  int *unaff_EDI;
  
  if ((*(int *)(in_EAX + 0xf40) != 0) && (unaff_EDI != (int *)0x0)) {
    cVar1 = (**(code **)(*unaff_EDI + 0x3d8))();
    if (cVar1 != '\0') {
      FUN_007fc970();
      *(undefined1 *)(in_EAX + 0x30b4) = 1;
      *(undefined1 *)(in_EAX + 0x30b5) = 0;
      if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {
        (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);
      }
      FUN_007fb990();
      (**(code **)(*unaff_EDI + 0xfc))(0,0x3f000000);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
