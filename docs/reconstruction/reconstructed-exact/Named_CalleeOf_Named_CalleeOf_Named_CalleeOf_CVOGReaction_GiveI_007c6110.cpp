// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveI_007c6110
// -----------------------------------------------------------------------------
// Stable ID: aa_007c6110
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x007c6110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~252 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, while×2, for×2, do×1.
//  - Notable callees: block×52, FUN_004231d0×17, _com_issue_error×3, CONCAT31×2, FUN_0041b570×2, FUN_0041c000×2, FUN_00423170×2, wcscpy×2.
//  - Strings: "//tVehicleTemplate/row".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

/* WARNING: Removing unreachable block (ram,0x007c6b57) */

/* WARNING: Removing unreachable block (ram,0x007c67af) */

/* WARNING: Removing unreachable block (ram,0x007c6782) */

/* WARNING: Removing unreachable block (ram,0x007c679a) */

/* WARNING: Removing unreachable block (ram,0x007c67b5) */

/* WARNING: Removing unreachable block (ram,0x007c67d7) */

/* WARNING: Removing unreachable block (ram,0x007c67ec) */

/* WARNING: Removing unreachable block (ram,0x007c67f2) */

/* WARNING: Removing unreachable block (ram,0x007c6814) */

/* WARNING: Removing unreachable block (ram,0x007c6829) */

/* WARNING: Removing unreachable block (ram,0x007c682f) */

/* WARNING: Removing unreachable block (ram,0x007c6850) */

/* WARNING: Removing unreachable block (ram,0x007c6865) */

/* WARNING: Removing unreachable block (ram,0x007c686b) */

/* WARNING: Removing unreachable block (ram,0x007c688d) */

/* WARNING: Removing unreachable block (ram,0x007c68a2) */

/* WARNING: Removing unreachable block (ram,0x007c68a8) */

/* WARNING: Removing unreachable block (ram,0x007c68ca) */

/* WARNING: Removing unreachable block (ram,0x007c68df) */

/* WARNING: Removing unreachable block (ram,0x007c68e5) */

/* WARNING: Removing unreachable block (ram,0x007c6907) */

/* WARNING: Removing unreachable block (ram,0x007c691c) */

/* WARNING: Removing unreachable block (ram,0x007c6922) */

/* WARNING: Removing unreachable block (ram,0x007c6945) */

/* WARNING: Removing unreachable block (ram,0x007c695a) */

/* WARNING: Removing unreachable block (ram,0x007c6960) */

/* WARNING: Removing unreachable block (ram,0x007c6982) */

/* WARNING: Removing unreachable block (ram,0x007c6997) */

/* WARNING: Removing unreachable block (ram,0x007c699d) */

/* WARNING: Removing unreachable block (ram,0x007c69bf) */

/* WARNING: Removing unreachable block (ram,0x007c69d4) */

/* WARNING: Removing unreachable block (ram,0x007c69da) */

/* WARNING: Removing unreachable block (ram,0x007c69fc) */

/* WARNING: Removing unreachable block (ram,0x007c6a11) */

/* WARNING: Removing unreachable block (ram,0x007c6a17) */

/* WARNING: Removing unreachable block (ram,0x007c6a47) */

/* WARNING: Removing unreachable block (ram,0x007c6a5c) */

/* WARNING: Removing unreachable block (ram,0x007c6a62) */

/* WARNING: Removing unreachable block (ram,0x007c6a84) */

/* WARNING: Removing unreachable block (ram,0x007c6a99) */

/* WARNING: Removing unreachable block (ram,0x007c6a9f) */

/* WARNING: Removing unreachable block (ram,0x007c6ac6) */

/* WARNING: Removing unreachable block (ram,0x007c6adb) */

/* WARNING: Removing unreachable block (ram,0x007c6ae1) */

/* WARNING: Removing unreachable block (ram,0x007c6b08) */

/* WARNING: Removing unreachable block (ram,0x007c6b1d) */

/* WARNING: Removing unreachable block (ram,0x007c6b23) */

/* WARNING: Removing unreachable block (ram,0x007c6b42) */

/* WARNING: Removing unreachable block (ram,0x007c6b5d) */

/* WARNING: Removing unreachable block (ram,0x007c6b82) */

/* WARNING: Removing unreachable block (ram,0x007c6b97) */

