// =============================================================================
// Named_tOutpost
// -----------------------------------------------------------------------------
// Stable ID: aa_007c3650
// Address:   0x007c3650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_tOutpost @ 0x007c3650
// Stable ID: aa_007c3650
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "//tOutpost/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×14, return×3, while×2, do×1.
//  - Notable callees: block×18, FUN_004231d0×4, _com_issue_error×3, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, CONCAT31, FUN_004048e0.
//  - Strings: "DBReader: %u against %s"; "//tOutpost/row".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//tOutpost/row"
 * Domain alias of FUN_007c3650 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007c3ab5) */

/* WARNING: Removing unreachable block (ram,0x007c3a2d) */

/* WARNING: Removing unreachable block (ram,0x007c39af) */

/* WARNING: Removing unreachable block (ram,0x007c39c7) */

/* WARNING: Removing unreachable block (ram,0x007c39e2) */

/* WARNING: Removing unreachable block (ram,0x007c39e8) */

/* WARNING: Removing unreachable block (ram,0x007c39fa) */

/* WARNING: Removing unreachable block (ram,0x007c3a12) */

/* WARNING: Removing unreachable block (ram,0x007c3a33) */

/* WARNING: Removing unreachable block (ram,0x007c3a56) */

/* WARNING: Removing unreachable block (ram,0x007c3a71) */

/* WARNING: Removing unreachable block (ram,0x007c3a77) */

/* WARNING: Removing unreachable block (ram,0x007c3a9a) */

/* WARNING: Removing unreachable block (ram,0x007c3abb) */

/* WARNING: Removing unreachable block (ram,0x007c3ae0) */

/* WARNING: Removing unreachable block (ram,0x007c3afb) */

/* WARNING: Removing unreachable block (ram,0x007c3b01) */

/* WARNING: Removing unreachable block (ram,0x007c3b1e) */



uint32_t /* width from decompiler */ __thiscall Named_tOutpost(char *param_1,uint32_t /* width from decompiler */ param_2,char param_3,int *param_4)



{

  int *piVar1;

  int iVar2;

  IUnknown *This;

  ULONG UVar3;

  IUnknown *local_6c;

  int *local_68;

  uint8_t *local_64;

  int iStack_60;

  uint8_t auStack_5c [12];

  BSTR local_50;

  BSTR pOStack_4c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint8_t *local_2c;

  uint32_t /* width from decompiler */ local_28;

  int local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae29a;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  local_68 = (int *)(uint)(param_3 != '\0');

  ExceptionList = &local_c;

  FUN_0041d4d0(0,0,0);

  if (DAT_00d1793c == '\0') {

    local_20 = &local_38;

    local_38 = 0;

    local_34 = 0;

    local_30 = 0;

    local_2c = (uint8_t *)0x0;

    local_28 = 0;

    local_24 = 0;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    FUN_004230d0(local_20);

    iVar2 = FUN_00422fb0(1);

    if (-1 < iVar2) {

      iVar2 = FUN_0041a810(&local_34,param_1 + 0x28,0,0,&DAT_00a140c8);

    }

    local_2c = auStack_5c;

    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(&local_34), iVar2 < 0)) ||

        (iVar2 = FUN_004231d0(&local_34), iVar2 < 0)) ||

       (((iVar2 = FUN_004231d0(&local_34), iVar2 < 0 || (iVar2 = FUN_004231d0(&local_34), iVar2 < 0)

         ) || (local_24 == 0)))) {

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

      FUN_0041a3e0();

    }

    else {

      iVar2 = FUN_0041c000();

      while (iVar2 == 0) {

        local_38 = local_50;

        FUN_0041b0b0();

        iVar2 = FUN_0041c000();

      }

      if (local_24 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      FUN_0041a3e0();

    }

  }

  else {

    local_50 = SysAllocString(L"//tOutpost/row");

    if (local_50 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_64 = &stack0xffffff80;

    local_4 = 1;

    FUN_00419ca0(&stack0xffffff80);

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0(&local_6c);

    local_4 = CONCAT31(local_4._1_3_,4);

    This = local_6c;

    if (local_6c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

      This = local_6c;

    }

    local_64 = (uint8_t *)0x0;

    UVar3 = (*This->lpVtbl[2].Release)(This);

    if ((int)UVar3 < 0) {

      _com_issue_errorex(UVar3,This,(_GUID *)&DAT_00a86118);

    }

    iVar2 = 0;

    if (0 < iStack_60) {

      do {

        if (local_68 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar1 = local_68;

        if (param_4 != (int *)0x0) {

          (**(code **)(*param_4 + 8))();

        }

        param_4 = (int *)0x0;

        (**(code **)(*piVar1 + 0x1c))(piVar1);

        iVar2 = iVar2 + 1;

      } while (iVar2 < iStack_60);

    }

    if (param_4 != (int *)0x0) {

      (**(code **)(*param_4 + 8))();

    }

    if (local_68 != (int *)0x0) {

      (**(code **)(*local_68 + 8))();

    }

    SysFreeString(pOStack_4c);

  }

  ExceptionList = puStack_8;

  return 0;

}
