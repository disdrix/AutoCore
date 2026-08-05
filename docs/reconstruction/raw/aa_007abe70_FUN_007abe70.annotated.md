# Annotated low-level: FUN_007abe70

| Field | Value |
|---|---|
| Stable ID | `aa_007abe70` |
| VA | `0x007abe70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007abe70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_007abe70(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0xd8))();
  if (cVar1 != '\0') {
    if (*(char *)((int)param_1 + 0xda) == '\0') {
      if (param_1[0xac] != 0) {
                    /* WARNING: Could not recover jumptable at 0x007abeeb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))();
        return uVar2;
      }
    }
    else {
      cVar1 = (**(code **)(*param_1 + 0x280))
                        ((int)(short)param_3,(int)(short)((uint)param_3 >> 0x10));
      if (cVar1 != '\0') {
        return 1;
      }
      (**(code **)(*param_1 + 800))(0,0,0,0,0,0);
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
