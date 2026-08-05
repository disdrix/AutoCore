# Annotated low-level: FUN_007b8de0

| Field | Value |
|---|---|
| Stable ID | `aa_007b8de0` |
| VA | `0x007b8de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007b8de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007b8de0(int *param_1,BSTR param_2,wchar_t *param_3)

{
  OLECHAR *psz;
  undefined1 uVar1;
  int *piVar2;
  BSTR _Source;
  int *local_14;
  undefined1 *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009ad07a;
  pvStack_c = ExceptionList;
  local_10 = &stack0xffffffd8;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_00419ca0(&stack0xffffffd8);
  local_4._0_1_ = 2;
  if (param_1 == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  local_4._0_1_ = 1;
  FUN_00419f60(&local_14);
  local_4._0_1_ = 3;
  uVar1 = (undefined1)local_4;
  local_4._0_1_ = 3;
  if (local_14 != (int *)0x0) {
    piVar2 = (int *)FUN_00419e90();
    local_4 = CONCAT31(local_4._1_3_,4);
    if (((undefined4 *)*piVar2 == (undefined4 *)0x0) ||
       (psz = *(OLECHAR **)*piVar2, psz == (OLECHAR *)0x0)) {
      _Source = (BSTR)0x0;
    }
    else {
      _Source = SysAllocString(psz);
      if (_Source == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0();
      }
    }
    if (local_10 != (undefined1 *)0x0) {
      FUN_00419e20();
    }
    wcscpy(param_3,_Source);
    SysFreeString(_Source);
    local_4._0_1_ = 1;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))();
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))();
    }
    SysFreeString(param_2);
    ExceptionList = pvStack_c;
    return;
  }
  local_4._0_1_ = uVar1;
  wcscpy(param_3,L"");
  local_4._0_1_ = 1;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  SysFreeString(param_2);
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
