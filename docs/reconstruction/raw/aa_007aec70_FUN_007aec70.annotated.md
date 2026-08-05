# Annotated low-level: FUN_007aec70

| Field | Value |
|---|---|
| Stable ID | `aa_007aec70` |
| VA | `0x007aec70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007aec70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007aec70(int *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)param_1[0xa5];
  if (pvVar1 != (void *)0x0) {
    if (*(char *)((int)param_1 + 0xbb) != '\0') {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    param_1[0xa5] = 0;
    *(undefined1 *)((int)param_1 + 0xbb) = 0;
    (**(code **)(*param_1 + 0x2b4))(&DAT_00a1419b);
  }
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
