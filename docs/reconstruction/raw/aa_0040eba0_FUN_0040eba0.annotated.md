# Annotated low-level: FUN_0040eba0

| Field | Value |
|---|---|
| Stable ID | `aa_0040eba0` |
| VA | `0x0040eba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040eba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0040eba0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = FUN_0096be60(param_2,param_3,0,(*(uint *)(*param_1 + 0x2c) & 0x80) != 0);
    return uVar1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
