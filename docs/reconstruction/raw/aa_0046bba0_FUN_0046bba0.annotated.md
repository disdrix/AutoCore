# Annotated low-level: FUN_0046bba0

| Field | Value |
|---|---|
| Stable ID | `aa_0046bba0` |
| VA | `0x0046bba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0046bba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0046bba0(uint param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009bdeb0;
  local_10 = ExceptionList;
  iVar3 = *(int *)((int)param_2 + 4);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)((int)param_2 + 0xc) - iVar3) / 0x18;
  }
  if (param_1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)((int)param_2 + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    if (0xaaaaaaaU - iVar2 < param_1) {
      ExceptionList = &local_10;
      FUN_004540b0();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)((int)param_2 + 8) - iVar3) / 0x18;
    }
    if (uVar6 < iVar2 + param_1) {
      if (0xaaaaaaa - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)((int)param_2 + 8) - iVar3) / 0x18;
      }
      if (uVar6 < iVar3 + param_1) {
        iVar3 = SkillSet_GetEntryCount(param_2);
        uVar6 = iVar3 + param_1;
      }
      pvVar4 = operator_new(uVar6 * 0x18);
      local_8 = 0;
      FUN_0046be60(param_3);
      FUN_00455f50(param_3);
      FUN_0046be60(param_3);
      pvVar1 = *(void **)((int)param_2 + 4);
      if (pvVar1 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)((int)param_2 + 8) - (int)pvVar1) / 0x18;
      }
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      *(void **)((int)param_2 + 0xc) = (void *)(uVar6 * 0x18 + (int)pvVar4);
      *(void **)((int)param_2 + 8) = (void *)((int)pvVar4 + (param_1 + iVar3) * 0x18);
      *(void **)((int)param_2 + 4) = pvVar4;
      ExceptionList = local_10;
      return;
    }
    if ((uint)((*(int *)((int)param_2 + 8) - param_3) / 0x18) < param_1) {
      FUN_0046be60(param_3);
      local_8 = 2;
      FUN_00455f50(param_3);
      *(int *)((int)param_2 + 8) = *(int *)((int)param_2 + 8) + param_1 * 0x18;
    }
    else {
      uVar5 = FUN_0046be60(param_3);
      *(undefined4 *)((int)param_2 + 8) = uVar5;
      FUN_00409ed0(param_3);
    }
    FUN_004426e0();
  }
  ExceptionList = local_10;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
