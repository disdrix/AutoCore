# Annotated low-level: FUN_005d3ac0

| Field | Value |
|---|---|
| Stable ID | `aa_005d3ac0` |
| VA | `0x005d3ac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d3ac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005d3ac0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)param_1[0xf];
  *param_1 = &PTR_FUN_009daabc;
  iVar2 = (**(code **)(*piVar1 + 0x18))();
  if (iVar2 == 6) {
    puVar3 = (undefined4 *)FUN_0055dfb0();
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
  }
  iVar2 = (**(code **)(*(int *)param_1[0xf] + 0x18))();
  if (iVar2 == 7) {
    puVar3 = (undefined4 *)FUN_0055dfb0();
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)*piVar1)(1);
  }
  FUN_005074d0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
