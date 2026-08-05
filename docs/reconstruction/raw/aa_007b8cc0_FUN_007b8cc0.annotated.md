# Annotated low-level: FUN_007b8cc0

| Field | Value |
|---|---|
| Stable ID | `aa_007b8cc0` |
| VA | `0x007b8cc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007b8cc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007b8cc0(int *param_1,BSTR param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *local_14;
  undefined1 *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009ad048;
  pvStack_c = ExceptionList;
  local_10 = &stack0xffffffdc;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_00419ca0(&stack0xffffffdc);
  local_4._0_1_ = 2;
  if (param_1 == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  local_4._0_1_ = 1;
  FUN_00419f60(&local_14);
  local_4._0_1_ = 3;
  if (local_14 == (int *)0x0) {
    *param_3 = '\0';
    local_4 = (uint)local_4._1_3_ << 8;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))();
    }
  }
  else {
    piVar3 = (int *)FUN_00419e90();
    local_4 = CONCAT31(local_4._1_3_,4);
    iVar2 = *piVar3;
    if (iVar2 == 0) {
      pcVar5 = (char *)0x0;
    }
    else {
      if (*(int *)(iVar2 + 4) == 0) {
        uVar4 = FUN_00717fb0();
        *(undefined4 *)(iVar2 + 4) = uVar4;
      }
      pcVar5 = *(char **)(iVar2 + 4);
    }
    do {
      cVar1 = *pcVar5;
      *param_3 = cVar1;
      pcVar5 = pcVar5 + 1;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    if (local_10 != (undefined1 *)0x0) {
      FUN_00419e20();
    }
    local_4._0_1_ = 1;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))();
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))();
    }
  }
  SysFreeString(param_2);
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
