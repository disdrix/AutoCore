# Annotated low-level: FUN_007abd60

| Field | Value |
|---|---|
| Stable ID | `aa_007abd60` |
| VA | `0x007abd60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007abd60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007abd60(int *param_1,int *param_2)

{
  int unaff_ESI;
  int unaff_EDI;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_c = param_2[1];
  local_10 = *param_2;
  local_4 = param_2[3] - local_c;
  local_8 = param_2[2] - local_10;
  (**(code **)(*param_1 + 0x118))(&local_10);
  (**(code **)(*param_1 + 8))(&local_c);
  param_1[0x5a] = unaff_EDI;
  param_1[0x5b] = unaff_ESI;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
