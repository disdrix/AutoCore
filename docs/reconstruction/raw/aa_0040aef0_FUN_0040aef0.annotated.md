# Annotated low-level: FUN_0040aef0

| Field | Value |
|---|---|
| Stable ID | `aa_0040aef0` |
| VA | `0x0040aef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040aef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_0040aef0(int *param_1)

{
  int *piVar1;
  int *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009bc5a8;
  local_c = ExceptionList;
  piVar1 = (int *)*unaff_ESI;
  if ((piVar1 != (int *)0x0) &&
     (ExceptionList = &local_c, piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {
    (**(code **)(*piVar1 + 4))();
  }
  *param_1 = *unaff_ESI;
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
