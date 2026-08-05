# Annotated low-level: FUN_004c2ab0

| Field | Value |
|---|---|
| Stable ID | `aa_004c2ab0` |
| VA | `0x004c2ab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c2ab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004c2ab0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *_Dst;
  
  _Dst = *(int **)(param_1 + 500);
  if (_Dst != *(int **)(param_1 + 0x1f8)) {
    while ((*(int *)*_Dst != param_2 || (((int *)*_Dst)[1] != param_3))) {
      _Dst = _Dst + 1;
      if (_Dst == *(int **)(param_1 + 0x1f8)) {
        return;
      }
    }
    iVar2 = *(int *)(param_1 + 0x1e4);
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(param_1 + 0x1ec) - iVar2 >> 2) <=
        (uint)(*(int *)(param_1 + 0x1e8) - iVar2 >> 2))) {
      FUN_004c2bb0(*(undefined4 *)(param_1 + 0x1e8),1,_Dst);
    }
    else {
      piVar1 = *(int **)(param_1 + 0x1e8);
      *piVar1 = *_Dst;
      *(int **)(param_1 + 0x1e8) = piVar1 + 1;
    }
    iVar2 = FUN_004c22a0(*(undefined4 *)(param_1 + 0x1d8),*(undefined4 *)(param_1 + 0x1dc));
    iVar3 = FUN_004c22a0(*(undefined4 *)*_Dst,((undefined4 *)*_Dst)[1]);
    if ((((iVar2 != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) < 3)) &&
       (1 < *(int *)(iVar2 + 0x24))) {
      *(undefined4 *)(iVar3 + 0x24) = 1;
    }
    memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x1f8) - (int)(_Dst + 1) >> 2) * 4);
    *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + -4;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
