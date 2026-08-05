# Annotated low-level: FUN_004eaed0

| Field | Value |
|---|---|
| Stable ID | `aa_004eaed0` |
| VA | `0x004eaed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004eaed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004eaed0(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  
  if (*(void **)(param_1 + 0x84) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x84));
  }
  *(undefined4 *)(param_1 + 0x84) = 0;
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    _Dest = operator_new__(sVar1 * 2 + 2);
    *(wchar_t **)(param_1 + 0x84) = _Dest;
    wcscpy(_Dest,param_2);
    *(undefined2 *)(*(int *)(param_1 + 0x84) + sVar1 * 2) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
