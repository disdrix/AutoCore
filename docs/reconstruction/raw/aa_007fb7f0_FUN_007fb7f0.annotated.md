# Annotated low-level: FUN_007fb7f0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb7f0` |
| VA | `0x007fb7f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fb7f0(void)

{
  char cVar1;
  int in_EAX;
  int *piVar2;
  int unaff_EDI;
  
  piVar2 = *(int **)(unaff_EDI + 0x1124);
  if (in_EAX == 2) {
    piVar2 = *(int **)(unaff_EDI + 0x1128);
  }
  else if (in_EAX == 3) {
    piVar2 = *(int **)(unaff_EDI + 0x112c);
  }
  else if (in_EAX == 4) {
    piVar2 = *(int **)(unaff_EDI + 0x1130);
  }
  else if (in_EAX == 5) {
    piVar2 = *(int **)(unaff_EDI + 0x1134);
  }
  if ((*(int *)(unaff_EDI + 0xf40) != 0) && (piVar2 != (int *)0x0)) {
    cVar1 = (**(code **)(*piVar2 + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(*piVar2 + 0x440))();
      if (**(int **)(unaff_EDI + 0xf40) != 0) {
        (**(code **)(*(int *)**(int **)(unaff_EDI + 0xf40) + 0xb0))(piVar2);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
