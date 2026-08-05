# Annotated low-level: FUN_005fc2b0

| Field | Value |
|---|---|
| Stable ID | `aa_005fc2b0` |
| VA | `0x005fc2b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fc2b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005fc2b0(void)

{
  int iVar1;
  undefined1 auStack_b8 [148];
  void *pvStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a7bde;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_00649e70();
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc0,0x2e);
  *(undefined2 *)(iVar1 + 4) = 0xc0;
  pvStack_1c = (void *)0x0;
  FUN_0064a1b0(auStack_b8);
  ExceptionList = pvStack_24;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
