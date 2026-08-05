# Annotated low-level: FUN_0044bcc0

| Field | Value |
|---|---|
| Stable ID | `aa_0044bcc0` |
| VA | `0x0044bcc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044bcc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0044bcc0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10), iVar1 != 0))
  {
    return *(undefined4 *)(iVar1 + 8);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
