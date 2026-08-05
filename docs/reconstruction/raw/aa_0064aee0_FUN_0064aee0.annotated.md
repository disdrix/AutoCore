# Annotated low-level: FUN_0064aee0

| Field | Value |
|---|---|
| Stable ID | `aa_0064aee0` |
| VA | `0x0064aee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064aee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_0064aee0(undefined4 *param_1,int *param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009e4958;
  param_1[2] = *param_2;
  FUN_0065d600(*(undefined4 *)(*(int *)(*param_2 + 0xc) + 0xc),param_2[1]);
  FUN_0064ae60(param_2);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
