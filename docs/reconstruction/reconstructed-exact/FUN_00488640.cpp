// =============================================================================
// FUN_00488640
// -----------------------------------------------------------------------------
// Stable ID: aa_00488640
// Address:   0x00488640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00488640 @ 0x00488640
// Stable ID: aa_00488640
// Embedded strings (evidence for future rename):
//   - "

// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×22, while×5, do×4, goto×4, return×3, for×1.
//  - Notable callees: FUN_00488390, FUN_00488640, author, exit, fprintf.
//  - Strings: "

              ,0x3e9,".
//  - Return sites: 3.

              ,0x3e9,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall

FUN_00488640(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            ,int *param_6)



{

  int *piVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  int iVar11;

  byte bVar12;

  uint uVar13;

  int *piVar14;

  uint32_t /* width from decompiler */ *puVar15;

  int unaff_ESI;

  int iVar16;

  int iVar17;

  byte local_4f8;

  int *local_4f4;

  int local_4f0;

  int local_4e8;

  int local_4d8;

  int local_4d4;

  int local_4d0;

  int local_4cc;

  int local_4c4;

  int local_4b4 [301];

  

  local_4b4[1] = param_1;

  local_4b4[0xc9] = param_2;

  iVar16 = 1;

  do {

    if (99 < iVar16) {

      fprintf((FILE *)(_iob_exref + 0x40),

              "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"

              ,0x3e9,"1.0.2, 30-Dec-2001");

                    /* WARNING: Subroutine does not return */

      exit(3);

    }

    iVar7 = local_4b4[iVar16];

    iVar8 = local_4b4[iVar16 + 100];

    iVar4 = local_4b4[iVar16 + 200];

    iVar17 = iVar16 + -1;

    if ((iVar7 - iVar8 < 0x14) || (0xe < iVar4)) {

      FUN_00488390();

      if (*param_6 < 0) {

        return;

      }

    }

    else {

      bVar2 = *(byte *)(*(int *)(unaff_ESI + (iVar8 + iVar7 >> 1) * 4) + iVar4 + param_3);

      bVar3 = *(byte *)(*(int *)(unaff_ESI + iVar7 * 4) + iVar4 + param_3);

      piVar1 = (int *)(unaff_ESI + iVar8 * 4);

      local_4f8 = *(byte *)(*piVar1 + iVar4 + param_3);

      bVar12 = bVar3;

      if (bVar3 < local_4f8) {

        bVar12 = local_4f8;

        local_4f8 = bVar3;

      }

      if ((bVar2 < bVar12) && (bVar12 = local_4f8, local_4f8 <= bVar2)) {

        bVar12 = bVar2;

      }

      uVar6 = (uint)bVar12;

      local_4f4 = (int *)iVar8;

      local_4f0 = iVar7;

LAB_00488707:

      for (; iVar8 <= iVar7; iVar8 = iVar8 + 1) {

        while( true ) {

          iVar17 = *(int *)(unaff_ESI + iVar8 * 4);

          uVar13 = (uint)*(byte *)(iVar17 + iVar4 + param_3);

          if (uVar13 != uVar6) break;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + iVar8 * 4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + (int)local_4f4 * 4);

          *(int *)(unaff_ESI + (int)local_4f4 * 4) = iVar17;

          local_4f4 = (int *)((int)local_4f4 + 1);

          iVar8 = iVar8 + 1;

          if (iVar7 < iVar8) goto LAB_004887a3;

        }

        if (uVar13 != uVar6 && -1 < (int)(uVar13 - uVar6)) {

          if (iVar8 <= iVar7) {

            do {

              iVar17 = *(int *)(unaff_ESI + iVar7 * 4);

              uVar13 = (uint)*(byte *)(iVar17 + iVar4 + param_3);

              if (uVar13 == uVar6) {

                *(uint32_t /* width from decompiler */ *)(unaff_ESI + iVar7 * 4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + local_4f0 * 4);

                *(int *)(unaff_ESI + local_4f0 * 4) = iVar17;

                local_4f0 = local_4f0 + -1;

              }

              else if ((int)(uVar13 - uVar6) < 0) goto LAB_004887bb;

              iVar7 = iVar7 + -1;

              if (iVar7 < iVar8) break;

            } while( true );

          }

          break;

        }

      }

LAB_004887a3:

      if (local_4f0 < (int)local_4f4) {

        local_4b4[iVar16 + 200] = iVar4 + 1;

        iVar17 = iVar16;

      }

      else {

        iVar17 = iVar8 - (int)local_4f4;

        local_4e8 = iVar17;

        if ((int)local_4f4 - local_4b4[iVar16 + 100] < iVar17) {

          local_4e8 = (int)local_4f4 - local_4b4[iVar16 + 100];

        }

        if (0 < local_4e8) {

          piVar14 = (int *)(unaff_ESI + (iVar8 - local_4e8) * 4);

          local_4f4 = piVar1;

          do {

            iVar11 = *local_4f4;

            *local_4f4 = *piVar14;

            *piVar14 = iVar11;

            piVar14 = piVar14 + 1;

            local_4e8 = local_4e8 + -1;

            local_4f4 = local_4f4 + 1;

          } while (local_4e8 != 0);

        }

        local_4e8 = local_4f0 - iVar7;

        if (local_4b4[iVar16] - local_4f0 < local_4f0 - iVar7) {

          local_4e8 = local_4b4[iVar16] - local_4f0;

        }

        if (0 < local_4e8) {

          puVar9 = (uint32_t /* width from decompiler */ *)(unaff_ESI + iVar8 * 4);

          puVar15 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 4 + (local_4b4[iVar16] - local_4e8) * 4);

          do {

            uVar5 = *puVar9;

            *puVar9 = *puVar15;

            *puVar15 = uVar5;

            puVar9 = puVar9 + 1;

            puVar15 = puVar15 + 1;

            local_4e8 = local_4e8 + -1;

          } while (local_4e8 != 0);

        }

        iVar8 = local_4b4[iVar16 + 100];

        iVar11 = local_4b4[iVar16];

        local_4cc = iVar17 + -1 + iVar8;

        iVar7 = (iVar7 - local_4f0) + 1 + iVar11;

        local_4b4[0] = local_4cc + 1;

        local_4c4 = iVar7 + -1;

        iVar17 = iVar7;

        if (local_4cc - iVar8 < iVar11 - iVar7) {

          iVar17 = iVar8;

          iVar11 = local_4cc;

          iVar8 = iVar7;

          local_4cc = local_4b4[iVar16];

        }

        iVar7 = iVar17;

        iVar10 = iVar11;

        local_4d4 = iVar4;

        local_4d0 = iVar4 + 1;

        if (iVar11 - iVar17 < local_4c4 - local_4b4[0]) {

          iVar7 = local_4b4[0];

          iVar10 = local_4c4;

          local_4d4 = iVar4 + 1;

          local_4d0 = iVar4;

          local_4c4 = iVar11;

          local_4b4[0] = iVar17;

        }

        iVar17 = iVar7;

        iVar11 = iVar10;

        local_4d8 = iVar4;

        if (local_4cc - iVar8 < iVar10 - iVar7) {

          local_4d8 = local_4d4;

          iVar17 = iVar8;

          iVar11 = local_4cc;

          iVar8 = iVar7;

          local_4d4 = iVar4;

          local_4cc = iVar10;

        }

        local_4b4[iVar16 + 100] = iVar8;

        local_4b4[iVar16 + 200] = local_4d8;

        local_4b4[iVar16] = local_4cc;

        local_4b4[iVar16 + 0x65] = iVar17;

        local_4b4[iVar16 + 1] = iVar11;

        local_4b4[iVar16 + 0xc9] = local_4d4;

        local_4b4[iVar16 + 0x66] = local_4b4[0];

        local_4b4[iVar16 + 2] = local_4c4;

        local_4b4[iVar16 + 0xca] = local_4d0;

        iVar17 = iVar16 + 2;

      }

    }

    iVar16 = iVar17;

    if (iVar17 < 1) {

      return;

    }

  } while( true );

LAB_004887bb:

  if (iVar7 < iVar8) goto LAB_004887a3;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + iVar8 * 4);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + iVar8 * 4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + iVar7 * 4);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + iVar7 * 4) = uVar5;

  iVar8 = iVar8 + 1;

  iVar7 = iVar7 + -1;

  goto LAB_00488707;

}
