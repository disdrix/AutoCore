// READABILITY (auto CF):
//  - Body size: ~823 non-empty decompiler lines.
//  - Control keywords: if×120, goto×63, return×8, while×4, do×2, for×1.
//  - Notable callees: block×82, SysAllocString×64, FUN_004231d0×46, FUN_007b8a60×44, FUN_007b87c0×8, FUN_007b8b90×7, _com_issue_error×7, CoTaskMemAlloc×6.
//  - Strings: "//vQuests/row"; "//vQuestObjectives/row"; "IDQuest"; "IDQuestObjective".
//  - Return sites: 8.

// =============================================================================
// Mission_DbLoadQuestsAndObjectives
// -----------------------------------------------------------------------------
// Purpose:  ADO/DB bulk-load of quest definitions and their child objectives. Walks `//vQuests/row` then nested `//vQuestObjectives/row`, populating IDQuest, IDQuestObjective, strObjectiveName, map/layer, XP/credits/attrib/skill-point reward columns into mission runtime tables.
//
// Address:  0x007c0350  (autoassault.exe, image base 0x400000)
// Stable:   aa_007c0350
// System:   missions-progression
//
// Evidence strings (from raw decompile):
//   - "//vQuests/row"
//   - "//vQuestObjectives/row"
//   - "IDQuest"
//   - "IDQuestObjective"
//   - "strObjectiveName"
//   - "strMapName"
//   - "intXP"
//   - "intCredits"
//   - "intAttribPoints"
//   - "intSkillPoints"
//   - "tinSequence"
//   - "IDContinentObject"
//
// Notable callees:
//   - FUN_00439770 (ADO open/query family)
//   - FUN_0041a810 / FUN_004231d0 (field get)
//   - FUN_007b8a60 / FUN_007b8de0 / FUN_007b87c0 (mission table inserts)
//   - SysAllocString
//   - FUN_007a4480
//
// Notes:    Primary mission definition ingest. Dual-review as mission data manager.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

/* WARNING: Removing unreachable block (ram,0x007c1888) */

/* WARNING: Removing unreachable block (ram,0x007c1f33) */

/* WARNING: Removing unreachable block (ram,0x007c1bcd) */

/* WARNING: Removing unreachable block (ram,0x007c18c8) */

/* WARNING: Removing unreachable block (ram,0x007c1807) */

/* WARNING: Removing unreachable block (ram,0x007c1786) */

/* WARNING: Removing unreachable block (ram,0x007c1706) */

/* WARNING: Removing unreachable block (ram,0x007c1746) */

/* WARNING: Removing unreachable block (ram,0x007c1b4d) */

/* WARNING: Removing unreachable block (ram,0x007c1f73) */

/* WARNING: Removing unreachable block (ram,0x007c17c6) */

/* WARNING: Removing unreachable block (ram,0x007c1eb3) */

/* WARNING: Removing unreachable block (ram,0x007c1848) */

/* WARNING: Removing unreachable block (ram,0x007c0f3f) */

/* WARNING: Removing unreachable block (ram,0x007c0f54) */

/* WARNING: Removing unreachable block (ram,0x007c0f56) */

/* WARNING: Removing unreachable block (ram,0x007c0f6d) */

/* WARNING: Removing unreachable block (ram,0x007c0f6f) */

/* WARNING: Removing unreachable block (ram,0x007c0fb4) */

/* WARNING: Removing unreachable block (ram,0x007c0fda) */

/* WARNING: Removing unreachable block (ram,0x007c1002) */

/* WARNING: Removing unreachable block (ram,0x007c102a) */

/* WARNING: Removing unreachable block (ram,0x007c1058) */

/* WARNING: Removing unreachable block (ram,0x007c1086) */

/* WARNING: Removing unreachable block (ram,0x007c10b1) */

/* WARNING: Removing unreachable block (ram,0x007c10dc) */

/* WARNING: Removing unreachable block (ram,0x007c1104) */

/* WARNING: Removing unreachable block (ram,0x007c112f) */

/* WARNING: Removing unreachable block (ram,0x007c115a) */

/* WARNING: Removing unreachable block (ram,0x007c1185) */

