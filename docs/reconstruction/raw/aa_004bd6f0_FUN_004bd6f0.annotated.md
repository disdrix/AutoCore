# Annotated low-level: FUN_004bd6f0

| Field | Value |
|---|---|
| Stable ID | `aa_004bd6f0` |
| VA | `0x004bd6f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bd6f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004bd6f0(int *param_1)

{
  param_1[2] = DAT_00b03738;
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  *param_1 = *DAT_00b03730;
  param_1[1] = (int)DAT_00b03730;
  *DAT_00b03730 = (int)param_1;
  *(int **)(*param_1 + 4) = param_1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
