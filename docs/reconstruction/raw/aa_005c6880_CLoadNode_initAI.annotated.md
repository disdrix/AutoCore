# Annotated low-level: CLoadNode_initAI

| Field | Value |
|---|---|
| Stable ID | `aa_005c6880` |
| VA | `0x005c6880` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005c6880`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall CLoadNode_initAI(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6dba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0076cf00("CLoadNode::_initAI");
  *(undefined1 *)(param_1 + 100) = 0;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1d8))
                            ();
  if (piVar1 == (int *)0x0) goto LAB_005c6932;
  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1dc))();
  if (iVar2 == 0) {
    if (((piVar1[0x8a] & piVar1[0x8b]) != 0xffffffff) || (param_2 = 0, (char)piVar1[0x8c] != '\0'))
    goto LAB_005c691c;
  }
  else {
LAB_005c691c:
    param_2 = 1;
  }
  (**(code **)(*piVar1 + 0xc0))(param_2,0xffffffff);
LAB_005c6932:
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
