# Annotated low-level: FUN_008f5fa0

| Field | Value |
|---|---|
| Stable ID | `aa_008f5fa0` |
| VA | `0x008f5fa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008f5fa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008f5fa0(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0xd0))();
  if (cVar1 != (char)param_2) {
    (**(code **)(*param_1 + 0xcc))(param_2);
    (**(code **)(*param_1 + 0x34c))();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
