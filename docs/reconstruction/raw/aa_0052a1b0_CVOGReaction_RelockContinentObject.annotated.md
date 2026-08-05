# Annotated low-level: CVOGReaction_RelockContinentObject

| Field | Value |
|---|---|
| Stable ID | `aa_0052a1b0` |
| VA | `0x0052a1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0052a1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGReaction_RelockContinentObject(int param_1,undefined4 param_2)

{
  void *local_13c;
  undefined1 local_138 [28];
  undefined4 local_11c;
  
  local_13c = (void *)0x0;
  FUN_00538c80(param_2,&local_13c);
  if (local_13c != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_13c);
  }
  param_1 = param_1 + *(int *)(*(int *)(param_1 + 4) + 4);
  if (param_1 + 4 == *(int *)(*(int *)(param_1 + 0xa8) + 0xe8a0)) {
    FUN_004d1d00();
    local_11c = 0x2a;
    FUN_004d9ec0(local_138,1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
