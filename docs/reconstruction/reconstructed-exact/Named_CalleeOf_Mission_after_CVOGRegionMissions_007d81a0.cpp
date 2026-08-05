// =============================================================================
// Named_CalleeOf_Mission_after_CVOGRegionMissions_007d81a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007d81a0
// Callee of Mission_after_CVOGRegionMissions
// Address:   0x007d81a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~370 non-empty decompiler lines.
//  - Control keywords: if×43, return×2, for×1.
//  - Notable callees: FUN_004231d0×28, FUN_00423670×28, FUN_007b8b90×28, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_00423170×2, FUN_004048e0.
//  - Strings: "//tConfigCosts/row[1]".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_after_CVOGRegionMissions
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Mission_after_CVOGRegionMissions_007d81a0(char *param_1,uint32_t /* width from decompiler */ *param_2)



{

  IUnknown *pIVar1;

  uint32_t /* width from decompiler */ uVar2;

  BSTR bstrString;

  ULONG UVar3;

  int iVar4;

  int *unaff_EBX;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  bool bVar6;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ *local_a4;

  uint32_t /* width from decompiler */ local_a0;

  int local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ *local_94;

  uint32_t /* width from decompiler */ local_90;

  IUnknown *local_8c;

  uint32_t /* width from decompiler */ local_88;

  IUnknown *local_84;

  IUnknown *local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  BSTR local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aeae8;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    uVar2 = 0x80004004;

  }

  else {

    bVar6 = DAT_00d1793c == '\0';

    puVar5 = param_2;

    ExceptionList = &local_c;

    for (iVar4 = 0x1c; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    if (bVar6) {

      local_94 = &local_ac;

      local_ac = 0;

      local_a8 = 0;

      local_a4 = (uint32_t /* width from decompiler */ *)0x0;

      local_a0 = 0;

      local_9c = 0;

      local_98 = 0;

      local_8c = (IUnknown *)0x0;

      local_90 = 0;

      local_88 = 0;

      local_84 = (IUnknown *)0x0;

      local_4 = 0;

      iVar4 = FUN_0041a810(local_94,param_1 + 0x28);

      local_a4 = &local_78;

      if ((((((((iVar4 < 0) || (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

              (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

             (((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

              ((iVar4 = FUN_004231d0(), iVar4 < 0 ||

               ((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)))))))) ||

            (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

           (((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

            (iVar4 = FUN_004231d0(), iVar4 < 0)))) ||

          (((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

           ((iVar4 = FUN_004231d0(), iVar4 < 0 ||

            ((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)))))))) ||

         (((iVar4 = FUN_004231d0(), iVar4 < 0 ||

           (((((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

              (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

             ((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)))) ||

            ((iVar4 = FUN_004231d0(), iVar4 < 0 ||

             ((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)))))))) ||

          ((iVar4 = FUN_004231d0(), iVar4 < 0 ||

           (((iVar4 = FUN_004231d0(), iVar4 < 0 || (iVar4 = FUN_004231d0(), iVar4 < 0)) ||

            (local_9c == 0)))))))) {

        FUN_00423170();

        FUN_007a4480();

        local_4 = 0xffffffff;

        FUN_0041a3e0();

      }

      else {

        iVar4 = FUN_0041a9b0();

        if (iVar4 == 0) {

          *param_2 = local_78;

          param_2[1] = local_4c;

          param_2[2] = local_20;

          param_2[3] = local_18;

          param_2[5] = local_10;

          param_2[4] = local_3c;

          param_2[6] = local_64;

          param_2[0xd] = local_24;

          param_2[0x14] = local_5c;

          param_2[0x15] = local_34;

          param_2[0x16] = local_54;

          param_2[0x17] = local_14;

          param_2[0x18] = local_70;

          param_2[0x1a] = local_2c;

          param_2[0x1b] = local_44;

          param_2[0x19] = local_1c;

          param_2[7] = local_6c;

          param_2[8] = local_68;

          param_2[9] = local_60;

          param_2[10] = local_58;

          param_2[0xb] = local_50;

          param_2[0xc] = local_48;

          param_2[0xe] = local_40;

          param_2[0xf] = local_38;

          param_2[0x10] = local_30;

          param_2[0x11] = local_28;

          param_2[0x12] = local_b0;

          param_2[0x13] = local_74;

        }

        if (local_9c != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        local_4 = 0xffffffff;

        FUN_0041a3e0();

      }

    }

    else {

      bstrString = SysAllocString(L"//tConfigCosts/row[1]");

      local_74 = bstrString;

      if (bstrString == (BSTR)0x0) {

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

      if (local_80 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      pIVar1 = local_80;

      local_7c = 0;

      UVar3 = (*local_80->lpVtbl[2].Release)(local_80);

      if ((int)UVar3 < 0) {

        _com_issue_errorex(UVar3,pIVar1,(_GUID *)&DAT_00a86118);

      }

      if (0 < (int)local_80) {

        if (local_84 == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        (*local_84->lpVtbl[2].AddRef)(local_84);

        if (unaff_ESI != (int *)0x0) {

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          *param_2 = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[1] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[2] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[3] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[5] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[4] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[6] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0xd] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x14] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x15] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x16] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x17] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x18] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x1a] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x1b] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x19] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[7] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[8] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[9] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[10] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0xb] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0xc] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0xe] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0xf] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x10] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x11] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x12] = in_XMM0_Da;

          FUN_00423670();

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8b90();

          param_2[0x13] = in_XMM0_Da;

        }

      }

      local_10._0_1_ = 3;

      if (unaff_ESI != (int *)0x0) {

        (**(code **)(*unaff_ESI + 8))();

      }

      local_10 = CONCAT31(local_10._1_3_,1);

      if (local_8c != (IUnknown *)0x0) {

        (*local_8c->lpVtbl->Release)(local_8c);

      }

      SysFreeString(bstrString);

    }

    uVar2 = 0;

  }

  ExceptionList = local_18;

  return uVar2;

}