/* WARNING: Removing unreachable block (ram,0x007c11b0) */

/* WARNING: Removing unreachable block (ram,0x007c11db) */

/* WARNING: Removing unreachable block (ram,0x007c1203) */

/* WARNING: Removing unreachable block (ram,0x007c122b) */

/* WARNING: Removing unreachable block (ram,0x007c1252) */

/* WARNING: Removing unreachable block (ram,0x007c1279) */

/* WARNING: Removing unreachable block (ram,0x007c129d) */

/* WARNING: Removing unreachable block (ram,0x007c12a7) */

/* WARNING: Removing unreachable block (ram,0x007c12ac) */

/* WARNING: Removing unreachable block (ram,0x007c12e9) */

/* WARNING: Removing unreachable block (ram,0x007c1301) */

/* WARNING: Removing unreachable block (ram,0x007c1307) */

/* WARNING: Removing unreachable block (ram,0x007c14ea) */

/* WARNING: Removing unreachable block (ram,0x007c1318) */

/* WARNING: Removing unreachable block (ram,0x007c1414) */

/* WARNING: Removing unreachable block (ram,0x007c142e) */

/* WARNING: Removing unreachable block (ram,0x007c1446) */

/* WARNING: Removing unreachable block (ram,0x007c1480) */

/* WARNING: Removing unreachable block (ram,0x007c1482) */

/* WARNING: Removing unreachable block (ram,0x007c14a0) */

/* WARNING: Removing unreachable block (ram,0x007c14c4) */

/* WARNING: Removing unreachable block (ram,0x007c2378) */

/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffcf4 : 0x007c21e6 */

/* WARNING: Removing unreachable block (ram,0x007c1ef3) */

/* WARNING: Removing unreachable block (ram,0x007c190d) */

/* WARNING: Removing unreachable block (ram,0x007c194d) */

/* WARNING: Removing unreachable block (ram,0x007c2033) */

/* WARNING: Removing unreachable block (ram,0x007c198d) */

/* WARNING: Removing unreachable block (ram,0x007c19cd) */

/* WARNING: Removing unreachable block (ram,0x007c2109) */

/* WARNING: Removing unreachable block (ram,0x007c1a0d) */

/* WARNING: Removing unreachable block (ram,0x007c1a4d) */

/* WARNING: Removing unreachable block (ram,0x007c1a8d) */

/* WARNING: Removing unreachable block (ram,0x007c1acd) */

/* WARNING: Removing unreachable block (ram,0x007c1b0d) */

/* WARNING: Removing unreachable block (ram,0x007c1b8d) */

/* WARNING: Removing unreachable block (ram,0x007c1c0d) */

/* WARNING: Removing unreachable block (ram,0x007c1c4f) */

/* WARNING: Removing unreachable block (ram,0x007c1c91) */

/* WARNING: Removing unreachable block (ram,0x007c1cd3) */

/* WARNING: Removing unreachable block (ram,0x007c1d15) */

/* WARNING: Removing unreachable block (ram,0x007c1d5a) */

/* WARNING: Removing unreachable block (ram,0x007c1d9f) */

/* WARNING: Removing unreachable block (ram,0x007c1de4) */

/* WARNING: Removing unreachable block (ram,0x007c1e29) */

/* WARNING: Removing unreachable block (ram,0x007c1e6e) */

/* WARNING: Removing unreachable block (ram,0x007c1fb3) */

/* WARNING: Removing unreachable block (ram,0x007c1ff3) */

/* WARNING: Removing unreachable block (ram,0x007c2073) */

/* WARNING: Removing unreachable block (ram,0x007c20ba) */

/* WARNING: Removing unreachable block (ram,0x007c214a) */

/* WARNING: Removing unreachable block (ram,0x007c218a) */

/* WARNING: Removing unreachable block (ram,0x007c21d0) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

/* WARNING: Exceeded maximum restarts with more pending */



uint32_t /* width from decompiler */ __thiscall Mission_DbLoadQuestsAndObjectives(char *param_1,int *param_2)



