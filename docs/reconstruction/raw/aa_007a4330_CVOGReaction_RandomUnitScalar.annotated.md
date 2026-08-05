# Annotated low-level: CVOGReaction_RandomUnitScalar

| Field | Value |
|---|---|
| Stable ID | `aa_007a4330` |
| VA | `0x007a4330` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a4330`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined * CVOGReaction_RandomUnitScalar(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b009f;
  local_c = ExceptionList;
  if ((DAT_00d20c34 & 1) == 0) {
    DAT_00d20c34 = DAT_00d20c34 | 1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_007a42d0();
    _atexit((_func_4879 *)&LAB_009c30c0);
  }
  ExceptionList = local_c;
  return &DAT_00d20c1c;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
