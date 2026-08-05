# Annotated low-level: FUN_005a1aa0

| Field | Value |
|---|---|
| Stable ID | `aa_005a1aa0` |
| VA | `0x005a1aa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005a1aa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005a1aa0(undefined4 *param_1)

{
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a620f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_009d7fcc;
  local_4 = 1;
  if ((int *)param_1[0x2c] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x2c] + 4))(1);
  }
  param_1[0x2c] = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_005a4c30(local_10,*(undefined4 *)param_1[0x2f],(undefined4 *)param_1[0x2f]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)param_1[0x2f]);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
