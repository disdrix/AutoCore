# Annotated low-level: FUN_005dec90

| Field | Value |
|---|---|
| Stable ID | `aa_005dec90` |
| VA | `0x005dec90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dec90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005dec90(void)

{
  undefined4 uVar1;
  
  if (DAT_00bc56a5 == '\x01') {
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))("---------------------------\n");
    FUN_00631f10(uVar1);
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))(" Havok - Build (%d)\n",0x131cb47);
    FUN_00631f10(uVar1);
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))(" Base system initialized.   \n");
    FUN_00631f10(uVar1);
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))("----------------------------\n");
    FUN_00631f10(uVar1);
    (**(code **)(*DAT_00d030e0 + 4))();
    FUN_00631f70();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
