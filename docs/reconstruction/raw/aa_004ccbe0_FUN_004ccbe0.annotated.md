# Annotated low-level: FUN_004ccbe0

| Field | Value |
|---|---|
| Stable ID | `aa_004ccbe0` |
| VA | `0x004ccbe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ccbe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004ccbe0(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = FUN_00513e70();
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + -0x28) != param_2) {
      FUN_00512670();
    }
    *(int *)(param_1 + -0x28) = param_2;
    return;
  }
  *(int *)(param_1 + -0x28) = param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
