# Annotated low-level: FUN_007afdc0

| Field | Value |
|---|---|
| Stable ID | `aa_007afdc0` |
| VA | `0x007afdc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007afdc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007afdc0(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xaa] != 0) && (param_1[0xa6] != 0)) {
    iVar1 = (**(code **)(*param_1 + 0x1a0))();
    if ((iVar1 != 0) && ((char)param_1[0x2e] == '\x01')) {
      FUN_00756060();
      if ((undefined4 *)param_1[0xad] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0xad])(0);
      }
      *(undefined1 *)(param_1 + 0x2e) = 0;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
