# Annotated low-level: FUN_004bff00

| Field | Value |
|---|---|
| Stable ID | `aa_004bff00` |
| VA | `0x004bff00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bff00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004bff00(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a194d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009cb624;
  local_4 = 0;
  FUN_004bfcb0();
  local_4 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1 + 1,0xc,9,FUN_004c0520);
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
