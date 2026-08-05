# Annotated low-level: FUN_007fddd0

| Field | Value |
|---|---|
| Stable ID | `aa_007fddd0` |
| VA | `0x007fddd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fddd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fddd0(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *_Dst;
  int unaff_EDI;
  int *local_4;
  
  _Dst = *(int **)(unaff_EDI + 0x3068);
  if (_Dst != *(int **)(unaff_EDI + 0x306c)) {
    local_4 = _Dst + 1;
    do {
      piVar1 = (int *)*_Dst;
      if (piVar1 == (int *)0x0) {
        _Dst = _Dst + 1;
        local_4 = local_4 + 1;
      }
      else {
        memmove(_Dst,local_4,(*(int *)(unaff_EDI + 0x306c) - (int)local_4 >> 2) * 4);
        *(int *)(unaff_EDI + 0x306c) = *(int *)(unaff_EDI + 0x306c) + -4;
        piVar2 = (int *)piVar1[0xac];
        cVar3 = (**(code **)(*piVar1 + 0x3d8))();
        if (cVar3 != '\0') {
          (**(code **)(*piVar1 + 0x440))();
        }
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0xb0))(piVar1);
        }
        (**(code **)*piVar1)(1);
      }
    } while (_Dst != *(int **)(unaff_EDI + 0x306c));
  }
  FUN_00418690(0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
