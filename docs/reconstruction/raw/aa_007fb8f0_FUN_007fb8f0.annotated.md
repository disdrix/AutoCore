# Annotated low-level: FUN_007fb8f0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb8f0` |
| VA | `0x007fb8f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb8f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fb8f0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x115c);
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x2b0) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);
  }
  iVar1 = *(int *)(unaff_ESI + 0x1160);
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x2b0) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);
  }
  if (*(undefined4 **)(unaff_ESI + 0x115c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x115c))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x115c) = 0;
  if (*(undefined4 **)(unaff_ESI + 0x1160) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x1160))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x1160) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
