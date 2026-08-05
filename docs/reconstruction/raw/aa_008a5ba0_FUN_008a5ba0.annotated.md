# Annotated low-level: FUN_008a5ba0

| Field | Value |
|---|---|
| Stable ID | `aa_008a5ba0` |
| VA | `0x008a5ba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008a5ba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008a5ba0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b621e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a4c61c;
  local_4 = 4;
  FUN_008a2a30();
  local_4._0_1_ = 3;
  _eh_vector_destructor_iterator_(param_1 + 0x173,0xc,4,FUN_00402280);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00415e90();
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)param_1[0x171]);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
