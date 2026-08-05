# Annotated low-level: FUN_0060cad0

| Field | Value |
|---|---|
| Stable ID | `aa_0060cad0` |
| VA | `0x0060cad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060cad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0060cad0(int param_1,undefined4 param_2)

{
  int local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  local_4 = *(undefined1 *)(param_1 + 0x21);
  local_8 = param_2;
  local_c = param_1;
  FUN_004e2600(FUN_0060c9b0,&local_c,0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
