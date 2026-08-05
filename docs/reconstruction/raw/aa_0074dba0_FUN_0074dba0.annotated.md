# Annotated low-level: FUN_0074dba0

| Field | Value |
|---|---|
| Stable ID | `aa_0074dba0` |
| VA | `0x0074dba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074dba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0074dba0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *local_4;
  
  local_4 = param_1;
  FUN_0046c1b0();
  piVar1 = local_4;
  if (local_4 == (int *)param_1[5]) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmPriorityBlendController.cpp",
                   0xfa,1,"RemoveAnimation() called with animation that is not added to controller!"
                  );
    return 0;
  }
  (**(code **)(*param_1 + 0x3c))(param_2,local_4 + 3);
  FUN_00449ff0(&local_4,piVar1);
  return param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
