// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_007e07b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007e07b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x007e07b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~393 non-empty decompiler lines.
//  - Control keywords: if×42, return×5.
//  - Notable callees: FUN_004231d0×25, FUN_00423670×25, FUN_007b87c0×13, FUN_007b8910×5, FUN_007b8de0×4, wcscpy×4, FUN_004048e0×3, FUN_0041a3e0×3.
//  - Strings: "//tCloneBase/row[@IDCloneBase=\'".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_007e07b0(int *param_1,char *param_2)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  byte bVar7;

  byte bVar8;

  byte bVar9;

  byte bVar10;

  byte bVar11;

  byte bVar12;

  int iVar13;

  wchar_t *lpString;

  IUnknown *This;

  ULONG UVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  uint uVar22;

  uint uVar23;

  uint uVar24;

  uint uVar25;

  uint uVar26;

  uint uVar27;

  int *unaff_EBX;

  int unaff_EBP;

  int *unaff_ESI;

  short local_454;

  short local_450;

  short sStack_44c;

  short sStack_448;

  short sStack_444;

  short sStack_440;

  short sStack_43c;

  short sStack_438;

  short sStack_434;

  short sStack_430;

  BSTR pOStack_42c;

  uint8_t auStack_428 [8];

  BSTR local_420;

  uint32_t /* width from decompiler */ local_41c;

  int local_418;

  uint32_t /* width from decompiler */ local_414;

  uint32_t /* width from decompiler */ local_410;

  uint32_t /* width from decompiler */ local_40c;

  uint32_t /* width from decompiler */ local_408;

  uint32_t /* width from decompiler */ *local_404;

  uint32_t /* width from decompiler */ local_400;

  IUnknown *local_3fc;

  uint32_t /* width from decompiler */ local_3f8;

  IUnknown *local_3f4;

  IUnknown *local_3f0;

  short sStack_3ec;

  int local_3e8;

  short sStack_3e4;

  short sStack_3e0;

  int aiStack_3dc [2];

  int iStack_3d4;

  int iStack_3d0;

  uint32_t /* width from decompiler */ local_3cc;

  wchar_t local_3c4 [14];

  wchar_t awStack_3a8 [66];

  wchar_t awStack_324 [66];

  wchar_t awStack_2a0 [66];

  wchar_t awStack_21c [258];

  void *pvStack_18;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aefe9;

  local_c = ExceptionList;

  local_3e8 = *param_1;

  if (DAT_00d1793c == '\0') {

    if (*param_2 == '\0') {

      ExceptionList = pvStack_18;

      return 0x80004004;

    }

    local_404 = &local_41c;

    local_41c = 0;

    local_418 = 0;

    local_414 = 0;

    local_410 = 0;

    local_40c = 0;

    local_408 = 0;

    local_3fc = (IUnknown *)0x0;

    local_400 = 0;

    local_3f8 = 0;

    local_3f4 = (IUnknown *)0x0;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_004230d0();

    iVar13 = FUN_00422fb0();

    if (-1 < iVar13) {

      iVar13 = FUN_0041a810(auStack_428,param_2 + 0x28,0,0);

    }

    local_420 = (BSTR)aiStack_3dc;

    if (((((((iVar13 < 0) || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

           (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

          ((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)))) ||

         (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

        (((((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

           ((iVar13 = FUN_004231d0(), iVar13 < 0 ||

            (((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

             (iVar13 = FUN_004231d0(), iVar13 < 0)))))) ||

          (((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

           ((iVar13 = FUN_004231d0(), iVar13 < 0 ||

            ((((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

              ((iVar13 = FUN_004231d0(), iVar13 < 0 ||

               (((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

                (iVar13 = FUN_004231d0(), iVar13 < 0)))))) ||

             ((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0))))))))))

         || (iVar13 = FUN_004231d0(), iVar13 < 0)))) ||

       (((iVar13 = FUN_004231d0(), iVar13 < 0 || (iVar13 = FUN_004231d0(), iVar13 < 0)) ||

        (local_418 == 0)))) {

      FUN_00423170();

      FUN_007a4480(1);

      uStack_10 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar13 = FUN_0041a9b0();

      if (iVar13 == 0) {

        param_1[1] = aiStack_3dc[0];

        wcscpy((wchar_t *)(param_1 + 3),awStack_2a0);

        wcscpy((wchar_t *)((int)param_1 + 0x8e),awStack_3a8);

        wcscpy((wchar_t *)(param_1 + 0x44),awStack_21c);

        wcscpy((wchar_t *)((int)param_1 + 0x312),awStack_324);

        param_1[0xe5] = (uint)(sStack_44c == -1);

        param_1[0xe6] = (uint)(local_454 == -1);

        param_1[0xe7] = (uint)(sStack_43c == -1);

        param_1[0xe8] = (uint)((short)unaff_EBX == -1);

        uVar15 = (int)sStack_448 >> 0x1f;

        param_1[0xe9] = (uint)(sStack_440 == -1);

        uVar16 = (int)sStack_438 >> 0x1f;

        uVar17 = (int)local_450 >> 0x1f;

        uVar18 = (int)sStack_430 >> 0x1f;

        uVar19 = (int)sStack_434 >> 0x1f;

        uVar20 = (int)sStack_444 >> 0x1f;

        uVar21 = (int)sStack_3ec >> 0x1f;

        uVar22 = (int)sStack_3e0 >> 0x1f;

        uVar23 = (int)(short)local_3e8 >> 0x1f;

        uVar24 = (int)sStack_3e4 >> 0x1f;

        uVar25 = (int)(short)local_3f8 >> 0x1f;

        uVar26 = (int)(short)local_3f0 >> 0x1f;

        uVar27 = (int)(short)pOStack_42c >> 0x1f;

        param_1[2] = (((int)(short)pOStack_42c ^ uVar27) - uVar27) +

                     ((((int)(short)local_3f0 ^ uVar26) - uVar26) +

                     ((((int)(short)local_3f8 ^ uVar25) - uVar25) +

                     ((((int)sStack_3e4 ^ uVar24) - uVar24) +

                     ((((int)(short)local_3e8 ^ uVar23) - uVar23) +

                     ((((int)sStack_3e0 ^ uVar22) - uVar22) +

                     ((((int)sStack_3ec ^ uVar21) - uVar21) +

                     ((((int)sStack_444 ^ uVar20) - uVar20) +

                     ((((int)sStack_434 ^ uVar19) - uVar19) +

                     ((((int)sStack_430 ^ uVar18) - uVar18) +

                     ((((int)local_450 ^ uVar17) - uVar17) +

                     ((((int)sStack_438 ^ uVar16) - uVar16) +

                     (((int)sStack_448 ^ uVar15) - uVar15) * 2) * 2) * 2) * 2) * 2) * 2) * 2) * 2) *

                     2) * 2) * 2) * 2;

        param_1[0xea] = iStack_3d4;

        param_1[0xeb] = unaff_EBP;

        param_1[0xec] = (uint)(iStack_3d4 != -1);

        FUN_0041a990();

        FUN_00423170();

        uStack_10 = 0xffffffff;

        FUN_0041a3e0();

      }

      else {

        FUN_0041a990();

        FUN_00423170();

        FUN_007a4480(1);

        uStack_10 = 0xffffffff;

        FUN_0041a3e0();

      }

    }

  }

  else {

    ExceptionList = &local_c;

    local_420 = SysAllocString(L"//tCloneBase/row[@IDCloneBase=\'");

    if (local_420 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_4 = 1;

    lpString = _itow(local_3e8,local_3c4,10);

    lstrlenW(lpString);

    iVar13 = FUN_00422ee0();

    if (iVar13 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    lstrlenW(L"\']");

    iVar13 = FUN_00422ee0();

    if (iVar13 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    This = local_3f0;

    if (local_3f0 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

      This = local_3f0;

    }

    local_3cc = 0;

    UVar14 = (*This->lpVtbl[2].Release)(This);

    if ((int)UVar14 < 0) {

      _com_issue_errorex(UVar14,This,(_GUID *)&DAT_00a86118);

    }

    if (0 < iStack_3d0) {

      if (local_3f4 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      if (unaff_EBX != (int *)0x0) {

        (**(code **)(*unaff_EBX + 8))();

      }

      (*local_3f4->lpVtbl[2].AddRef)(local_3f4);

      if (unaff_ESI != (int *)0x0) {

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8a60();

        param_1[1] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))(unaff_ESI);

        }

        FUN_007b8de0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))(unaff_ESI);

        }

        FUN_007b8de0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))(unaff_ESI);

        }

        FUN_007b8de0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))(unaff_ESI);

        }

        FUN_007b8de0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8910();

        param_1[0xe5] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8910();

        param_1[0xe6] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8910();

        param_1[0xe7] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8a60();

        param_1[0xea] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8a60();

        param_1[0xeb] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8910();

        param_1[0xe8] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        iVar13 = FUN_007b8910();

        param_1[0xe9] = iVar13;

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar1 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar2 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar3 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar4 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar5 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar6 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar7 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar8 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar9 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar10 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar11 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        bVar12 = FUN_007b87c0();

        FUN_00423670();

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        uVar15 = FUN_007b87c0();

        param_1[2] = (uVar15 & 0xff) +

                     ((uint)bVar1 +

                     ((uint)bVar2 +

                     ((uint)bVar3 +

                     ((uint)bVar4 +

                     ((uint)bVar5 +

                     ((uint)bVar6 +

                     ((uint)bVar7 +

                     ((uint)bVar8 +

                     ((uint)bVar9 + ((uint)bVar10 + ((uint)bVar11 + (uint)bVar12 * 2) * 2) * 2) * 2)

                     * 2) * 2) * 2) * 2) * 2) * 2) * 2) * 2;

        param_1[0xec] = (uint)(param_1[0xea] != -1);

      }

    }

    uStack_10._0_1_ = 3;

    if (unaff_ESI != (int *)0x0) {

      (**(code **)(*unaff_ESI + 8))();

    }

    uStack_10 = CONCAT31(uStack_10._1_3_,1);

    if (local_3fc != (IUnknown *)0x0) {

      (*local_3fc->lpVtbl->Release)(local_3fc);

    }

    SysFreeString(pOStack_42c);

  }

  ExceptionList = pvStack_18;

  return 0;

}
