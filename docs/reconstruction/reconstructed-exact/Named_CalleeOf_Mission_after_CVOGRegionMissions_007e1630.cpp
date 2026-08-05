// =============================================================================
// Named_CalleeOf_Mission_after_CVOGRegionMissions_007e1630
// -----------------------------------------------------------------------------
// Stable ID: aa_007e1630
// Callee of Mission_after_CVOGRegionMissions
// Address:   0x007e1630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_after_CVOGRegionMissions: mission/objective helper. Evidence string: "IDCloneBase". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "IDCloneBase"
//   - "intType"
//   - "bitIsAvailable"
//   - "bitIsGeneratable"
//   - "strUniqueName"
//   - "strShortDesc"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~269 non-empty decompiler lines.
//  - Control keywords: if×36, goto×11, return×3, do×2, while×2.
//  - Notable callees: FUN_004231d0×7, SysAllocString×7, CONCAT31×6, FUN_0041a3e0×5, FUN_00423170×4, FUN_007a4480×3, _com_issue_error×3, FUN_0041a810×2.
//  - Strings: "//vCloneBase_NameList/row"; "IDCloneBase"; "intType"; "bitIsAvailable".
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x007e1777) */

/* WARNING: Removing unreachable block (ram,0x007e17ec) */

/* WARNING: Exceeded maximum restarts with more pending */



uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Mission_after_CVOGRegionMissions_007e1630(char *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  ULONG UVar3;

  int iVar4;

  BSTR pOVar5;

  uint32_t /* width from decompiler */ uVar6;

  IUnknownVtbl *pIVar7;

  int *unaff_EBX;

  int *unaff_ESI;

  IUnknown *This;

  int *piVar8;

  IUnknown *pIVar9;

  int unaff_retaddr;

  int local_168;

  IUnknown *local_164;

  uint8_t *local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  BSTR *local_154;

  uint32_t /* width from decompiler */ *local_150;

  int local_14c;

  int local_148;

  uint32_t /* width from decompiler */ *local_144;

  uint32_t /* width from decompiler */ *local_140;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  BSTR local_130;

  BSTR local_12c;

  int local_128;

  char *local_124;

  int local_120;

  int local_11c;

  wchar_t local_118 [66];

  wchar_t awStack_94 [66];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af039;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    ExceptionList = pvStack_10;

    return 0x80004004;

  }

  ExceptionList = &local_c;

  local_124 = param_1;

  local_12c = SysAllocString(L"//vCloneBase_NameList/row");

  if (local_12c == (BSTR)0x0) {

LAB_007e167a:

                    /* WARNING: Subroutine does not return */

    FUN_004048e0();

  }

  local_160 = (uint8_t *)0x0;

  local_4._0_1_ = 2;

  local_4._1_3_ = 0;

  if (DAT_00d1793c == '\0') {

    local_140 = &local_158;

    local_158 = 0;

    local_154 = (BSTR *)0x0;

    local_150 = (uint32_t /* width from decompiler */ *)0x0;

    local_14c = 0;

    local_148 = 0;

    local_144 = (uint32_t /* width from decompiler */ *)0x0;

    local_138 = 0;

    local_13c = 0;

    local_134 = 0;

    local_130 = (BSTR)0x0;

    local_4 = 3;

    iVar1 = FUN_0041a810(local_140);

    local_150 = &local_15c;

    if (((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (local_148 == 0)) {

      FUN_00423170();

      FUN_007a4480();

      local_4._0_1_ = 2;

      FUN_0041a3e0();

      local_4 = CONCAT31(local_4._1_3_,1);

      goto LAB_007e1b52;

    }

    iVar1 = FUN_0041a9b0();

    if (local_148 != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    if (iVar1 != 0) {

      FUN_007a4480();

      local_4._0_1_ = 2;

      FUN_0041a3e0();

      local_4 = CONCAT31(local_4._1_3_,1);

      goto LAB_007e1b52;

    }

    local_4 = CONCAT31(local_4._1_3_,2);

    FUN_0041a3e0();

  }

  else {

    FUN_00419ca0();

    local_4._0_1_ = 4;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,2);

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    pIVar9 = (IUnknown *)*puVar2;

    This = (IUnknown *)0x0;

    if (pIVar9 != (IUnknown *)0x0) {

      (*pIVar9->lpVtbl->AddRef)(pIVar9);

      This = pIVar9;

    }

    if (local_164 != (IUnknown *)0x0) {

      (*local_164->lpVtbl->Release)();

    }

    if (This == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_164 = (IUnknown *)0x0;

    UVar3 = (*This->lpVtbl[2].Release)(This);

    local_160 = &stack0xfffffe80;

    if ((int)UVar3 < 0) {

      _com_issue_errorex(UVar3,This,(_GUID *)&DAT_00a86118);

      local_160 = &stack0xfffffe80;

    }

  }

  FUN_0041a9f0();

  iVar1 = *(int *)(unaff_retaddr + 4);

  pIVar9 = local_164;

  if (DAT_00d1793c == '\0') {

    local_144 = &local_15c;

    local_15c = 0;

    local_158 = 0;

    local_154 = (BSTR *)0x0;

    local_150 = (uint32_t /* width from decompiler */ *)0x0;

    local_14c = 0;

    local_148 = 0;

    local_13c = 0;

    local_140 = (uint32_t /* width from decompiler */ *)0x0;

    local_138 = 0;

    local_134 = 0;

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,5);

    iVar4 = FUN_0041a810(local_144,local_128 + 0x28);

    local_154 = &local_12c;

    if (((((-1 < iVar4) && (iVar4 = FUN_004231d0(), -1 < iVar4)) &&

         ((iVar4 = FUN_004231d0(), -1 < iVar4 &&

          ((iVar4 = FUN_004231d0(), -1 < iVar4 && (iVar4 = FUN_004231d0(), -1 < iVar4)))))) &&

        (iVar4 = FUN_004231d0(), -1 < iVar4)) &&

       ((iVar4 = FUN_004231d0(), -1 < iVar4 && (local_14c != 0)))) {

      iVar4 = 0;

      if (0 < (int)local_160) {

        piVar8 = (int *)(iVar1 + 0x8c);

        do {

          iVar1 = FUN_0041c000();

          if (iVar1 != 0) break;

          piVar8[-0x23] = (int)local_12c;

          piVar8[-0x22] = local_11c;

          *piVar8 = iVar4;

          *(bool *)(piVar8 + 1) = local_124 != (char *)0x0;

          *(bool *)((int)piVar8 + 5) = local_120 != 0;

          wcscpy((wchar_t *)(piVar8 + -0x21),local_118);

          wcscpy((wchar_t *)((int)piVar8 + 6),awStack_94);

          iVar4 = iVar4 + 1;

          piVar8 = piVar8 + 0x45;

        } while (iVar4 < (int)local_160);

      }

      if (local_14c != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

      FUN_0041a3e0();

      goto LAB_007e1b2f;

    }

    FUN_00423170();

    FUN_007a4480();

    puStack_8._0_1_ = 2;

    FUN_0041a3e0();

    puStack_8._0_1_ = 1;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)((uint)puStack_8._1_3_ << 8);

    if (local_164 == (IUnknown *)0x0) goto LAB_007e1b52;

    pIVar7 = local_164->lpVtbl;

  }

  else {

    local_168 = 0;

    if (0 < (int)local_160) {

      iVar1 = iVar1 + 0x90;

      piVar8 = unaff_EBX;

      do {

        if (local_164 == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

          unaff_EBX = piVar8;

        }

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        piVar8 = (int *)0x0;

        (*local_164->lpVtbl[2].AddRef)(local_164);

        pIVar9 = local_164;

        if (unaff_ESI != (int *)0x0) {

          pOVar5 = SysAllocString(L"IDCloneBase");

          if (pOVar5 == (BSTR)0x0) goto LAB_007e167a;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))();

          }

          uVar6 = FUN_007b8a60();

          *(uint32_t /* width from decompiler */ *)(iVar1 + -0x90) = uVar6;

          pOVar5 = SysAllocString(L"intType");

          if (pOVar5 == (BSTR)0x0) goto LAB_007e167a;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))();

          }

          uVar6 = FUN_007b8a60();

          *(uint32_t /* width from decompiler */ *)(iVar1 + -0x8c) = uVar6;

          pOVar5 = SysAllocString(L"bitIsAvailable");

          if (pOVar5 == (BSTR)0x0) goto LAB_007e167a;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))();

          }

          iVar4 = FUN_007b8910();

          *(bool *)iVar1 = iVar4 != 0;

          pOVar5 = SysAllocString(L"bitIsGeneratable");

          if (pOVar5 == (BSTR)0x0) goto LAB_007e167a;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))();

          }

          iVar4 = FUN_007b8910();

          *(bool *)(iVar1 + 1) = iVar4 != 0;

          pOVar5 = SysAllocString(L"strUniqueName");

          if (pOVar5 == (BSTR)0x0) goto LAB_007e167a;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8de0();

          pOVar5 = SysAllocString(L"strShortDesc");

          if (pOVar5 == (BSTR)0x0) goto LAB_007e167a;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

          }

          FUN_007b8de0();

          pIVar9 = (IUnknown *)0x0;

        }

        local_168 = local_168 + 1;

        iVar1 = iVar1 + 0x114;

        unaff_EBX = unaff_ESI;

      } while (local_168 < (int)local_160);

    }

LAB_007e1b2f:

    puStack_8._0_1_ = 1;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)((uint)puStack_8._1_3_ << 8);

    if (pIVar9 == (IUnknown *)0x0) goto LAB_007e1b52;

    pIVar7 = pIVar9->lpVtbl;

  }

  (*pIVar7->Release)(pIVar9);

LAB_007e1b52:

  SysFreeString(local_130);

  ExceptionList = pvStack_10;

  return 0;

}
