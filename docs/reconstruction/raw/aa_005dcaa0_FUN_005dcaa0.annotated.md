# Annotated low-level: FUN_005dcaa0

| Field | Value |
|---|---|
| Stable ID | `aa_005dcaa0` |
| VA | `0x005dcaa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dcaa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005dcaa0(int param_1)

{
  FUN_00581d50();
  FUN_004e2600(&LAB_005db3d0,0,0);
  if ((*(char *)(param_1 + -0x60) != '\0') &&
     (*(undefined1 *)(param_1 + -0x60) = 0, *(int *)(param_1 + -0xe8) != 0)) {
    FUN_005081d0();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
