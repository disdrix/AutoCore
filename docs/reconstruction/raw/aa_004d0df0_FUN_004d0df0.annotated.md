# Annotated low-level: FUN_004d0df0

| Field | Value |
|---|---|
| Stable ID | `aa_004d0df0` |
| VA | `0x004d0df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d0df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * __thiscall FUN_004d0df0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1fa1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("GenerateLootItem (id)");
  local_4 = 0;
  iVar1 = FUN_0050a7d0(param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x218))(param_1);
    }
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return piVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
