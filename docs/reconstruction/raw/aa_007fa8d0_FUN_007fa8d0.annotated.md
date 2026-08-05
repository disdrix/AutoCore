# Annotated low-level: FUN_007fa8d0

| Field | Value |
|---|---|
| Stable ID | `aa_007fa8d0` |
| VA | `0x007fa8d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fa8d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007faaf8) */
/* WARNING: Removing unreachable block (ram,0x007fab0f) */
/* WARNING: Removing unreachable block (ram,0x007fab15) */
/* WARNING: Removing unreachable block (ram,0x007fab60) */
/* WARNING: Removing unreachable block (ram,0x007fab73) */
/* WARNING: Removing unreachable block (ram,0x007fab7e) */
/* WARNING: Removing unreachable block (ram,0x007fab91) */
/* WARNING: Removing unreachable block (ram,0x007faba4) */
/* WARNING: Removing unreachable block (ram,0x007fabb7) */
/* WARNING: Removing unreachable block (ram,0x007fabca) */
/* WARNING: Removing unreachable block (ram,0x007fabdd) */
/* WARNING: Removing unreachable block (ram,0x007fabe5) */
/* WARNING: Removing unreachable block (ram,0x007fabf8) */
/* WARNING: Removing unreachable block (ram,0x007fac08) */
/* WARNING: Removing unreachable block (ram,0x007fac1b) */
/* WARNING: Removing unreachable block (ram,0x007fac2b) */
/* WARNING: Removing unreachable block (ram,0x007fac3e) */
/* WARNING: Removing unreachable block (ram,0x007fac44) */
/* WARNING: Removing unreachable block (ram,0x007fab50) */
/* WARNING: Removing unreachable block (ram,0x007fac4c) */
/* WARNING: Removing unreachable block (ram,0x007fac51) */
/* WARNING: Removing unreachable block (ram,0x007fac68) */
/* WARNING: Removing unreachable block (ram,0x007facc0) */
/* WARNING: Removing unreachable block (ram,0x007facdb) */
/* WARNING: Removing unreachable block (ram,0x007face5) */
/* WARNING: Removing unreachable block (ram,0x007fad37) */
/* WARNING: Removing unreachable block (ram,0x007fad4a) */
/* WARNING: Removing unreachable block (ram,0x007fad5a) */
/* WARNING: Removing unreachable block (ram,0x007fad71) */
/* WARNING: Removing unreachable block (ram,0x007fad88) */
/* WARNING: Removing unreachable block (ram,0x007fad9f) */
/* WARNING: Removing unreachable block (ram,0x007fadb6) */
/* WARNING: Removing unreachable block (ram,0x007fadcd) */
/* WARNING: Removing unreachable block (ram,0x007fade4) */
/* WARNING: Removing unreachable block (ram,0x007fadfb) */
/* WARNING: Removing unreachable block (ram,0x007fae12) */
/* WARNING: Removing unreachable block (ram,0x007fae35) */
/* WARNING: Removing unreachable block (ram,0x007fae58) */
/* WARNING: Removing unreachable block (ram,0x007fae72) */
/* WARNING: Removing unreachable block (ram,0x007fae92) */
/* WARNING: Removing unreachable block (ram,0x007faeb2) */
/* WARNING: Removing unreachable block (ram,0x007faec5) */
/* WARNING: Removing unreachable block (ram,0x007faea5) */
/* WARNING: Removing unreachable block (ram,0x007fae85) */
/* WARNING: Removing unreachable block (ram,0x007fae6b) */
/* WARNING: Removing unreachable block (ram,0x007faeca) */
/* WARNING: Removing unreachable block (ram,0x007fae48) */
/* WARNING: Removing unreachable block (ram,0x007fae25) */
/* WARNING: Removing unreachable block (ram,0x007fad2a) */
/* WARNING: Removing unreachable block (ram,0x007faed0) */
/* WARNING: Removing unreachable block (ram,0x007faed6) */
/* WARNING: Removing unreachable block (ram,0x007faef5) */

void __thiscall FUN_007fa8d0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  wchar_t *unaff_ESI;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b153a;
  local_c = ExceptionList;
  local_4 = 0;
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    ExceptionList = &local_c;
    (**(code **)(*param_2 + 0x1c))();
    iVar1 = _wcsicmp(L"ACCURACY_ADJUST",unaff_ESI);
    if (iVar1 == 0) {
      FUN_007a8b00(param_2,&uStack_1c,&uStack_18);
      *(undefined4 *)(param_1 + 0x4a4) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4a8) = uStack_18;
      *(undefined4 *)(param_1 + 0x4ac) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4b0) = uStack_18;
      *(undefined4 *)(param_1 + 0x4b4) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4b8) = uStack_18;
      *(undefined4 *)(param_1 + 0x4bc) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4c0) = uStack_18;
      *(undefined4 *)(param_1 + 0x4c4) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4c8) = uStack_18;
      *(undefined4 *)(param_1 + 0x4cc) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4d0) = uStack_18;
      *(undefined4 *)(param_1 + 0x4d4) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4d8) = uStack_18;
      *(undefined4 *)(param_1 + 0x4dc) = uStack_1c;
      *(undefined4 *)(param_1 + 0x4e0) = uStack_18;
    }
    else {
      iVar1 = _wcsicmp(L"COMBAT_ACCURACY_ADJUST",unaff_ESI);
      if (iVar1 == 0) {
        FUN_007a8b00(param_2,&uStack_1c,&uStack_18);
        *(undefined4 *)(param_1 + 0x540) = uStack_1c;
        *(undefined4 *)(param_1 + 0x544) = uStack_18;
        *(undefined4 *)(param_1 + 0x548) = uStack_1c;
        *(undefined4 *)(param_1 + 0x54c) = uStack_18;
        *(undefined4 *)(param_1 + 0x550) = uStack_1c;
        *(undefined4 *)(param_1 + 0x554) = uStack_18;
        *(undefined4 *)(param_1 + 0x558) = uStack_1c;
        *(undefined4 *)(param_1 + 0x55c) = uStack_18;
        *(undefined4 *)(param_1 + 0x560) = uStack_1c;
        *(undefined4 *)(param_1 + 0x564) = uStack_18;
        *(undefined4 *)(param_1 + 0x568) = uStack_1c;
        *(undefined4 *)(param_1 + 0x56c) = uStack_18;
        *(undefined4 *)(param_1 + 0x570) = uStack_1c;
        *(undefined4 *)(param_1 + 0x574) = uStack_18;
        *(undefined4 *)(param_1 + 0x578) = uStack_1c;
        *(undefined4 *)(param_1 + 0x57c) = uStack_18;
      }
      else {
        iVar1 = _wcsicmp(L"CURSOR",unaff_ESI);
        if ((iVar1 == 0) || (iVar1 = _wcsicmp(L"CURSOR_COMBAT",unaff_ESI), iVar1 == 0)) {
          _wcsicmp(L"CURSOR_COMBAT",unaff_ESI);
          (**(code **)(*param_2 + 0x30))(param_2);
        }
        else {
          iVar1 = _wcsicmp(L"CURSOR_ACCURACY",unaff_ESI);
          if ((iVar1 == 0) || (iVar1 = _wcsicmp(L"CURSOR_COMBAT_ACCURACY",unaff_ESI), iVar1 == 0)) {
            _wcsicmp(L"CURSOR_COMBAT_ACCURACY",unaff_ESI);
            (**(code **)(*param_2 + 0x30))(param_2);
          }
        }
      }
    }
    local_c = (void *)0xffffffff;
    SysFreeString(unaff_ESI);
    ExceptionList = pvStack_14;
    return;
  }
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  SysFreeString((BSTR)0x0);
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
