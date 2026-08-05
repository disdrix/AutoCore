# Annotated low-level: FUN_0084dac0

| Field | Value |
|---|---|
| Stable ID | `aa_0084dac0` |
| VA | `0x0084dac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0084dac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0084dac0(int *param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  int *piVar2;
  int unaff_retaddr;
  undefined1 local_8 [4];
  int *piStack_4;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x140))(local_8,1);
  iVar1 = *piVar2;
  if (param_4 == '\0') {
    piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0x00000000,1);
    if (*piVar2 < iVar1 / 2 + unaff_retaddr) {
      (**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0x00000000,1);
    }
    if (DAT_00d1b25c / 2 < (int)param_1) {
      (**(code **)(*piStack_4 + 0x140))(&param_2,1);
    }
  }
  (**(code **)(*piStack_4 + 0x118))(&stack0xffffffe0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
