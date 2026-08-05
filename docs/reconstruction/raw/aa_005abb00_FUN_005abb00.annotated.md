# Annotated low-level: FUN_005abb00

| Field | Value |
|---|---|
| Stable ID | `aa_005abb00` |
| VA | `0x005abb00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005abb00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005abb00(undefined4 *param_1)

{
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a6523;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_009d8da8;
  local_4 = 0;
  FUN_005ac890(local_10,*(undefined4 *)param_1[0x1443],(undefined4 *)param_1[0x1443]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)param_1[0x1443]);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
