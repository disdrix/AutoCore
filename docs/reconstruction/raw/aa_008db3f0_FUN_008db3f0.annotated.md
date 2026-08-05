# Annotated low-level: FUN_008db3f0

| Field | Value |
|---|---|
| Stable ID | `aa_008db3f0` |
| VA | `0x008db3f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008db3f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008db3f0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x584) != 0) {
    if (param_2 != 6) {
      (**(code **)(**(int **)(param_1 + 0x584) + 0x58))();
      return;
    }
    piVar1 = *(int **)(param_1 + 0x584);
    iVar2 = *piVar1;
    uVar3 = (**(code **)(**(int **)(param_1 + 0x584) + 0x2d8))();
    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);
    (**(code **)(iVar2 + 0x50))("i_d_first_2d_btn_minimize_off.dds",uVar3);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
