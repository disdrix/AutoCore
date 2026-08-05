# Annotated low-level: FUN_007fd3d0

| Field | Value |
|---|---|
| Stable ID | `aa_007fd3d0` |
| VA | `0x007fd3d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fd3d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fd3d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x30a0) != 0) {
    FUN_0083edf0();
    FUN_0083ee80(param_1,param_2,param_3,param_4);
    *(undefined1 *)(unaff_EDI + 0x30b6) = 0;
    *(undefined1 *)(unaff_EDI + 0x30b7) = 1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
