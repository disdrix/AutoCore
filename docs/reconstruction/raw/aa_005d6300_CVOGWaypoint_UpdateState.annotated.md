# Annotated low-level: CVOGWaypoint_UpdateState

| Field | Value |
|---|---|
| Stable ID | `aa_005d6300` |
| VA | `0x005d6300` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d6300`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall CVOGWaypoint_UpdateState(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7122;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("CVOGWaypoint::UpdateState");
  local_4 = 0;
  switch(*(undefined1 *)(param_1 + 0x50)) {
  case 0:
    FUN_005d5750();
    break;
  case 1:
    FUN_005d5960();
    break;
  case 2:
    FUN_005d5cc0();
    break;
  case 3:
    FUN_005d5680();
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
