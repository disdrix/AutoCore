// READABILITY (auto CF):
//  - Body size: ~193 non-empty decompiler lines.
//  - Control keywords: if×25, while×2, return×2, goto×2.
//  - Notable callees: block×17, SysAllocString×15, FUN_004231d0×14, FUN_007b8a60×14, _com_issue_error×4, CONCAT31×2, FUN_0041a3e0×2, FUN_0041a760×2.
//  - Strings: "//tConfigNewCharacters/row"; "IDRace"; "IDClass"; "CBIDVehicle".
//  - Return sites: 2.

// =============================================================================
// Skill_IDSkillBattleMode1
// -----------------------------------------------------------------------------
// Stable ID: aa_007b92c0
// Address:   0x007b92c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "IDSkillBattleMode1"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007b9b82) */

/* WARNING: Removing unreachable block (ram,0x007b9b0a) */

/* WARNING: Removing unreachable block (ram,0x007b9a8e) */

/* WARNING: Removing unreachable block (ram,0x007b9a12) */

/* WARNING: Removing unreachable block (ram,0x007b9996) */

/* WARNING: Removing unreachable block (ram,0x007b991a) */

/* WARNING: Removing unreachable block (ram,0x007b989e) */

/* WARNING: Removing unreachable block (ram,0x007b9822) */

/* WARNING: Removing unreachable block (ram,0x007b97df) */

/* WARNING: Removing unreachable block (ram,0x007b9860) */

/* WARNING: Removing unreachable block (ram,0x007b98dc) */

/* WARNING: Removing unreachable block (ram,0x007b9958) */

/* WARNING: Removing unreachable block (ram,0x007b99d4) */

/* WARNING: Removing unreachable block (ram,0x007b9a50) */

/* WARNING: Removing unreachable block (ram,0x007b9acc) */

/* WARNING: Removing unreachable block (ram,0x007b9b48) */

/* WARNING: Removing unreachable block (ram,0x007b9b98) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Skill_IDSkillBattleMode1(char *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  ULONG UVar3;

  int iVar4;

  BSTR pOVar5;

  int unaff_EBX;

  IUnknown *local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ *local_b0;

  uint32_t /* width from decompiler */ local_ac;

  int local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ *local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ local_80 [7];

  void *local_64;

  BSTR local_60;

  BSTR local_5c;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ade1d;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    uVar1 = 0x80004004;

  }

  else {

    if (DAT_00d1793c == '\0') {

      local_a0 = &local_b8;

      local_b8 = 0;

      local_b4 = 0;

      local_b0 = (uint32_t /* width from decompiler */ *)0x0;

      local_ac = 0;

      local_a8 = 0;

      local_a4 = 0;

      local_98 = 0;

      local_9c = 0;

      local_94 = 0;

      local_90 = 0;

      local_4 = 0;

      ExceptionList = &local_c;

      iVar2 = FUN_0041a810(local_a0,param_1 + 0x28,0,0);

      local_b0 = local_80;

      if (((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

            ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

          (((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

             (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

            ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 || (local_a8 == 0)))))))) {

        FUN_00423170();

        FUN_007a4480(1);

        local_4 = 0xffffffff;

        FUN_0041a3e0();

      }

      else {

        iVar2 = FUN_0041c000();

        while (iVar2 == 0) {

          local_10 = local_64;

          FUN_0041a760();

          iVar2 = FUN_0041c000();

        }

        if (local_a8 != 0) {

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

      local_5c = SysAllocString(L"//tConfigNewCharacters/row");

      if (local_5c == (BSTR)0x0) {

LAB_007b96dd:

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

      if (local_bc == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      UVar3 = (*local_bc->lpVtbl[2].Release)(local_bc);

      if ((int)UVar3 < 0) {

        _com_issue_errorex(UVar3,local_bc,(_GUID *)&DAT_00a86118);

      }

      if (0 < unaff_EBX) {

        iVar2 = 0;

        while( true ) {

          _com_issue_error(-0x7fffbffd);

          iVar4 = (**(code **)(_DAT_00000000 + 0x20))();

          if (iVar4 < 0) {

            _com_issue_errorex(iVar4,(IUnknown *)0x0,(_GUID *)&DAT_00a86118);

          }

          if (-1 < iVar2) goto LAB_007b9b72;

          _com_issue_error(-0x7fffbffd);

          (**(code **)(_DAT_00000000 + 0x1c))(0);

          pOVar5 = SysAllocString(L"IDRace");

          if (pOVar5 == (BSTR)0x0) break;

          FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDClass");

          if (pOVar5 == (BSTR)0x0) break;

          local_b8 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"CBIDVehicle");

          if (pOVar5 == (BSTR)0x0) break;

          local_b4 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"CBIDTrailer");

          if (pOVar5 == (BSTR)0x0) break;

          local_b0 = (uint32_t /* width from decompiler */ *)FUN_007b8a60();

          pOVar5 = SysAllocString(L"CBIDWeapon");

          if (pOVar5 == (BSTR)0x0) break;

          local_ac = FUN_007b8a60();

          pOVar5 = SysAllocString(L"CBIDArmor");

          if (pOVar5 == (BSTR)0x0) break;

          local_a8 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"CBIDPowerPlant");

          if (pOVar5 == (BSTR)0x0) break;

          local_a4 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"CBIDRaceItem");

          if (pOVar5 == (BSTR)0x0) break;

          local_a0 = (uint32_t /* width from decompiler */ *)FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDStartingTown");

          if (pOVar5 == (BSTR)0x0) break;

          local_9c = FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDStartingSkill1");

          if (pOVar5 == (BSTR)0x0) break;

          local_98 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDOptionCode");

          if (pOVar5 == (BSTR)0x0) break;

          local_94 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDSkillBattleMode1");

          if (pOVar5 == (BSTR)0x0) break;

          local_90 = FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDSkillBattleMode2");

          if (pOVar5 == (BSTR)0x0) break;

          uStack_8c = FUN_007b8a60();

          pOVar5 = SysAllocString(L"IDSkillBattleMode3");

          if (pOVar5 == (BSTR)0x0) break;

          uStack_88 = FUN_007b8a60();

          FUN_0041a760();

          iVar2 = iVar2 + 1;

        }

        goto LAB_007b96dd;

      }

LAB_007b9b72:

      puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

      SysFreeString(local_60);

    }

    uVar1 = 0;

  }

  ExceptionList = local_10;

  return uVar1;

}
