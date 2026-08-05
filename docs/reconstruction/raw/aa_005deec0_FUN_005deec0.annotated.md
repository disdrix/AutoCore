# Annotated low-level: FUN_005deec0

| Field | Value |
|---|---|
| Stable ID | `aa_005deec0` |
| VA | `0x005deec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005deec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005deec0(undefined4 *param_1,char *param_2)

{
  FILE *pFVar1;
  
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0xffffffff;
  *param_1 = &PTR_FUN_009dbb1c;
  *(undefined1 *)(param_1 + 4) = 1;
  pFVar1 = fopen(param_2,"rb");
  param_1[3] = pFVar1;
  *(bool *)(param_1 + 4) = pFVar1 != (FILE *)0x0;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
