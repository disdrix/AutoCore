# Annotated low-level: FUN_008d3ee0

| Field | Value |
|---|---|
| Stable ID | `aa_008d3ee0` |
| VA | `0x008d3ee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008d3ee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008d3ee0(int param_1)

{
  int iVar1;
  
  FUN_008d7800(param_1);
  if ((*(int *)(param_1 + 0x548) != 0) && (*(int *)(*(int *)(param_1 + 0x548) + 0x48) != 0)) {
    iVar1 = *(int *)(param_1 + 0x568);
    if (iVar1 == 0) {
      FUN_008d3a70();
      return;
    }
    if (iVar1 == 1) {
      FUN_008d3c90();
      return;
    }
    if (iVar1 == 2) {
      FUN_008d3b30();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
