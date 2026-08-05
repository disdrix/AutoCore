# Annotated low-level: FUN_004ebf50

| Field | Value |
|---|---|
| Stable ID | `aa_004ebf50` |
| VA | `0x004ebf50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ebf50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004ebf50(int param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a27cf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("CollectAllSoundPreloads");
  local_4 = 0;
  FUN_004eb3b0();
  if (*(int *)(param_1 + 0x88) != 0) {
    FUN_004a04f0(param_2,0,1,0);
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
