# Annotated low-level: FUN_007a4fd0

| Field | Value |
|---|---|
| Stable ID | `aa_007a4fd0` |
| VA | `0x007a4fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a4fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_007a4fd0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *_Dst;
  
  _Dst = *(int **)(param_1 + 8);
  while( true ) {
    if (_Dst == *(int **)(param_1 + 0xc)) {
      return 0;
    }
    iVar1 = *_Dst;
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x200) == param_2)) &&
       (*(int *)(iVar1 + 0x204) == param_3)) break;
    _Dst = _Dst + 1;
  }
  if ((void *)*_Dst != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)*_Dst);
  }
  memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0xc) - (int)(_Dst + 1) >> 2) * 4);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -4;
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
