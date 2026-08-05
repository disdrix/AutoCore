# Annotated low-level: FUN_0052ace0

| Field | Value |
|---|---|
| Stable ID | `aa_0052ace0` |
| VA | `0x0052ace0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0052ace0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0052ace0(int param_1)

{
  int iVar1;
  undefined4 *_Src;
  undefined4 *_Dst;
  
  _Dst = *(undefined4 **)(param_1 + 0xd80);
  if (_Dst != *(undefined4 **)(param_1 + 0xd84)) {
    _Src = _Dst + 1;
    do {
      iVar1 = (**(code **)(*(int *)*_Dst + 0x25c))();
      if (iVar1 < 1) {
        FUN_004d4790(*_Dst);
        memmove(_Dst,_Src,(*(int *)(param_1 + 0xd84) - (int)_Src >> 2) * 4);
        *(int *)(param_1 + 0xd84) = *(int *)(param_1 + 0xd84) + -4;
      }
      else {
        _Dst = _Dst + 1;
        _Src = _Src + 1;
      }
    } while (_Dst != *(undefined4 **)(param_1 + 0xd84));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
