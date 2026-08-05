# Annotated low-level: FUN_007ab6e0

| Field | Value |
|---|---|
| Stable ID | `aa_007ab6e0` |
| VA | `0x007ab6e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ab6e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007ab6e0(int *param_1)

{
  int unaff_ESI;
  int local_10;
  int iStack_c;
  int iStack_8;
  
  (**(code **)(*param_1 + 0x204))(&local_10);
  iStack_8 = param_1[0x5d] + local_10;
  iStack_c = param_1[0x5c] + unaff_ESI;
  (**(code **)(*param_1 + 8))(&iStack_c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