/* WARNING: Removing unreachable block (ram,0x007c6b9d) */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveI_007c6110(char *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  ULONG UVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *unaff_retaddr;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ uStack_358;

  IUnknown *local_354;

  uint32_t /* width from decompiler */ local_350;

  uint32_t /* width from decompiler */ local_34c;

  BSTR *local_348;

  uint32_t /* width from decompiler */ local_344;

  int local_340;

  uint32_t /* width from decompiler */ local_33c;

  uint32_t /* width from decompiler */ *local_338;

  uint32_t /* width from decompiler */ local_334;

  uint32_t /* width from decompiler */ local_330;

  uint32_t /* width from decompiler */ local_32c;

  int local_328;

  uint8_t *local_324;

  uint32_t /* width from decompiler */ *local_318;

  uint32_t /* width from decompiler */ *local_314;

  uint32_t /* width from decompiler */ local_310;

  BSTR local_30c;

  BSTR local_308;

  uint32_t /* width from decompiler */ local_300;

  uint32_t /* width from decompiler */ local_2f0;

  uint32_t /* width from decompiler */ local_2e4;

  uint32_t /* width from decompiler */ local_2e0;

  uint32_t /* width from decompiler */ local_2c8;

  uint32_t /* width from decompiler */ local_2c4;

  float local_2b8;

  uint8_t local_2b2;

  uint8_t local_2b1;

  wchar_t local_2b0 [101];

  wchar_t local_1e6 [65];

  uint32_t /* width from decompiler */ local_164;

  uint32_t /* width from decompiler */ local_160;

  wchar_t local_15c [66];

  wchar_t local_d8 [102];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae3bc;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  ExceptionList = &local_c;

  *param_2 = 0;

  local_314 = (uint32_t /* width from decompiler */ *)FUN_0041d3f0();

  local_310 = 0;

  local_4 = 0;

  if (DAT_00d1793c == '\0') {

    local_338 = &local_350;

    local_350 = 0;

    local_34c = 0;

    local_348 = (BSTR *)0x0;

    local_344 = 0;

    local_340 = 0;

    local_33c = 0;

    local_330 = 0;

    local_334 = 0;

    local_32c = 0;

    local_328 = 0;

    local_4 = 1;

    iVar2 = FUN_0041a810(local_338,param_1 + 0x28,0);

    local_348 = &local_30c;

    if (((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

        (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

       (((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

         (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

        ((iVar2 = FUN_004231d0(), iVar2 < 0 || (local_340 == 0)))))) {

      FUN_00423170();

      FUN_007a4480();

    }

    else {

      iVar2 = FUN_0041c000();

      uVar1 = 0;

      puVar7 = local_314;

      while (local_314 = puVar7, iVar2 == 0) {

        local_2b2 = uStack_358._2_1_;

        local_2b1 = uStack_358._3_1_;

        local_2b8 = (float)((uint)uStack_358 >> 8 & 0xff) * DAT_00a0f718;

        wcscpy(local_2b0,local_d8);

        wcscpy(local_1e6,local_15c);

        local_164 = local_2e4;

        local_160 = local_2f0;

        local_2c8 = local_2e0;

        local_2c4 = local_300;

        iVar2 = FUN_00420630();

        FUN_00420670();

        puVar7[1] = iVar2;

        **(int **)(iVar2 + 4) = iVar2;

        iVar2 = FUN_0041c000();

        uVar1 = local_310;

        puVar7 = local_314;

      }

      *param_2 = uVar1;

      if (local_340 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      FUN_0041b570();

      puVar4 = *(uint32_t /* width from decompiler */ **)(param_3 + 4);

      for (puVar7 = (uint32_t /* width from decompiler */ *)*local_314; puVar7 != local_314; puVar7 = (uint32_t /* width from decompiler */ *)*puVar7) {

        puVar5 = puVar7 + 2;

        puVar6 = puVar4;

        for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar6 = *puVar5;

          puVar5 = puVar5 + 1;

          puVar6 = puVar6 + 1;

        }

        puVar4 = puVar4 + 0x60;

      }

    }

    local_4 = local_4 & 0xffffff00;

    puVar7 = (uint32_t /* width from decompiler */ *)0x7c664a;

    FUN_0041a3e0();

    FUN_00415e90();

    local_318 = puVar7;

  }

  else {

    local_308 = SysAllocString(L"//tVehicleTemplate/row");

    if (local_308 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_324 = &stack0xfffffc8c;

    local_4._0_1_ = 2;

    FUN_00419ca0();

    local_4._0_1_ = 3;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 2;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,5);

    if (local_354 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_324 = (uint8_t *)0x0;

    UVar3 = (*local_354->lpVtbl[2].Release)(local_354);

    if ((int)UVar3 < 0) {

      _com_issue_errorex(UVar3,local_354,(_GUID *)&DAT_00a86118);

    }

    iVar2 = local_328;

    *unaff_retaddr = local_328;

    FUN_0041b570();

    local_324 = (uint8_t *)0x0;

    piVar8 = unaff_EBX;

    if (0 < iVar2) {

      do {

        if (uStack_358 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        if (piVar8 != (int *)0x0) {

          (**(code **)(*piVar8 + 8))();

        }

        (**(code **)(*uStack_358 + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_324 = (uint8_t *)((int)local_324 + 1);

        piVar8 = (int *)0x0;

      } while ((int)local_324 < local_328);

    }

    puStack_8._0_1_ = 4;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    if (uStack_358 != (int *)0x0) {

      (**(code **)(*uStack_358 + 8))();

    }

    SysFreeString(local_30c);

    puVar7 = (uint32_t /* width from decompiler */ *)*local_318;

    *local_318 = local_318;

    local_318[1] = local_318;

    if (puVar7 != local_318) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar7);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_318);

}
