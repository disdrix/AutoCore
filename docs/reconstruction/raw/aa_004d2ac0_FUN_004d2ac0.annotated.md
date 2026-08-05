# Annotated low-level: FUN_004d2ac0

| Field | Value |
|---|---|
| Stable ID | `aa_004d2ac0` |
| VA | `0x004d2ac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d2ac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool __thiscall FUN_004d2ac0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  void *pvVar1;
  
  if (*(char *)(param_1 + 0x83) != '\0') {
    return true;
  }
  pvVar1 = CNDHash_LookupByKey(*(void **)(param_2 + 0x534),param_4);
  return pvVar1 != (void *)0x0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
