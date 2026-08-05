# Annotated low-level: FUN_0078fdd0

| Field | Value |
|---|---|
| Stable ID | `aa_0078fdd0` |
| VA | `0x0078fdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0078fdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 __fastcall FUN_0078fdd0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0078fdf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x388))();
    return uVar2;
  }
  return *(undefined1 *)((int)param_1 + 0x496);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
