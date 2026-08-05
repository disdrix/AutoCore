# Annotated low-level: FUN_0063fac0

| Field | Value |
|---|---|
| Stable ID | `aa_0063fac0` |
| VA | `0x0063fac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0063fac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0063fac0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x24,0x10);
  *(undefined2 *)(iVar1 + 4) = 0x24;
  FUN_00652790(0xffffffff);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
