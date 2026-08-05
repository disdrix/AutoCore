# Annotated low-level: FUN_0049dab0

| Field | Value |
|---|---|
| Stable ID | `aa_0049dab0` |
| VA | `0x0049dab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0049dab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool FUN_0049dab0(wchar_t *param_1,int param_2,int *param_3)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  pwVar1 = wcstok(param_1,L", ");
  while ((pwVar1 != (wchar_t *)0x0 && (*param_3 < 8))) {
    uVar2 = FUN_0049cb20(pwVar1);
    *(undefined4 *)(param_2 + *param_3 * 4) = uVar2;
    pwVar1 = wcstok((wchar_t *)0x0,L", ");
    *param_3 = *param_3 + 1;
  }
  return 0 < *param_3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
