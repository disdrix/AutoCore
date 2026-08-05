// READABILITY (auto CF):
//  - Body size: ~967 non-empty decompiler lines.
//  - Control keywords: if×166, goto×60, while×8, return×6, do×6, for×1.
//  - Notable callees: SysAllocString×62, FUN_004231d0×58, FUN_007b8a60×48, FUN_00423f40×8, CONCAT31×7, FUN_007b8910×6, FUN_007b8de0×6, CONCAT11×4.
//  - Strings: "//vSkillsCharacters/row"; "IDClass"; "IDRace"; "IDSkill".
//  - Return sites: 6.

// =============================================================================
// Skill_vSkillsNotCharacters_row
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "//vSkillsNotCharacters/row"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_007e34b0 clean capture (not modernized).
//
// Address:  0x007e34b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_007e34b0
// Stable ID: aa_007e34b0
// System:   skills-abilities
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_007e34b0_*.md
//           Original Ghidra symbol: FUN_007e34b0
//
// Exactness: Body mirrors reconstructed-exact/FUN_007e34b0*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Skill_vSkillsNotCharacters_row
// -----------------------------------------------------------------------------
// Stable ID: aa_007e34b0
// Address:   0x007e34b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "//vSkillsNotCharacters/row"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Removing unreachable block (ram,0x007e48ba) */

/* WARNING: Removing unreachable block (ram,0x007e48fb) */

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffed10 : 0x007e44cb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



uint32_t /* width from decompiler */ __fastcall Skill_vSkillsNotCharacters_row(char *param_1)



