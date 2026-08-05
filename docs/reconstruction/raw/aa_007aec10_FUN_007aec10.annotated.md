# Annotated low-level: FUN_007aec10

| Field | Value |
|---|---|
| Stable ID | `aa_007aec10` |
| VA | `0x007aec10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007aec10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007aec10(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x328))();
  if (cVar1 == '\0') {
    param_1[0xa7] = 0;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x5c))(param_1[0xa5]);
    param_1[0xa7] = iVar2;
  }
  if (param_1[0xa7] != 0) {
    iVar2 = FUN_007ae2a0(param_1[0xa7]);
    param_1[0xa8] = iVar2;
    return;
  }
  param_1[0xa8] = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
