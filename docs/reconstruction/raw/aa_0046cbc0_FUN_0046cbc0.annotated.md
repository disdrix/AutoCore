# Annotated low-level: FUN_0046cbc0

| Field | Value |
|---|---|
| Stable ID | `aa_0046cbc0` |
| VA | `0x0046cbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0046cbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_0046cbc0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 4);
  if (iVar1 != 0) {
    if ((*(int *)(unaff_EDI + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_0046cc07;
    }
  }
  iVar1 = 0;
LAB_0046cc07:
  FUN_0044f720(param_2,param_3);
  *param_1 = *(int *)(unaff_EDI + 4) + iVar1 * 0x24;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