{

  BSTR *ppOVar1;

  IUnknown *This;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  uint8_t uVar4;

  uint8_t uVar5;

  short sVar6;

  uint16_t uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  int *piVar11;

  int iVar12;

  ULONG UVar13;

  uint32_t /* width from decompiler */ *puVar14;

  BSTR *unaff_EBX;

  BSTR *ppOVar15;

  int *unaff_EBP;

  BSTR *unaff_ESI;

  code *pcVar16;

  IUnknown *This_00;

  BSTR pOVar17;

  code *in_stack_ffffed10;

  int *local_12cc;

  int *local_12c8;

  BSTR *local_12c4;

  uint32_t /* width from decompiler */ uStack_12c0;

  int local_12bc;

  uint32_t /* width from decompiler */ local_12b8;

  int **local_12b4;

  uint32_t /* width from decompiler */ local_12b0;

  int local_12ac;

  uint32_t /* width from decompiler */ local_12a8;

  int *local_12a4;

  uint32_t /* width from decompiler */ *local_12a0;

  BSTR local_129c;

  uint32_t /* width from decompiler */ *local_1298;

  int local_1294;

  short local_1290;

  BSTR local_128c;

  int local_1288;

  BSTR local_1284;

  IUnknown *local_1280;

  uint32_t /* width from decompiler */ uStack_127c;

  short local_1278;

  BSTR local_1274;

  uint32_t /* width from decompiler */ local_1270;

  int iStack_126c;

  uint32_t /* width from decompiler */ local_1268;

  int *local_1264;

  uint32_t /* width from decompiler */ uStack_1260;

  char *local_125c;

  int *local_1258;

  uint32_t /* width from decompiler */ local_1254;

  uint32_t /* width from decompiler */ local_1250;

  uint32_t /* width from decompiler */ local_124c;

  uint32_t /* width from decompiler */ local_1248;

  uint32_t /* width from decompiler */ local_1244;

  uint32_t /* width from decompiler */ local_1240;

  uint32_t /* width from decompiler */ local_123c;

  uint32_t /* width from decompiler */ local_1238;

  uint32_t /* width from decompiler */ local_1234;

  uint32_t /* width from decompiler */ local_1230;

  uint32_t /* width from decompiler */ local_122c;

  uint32_t /* width from decompiler */ local_1228;

  uint32_t /* width from decompiler */ local_1224;

  uint32_t /* width from decompiler */ local_1220;

  wchar_t local_121c [34];

  BSTR pOStack_11d8;

  int *piStack_11d4;

  uint32_t /* width from decompiler */ uStack_11d0;

  int *piStack_11cc;

  uint32_t /* width from decompiler */ local_11c8;

  uint32_t /* width from decompiler */ local_11c4;

  uint32_t /* width from decompiler */ local_11c0;

  uint32_t /* width from decompiler */ local_11bc;

  uint32_t /* width from decompiler */ local_11b8;

  uint32_t /* width from decompiler */ local_11b4;

  uint32_t /* width from decompiler */ local_11b0;

  uint32_t /* width from decompiler */ local_11ac;

  uint32_t /* width from decompiler */ local_11a8;

  uint32_t /* width from decompiler */ local_11a4;

  uint8_t local_11a0;

  uint8_t uStack_119f;

  uint8_t uStack_119e;

  uint8_t uStack_119d;

  uint8_t uStack_1199;

  wchar_t awStack_115e [1025];

  wchar_t awStack_95c [66];

  uint uStack_8d8;

  uint uStack_8d4;

  uint32_t /* width from decompiler */ uStack_8d0;

  uint32_t /* width from decompiler */ uStack_8cc;

  uint32_t /* width from decompiler */ local_8c8;

  char *local_8c4;

  uint32_t /* width from decompiler */ local_8c0;

  uint32_t /* width from decompiler */ local_8bc;

  uint32_t /* width from decompiler */ local_8b8;

  uint32_t /* width from decompiler */ local_8b4;

  uint32_t /* width from decompiler */ local_8b0;

  uint32_t /* width from decompiler */ local_8ac;

  void *local_8a8;

  void *local_8a4;

  void *local_8a0;

  wchar_t awStack_820 [1030];

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0182;

  local_c = ExceptionList;

  uStack_10 = 0x7e34cf;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  ExceptionList = &local_c;

  local_125c = param_1;

  FUN_007d9440();

  uVar5 = (uint8_t)((uint)unaff_EBX >> 0x18);

  if (DAT_00d1793c == '\0') {

    local_12a4 = &local_12bc;

    local_12bc = 0;

    local_12b8 = 0;

    local_12b4 = (int **)0x0;

    local_12b0 = 0;

    local_12ac = 0;

    local_12a8 = 0;

    local_129c = (BSTR)0x0;

    local_12a0 = (uint32_t /* width from decompiler */ *)0x0;

    local_1298 = (uint32_t /* width from decompiler */ *)0x0;

    local_1294 = 0;

    local_4 = 0;

    iVar8 = FUN_0041a810(local_12a4);

    local_12b4 = &local_1264;

    if ((((((((((-1 < iVar8) && (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

              (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

             ((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)))) &&

            ((iVar8 = FUN_004231d0(), -1 < iVar8 &&

             ((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)))))) &&

           (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

          ((((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

            (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

           (((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

            ((iVar8 = FUN_004231d0(), -1 < iVar8 &&

             ((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8))))))))))

         && ((iVar8 = FUN_004231d0(), -1 < iVar8 &&

             (((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

              (iVar8 = FUN_004231d0(), -1 < iVar8)))))) &&

        ((((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

          ((iVar8 = FUN_004231d0(), -1 < iVar8 &&

           ((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)))))) &&

         (iVar8 = FUN_004231d0(), -1 < iVar8)))) &&

       (((((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

          (iVar8 = FUN_004231d0(), -1 < iVar8)) &&

         ((iVar8 = FUN_004231d0(), -1 < iVar8 && (iVar8 = FUN_004231d0(), -1 < iVar8)))) &&

        ((iVar8 = FUN_004231d0(), -1 < iVar8 &&

         ((iVar8 = FUN_004231d0(), -1 < iVar8 && (local_12ac != 0)))))))) {

      iVar8 = FUN_0041a9b0();

      pcVar16 = wcscpy_exref;

      uVar2 = uStack_8d0;

      while (iVar8 == 0) {

        uStack_127c._3_1_ = (uint8_t)((uint)uStack_127c >> 0x18);

        local_1270._3_1_ = (uint8_t)((uint)local_1270 >> 0x18);

        uStack_8cc = (uint)((short)local_1288 == -1);

        local_11a4._0_2_ = CONCAT11(local_1270._3_1_,uStack_127c._3_1_);

        local_11a4 = CONCAT13(uVar5,CONCAT12((char)((uint)local_128c >> 0x18),(uint16_t)local_11a4

                                            ));

        uStack_8d0._2_2_ = (uint16_t)((uint)uVar2 >> 0x10);

        uStack_8d0._0_2_ = CONCAT11((char)((uint)unaff_EBX >> 0x10),(char)uVar2);

        pOStack_11d8 = local_1274;

        piStack_11d4 = local_1264;

        uStack_11d0 = local_1268;

        piStack_11cc = local_1258;

        local_11c8 = uStack_1260;

        local_11c4 = local_1250;

        local_11c0 = local_1238;

        local_11bc = local_1244;

        local_11b8 = local_1254;

        local_11b4 = local_123c;

        local_11b0 = local_1228;

        local_11ac = local_1220;

        local_11a8 = local_1224;

        local_8c8 = local_1248;

        local_8c4 = local_125c;

        (*pcVar16)();

        (*pcVar16)(awStack_115e,awStack_820);

        (*pcVar16)(awStack_95c,&local_8a4);

        uStack_8d0 = CONCAT31(uStack_8d0._1_3_,(char)((uint)unaff_EBX >> 8));

        uStack_8d8 = (uint)((short)local_1294 == -1);

        local_8b4 = local_122c;

        uStack_8d4 = (uint)(local_1278 == -1);

        local_8bc = local_124c;

        local_8b0 = local_1240;

        local_8b8 = local_1234;

        local_8c0 = local_1230;

        local_8ac = CONCAT22(local_8ac._2_2_,local_1290);

        if (local_1290 < 1) {

          local_8a8 = (void *)0x0;

        }

        else {

          local_8a8 = operator_new__(local_1290 * 0x14);

          if ((local_8a8 != (void *)0x0) &&

             (puVar9 = (uint32_t /* width from decompiler */ *)FUN_0041ac60(), pcVar16 = wcscpy_exref,

             puVar9 != (uint32_t /* width from decompiler */ *)0x0)) {

            FUN_004294f0();

            iVar8 = FUN_00423f40();

            if (iVar8 == 0) {

              iVar8 = 0;

              do {

                if (local_12a0 == (uint32_t /* width from decompiler */ *)0x0) break;

                puVar14 = (uint32_t /* width from decompiler */ *)(iVar8 + (int)local_8a8);

                *puVar14 = *local_12a0;

                puVar14[1] = local_12a0[1];

                puVar14[2] = local_12a0[2];

                puVar14[3] = local_12a0[3];

                puVar14[4] = local_12a0[4];

                iVar8 = iVar8 + 0x14;

                iVar10 = FUN_00423f40();

              } while (iVar10 == 0);

            }

            if (*(char *)(puVar9 + 10) != '\0') {

              *(uint8_t *)(puVar9 + 10) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(puVar9 + 1));

            }

            (**(code **)*puVar9)();

            pcVar16 = wcscpy_exref;

          }

        }

        FUN_0041aef0();

        (*pcVar16)();

        iVar8 = FUN_0041c000();

        uVar2 = uStack_8d0;

      }

      uStack_8d0 = uVar2;

      if (local_12bc != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      uStack_14 = 0xffffffff;

      FUN_0041a3e0();

      goto LAB_007e4956;

    }

    FUN_00423170();

LAB_007e4db5:

    FUN_007a4480();

    local_4 = 0xffffffff;

    FUN_0041a3e0();

  }

  else {

    local_1274 = SysAllocString(L"//vSkillsCharacters/row");

    if (local_1274 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_12c4 = (BSTR *)0x0;

    local_12c8 = (int *)0x0;

    local_12cc = (int *)&stack0xffffed20;

    local_4._0_1_ = 3;

    local_4._1_3_ = 0;

    local_1270 = (IUnknown *)0x0;

    local_1288 = 0;

    FUN_00419ca0();

    local_4._0_1_ = 4;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,3);

    piVar11 = (int *)FUN_00419ed0();

    ppOVar1 = (BSTR *)*piVar11;

    ppOVar15 = local_12c4;

    if (ppOVar1 != (BSTR *)0x0) {

      local_12c4 = ppOVar1;

      (**(code **)(*ppOVar1 + 2))();

      ppOVar15 = ppOVar1;

    }

    if (local_128c != (BSTR)0x0) {

      (**(code **)(*(int *)local_128c + 8))();

    }

    if (ppOVar15 == (BSTR *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    if (local_12c8 != (int *)0x0) {

      (**(code **)(*local_12c8 + 8))();

    }

    local_12c8 = (int *)0x0;

    (**(code **)(*ppOVar15 + 0xe))();

    local_1298 = (uint32_t /* width from decompiler */ *)&stack0xffffed14;

    pOVar17 = SysAllocString(L"IDClass");

    if (pOVar17 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_1298 = (uint32_t /* width from decompiler */ *)&stack0xffffed10;

    puVar9 = (uint32_t /* width from decompiler */ *)&stack0xffffed10;

    if (unaff_EBP != (int *)0x0) {

      (**(code **)(*unaff_EBP + 4))();

      puVar9 = local_1298;

    }

    local_1298 = puVar9;

    uStack_1260 = FUN_007b8a60();

    local_1298 = (uint32_t /* width from decompiler */ *)&stack0xffffed14;

    pOVar17 = SysAllocString(L"IDRace");

    if (pOVar17 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_1298 = (uint32_t /* width from decompiler */ *)&stack0xffffed10;

    if (unaff_EBP != (int *)0x0) {

      local_1298 = (uint32_t /* width from decompiler */ *)&stack0xffffed10;

      (**(code **)(*unaff_EBP + 4))();

    }

    local_1264 = (int *)FUN_007b8a60();

    (**(code **)(*ppOVar15 + 0x10))();

    local_1298 = (uint32_t /* width from decompiler */ *)0x0;

    iVar8 = uStack_127c;

    if (0 < local_1294) {

      do {

        pOVar17 = SysAllocString(L"IDSkill");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        piStack_11d4 = (int *)FUN_007b8a60();

        uStack_11d0 = uStack_1260;

        piStack_11cc = local_1264;

        pOVar17 = SysAllocString(L"intTargetType");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11c8 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"intTargetSubType");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11c4 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"intTargetCOType");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11c0 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"intAffectedTarget");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11bc = FUN_007b8a60();

        pOVar17 = SysAllocString(L"intAffectedSubType");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11b8 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"intAffectedCOType");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11b4 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"intStatusEffect");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11b0 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"IDSkillPrerequisite1");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11ac = FUN_007b8a60();

        pOVar17 = SysAllocString(L"IDSkillPrerequisite2");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11a8 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"IDSkillPrerequisite3");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11a4 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"tinLocationTree");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_11a0 = FUN_007b8a60();

        pOVar17 = SysAllocString(L"tinLocationLine");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        uStack_119f = FUN_007b8a60();

        pOVar17 = SysAllocString(L"tinMinimumLevel");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        uStack_119e = FUN_007b8a60();

        pOVar17 = SysAllocString(L"tinSkillType");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        uStack_119d = FUN_007b8a60();

        pOVar17 = SysAllocString(L"tinMaxSkillLevel");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        uVar4 = FUN_007b8a60();

        uStack_8cc._0_2_ = CONCAT11(uVar4,(uint8_t)uStack_8cc);

        pOVar17 = SysAllocString(L"bitUseBodyForArc");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_8c8 = FUN_007b8910();

        pOVar17 = SysAllocString(L"intGroup");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_8c4 = (char *)FUN_007b8a60();

        pOVar17 = SysAllocString(L"intCategory");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 4))();

        }

        local_8bc = FUN_007b8a60();

        pOVar17 = SysAllocString(L"strName");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        unaff_EBP = (int *)&stack0xffffed0c;

        if (unaff_EBX != (BSTR *)0x0) {

          (**(code **)(*unaff_EBX + 2))();

        }

        FUN_007b8de0();

        pOVar17 = SysAllocString(L"strDescription");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (*in_stack_ffffed10)(&stack0xffffed0c);

        }

        FUN_007b8de0();

        pOVar17 = SysAllocString(L"strXMLName");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (*in_stack_ffffed10)(&stack0xffffed0c);

        }

        FUN_007b8de0();

        iVar10 = 0x7e4526;

        pOVar17 = SysAllocString(L"bitIsChain");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        uStack_8d4 = FUN_007b8910();

        iVar10 = 0x7e4567;

        pOVar17 = SysAllocString(L"bitIsSpray");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        uStack_8d0 = FUN_007b8910();

        iVar10 = 0x7e45a8;

        pOVar17 = SysAllocString(L"tinOptionalAction");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        uVar4 = FUN_007b8a60();

        uStack_8cc = CONCAT31(uStack_8cc._1_3_,uVar4);

        iVar10 = 0x7e45e9;

        pOVar17 = SysAllocString(L"IDSkillOptional1");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        local_8b8 = FUN_007b8a60();

        iVar10 = 0x7e462a;

        pOVar17 = SysAllocString(L"IDSkillOptional2");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        local_8b4 = FUN_007b8a60();

        iVar10 = 0x7e466b;

        pOVar17 = SysAllocString(L"IDSkillOptional3");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        local_8b0 = FUN_007b8a60();

        iVar10 = 0x7e46ac;

        pOVar17 = SysAllocString(L"IDSkillOptional4");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        local_8ac = FUN_007b8a60();

        iVar10 = 0x7e46ed;

        pOVar17 = SysAllocString(L"CBIDSummonedCreature");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        local_8bc = FUN_007b8a60();

        iVar10 = 0x7e472e;

        pOVar17 = SysAllocString(L"sinNumberOfElements");

        if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

        if (&stack0x00000000 != (uint8_t *)0x12f4) {

          (**(code **)(iVar10 + 4))();

        }

        iVar10 = 0x7e4758;

        sVar6 = FUN_007b8a60();

        local_8a8 = (void *)CONCAT22(local_8a8._2_2_,sVar6);

        local_8a4 = (void *)0x0;

        unaff_ESI = (BSTR *)&stack0xffffed10;

        if ((0 < sVar6) &&

           (local_8a4 = operator_new__(sVar6 * 0x14), unaff_ESI = (BSTR *)&stack0xffffed10,

           local_8a4 != (void *)0x0)) {

          iVar10 = 0x7e47b4;

          puVar9 = (uint32_t /* width from decompiler */ *)FUN_0041ac60();

          unaff_ESI = (BSTR *)&stack0xffffed10;

          if (puVar9 != (uint32_t /* width from decompiler */ *)0x0) {

            unaff_ESI = (BSTR *)0x0;

            FUN_004294f0();

            iVar8 = FUN_00423f40();

            if (iVar8 == 0) {

              iVar8 = 0;

              do {

                if (local_129c == (BSTR)0x0) break;

                puVar14 = (uint32_t /* width from decompiler */ *)((int)local_8a4 + iVar8);

                *puVar14 = *(uint32_t /* width from decompiler */ *)local_129c;

                puVar14[1] = *(uint32_t /* width from decompiler */ *)(local_129c + 2);

                puVar14[2] = *(uint32_t /* width from decompiler */ *)(local_129c + 4);

                puVar14[3] = *(uint32_t /* width from decompiler */ *)(local_129c + 6);

                puVar14[4] = *(uint32_t /* width from decompiler */ *)(local_129c + 8);

                iVar8 = iVar8 + 0x14;

                iVar12 = FUN_00423f40();

              } while (iVar12 == 0);

            }

            if (*(char *)(puVar9 + 10) != '\0') {

              *(uint8_t *)(puVar9 + 10) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(puVar9 + 1));

            }

            (**(code **)*puVar9)();

            ppOVar15 = unaff_EBX;

            iVar8 = uStack_127c;

          }

        }

        FUN_0041aef0();

        if (iVar8 < local_1294) {

          if (&stack0x00000000 != (uint8_t *)0x12f4) {

            (**(code **)(iVar10 + 8))();

          }

          unaff_EBP = (int *)0x0;

          (**(code **)(*ppOVar15 + 0xe))();

          iVar8 = iVar8 + 1;

          uStack_127c = iVar8;

          pOVar17 = SysAllocString(L"IDClass");

          if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

          unaff_ESI = (BSTR *)&stack0xffffed10;

          uStack_1260 = FUN_007b8a60();

          pOVar17 = SysAllocString(L"IDRace");

          if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

          local_1264 = (int *)FUN_007b8a60();

        }

        local_1298 = (uint32_t /* width from decompiler */ *)((int)local_1298 + 1);

      } while ((int)local_1298 < local_1294);

    }

    uStack_10._0_1_ = 2;

    if (unaff_EBP != (int *)0x0) {

      (**(code **)(*unaff_EBP + 8))();

    }

    uStack_10 = CONCAT31(uStack_10._1_3_,1);

    (**(code **)(*ppOVar15 + 4))();

    SysFreeString(local_1284);

LAB_007e4956:

    if (DAT_00d1793c == '\0') {

      local_12b4 = &local_12cc;

      local_12cc = (int *)0x0;

      local_12c8 = (int *)0x0;

      local_12c4 = (BSTR *)0x0;

      uStack_12c0 = 0;

      local_12bc = 0;

      local_12b8 = 0;

      local_12ac = 0;

      local_12b0 = 0;

      local_12a8 = 0;

      local_12a4 = (int *)0x0;

      uStack_14 = 5;

      iVar8 = FUN_0041a810(local_12b4,iStack_126c + 0x28,0,0,&DAT_00a140c8);

      local_12c4 = &local_1274;

      if ((((((iVar8 < 0) || (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

            (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

           (((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

             (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

            ((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

             ((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

              (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)))))))) ||

          ((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

           (((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

             (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

            (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)))))) ||

         ((((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

            (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

           (((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

             ((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

              (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)))) ||

            (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)))) ||

          ((((((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

               (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

              (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

             ((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

              (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)))) ||

            (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) ||

           (((iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0 ||

             (iVar8 = FUN_004231d0(&local_12cc), iVar8 < 0)) || (local_12bc == 0)))))))) {

        FUN_00423170();

        goto LAB_007e4db5;

      }

      iVar8 = FUN_0041a9b0();

      while (iVar8 == 0) {

        piStack_11d4 = (int *)0xffffffff;

        uStack_11d0 = 0xffffffff;

        local_11a4 = CONCAT13(uVar5,(undefined3)local_11a4);

        pOStack_11d8 = local_1274;

        piStack_11cc = local_1258;

        local_11c8 = uStack_1260;

        local_11c4 = local_1250;

        local_11c0 = local_1238;

        local_11bc = local_1244;

        local_11b8 = local_1254;

        local_11b4 = local_123c;

        wcscpy((wchar_t *)&local_11a0,local_121c);

        wcscpy(awStack_115e,awStack_820);

        wcscpy(awStack_95c,(wchar_t *)&local_8a4);

        uStack_8d8 = (uint)((short)local_1294 == -1);

        uStack_8d4 = (uint)(local_1278 == -1);

        local_8b4 = local_122c;

        local_8bc = local_124c;

        local_8b8 = local_1234;

        local_8c0 = local_1230;

        local_8b0 = local_1240;

        uStack_8cc = (uint)((short)local_1288 == -1);

        uStack_8d0._0_2_ = (uint16_t)((uint)unaff_EBX >> 8);

        local_8ac = CONCAT22(local_8ac._2_2_,local_1290);

        local_8c8 = local_1248;

        local_8c4 = local_125c;

        if (local_1290 < 1) {

          local_8a8 = (void *)0x0;

        }

        else {

          local_8a8 = operator_new__(local_1290 * 0x14);

          if ((local_8a8 != (void *)0x0) &&

             (puVar9 = (uint32_t /* width from decompiler */ *)FUN_0041ac60(), puVar9 != (uint32_t /* width from decompiler */ *)0x0)) {

            FUN_004294f0();

            iVar8 = FUN_00423f40();

            if (iVar8 == 0) {

              iVar8 = 0;

              do {

                if (local_12a0 == (uint32_t /* width from decompiler */ *)0x0) break;

                puVar14 = (uint32_t /* width from decompiler */ *)(iVar8 + (int)local_8a8);

                *puVar14 = *local_12a0;

                puVar14[1] = local_12a0[1];

                puVar14[2] = local_12a0[2];

                puVar14[3] = local_12a0[3];

                puVar14[4] = local_12a0[4];

                iVar8 = iVar8 + 0x14;

                iVar10 = FUN_00423f40();

              } while (iVar10 == 0);

            }

            if (*(char *)(puVar9 + 10) != '\0') {

              *(uint8_t *)(puVar9 + 10) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(puVar9 + 1));

            }

            (**(code **)*puVar9)();

          }

        }

        FUN_0041aef0();

        wcscpy((wchar_t *)&local_8a4,L"");

        iVar8 = FUN_0041c000();

      }

      if (local_12ac != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      local_1280 = (IUnknown *)0x0;

      uStack_14 = 7;

      local_129c = SysAllocString(L"//vSkillsNotCharacters/row");

      if (local_129c == (BSTR)0x0) {

LAB_007e50f3:

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      local_1298 = (uint32_t /* width from decompiler */ *)&stack0xffffed10;

      uStack_14._0_1_ = 8;

      FUN_00419ca0();

      uStack_14._0_1_ = 9;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      uStack_14 = CONCAT31(uStack_14._1_3_,8);

      puVar9 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

      This = (IUnknown *)*puVar9;

      This_00 = local_1280;

      if (This != (IUnknown *)0x0) {

        local_1280 = This;

        (*This->lpVtbl->AddRef)(This);

        This_00 = This;

      }

      if (local_1284 != (BSTR)0x0) {

        (**(code **)(*(int *)local_1284 + 8))();

      }

      if (This_00 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_1298 = (uint32_t /* width from decompiler */ *)0x0;

      UVar13 = (*This_00->lpVtbl[2].Release)(This_00);

      if ((int)UVar13 < 0) {

        _com_issue_errorex(UVar13,This_00,(_GUID *)&DAT_00a86118);

      }

      pOVar17 = (BSTR)0x0;

      local_1288 = 0;

      if (0 < (int)local_129c) {

        do {

          if (unaff_ESI != (BSTR *)0x0) {

            (**(code **)(*unaff_ESI + 4))();

          }

          local_12c4 = (BSTR *)0x0;

          (*This_00->lpVtbl[2].AddRef)(This_00);

          unaff_ESI = (BSTR *)0x0;

          if (local_12cc != (int *)0x0) {

            piStack_11cc = (int *)0xffffffff;

            local_11c8 = 0xffffffff;

            pOVar17 = SysAllocString(L"IDSkill");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uStack_11d0 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intTargetType");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11c4 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intTargetSubType");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11c0 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intTargetCOType");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11bc = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intAffectedTarget");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11b8 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intAffectedSubType");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11b4 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intAffectedCOType");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11b0 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intStatusEffect");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_11ac = FUN_007b8a60();

            pOVar17 = SysAllocString(L"tinSkillType");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uStack_1199 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"bitIsChain");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uStack_8d0 = FUN_007b8910();

            pOVar17 = SysAllocString(L"bitIsSpray");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uStack_8cc = FUN_007b8910();

            pOVar17 = SysAllocString(L"tinOptionalAction");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uVar5 = FUN_007b8a60();

            local_8c8 = CONCAT31(local_8c8._1_3_,uVar5);

            pOVar17 = SysAllocString(L"IDSkillOptional1");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8b4 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"IDSkillOptional2");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8b0 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"IDSkillOptional3");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8ac = FUN_007b8a60();

            pOVar17 = SysAllocString(L"IDSkillOptional4");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8a8 = (void *)FUN_007b8a60();

            pOVar17 = SysAllocString(L"CBIDSummonedCreature");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8b8 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"sinNumberOfElements");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uVar7 = FUN_007b8a60();

            local_8a4 = (void *)CONCAT22(local_8a4._2_2_,uVar7);

            pOVar17 = SysAllocString(L"tinMaxSkillLevel");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            uVar5 = FUN_007b8a60();

            local_8c8._0_2_ = CONCAT11(uVar5,(uint8_t)local_8c8);

            pOVar17 = SysAllocString(L"bitUseBodyForArc");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8c4 = (char *)FUN_007b8910();

            pOVar17 = SysAllocString(L"intGroup");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8c0 = FUN_007b8a60();

            pOVar17 = SysAllocString(L"intCategory");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            local_8bc = FUN_007b8a60();

            pOVar17 = SysAllocString(L"strName");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            FUN_007b8de0();

            pOVar17 = SysAllocString(L"strDescription");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            FUN_007b8de0();

            pOVar17 = SysAllocString(L"strXMLName");

            if (pOVar17 == (BSTR)0x0) goto LAB_007e50f3;

            if (local_12cc != (int *)0x0) {

              (**(code **)(*local_12cc + 4))();

            }

            FUN_007b8de0();

            if ((short)local_8a4 < 1) {

              local_8a0 = (void *)0x0;

            }

            else {

              local_8a0 = operator_new__((short)local_8a4 * 0x14);

              if ((local_8a0 != (void *)0x0) &&

                 (puVar9 = (uint32_t /* width from decompiler */ *)FUN_0041ac60(), puVar9 != (uint32_t /* width from decompiler */ *)0x0)) {

                FUN_004294f0();

                iVar8 = FUN_00423f40();

                if (iVar8 == 0) {

                  iVar8 = 0;

                  do {

                    if (local_1298 == (uint32_t /* width from decompiler */ *)0x0) break;

                    puVar14 = (uint32_t /* width from decompiler */ *)((int)local_8a0 + iVar8);

                    *puVar14 = *local_1298;

                    puVar14[1] = local_1298[1];

                    puVar14[2] = local_1298[2];

                    puVar14[3] = local_1298[3];

                    puVar14[4] = local_1298[4];

                    iVar8 = iVar8 + 0x14;

                    iVar10 = FUN_00423f40();

                  } while (iVar10 == 0);

                }

                if (*(char *)(puVar9 + 10) != '\0') {

                  *(uint8_t *)(puVar9 + 10) = 0;

                  LeaveCriticalSection((LPCRITICAL_SECTION)(puVar9 + 1));

                }

                (**(code **)*puVar9)();

              }

            }

            FUN_0041aef0();

            unaff_ESI = local_12c4;

            This_00 = local_1270;

            pOVar17 = local_1274;

          }

          pOVar17 = (BSTR)((int)pOVar17 + 1);

          local_1274 = pOVar17;

        } while ((int)pOVar17 < local_1288);

      }

      SysFreeString(local_128c);

      local_4 = CONCAT31(local_4._1_3_,6);

      if (local_12c4 != (BSTR *)0x0) {

        (**(code **)(*local_12c4 + 4))();

      }

      local_4 = 0xffffffff;

      (*This_00->lpVtbl->Release)(This_00);

    }

    pcVar3 = local_125c;

    if (*(uint32_t /* width from decompiler */ **)(local_125c + 0x558) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(local_125c + 0x558))();

    }

    pcVar3[0x558] = '\0';

    pcVar3[0x559] = '\0';

    pcVar3[0x55a] = '\0';

    pcVar3[0x55b] = '\0';

  }

  ExceptionList = local_c;

  return 0;

}
