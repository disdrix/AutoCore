// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007df470
// -----------------------------------------------------------------------------
// Stable ID: aa_007df470
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007df470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "DBReader: %u against %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, do×1, while×1.
//  - Notable callees: block×21, FUN_0041a3e0×3, FUN_00422fb0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a990×2, FUN_007a4480×2.
//  - Strings: "//tCharacter/row"; "DBReader: %u against %s".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007df918) */

/* WARNING: Removing unreachable block (ram,0x007df8a6) */

/* WARNING: Removing unreachable block (ram,0x007df81c) */

/* WARNING: Removing unreachable block (ram,0x007df7a4) */

/* WARNING: Removing unreachable block (ram,0x007df7bc) */

/* WARNING: Removing unreachable block (ram,0x007df7d1) */

/* WARNING: Removing unreachable block (ram,0x007df7d7) */

/* WARNING: Removing unreachable block (ram,0x007df7ef) */

/* WARNING: Removing unreachable block (ram,0x007df807) */

/* WARNING: Removing unreachable block (ram,0x007df822) */

/* WARNING: Removing unreachable block (ram,0x007df836) */

/* WARNING: Removing unreachable block (ram,0x007df84e) */

/* WARNING: Removing unreachable block (ram,0x007df863) */

/* WARNING: Removing unreachable block (ram,0x007df869) */

/* WARNING: Removing unreachable block (ram,0x007df8d1) */

/* WARNING: Removing unreachable block (ram,0x007df879) */

/* WARNING: Removing unreachable block (ram,0x007df8f7) */

/* WARNING: Removing unreachable block (ram,0x007df8fd) */

/* WARNING: Removing unreachable block (ram,0x007df91e) */

/* WARNING: Removing unreachable block (ram,0x007df92b) */

/* WARNING: Removing unreachable block (ram,0x007df931) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007df470(char *param_1,short *param_2)



{

  int iVar1;

  ULONG UVar2;

  IUnknown *unaff_EBX;

  int *unaff_retaddr;

  IUnknown *pIVar3;

  IUnknown *local_4c;

  BSTR local_48;

  BSTR local_44;

  uint local_40;

  uint8_t *local_3c;

  IUnknown **local_38;

  uint32_t /* width from decompiler */ local_34;

  int local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ **local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  void *local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aef0a;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c != '\0') {

    ExceptionList = &local_c;

    local_44 = SysAllocString(L"//tCharacter/row");

    if (local_44 != (BSTR)0x0) {

      local_3c = &stack0xffffff9c;

      local_4 = 1;

      FUN_00419ca0();

      local_4._0_1_ = 2;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_4._0_1_ = 1;

      FUN_00419ed0();

      local_4 = CONCAT31(local_4._1_3_,4);

      if (local_4c == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      pIVar3 = local_4c;

      local_48 = (BSTR)0x0;

      UVar2 = (*local_4c->lpVtbl[2].Release)(local_4c);

      if ((int)UVar2 < 0) {

        _com_issue_errorex(UVar2,pIVar3,(_GUID *)&DAT_00a86118);

      }

      iVar1 = 0;

      pIVar3 = unaff_EBX;

      if (0 < (int)local_4c) {

        do {

          _com_issue_error(-0x7fffbffd);

          if (pIVar3 != (IUnknown *)0x0) {

            (*pIVar3->lpVtbl->Release)(pIVar3);

          }

          pIVar3 = (IUnknown *)0x0;

          (**(code **)(_DAT_00000000 + 0x1c))(0);

          unaff_EBX = (IUnknown *)0x0;

          iVar1 = iVar1 + 1;

        } while (iVar1 < (int)local_4c);

      }

      puStack_8._0_1_ = 3;

      if (unaff_EBX != (IUnknown *)0x0) {

        (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

      }

      puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

      SysFreeString(local_48);

      ExceptionList = local_10;

      return 1;

    }

                    /* WARNING: Subroutine does not return */

    FUN_004048e0();

  }

  local_40 = (uint)*(byte *)((int)param_2 + 9);

  local_3c = (uint8_t *)CONCAT22((short)((uint)param_1 >> 0x10),-*param_2);

  local_38 = (IUnknown **)0x0;

  local_34 = 0;

  local_30 = 0;

  local_2c = 0;

  local_20 = &local_38;

  local_28 = 0;

  local_24 = 0;

  local_18 = 0;

  local_1c = 0;

  local_14 = (void *)0x0;

  local_10 = (void *)0x0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_004230d0();

  iVar1 = FUN_00422fb0(1,1);

  if (((-1 < iVar1) && (iVar1 = FUN_00422fb0(1,2), -1 < iVar1)) &&

     (iVar1 = FUN_00422fb0(1,3), -1 < iVar1)) {

    iVar1 = FUN_0041a810(&local_40,param_1 + 0x28,0,0,&DAT_00a140c8,0);

  }

  local_38 = &local_4c;

  if ((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_40,1), -1 < iVar1)) {

    if (local_30 != 0) {

      iVar1 = FUN_0041a9b0();

      if (iVar1 == 0) {

        *unaff_retaddr = (int)local_4c;

        FUN_0041a990();

        FUN_00423170();

        local_c = (void *)0xffffffff;

        FUN_0041a3e0();

        ExceptionList = local_14;

        return 0;

      }

      FUN_0041a990();

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s",iVar1);

      local_c = (void *)0xffffffff;

      FUN_0041a3e0();

      ExceptionList = local_14;

      return 0;

    }

    iVar1 = -0x7fffbffb;

  }

  FUN_00423170();

  FUN_007a4480(1,"DBReader: %u against %s",iVar1);

  local_c = (void *)0xffffffff;

  FUN_0041a3e0();

  ExceptionList = local_14;

  return 0;

}
