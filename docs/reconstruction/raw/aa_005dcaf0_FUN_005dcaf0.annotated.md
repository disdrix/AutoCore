# Annotated low-level: FUN_005dcaf0

| Field | Value |
|---|---|
| Stable ID | `aa_005dcaf0` |
| VA | `0x005dcaf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dcaf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005dcaf0(int param_1)

{
  FUN_00581d10();
  FUN_004e2600(&LAB_005db400,0,0);
  if (*(char *)(param_1 + -0x60) != '\x01') {
    *(undefined1 *)(param_1 + -0x60) = 1;
    if (*(CVOGHBBase **)(param_1 + -0xe8) != (CVOGHBBase *)0x0) {
      CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + -0xe8));
    }
    if (*(char *)(param_1 + -0x35) != '\0') {
      FUN_005de1b0(0,0,0,0,0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
