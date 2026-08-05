# Raw capture: FUN_007cf0c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cf0c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007cf0c0` |
| **Canonical name** | `FUN_007cf0c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007cfa6b) */
/* WARNING: Removing unreachable block (ram,0x007cfa3e) */
/* WARNING: Removing unreachable block (ram,0x007cfa56) */
/* WARNING: Removing unreachable block (ram,0x007cfa71) */
/* WARNING: Removing unreachable block (ram,0x007cfa9a) */
/* WARNING: Removing unreachable block (ram,0x007cfaaf) */
/* WARNING: Removing unreachable block (ram,0x007cfab5) */
/* WARNING: Removing unreachable block (ram,0x007cfadf) */
/* WARNING: Removing unreachable block (ram,0x007cfaf4) */
/* WARNING: Removing unreachable block (ram,0x007cfafa) */
/* WARNING: Removing unreachable block (ram,0x007cfb23) */
/* WARNING: Removing unreachable block (ram,0x007cfb38) */
/* WARNING: Removing unreachable block (ram,0x007cfb3e) */
/* WARNING: Removing unreachable block (ram,0x007cfb68) */
/* WARNING: Removing unreachable block (ram,0x007cfb7d) */
/* WARNING: Removing unreachable block (ram,0x007cfb83) */
/* WARNING: Removing unreachable block (ram,0x007cfbad) */
/* WARNING: Removing unreachable block (ram,0x007cfbc2) */
/* WARNING: Removing unreachable block (ram,0x007cfbc8) */
/* WARNING: Removing unreachable block (ram,0x007cfbef) */
/* WARNING: Removing unreachable block (ram,0x007cfc04) */
/* WARNING: Removing unreachable block (ram,0x007cfc0a) */
/* WARNING: Removing unreachable block (ram,0x007cfc31) */
/* WARNING: Removing unreachable block (ram,0x007cfc46) */
/* WARNING: Removing unreachable block (ram,0x007cfc4c) */
/* WARNING: Removing unreachable block (ram,0x007cfc70) */
/* WARNING: Removing unreachable block (ram,0x007cfc85) */
/* WARNING: Removing unreachable block (ram,0x007cfc8b) */
/* WARNING: Removing unreachable block (ram,0x007cfcb0) */
/* WARNING: Removing unreachable block (ram,0x007cfcc5) */
/* WARNING: Removing unreachable block (ram,0x007cfccb) */
/* WARNING: Removing unreachable block (ram,0x007cfcf0) */
/* WARNING: Removing unreachable block (ram,0x007cfd05) */
/* WARNING: Removing unreachable block (ram,0x007cfd0b) */
/* WARNING: Removing unreachable block (ram,0x007cfd33) */
/* WARNING: Removing unreachable block (ram,0x007cfd48) */
/* WARNING: Removing unreachable block (ram,0x007cfd4e) */
/* WARNING: Removing unreachable block (ram,0x007cfd73) */
/* WARNING: Removing unreachable block (ram,0x007cfd88) */
/* WARNING: Removing unreachable block (ram,0x007cfd8e) */
/* WARNING: Removing unreachable block (ram,0x007cfdb6) */
/* WARNING: Removing unreachable block (ram,0x007cfdcb) */
/* WARNING: Removing unreachable block (ram,0x007cfdd1) */
/* WARNING: Removing unreachable block (ram,0x007cfdf9) */
/* WARNING: Removing unreachable block (ram,0x007cfe0e) */
/* WARNING: Removing unreachable block (ram,0x007cfe14) */
/* WARNING: Removing unreachable block (ram,0x007cfe3c) */
/* WARNING: Removing unreachable block (ram,0x007cfe51) */
/* WARNING: Removing unreachable block (ram,0x007cfe57) */
/* WARNING: Removing unreachable block (ram,0x007cfe7f) */
/* WARNING: Removing unreachable block (ram,0x007cfe94) */
/* WARNING: Removing unreachable block (ram,0x007cfe9a) */
/* WARNING: Removing unreachable block (ram,0x007cfec2) */
/* WARNING: Removing unreachable block (ram,0x007cfed7) */
/* WARNING: Removing unreachable block (ram,0x007cfedd) */
/* WARNING: Removing unreachable block (ram,0x007cff0d) */
/* WARNING: Removing unreachable block (ram,0x007cff22) */
/* WARNING: Removing unreachable block (ram,0x007cff28) */
/* WARNING: Removing unreachable block (ram,0x007cff47) */
/* WARNING: Removing unreachable block (ram,0x007cff5c) */
/* WARNING: Removing unreachable block (ram,0x007cff62) */
/* WARNING: Removing unreachable block (ram,0x007cff8a) */
/* WARNING: Removing unreachable block (ram,0x007cff9f) */
/* WARNING: Removing unreachable block (ram,0x007cffa5) */
/* WARNING: Removing unreachable block (ram,0x007cffce) */
/* WARNING: Removing unreachable block (ram,0x007cffe3) */
/* WARNING: Removing unreachable block (ram,0x007cffe9) */
/* WARNING: Removing unreachable block (ram,0x007d0013) */
/* WARNING: Removing unreachable block (ram,0x007d0028) */
/* WARNING: Removing unreachable block (ram,0x007d002e) */
/* WARNING: Removing unreachable block (ram,0x007d0057) */
/* WARNING: Removing unreachable block (ram,0x007d006c) */
/* WARNING: Removing unreachable block (ram,0x007d0072) */
/* WARNING: Removing unreachable block (ram,0x007d009b) */
/* WARNING: Removing unreachable block (ram,0x007d00b0) */
/* WARNING: Removing unreachable block (ram,0x007d00b6) */
/* WARNING: Removing unreachable block (ram,0x007d00df) */
/* WARNING: Removing unreachable block (ram,0x007d00f4) */
/* WARNING: Removing unreachable block (ram,0x007d00fa) */
/* WARNING: Removing unreachable block (ram,0x007d0123) */
/* WARNING: Removing unreachable block (ram,0x007d0138) */
/* WARNING: Removing unreachable block (ram,0x007d013e) */
/* WARNING: Removing unreachable block (ram,0x007d0171) */
/* WARNING: Removing unreachable block (ram,0x007d0186) */
/* WARNING: Removing unreachable block (ram,0x007d018c) */
/* WARNING: Removing unreachable block (ram,0x007d01ab) */
/* WARNING: Removing unreachable block (ram,0x007d01c0) */
/* WARNING: Removing unreachable block (ram,0x007d01c6) */

undefined4 __thiscall FUN_007cf0c0(char *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  IUnknown *pIVar2;
  int iVar3;
  LPVOID pvVar4;
  int iVar5;
  BSTR bstrString;
  ULONG UVar6;
  int *unaff_EBX;
  undefined4 *unaff_retaddr;
  int *piVar7;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 *local_15c;
  undefined4 local_158;
  int local_154;
  undefined4 local_150;
  undefined4 *local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  int *local_13c;
  IUnknown *local_138;
  undefined1 *local_134;
  undefined2 local_130;
  undefined2 local_12c;
  short local_128;
  int local_124;
  undefined2 local_11c;
  short local_118;
  undefined2 local_114;
  undefined2 local_110;
  short local_10c;
  undefined2 local_108;
  short local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  BSTR local_d8;
  BSTR local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  wchar_t local_b8 [34];
  wchar_t local_74 [50];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ae911;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_3 = 0;
  *param_2 = 0;
  if (*param_1 == '\0') {
    ExceptionList = pvStack_10;
    return 0x80004004;
  }
  if (DAT_00d1793c == '\0') {
    local_14c = &local_164;
    local_164 = 0;
    local_160 = 0;
    local_15c = (undefined4 *)0x0;
    local_158 = 0;
    local_154 = 0;
    local_150 = 0;
    local_144 = 0;
    local_148 = 0;
    local_140 = 0;
    local_13c = (int *)0x0;
    local_4 = 0;
    iVar3 = FUN_0041a810(local_14c,param_1 + 0x28,0);
    local_15c = &local_100;
    if ((((((((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
            (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
           (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
            ((iVar3 = FUN_004231d0(), iVar3 < 0 ||
             ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||
          (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
         ((((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
             (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
            ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||
           (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
          (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
           (((iVar3 = FUN_004231d0(), iVar3 < 0 ||
             (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
              (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||
            (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
             (iVar3 = FUN_004231d0(), iVar3 < 0)))))))))) ||
        (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
         ((iVar3 = FUN_004231d0(), iVar3 < 0 ||
          (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
           (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||
       ((iVar3 = FUN_004231d0(), iVar3 < 0 || (local_154 == 0)))) {
      FUN_00423170();
      FUN_007a4480();
      local_4 = 0xffffffff;
      FUN_0041a3e0();
    }
    else {
      *param_3 = 0;
      *param_2 = 0;
      iVar3 = FUN_0041a9b0();
      if (iVar3 == 0) {
        if (local_104 < 1) {
          local_4 = 0xffffffff;
          FUN_0041a3e0();
          ExceptionList = pvStack_10;
          return 0;
        }
        *param_2 = (int)local_104;
        pvVar4 = CoTaskMemAlloc(local_104 * 0x118);
        *param_3 = (int)pvVar4;
        if (pvVar4 == (LPVOID)0x0) {
          local_4 = 0xffffffff;
          FUN_0041a3e0();
          ExceptionList = pvStack_10;
          return 0x8007000e;
        }
        iVar3 = 0;
        do {
          *(undefined2 *)(iVar3 + 0x108 + *param_3) = local_110;
          *(undefined4 *)(iVar3 + 0x10c + *param_3) = local_c4;
          *(undefined2 *)(iVar3 + 0x110 + *param_3) = local_12c;
          *(undefined4 *)(iVar3 + 0x114 + *param_3) = local_cc;
          *(undefined4 *)(iVar3 + 0x84 + *param_3) = local_fc;
          *(undefined4 *)(iVar3 + 0x10 + *param_3) = local_bc;
          *(undefined4 *)(iVar3 + 8 + *param_3) = local_f0;
          *(undefined4 *)(iVar3 + *param_3) = local_100;
          *(undefined4 *)(iVar3 + 0x14 + *param_3) = local_d0;
          *(undefined4 *)(iVar3 + 0x18 + *param_3) = local_e8;
          *(undefined4 *)(iVar3 + 0x88 + *param_3) = local_c0;
          *(uint *)(iVar3 + 0xc + *param_3) = (uint)(local_128 == -1);
          *(undefined4 *)(iVar3 + 0x8c + *param_3) = local_e0;
          *(undefined4 *)(iVar3 + 0x90 + *param_3) = local_c8;
          *(BSTR *)(iVar3 + 0x94 + *param_3) = local_d8;
          *(undefined4 *)(iVar3 + 0x98 + *param_3) = local_f8;
          *(undefined4 *)(iVar3 + 0x9c + *param_3) = local_f4;
          *(undefined4 *)(iVar3 + 0xa0 + *param_3) = local_ec;
          *(uint *)(iVar3 + 0xa4 + *param_3) = (uint)(local_118 == -1);
          *(undefined2 *)(iVar3 + 0xa8 + *param_3) = local_108;
          *(undefined4 *)(iVar3 + 0xac + *param_3) = local_e4;
          *(undefined2 *)(iVar3 + 0xb0 + *param_3) = local_114;
          *(undefined2 *)(iVar3 + 0xb2 + *param_3) = (undefined2)local_124;
          *(undefined2 *)(iVar3 + 0xb4 + *param_3) = local_130;
          *(undefined2 *)(iVar3 + 0xb6 + *param_3) = local_11c;
          *(undefined4 *)(iVar3 + 0xbc + *param_3) = local_dc;
          wcscpy((wchar_t *)(iVar3 + 0x1c + *param_3),local_74);
          wcscpy((wchar_t *)(iVar3 + 0xc4 + *param_3),local_b8);
          *(uint *)(iVar3 + 0xc0 + *param_3) = (uint)(local_10c == -1);
          iVar5 = FUN_0041c000();
          iVar3 = iVar3 + 0x118;
        } while (iVar5 == 0);
      }
      if (local_154 != 0) {
        FUN_00422de0();
        FUN_0041bf70();
      }
      FUN_00423170();
      local_4 = 0xffffffff;
      FUN_0041a3e0();
    }
  }
  else {
    bstrString = SysAllocString(L"//vPrefixRaceItem/row");
    local_d4 = bstrString;
    if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_134 = &stack0xfffffe80;
    local_4 = 1;
    FUN_00419ca0();
    local_4._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_4._0_1_ = 1;
    FUN_00419ed0();
    local_4 = CONCAT31(local_4._1_3_,4);
    if (local_138 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    pIVar2 = local_138;
    local_134 = (undefined1 *)0x0;
    UVar6 = (*local_138->lpVtbl[2].Release)(local_138);
    if ((int)UVar6 < 0) {
      _com_issue_errorex(UVar6,pIVar2,(_GUID *)&DAT_00a86118);
    }
    pIVar2 = local_138;
    *unaff_retaddr = local_138;
    pvVar4 = CoTaskMemAlloc((int)local_138 * 0x118);
    *param_3 = (int)pvVar4;
    local_124 = 0;
    piVar7 = unaff_EBX;
    if (0 < (int)pIVar2) {
      do {
        if (local_13c == (int *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        piVar1 = local_13c;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))();
        }
        (**(code **)(*piVar1 + 0x1c))();
        unaff_EBX = (int *)0x0;
        local_124 = local_124 + 1;
        bstrString = local_d8;
        piVar7 = (int *)0x0;
      } while (local_124 < (int)local_138);
    }
    puStack_8._0_1_ = 3;
    if (unaff_EBX != (int *)0x0) {
      (**(code **)(*unaff_EBX + 8))();
    }
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
    if (local_13c != (int *)0x0) {
      (**(code **)(*local_13c + 8))();
    }
    SysFreeString(bstrString);
  }
  ExceptionList = pvStack_10;
  return 0;
}
```
