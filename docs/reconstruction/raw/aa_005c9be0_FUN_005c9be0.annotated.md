# Annotated low-level: FUN_005c9be0

| Field | Value |
|---|---|
| Stable ID | `aa_005c9be0` |
| VA | `0x005c9be0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005c9be0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_005c9be0(int param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a6f6b;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0xd0) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      *(undefined4 *)((int)pvVar1 + 8) = 0;
      *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    }
    *(void **)(param_1 + 0xd0) = pvVar1;
  }
  ExceptionList = local_c;
  return *(undefined4 *)(param_1 + 0xd0);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
