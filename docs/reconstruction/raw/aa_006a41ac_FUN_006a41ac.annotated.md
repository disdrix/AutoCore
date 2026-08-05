# Annotated low-level: FUN_006a41ac

| Field | Value |
|---|---|
| Stable ID | `aa_006a41ac` |
| VA | `0x006a41ac` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a41ac`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006a41ac(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_2 + 8U & 0xfffffff8;
  piVar1 = (int *)(**(code **)**(undefined4 **)(param_1 + 4))(uVar2 * param_3 + 0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = 0;
    *piVar1 = param_1;
    piVar1[3] = 1;
    piVar1[2] = uVar2 - 1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