{

  int *piVar1;

  IUnknown *pIVar2;

  IUnknown *pIVar3;

  uint8_t uVar4;

  byte bVar5;

  uint16_t uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  LPVOID pvVar10;

  uint32_t /* width from decompiler */ *puVar11;

  ULONG UVar12;

  int iVar13;

  BSTR pOVar14;

  BSTR pOVar15;

  uint uVar16;

  int *unaff_EBX;

  int *unaff_EBP;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  int *unaff_retaddr;

  int in_stack_fffffcf4;

  int *local_2f0;

  IUnknown *local_2ec;

  IUnknown *local_2e8;

  int *local_2e4;

  int *local_2e0;

  uint uStack_2d4;

  uint32_t /* width from decompiler */ local_2cc;

  uint32_t /* width from decompiler */ local_2c8;

  BSTR *local_2c4;

  uint32_t /* width from decompiler */ local_2c0;

  int local_2bc;

  uint32_t /* width from decompiler */ local_2b8;

  uint32_t /* width from decompiler */ *local_2b4;

  uint32_t /* width from decompiler */ local_2b0;

  uint32_t /* width from decompiler */ local_2ac;

  uint32_t /* width from decompiler */ local_2a8;

  int local_2a4;

  BSTR local_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  BSTR local_298;

  BSTR local_294 [12];

  uint16_t local_264;

  uint16_t local_260;

  short local_25c;

  uint16_t local_258;

  short local_254;

  uint8_t *local_250;

  uint16_t local_248;

  uint16_t local_244;

  uint16_t local_240;

  uint16_t local_23c;

  uint32_t /* width from decompiler */ local_238;

  uint32_t /* width from decompiler */ local_234;

  uint32_t /* width from decompiler */ local_230;

  uint32_t /* width from decompiler */ local_22c;

  uint32_t /* width from decompiler */ local_228;

  uint32_t /* width from decompiler */ local_224;

  uint32_t /* width from decompiler */ local_220;

  uint32_t /* width from decompiler */ local_21c;

  uint32_t /* width from decompiler */ local_218;

  uint32_t /* width from decompiler */ local_214;

  uint32_t /* width from decompiler */ local_210;

  uint32_t /* width from decompiler */ local_20c;

  uint32_t /* width from decompiler */ local_204;

  uint32_t /* width from decompiler */ local_1fc;

  uint32_t /* width from decompiler */ local_1f4;

  uint32_t /* width from decompiler */ local_1ec;

  uint32_t /* width from decompiler */ local_1e4;

  uint32_t /* width from decompiler */ local_1dc;

  uint32_t /* width from decompiler */ local_1d4;

  uint32_t /* width from decompiler */ local_1cc;

  uint32_t /* width from decompiler */ local_1c8;

  uint32_t /* width from decompiler */ local_1c4;

  uint32_t /* width from decompiler */ local_1c0;

  uint32_t /* width from decompiler */ local_1bc;

  uint32_t /* width from decompiler */ local_1b8;

  uint32_t /* width from decompiler */ local_1b4;

  uint32_t /* width from decompiler */ local_1b0;

  uint32_t /* width from decompiler */ local_1ac;

  uint32_t /* width from decompiler */ local_1a8;

  uint32_t /* width from decompiler */ local_1a4;

  uint32_t /* width from decompiler */ local_1a0;

  uint32_t /* width from decompiler */ local_19c;

  wchar_t local_90 [66];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae218;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    uVar7 = 0x80004004;

  }

  else {

    local_234 = 0xffffffff;

    local_238 = 0xffffffff;

    ExceptionList = &local_c;

    iVar8 = FUN_00439770();

    *(uint8_t *)(iVar8 + 0x15) = 1;

    *(int *)(iVar8 + 4) = iVar8;

    *(int *)iVar8 = iVar8;

    *(int *)(iVar8 + 8) = iVar8;

    local_4 = 0;

    if (DAT_00d1793c == '\0') {

      local_2b4 = &local_2cc;

      local_2cc = 0;

      local_2c8 = 0;

      local_2c4 = (BSTR *)0x0;

      local_2c0 = 0;

      local_2bc = 0;

      local_2b8 = 0;

      local_2ac = 0;

      local_2b0 = 0;

      local_2a8 = 0;

      local_2a4 = 0;

      local_4 = 1;

      iVar8 = FUN_0041a810(local_2b4,param_1 + 0x28,0);

      local_2c4 = local_294;

      if (((((iVar8 < 0) || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

           (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

          (((((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

             ((iVar8 = FUN_004231d0(), iVar8 < 0 ||

              ((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)))))) ||

            (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

           (((((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

              (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

             ((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)))) ||

            ((iVar8 = FUN_004231d0(), iVar8 < 0 ||

             ((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)))))))))) ||

         ((((iVar8 = FUN_004231d0(), iVar8 < 0 ||

            (((((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

               (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

              ((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)))) ||

             (iVar8 = FUN_004231d0(), iVar8 < 0)))) ||

           (((((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

              ((iVar8 = FUN_004231d0(), iVar8 < 0 ||

               (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

                (iVar8 = FUN_004231d0(), iVar8 < 0)))))) ||

             (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

              (iVar8 = FUN_004231d0(), iVar8 < 0)))) ||

            (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

             ((iVar8 = FUN_004231d0(), iVar8 < 0 ||

              (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

               (iVar8 = FUN_004231d0(), iVar8 < 0)))))))))) ||

          (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

           ((iVar8 = FUN_004231d0(), iVar8 < 0 ||

            (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

             ((iVar8 = FUN_004231d0(), iVar8 < 0 ||

              (((iVar8 = FUN_004231d0(), iVar8 < 0 || (iVar8 = FUN_004231d0(), iVar8 < 0)) ||

               (local_2bc == 0)))))))))))))) {

        FUN_00423170();

        FUN_007a4480();

        local_4 = local_4 & 0xffffff00;

        FUN_0041a3e0();

        local_4 = 0xffffffff;

        FUN_0041a480();

      }

      else {

        iVar8 = FUN_0041c000();

        while (iVar8 == 0) {

          puVar9 = CoTaskMemAlloc(0x138);

          if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

            local_4 = local_4 & 0xffffff00;

            FUN_0041a3e0();

            local_4 = 0xffffffff;

            FUN_0041a480();

            ExceptionList = local_c;

            return 0x8007000e;

          }

          *puVar9 = local_294[0];

          wcscpy((wchar_t *)(puVar9 + 1),local_90);

          *(uint8_t *)((int)puVar9 + 0x86) = uStack_29c._3_1_;

          puVar9[0x22] = local_214;

          puVar9[0x23] = local_1c8;

          *(uint16_t *)(puVar9 + 0x24) = local_244;

          *(uint16_t *)((int)puVar9 + 0x92) = local_23c;

          puVar9[0x25] = local_1c0;

          puVar9[0x26] = local_1b8;

          *(uint16_t *)(puVar9 + 0x2b) = local_240;

          puVar9[0x27] = local_1b0;

          puVar9[0x28] = local_1a8;

          puVar9[0x29] = local_1dc;

          puVar9[0x2a] = local_224;

          puVar9[0x2c] = local_1b4;

          puVar9[0x2d] = local_21c;

          puVar9[0x2e] = local_1d4;

          puVar9[0x2f] = local_230;

          puVar9[0x30] = local_19c;

          puVar9[0x31] = local_20c;

          puVar9[0x32] = local_1cc;

          puVar9[0x33] = local_204;

          puVar9[0x34] = local_1ac;

          puVar9[0x35] = local_1fc;

          puVar9[0x36] = local_1c4;

          puVar9[0x37] = local_1f4;

          *(uint16_t *)(puVar9 + 0x38) = local_260;

          *(uint16_t *)((int)puVar9 + 0xe2) = local_258;

          *(uint16_t *)(puVar9 + 0x39) = local_248;

          *(uint16_t *)((int)puVar9 + 0xe6) = local_250._0_2_;

          *(ushort *)(puVar9 + 0x3e) = (ushort)(local_25c == -1);

          *(ushort *)((int)puVar9 + 0xfa) = (ushort)(local_254 == -1);

          puVar9[0x3f] = local_1a0;

          puVar9[0x40] = local_1ec;

          puVar9[0x41] = local_1bc;

          puVar9[0x42] = local_1e4;

          puVar9[0x43] = local_1a4;

          puVar9[0x44] = local_22c;

          puVar9[0x45] = local_228;

          puVar9[0x46] = local_220;

          *(uint8_t *)(puVar9 + 0x4c) = 0;

          pvVar10 = CoTaskMemAlloc((uStack_2d4 >> 0x18) * 4);

          puVar9[0x4d] = pvVar10;

          *(uint16_t *)(puVar9 + 0x47) = local_264;

          puVar9[0x3a] = 0;

          puVar9[0x3b] = 0;

          puVar9[0x3c] = 0;

          puVar9[0x3d] = 0;

          puVar9[0x4a] = local_234;

          puVar9[0x4b] = local_238;

          puVar9[0x48] = local_218;

          puVar9[0x49] = local_210;

          if (pvVar10 == (LPVOID)0x0) {

            local_4 = local_4 & 0xffffff00;

            FUN_0041a3e0();

            local_4 = 0xffffffff;

            FUN_0041a480();

            ExceptionList = local_c;

            return 0x8007000e;

          }

          puVar11 = (uint32_t /* width from decompiler */ *)FUN_0041b440();

          *puVar11 = puVar9;

          iVar8 = FUN_0041c000();

        }

        FUN_0041a990();

        FUN_00423170();

        *param_2 = 0;

        local_4 = local_4 & 0xffffff00;

        FUN_0041a3e0();

        local_4 = 0xffffffff;

        FUN_0041a480();

      }

      uVar7 = 0;

    }

    else {

      local_298 = SysAllocString(L"//vQuests/row");

      if (local_298 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      local_2ec = (IUnknown *)&stack0xfffffcfc;

      local_4._0_1_ = 3;

      FUN_00419ca0();

      local_4._0_1_ = 4;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_4._0_1_ = 3;

      FUN_00419ed0();

      local_2f0 = (int *)0x0;

      local_4 = CONCAT31(local_4._1_3_,6);

      if (local_2e8 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      UVar12 = (*local_2e8->lpVtbl[2].Release)(local_2e8);

      if ((int)UVar12 < 0) {

        _com_issue_errorex(UVar12,local_2e8,(_GUID *)&DAT_00a86118);

      }

      pIVar2 = (IUnknown *)&stack0xfffffcfc;

      if ((int)uStack_2d4 < 1) {

LAB_007c22db:

        local_2ec = pIVar2;

        pOVar14 = SysAllocString(L"//vQuestObjectives/row");

        if (pOVar14 == (BSTR)0x0) {

LAB_007c22ea:

                    /* WARNING: Subroutine does not return */

          FUN_004048e0();

        }

        local_250 = &stack0xfffffcf8;

        puStack_8._0_1_ = 7;

        FUN_00419ca0();

        puStack_8._0_1_ = 8;

        if (DAT_00d1e56c == 0) {

          _com_issue_error(-0x7fffbffd);

        }

        puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,7);

        puVar9 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

        pIVar2 = (IUnknown *)*puVar9;

        pIVar3 = local_2ec;

        if (local_2ec != pIVar2) {

          if (pIVar2 != (IUnknown *)0x0) {

            (*pIVar2->lpVtbl->AddRef)(pIVar2);

          }

          pIVar3 = pIVar2;

          if (local_2ec != (IUnknown *)0x0) {

            (*local_2ec->lpVtbl->Release)(local_2ec);

          }

        }

        local_2ec = pIVar3;

        local_2a4 = 0;

        do {

          iVar8 = local_2a4;

          if (local_2ec == (IUnknown *)0x0) {

            _com_issue_error(-0x7fffbffd);

          }

          UVar12 = (*local_2ec->lpVtbl[2].Release)(local_2ec);

          if ((int)UVar12 < 0) {

            _com_issue_errorex(UVar12,local_2ec,(_GUID *)&DAT_00a86118);

          }

          if (-1 < iVar8) {

            SysFreeString((BSTR)local_2ec);

            local_c._0_1_ = 5;

            if (unaff_EBP != (int *)0x0) {

              (**(code **)(*unaff_EBP + 8))();

            }

            local_c = (void *)CONCAT31(local_c._1_3_,3);

            if (local_2f0 != (int *)0x0) {

              (**(code **)(*local_2f0 + 8))();

            }

            SysFreeString(local_2a0);

            local_c = (void *)0xffffffff;

            FUN_00421110(&stack0xfffffd0c);

                    /* WARNING: Subroutine does not return */

            operator_delete(local_2e4);

          }

          if (local_2f0 == (int *)0x0) {

            _com_issue_error(-0x7fffbffd);

          }

          if (unaff_EBP != (int *)0x0) {

            (**(code **)(*unaff_EBP + 8))();

          }

          unaff_EBP = (int *)0x0;

          (**(code **)(*local_2f0 + 0x1c))(local_2f0);

          if (unaff_EBX != (int *)0x0) {

            puVar9 = CoTaskMemAlloc(0x140);

            if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

              SysFreeString(pOVar14);

              puStack_8._0_1_ = 5;

              if (unaff_EBX != (int *)0x0) {

                (**(code **)(*unaff_EBX + 8))();

              }

              puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,3);

              if (local_2ec != (IUnknown *)0x0) {

                (*local_2ec->lpVtbl->Release)();

              }

              SysFreeString(uStack_29c);

              puStack_8 = (uint8_t *)0xffffffff;

              FUN_00421110();

                    /* WARNING: Subroutine does not return */

              operator_delete(local_2e0);

            }

            pOVar15 = SysAllocString(L"IDQuest");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            *puVar9 = uVar7;

            pOVar15 = SysAllocString(L"IDQuestObjective");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[1] = uVar7;

            pOVar15 = SysAllocString(L"intWorldPosition");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[0x44] = uVar7;

            pOVar15 = SysAllocString(L"tinSequence");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar4 = FUN_007b8a60();

            *(uint8_t *)(puVar9 + 2) = uVar4;

            pOVar15 = SysAllocString(L"IDContinentObject");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[0x45] = uVar7;

            pOVar15 = SysAllocString(L"intLayerIndex");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar4 = FUN_007b8a60();

            *(uint8_t *)(puVar9 + 0x46) = uVar4;

            pOVar15 = SysAllocString(L"strObjectiveName");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))(unaff_EBX);

            }

            FUN_007b8de0();

            pOVar15 = SysAllocString(L"strMapName");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))(unaff_EBX);

            }

            FUN_007b8de0();

            pOVar15 = SysAllocString(L"intXP");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[0x47] = uVar7;

            pOVar15 = SysAllocString(L"intCredits");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[0x48] = uVar7;

            pOVar15 = SysAllocString(L"intAttribPoints");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[0x49] = uVar7;

            pOVar15 = SysAllocString(L"intSkillPoints");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar7 = FUN_007b8a60();

            puVar9[0x4a] = uVar7;

            pOVar15 = SysAllocString(L"bitReturnToNPC");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar16 = FUN_007b87c0();

            puVar9[0x4b] = uVar16 & 0xff;

            pOVar15 = SysAllocString(L"sinXPIndex");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar6 = FUN_007b8a60();

            *(uint16_t *)(puVar9 + 0x4c) = uVar6;

            pOVar15 = SysAllocString(L"sinCreditsIndex");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            uVar6 = FUN_007b8a60();

            *(uint16_t *)((int)puVar9 + 0x132) = uVar6;

            pOVar15 = SysAllocString(L"rlXPScaler");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            FUN_007b8b90();

            puVar9[0x4d] = in_XMM0_Da;

            pOVar15 = SysAllocString(L"rlXPScalerBalance");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            FUN_007b8b90();

            puVar9[0x4e] = in_XMM0_Da;

            pOVar15 = SysAllocString(L"rlCreditsScaler");

            if (pOVar15 == (BSTR)0x0) goto LAB_007c22ea;

            if (unaff_EBX != (int *)0x0) {

              (**(code **)(*unaff_EBX + 4))();

            }

            local_2f0 = (int *)&stack0xfffffcf4;

            FUN_007b8b90();

            puVar9[0x4f] = in_XMM0_Da;

            puVar11 = (uint32_t /* width from decompiler */ *)FUN_0041b610();

            if ((int *)*puVar11 != local_2e0) {

              iVar8 = ((int *)*puVar11)[4];

              *(uint32_t /* width from decompiler */ **)(*(int *)(iVar8 + 0x134) + (uint)*(byte *)(iVar8 + 0x130) * 4) =

                   puVar9;

              *(char *)(iVar8 + 0x130) = *(char *)(iVar8 + 0x130) + '\x01';

            }

          }

          local_2a4 = local_2a4 + 1;

        } while( true );

      }

      local_2a4 = 0;

      while( true ) {

        if (local_2ec == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        iVar13 = (*local_2ec->lpVtbl[2].Release)();

        if (iVar13 < 0) {

          _com_issue_errorex(iVar13,local_2ec,(_GUID *)&DAT_00a86118);

        }

        if (-1 < local_2a4) {

          pvVar10 = CoTaskMemAlloc(iVar8 * 4);

          *param_2 = (int)pvVar10;

          piVar1 = (int *)*local_2e0;

          if (piVar1 != local_2e0) {

            iVar13 = 0;

            do {

              *(int *)(iVar13 + *param_2) = piVar1[4];

              iVar13 = iVar13 + 4;

              FUN_0046f100();

            } while (piVar1 != local_2e0);

          }

          *unaff_retaddr = iVar8;

          pIVar2 = local_2ec;

          goto LAB_007c22db;

        }

        if (local_2ec == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        unaff_EBX = (int *)0x0;

        (*local_2ec->lpVtbl[2].AddRef)();

        puVar9 = CoTaskMemAlloc(0x138);

        if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

          if (local_2ec != (IUnknown *)0x0) {

            (*local_2ec->lpVtbl->Release)();

          }

          if (local_2e4 != (int *)0x0) {

            (**(code **)(*local_2e4 + 8))();

          }

          SysFreeString(local_294[0]);

          FUN_00421110();

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)0x0);

        }

        pOVar14 = SysAllocString(L"IDQuest");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        if (local_2ec != (IUnknown *)0x0) {

          (*local_2ec->lpVtbl->AddRef)();

        }

        uVar7 = FUN_007b8a60();

        *puVar9 = uVar7;

        pOVar14 = SysAllocString(L"strName");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        if (local_2ec != (IUnknown *)0x0) {

          (*local_2ec->lpVtbl->AddRef)();

        }

        FUN_007b8de0();

        pOVar14 = SysAllocString(L"tinType");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar4 = FUN_007b8a60();

        *(uint8_t *)((int)puVar9 + 0x86) = uVar4;

        pOVar14 = SysAllocString(L"cbidNPC");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x22] = uVar7;

        pOVar14 = SysAllocString(L"intPriority");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x23] = uVar7;

        pOVar14 = SysAllocString(L"sinReqRace");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar6 = FUN_007b8a60();

        *(uint16_t *)(puVar9 + 0x24) = uVar6;

        pOVar14 = SysAllocString(L"sinReqClass");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar6 = FUN_007b8a60();

        *(uint16_t *)((int)puVar9 + 0x92) = uVar6;

        pOVar14 = SysAllocString(L"intReqLevelMin");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x25] = uVar7;

        pOVar14 = SysAllocString(L"intReqLevelMax");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x26] = uVar7;

        pOVar14 = SysAllocString(L"bitIsRepeatable");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)(puVar9 + 0x2b) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"intReqMissionID1");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x27] = uVar7;

        pOVar14 = SysAllocString(L"intReqMissionID2");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x28] = uVar7;

        pOVar14 = SysAllocString(L"intReqMissionID3");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x29] = uVar7;

        pOVar14 = SysAllocString(L"intReqMissionID4");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x2a] = uVar7;

        pOVar14 = SysAllocString(L"cbidItem1");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x2c] = uVar7;

        pOVar14 = SysAllocString(L"cbidItem2");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x2d] = uVar7;

        pOVar14 = SysAllocString(L"cbidItem3");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x2e] = uVar7;

        pOVar14 = SysAllocString(L"cbidItem4");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x2f] = uVar7;

        pOVar14 = SysAllocString(L"cbidItemTemplate1");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x30] = uVar7;

        pOVar14 = SysAllocString(L"cbidItemTemplate2");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x31] = uVar7;

        pOVar14 = SysAllocString(L"cbidItemTemplate3");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x32] = uVar7;

        pOVar14 = SysAllocString(L"cbidItemTemplate4");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x33] = uVar7;

        pOVar14 = SysAllocString(L"rlItemValue1");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        FUN_007b8b90();

        puVar9[0x34] = in_XMM0_Da;

        pOVar14 = SysAllocString(L"rlItemValue2");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        FUN_007b8b90();

        puVar9[0x35] = in_XMM0_Da;

        pOVar14 = SysAllocString(L"rlItemValue3");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        FUN_007b8b90();

        puVar9[0x36] = in_XMM0_Da;

        pOVar14 = SysAllocString(L"rlItemValue4");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        FUN_007b8b90();

        puVar9[0x37] = in_XMM0_Da;

        pOVar14 = SysAllocString(L"bitIsKit1");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)(puVar9 + 0x38) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"bitIsKit2");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)((int)puVar9 + 0xe2) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"bitIsKit3");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)(puVar9 + 0x39) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"bitIsKit4");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)((int)puVar9 + 0xe6) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"bitAutoAssign");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)(puVar9 + 0x3e) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"bActiveObjectiveOverride");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b87c0();

        *(ushort *)((int)puVar9 + 0xfa) = (ushort)bVar5;

        pOVar14 = SysAllocString(L"intAchievement");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x40] = uVar7;

        pOVar14 = SysAllocString(L"IDContinent");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x3f] = uVar7;

        pOVar14 = SysAllocString(L"IDDiscipline");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x41] = uVar7;

        pOVar14 = SysAllocString(L"intDisciplineValue");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x42] = uVar7;

        pOVar14 = SysAllocString(L"IDRewardDiscipline");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x43] = uVar7;

        pOVar14 = SysAllocString(L"intRewardDisciplineValue");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x44] = uVar7;

        pOVar14 = SysAllocString(L"intRewardUnassignedDisciplinePoints");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x45] = uVar7;

        pOVar14 = SysAllocString(L"intRequirementEventID");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x46] = uVar7;

        *(uint8_t *)(puVar9 + 0x4c) = 0;

        pOVar14 = SysAllocString(L"tinNumberOfObjectives");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        bVar5 = FUN_007b8a60();

        pvVar10 = CoTaskMemAlloc((uint)bVar5 * 4);

        puVar9[0x4d] = pvVar10;

        pOVar14 = SysAllocString(L"sinTargetLevel");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar6 = FUN_007b8a60();

        *(uint16_t *)(puVar9 + 0x47) = uVar6;

        pOVar14 = SysAllocString(L"IDRegion");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        uVar7 = FUN_007b8a60();

        puVar9[0x4a] = uVar7;

        pOVar14 = SysAllocString(L"IDPocket");

        if (pOVar14 == (BSTR)0x0) goto LAB_007c22ea;

        local_2ec = (IUnknown *)&stack0xfffffcf8;

        uVar7 = FUN_007b8a60();

        puVar9[0x4b] = uVar7;

        if (puVar9[0x4d] == 0) break;

        puVar11 = (uint32_t /* width from decompiler */ *)FUN_0041b440();

        local_2a0 = (BSTR)((int)local_2a0 + 1);

        *puVar11 = puVar9;

      }

      local_4 = CONCAT31(local_4._1_3_,3);

      if (&stack0x00000000 != (uint8_t *)0x30c) {

        (**(code **)(in_stack_fffffcf4 + 8))();

      }

      SysFreeString(local_298);

      local_4 = 0xffffffff;

      FUN_0041a480();

      uVar7 = 0x8007000e;

    }

  }

  ExceptionList = local_c;

  return uVar7;

}
