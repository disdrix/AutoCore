# Annotated low-level: FUN_005e6be0

| Field | Value |
|---|---|
| Stable ID | `aa_005e6be0` |
| VA | `0x005e6be0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005e6be0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005e6be0(int *param_1)

{
  char cVar1;
  void *pvVar2;
  
  if ((void *)param_1[0x5b] != (void *)0x0) {
    operator_delete__((void *)param_1[0x5b]);
  }
  param_1[0x5b] = 0;
  pvVar2 = operator_new__(0x20);
  param_1[0x5b] = (int)pvVar2;
  cVar1 = (**(code **)(*param_1 + 0xa0))(pvVar2);
  if (cVar1 == '\0') {
    if ((void *)param_1[0x5b] != (void *)0x0) {
      operator_delete__((void *)param_1[0x5b]);
    }
    param_1[0x5b] = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
