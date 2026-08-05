// =============================================================================
// Named_vConsumables
// -----------------------------------------------------------------------------
// Stable ID: aa_007cd4d0
// Address:   0x007cd4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_vConsumables @ 0x007cd4d0
// Stable ID: aa_007cd4d0
// Embedded strings (evidence for future rename):
//   - "//vConsumables/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, while×2, do×1.
//  - Notable callees: block×17, FUN_004231d0×5, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, CONCAT22.
//  - Strings: "//vConsumables/row".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//vConsumables/row"
 * Domain alias of FUN_007cd4d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007cd926) */

/* WARNING: Removing unreachable block (ram,0x007cd8a8) */

/* WARNING: Removing unreachable block (ram,0x007cd82c) */

/* WARNING: Removing unreachable block (ram,0x007cd7ff) */

/* WARNING: Removing unreachable block (ram,0x007cd817) */

/* WARNING: Removing unreachable block (ram,0x007cd832) */

/* WARNING: Removing unreachable block (ram,0x007cd855) */

/* WARNING: Removing unreachable block (ram,0x007cd86a) */

/* WARNING: Removing unreachable block (ram,0x007cd870) */

/* WARNING: Removing unreachable block (ram,0x007cd893) */

/* WARNING: Removing unreachable block (ram,0x007cd8ae) */

/* WARNING: Removing unreachable block (ram,0x007cd8d2) */

/* WARNING: Removing unreachable block (ram,0x007cd8e7) */

/* WARNING: Removing unreachable block (ram,0x007cd8ed) */

/* WARNING: Removing unreachable block (ram,0x007cd911) */

/* WARNING: Removing unreachable block (ram,0x007cd92c) */

/* WARNING: Removing unreachable block (ram,0x007cd976) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Named_vConsumables(char *param_1)



{

  int iVar1;

  ULONG UVar2;

  uint16_t local_70;

  IUnknown *local_6c;

  IUnknown *local_64;

  uint32_t /* width from decompiler */ local_5c [2];

  BSTR local_54;

  BSTR local_50;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ *local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae7c9;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_20 = &local_38;

    local_38 = 0;

    local_34 = 0;

    local_30 = (uint32_t /* width from decompiler */ *)0x0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = (void *)0x0;

    local_4 = 0;

    ExceptionList = &local_c;

    iVar1 = FUN_0041a810(local_20,param_1 + 0x28,0,0);

    local_30 = local_5c;

    if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (iVar1 = FUN_004231d0(), iVar1 < 0)

        ) || (((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||

              ((iVar1 = FUN_004231d0(), iVar1 < 0 || (local_28 == 0)))))) {

      FUN_00423170();

      FUN_007a4480(1);

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar1 = FUN_0041c000();

      while (iVar1 == 0) {

        local_44 = CONCAT22(local_6c._0_2_,local_70);

        FUN_0041b0b0();

        iVar1 = FUN_0041c000();

      }

      if (local_28 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    ExceptionList = &local_c;

    local_50 = SysAllocString(L"//vConsumables/row");

    if (local_50 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    if (local_64 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar2 = (*local_64->lpVtbl[2].Release)(local_64);

    if ((int)UVar2 < 0) {

      _com_issue_errorex(UVar2,local_64,(_GUID *)&DAT_00a86118);

    }

    iVar1 = 0;

    if (0 < (int)local_64) {

      do {

        _com_issue_error(-0x7fffbffd);

        if (local_6c != (IUnknown *)0x0) {

          (*local_6c->lpVtbl->Release)(local_6c);

        }

        local_6c = (IUnknown *)0x0;

        (**(code **)(_DAT_00000000 + 0x1c))(0);

        iVar1 = iVar1 + 1;

      } while (iVar1 < (int)local_64);

    }

    puStack_8._0_1_ = 3;

    if (local_6c != (IUnknown *)0x0) {

      (*local_6c->lpVtbl->Release)(local_6c);

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

    SysFreeString(local_54);

  }

  ExceptionList = local_10;

  return 0;

}
