# Annotated low-level: FUN_0073ecf0

| Field | Value |
|---|---|
| Stable ID | `aa_0073ecf0` |
| VA | `0x0073ecf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0073ecf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0073ecf0(int param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ac0a2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0073ebf0();
  pvVar1 = operator_new__(unaff_EDI * 4);
  *(void **)(param_1 + 0xc) = pvVar1;
  pvVar1 = operator_new__(unaff_EDI * 4);
  *(void **)(param_1 + 0x10) = pvVar1;
  piVar2 = operator_new__(unaff_EDI * 0x10 + 4);
  local_4 = 0;
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = piVar2 + 1;
    *piVar2 = unaff_EDI;
    _eh_vector_constructor_iterator_
              (piVar3,0x10,unaff_EDI,(_func_void_void_ptr *)&LAB_00456430,FUN_00449d40);
  }
  iVar4 = 0;
  if (0 < unaff_EDI) {
    piVar5 = (int *)(param_3 + 0xc);
    piVar2 = piVar3 + 2;
    do {
      piVar2[-1] = *(int *)(param_1 + 0xc) + iVar4 * 4;
      *piVar2 = *(int *)(param_1 + 0x10) + iVar4 * 4;
      if (param_3 != 0) {
        piVar2[1] = *piVar5;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 4;
      piVar2 = piVar2 + 4;
    } while (iVar4 < unaff_EDI);
  }
  *(int **)(param_1 + 8) = piVar3;
  *(int *)(param_1 + 0x14) = unaff_EDI;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
