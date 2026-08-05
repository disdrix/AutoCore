// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00489310
// -----------------------------------------------------------------------------
// Stable ID: aa_00489310
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00489310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "

                ,0x7d1,". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "

                ,0x7d1,"
//   - "

              ,0x7d2,"
//   - "
//   - "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×17, while×11, do×8, return×4, for×1.
//  - Notable callees: SBORROW4×4, author×2, exit×2, fprintf×2, FUN_00489310.
//  - Strings: "

                ,0x7d1,"; "

              ,0x7d2,".
//  - Return sites: 4.

                ,0x7d1,"
//   - "

              ,0x7d2,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00489310(uint32_t /* width from decompiler */ param_1,int *param_2,int param_3,int param_4,int param_5)



{

  uint uVar1;

  uint uVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  int iVar14;

  int *piVar15;

  uint uVar16;

  bool bVar17;

  int local_1448;

  int local_1438 [260];

  uint local_1028 [516];

  int local_818 [515];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x489320;

  if (0 < param_4) {

    iVar11 = 4 - (int)param_2;

    iVar14 = param_4;

    do {

      iVar4 = *param_2;

      if (iVar4 == 0) {

        iVar4 = 1;

      }

      *(int *)((int)local_1028 + iVar11 + (int)param_2) = iVar4 << 8;

      param_2 = param_2 + 1;

      iVar14 = iVar14 + -1;

    } while (iVar14 != 0);

  }

  do {

    iVar11 = 0;

    local_1438[0] = 0;

    local_1028[0] = 0;

    local_818[0] = -2;

    local_1448 = 1;

    iVar14 = param_4;

    if (0 < param_4) {

      piVar15 = local_818;

      for (iVar4 = param_4; piVar15 = piVar15 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {

        *piVar15 = -1;

      }

      do {

        iVar11 = iVar11 + 1;

        local_1438[iVar11] = local_1448;

        iVar4 = local_1438[iVar11 >> 1];

        iVar8 = iVar11;

        if ((int)local_1028[local_1448] < (int)local_1028[iVar4]) {

          uVar1 = local_1028[local_1448];

          iVar5 = iVar11 >> 1;

          iVar9 = iVar11;

          do {

            iVar8 = iVar5;

            local_1438[iVar9] = iVar4;

            iVar4 = local_1438[iVar8 >> 1];

            iVar5 = iVar8 >> 1;

            iVar9 = iVar8;

          } while ((int)uVar1 < (int)local_1028[iVar4]);

        }

        local_1438[iVar8] = local_1448;

        local_1448 = local_1448 + 1;

      } while (local_1448 <= param_4);

      iVar4 = local_1438[1];

      if (0x103 < iVar11) {

        fprintf((FILE *)(_iob_exref + 0x40),

                "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"

                ,0x7d1,"1.0.2, 30-Dec-2001");

                    /* WARNING: Subroutine does not return */

        exit(3);

      }

      while (local_1438[1] = iVar4, 1 < iVar11) {

        iVar8 = local_1438[iVar11];

        iVar12 = iVar11 + -1;

        iVar5 = 2;

        local_1438[1] = iVar8;

        iVar9 = 1;

        if (1 < iVar12) {

          uVar1 = local_1028[iVar8];

          bVar17 = SBORROW4(2,iVar12);

          iVar10 = 2 - iVar12;

          do {

            iVar6 = iVar5;

            if ((bVar17 != iVar10 < 0) &&

               ((int)local_1028[local_1438[iVar5 + 1]] < (int)local_1028[local_1438[iVar5]])) {

              iVar6 = iVar5 + 1;

            }

            if ((int)uVar1 < (int)local_1028[local_1438[iVar6]]) break;

            local_1438[iVar9] = local_1438[iVar6];

            iVar5 = iVar6 * 2;

            bVar17 = SBORROW4(iVar5,iVar12);

            iVar10 = iVar5 - iVar12;

            iVar9 = iVar6;

          } while (iVar5 <= iVar12);

        }

        local_1438[iVar9] = iVar8;

        iVar9 = local_1438[1];

        iVar8 = local_1438[iVar12];

        iVar11 = iVar11 + -2;

        iVar5 = 2;

        local_1438[1] = iVar8;

        iVar10 = 1;

        if (1 < iVar11) {

          uVar1 = local_1028[iVar8];

          bVar17 = SBORROW4(2,iVar11);

          iVar6 = 2 - iVar11;

          do {

            iVar7 = iVar5;

            if ((bVar17 != iVar6 < 0) &&

               ((int)local_1028[local_1438[iVar5 + 1]] < (int)local_1028[local_1438[iVar5]])) {

              iVar7 = iVar5 + 1;

            }

            if ((int)uVar1 < (int)local_1028[local_1438[iVar7]]) break;

            local_1438[iVar10] = local_1438[iVar7];

            iVar5 = iVar7 * 2;

            bVar17 = SBORROW4(iVar5,iVar11);

            iVar6 = iVar5 - iVar11;

            iVar10 = iVar7;

          } while (iVar5 <= iVar11);

        }

        iVar14 = iVar14 + 1;

        local_1438[iVar10] = iVar8;

        uVar1 = local_1028[iVar9];

        local_818[iVar9] = iVar14;

        local_818[iVar4] = iVar14;

        uVar2 = local_1028[iVar4];

        uVar13 = uVar1 & 0xff;

        uVar16 = uVar2 & 0xff;

        if (uVar13 < uVar16) {

          uVar13 = uVar16;

        }

        local_1438[iVar12] = iVar14;

        local_818[iVar14] = -1;

        local_1028[iVar14] = (uVar2 & 0xffffff00) + (uVar1 & 0xffffff00) | uVar13 + 1;

        uVar2 = local_1028[iVar14];

        iVar11 = local_1438[iVar12 >> 1];

        uVar1 = local_1028[iVar11];

        iVar4 = iVar12;

        iVar8 = iVar12 >> 1;

        while ((int)uVar2 < (int)uVar1) {

          local_1438[iVar4] = iVar11;

          iVar11 = local_1438[iVar8 >> 1];

          iVar4 = iVar8;

          iVar8 = iVar8 >> 1;

          uVar1 = local_1028[iVar11];

        }

        local_1438[iVar4] = iVar14;

        iVar11 = iVar12;

        iVar4 = local_1438[1];

      }

    }

    if (0x203 < iVar14) {

      fprintf((FILE *)(_iob_exref + 0x40),

              "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"

              ,0x7d2,"1.0.2, 30-Dec-2001");

                    /* WARNING: Subroutine does not return */

      exit(3);

    }

    iVar11 = 1;

    bVar17 = false;

    if (param_4 < 1) {

      return;

    }

    piVar15 = local_818;

    do {

      piVar15 = piVar15 + 1;

      iVar4 = 0;

      iVar14 = *piVar15;

      piVar3 = piVar15;

      while (-1 < iVar14) {

        piVar3 = local_818 + *piVar3;

        iVar4 = iVar4 + 1;

        iVar14 = *piVar3;

      }

      *(char *)(param_3 + -1 + iVar11) = (char)iVar4;

      if (param_5 < iVar4) {

        bVar17 = true;

      }

      iVar11 = iVar11 + 1;

    } while (iVar11 <= param_4);

    if (!bVar17) {

      return;

    }

    iVar11 = 1;

    if (1 < param_4) {

      do {

        local_1028[iVar11] = (((int)local_1028[iVar11] >> 8) / 2 + 1) * 0x100;

        iVar11 = iVar11 + 1;

      } while (iVar11 < param_4);

    }

  } while( true );

}
