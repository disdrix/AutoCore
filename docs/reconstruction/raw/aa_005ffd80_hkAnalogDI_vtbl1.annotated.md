# Annotated low-level: hkAnalogDI_vtbl1

| Field | Value |
|---|---|
| Stable ID | `aa_005ffd80` |
| VA | `0x005ffd80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ffd80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall hkAnalogDI_vtbl1(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 5) & 0x80) != 0) {
    uVar1 = FUN_005ffc90(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
