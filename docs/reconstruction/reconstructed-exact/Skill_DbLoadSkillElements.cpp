// READABILITY (auto CF):
//  - Body size: ~187 non-empty decompiler lines.
//  - Control keywords: if×15, return×3, while×2, do×1.
//  - Notable callees: block×16, FUN_004231d0×5, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, FUN_004048e0.
//  - Strings: "DBReader: %u against %s"; "//tSkillElements/row".
//  - Return sites: 3.

// =============================================================================
// Skill_DbLoadSkillElements
// -----------------------------------------------------------------------------
// Purpose:  Load skill element rows from `//tSkillElements/row` for a parent skill definition (called from Skill_DbLoadSkillsCharacters). Builds per-skill element list used by cast/apply pipelines.
//
// Address:  0x007d9440  (autoassault.exe, image base 0x400000)
// Stable:   aa_007d9440
// System:   skills-abilities
//
// Evidence strings (from raw decompile):
//   - "//tSkillElements/row"
//   - "DBReader: %u against %s"
//
// Notable callees:
//   - operator_new
//   - FUN_0041c730 / FUN_0041a810 / FUN_004231d0
//   - SysAllocString
//   - FUN_007a4480
//
// Notes:    __thiscall on skill/container; param_2 mode flag.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

/* WARNING: Removing unreachable block (ram,0x007d98be) */

/* WARNING: Removing unreachable block (ram,0x007d9842) */

/* WARNING: Removing unreachable block (ram,0x007d97ce) */

/* WARNING: Removing unreachable block (ram,0x007d97ee) */

/* WARNING: Removing unreachable block (ram,0x007d9803) */

/* WARNING: Removing unreachable block (ram,0x007d9809) */

/* WARNING: Removing unreachable block (ram,0x007d982d) */

/* WARNING: Removing unreachable block (ram,0x007d9848) */

/* WARNING: Removing unreachable block (ram,0x007d986c) */

/* WARNING: Removing unreachable block (ram,0x007d9881) */

/* WARNING: Removing unreachable block (ram,0x007d9887) */

/* WARNING: Removing unreachable block (ram,0x007d98a9) */

/* WARNING: Removing unreachable block (ram,0x007d98c4) */

/* WARNING: Removing unreachable block (ram,0x007d98e5) */

/* WARNING: Removing unreachable block (ram,0x007d98fa) */

/* WARNING: Removing unreachable block (ram,0x007d9900) */

/* WARNING: Exceeded maximum restarts with more pending */



uint32_t /* width from decompiler */ __thiscall Skill_DbLoadSkillElements(char *param_1,char param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  BSTR bstrString;

  ULONG UVar4;

  IUnknown *unaff_EBX;

  uint8_t *puVar5;

  bool bVar6;

  IUnknown *pIStack_64;

  IUnknown *pIStack_60;

  int iStack_5c;

  int iStack_58;

  char *local_54;

  uint8_t *puStack_50;

  int iStack_4c;

  int iStack_48;

  int iStack_44;

  BSTR pOStack_40;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  int *piStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  int iStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ *puStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009aeb3e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_54 = param_1;

  if ((param_2 != '\0') &&

     (ExceptionList = &pvStack_c, *(uint32_t /* width from decompiler */ **)(param_1 + 0x558) != (uint32_t /* width from decompiler */ *)0x0)) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x558))();

    param_1[0x558] = '\0';

    param_1[0x559] = '\0';

    param_1[0x55a] = '\0';

    param_1[0x55b] = '\0';

  }

  puVar1 = operator_new(0x38);

  uStack_4 = 0;

  pOStack_40 = (BSTR)puVar1;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0041c730();

    *puVar1 = &PTR_FUN_00a8615c;

    puVar1[0xd] = 0;

  }

  uStack_4 = 0xffffffff;

  bVar6 = DAT_00d1793c == '\0';

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x558) = puVar1;

  if (bVar6) {

    if (*param_1 == '\0') {

      ExceptionList = pvStack_c;

      return 0x80004004;

    }

    puStack_20 = &uStack_38;

    uStack_38 = 0;

    uStack_34 = 0;

    piStack_30 = (int *)0x0;

    uStack_2c = 0;

    iStack_28 = 0;

    uStack_24 = 0;

    uStack_18 = 0;

    uStack_1c = 0;

    uStack_14 = 0;

    uStack_10 = 0;

    uStack_4 = 1;

    iVar2 = FUN_0041a810(puStack_20,param_1 + 0x28,0,0,&DAT_00a140c8);

    piStack_30 = &iStack_5c;

    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(&uStack_38), iVar2 < 0)) ||

        (iVar2 = FUN_004231d0(&uStack_38), iVar2 < 0)) ||

       (((iVar2 = FUN_004231d0(&uStack_38), iVar2 < 0 ||

         (iVar2 = FUN_004231d0(&uStack_38), iVar2 < 0)) ||

        ((iVar2 = FUN_004231d0(&uStack_38), iVar2 < 0 || (iStack_28 == 0)))))) {

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

      uStack_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar2 = FUN_0041c000();

      while (iVar2 == 0) {

        piVar3 = operator_new(0x14);

        piVar3[3] = iStack_4c;

        piVar3[4] = iStack_48;

        piVar3[1] = iStack_44;

        *piVar3 = iStack_5c;

        *(char *)(piVar3 + 2) = param_2;

        FUN_0041ace0(*(uint32_t /* width from decompiler */ *)(local_54 + 0x558));

        iVar2 = FUN_0041c000();

      }

      if (iStack_28 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      uStack_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    bstrString = SysAllocString(L"//tSkillElements/row");

    pOStack_40 = bstrString;

    if (bstrString == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    puStack_50 = &stack0xffffff88;

    uStack_4 = 2;

    FUN_00419ca0();

    uStack_4._0_1_ = 3;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    uStack_4._0_1_ = 2;

    FUN_00419ed0();

    uStack_4 = CONCAT31(uStack_4._1_3_,5);

    if (pIStack_60 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    iStack_58 = 0;

    UVar4 = (*pIStack_60->lpVtbl[2].Release)(pIStack_60);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,pIStack_60,(_GUID *)&DAT_00a86118);

    }

    puVar5 = (uint8_t *)0x0;

    local_54 = (char *)0x0;

    if (0 < iStack_5c) {

      do {

        pIStack_64 = (IUnknown *)0x0;

        if (pIStack_60 == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

          unaff_EBX = pIStack_64;

        }

        if (unaff_EBX != (IUnknown *)0x0) {

          (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

        }

        pIStack_64 = (IUnknown *)0x0;

        (*pIStack_60->lpVtbl[2].AddRef)(pIStack_60);

        puVar5 = puVar5 + 1;

        unaff_EBX = pIStack_64;

        bstrString = pOStack_40;

        puStack_50 = puVar5;

      } while ((int)puVar5 < iStack_58);

    }

    uStack_4._0_1_ = 4;

    if (unaff_EBX != (IUnknown *)0x0) {

      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

    }

    uStack_4 = CONCAT31(uStack_4._1_3_,2);

    if (pIStack_60 != (IUnknown *)0x0) {

      (*pIStack_60->lpVtbl->Release)();

    }

    SysFreeString(bstrString);

  }

  ExceptionList = pvStack_c;

  return 0;

}
