# Annotated low-level: FUN_0084fdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0084fdf0` |
| VA | `0x0084fdf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0084fdf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0084fdf0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (40000 < param_3) {
    if ((param_2 != 5) && (param_2 != 6)) {
      if (param_2 != 8) goto LAB_0084fe23;
      FUN_0084f810();
    }
    return 1;
  }
LAB_0084fe23:
  cVar1 = (**(code **)(*param_1 + 0xd8))();
  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {
    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);
    return uVar2;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
