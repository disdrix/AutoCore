# Annotated low-level: FUN_008c8fa0

| Field | Value |
|---|---|
| Stable ID | `aa_008c8fa0` |
| VA | `0x008c8fa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008c8fa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008c8fa0(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x590);
  if (piVar1 != (int *)0x0) {
    *(undefined1 *)((int)piVar1 + 0x489) = 0;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);
    piVar1[0x8b] = *piVar2;
  }
  piVar1 = *(int **)(unaff_ESI + 0x594);
  if (piVar1 != (int *)0x0) {
    *(undefined1 *)((int)piVar1 + 0x489) = 0;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);
    piVar1[0x8b] = *piVar2;
  }
  if (*(int *)(unaff_ESI + 0x564) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x564) + 0xd4))(1);
  }
  if (*(int *)(unaff_ESI + 0x56c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x56c) + 0xd4))(1);
  }
  if (*(int *)(unaff_ESI + 0x570) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x570) + 0xd4))(1);
  }
  if (*(int *)(unaff_ESI + 0x568) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0xd4))(1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
