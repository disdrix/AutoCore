// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004879a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004879a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004879a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "

              ,0x3ec,". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "

              ,0x3ec,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×19, while×5, do×4, goto×4, return×2, for×1.
//  - Notable callees: FUN_00487900, FUN_004879a0, author, exit, fprintf.
//  - Strings: "

              ,0x3ec,".
//  - Return sites: 2.

              ,0x3ec,"
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004879a0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int iVar11;

  int unaff_EDI;

  int local_33c;

  int local_334;

  int local_330;

  uint local_328;

  int local_324 [100];

  int aiStack_194 [101];

  

  local_324[1] = param_1;

  local_328 = 0;

  aiStack_194[1] = param_2;

  local_334 = 1;

  do {

    if (99 < local_334) {

      fprintf((FILE *)(_iob_exref + 0x40),

              "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"

              ,0x3ec,"1.0.2, 30-Dec-2001");

                    /* WARNING: Subroutine does not return */

      exit(3);

    }

    iVar2 = aiStack_194[local_334];

    iVar3 = local_324[local_334];

    iVar1 = local_334 + -1;

    if (iVar2 - iVar3 < 10) {

      FUN_00487900(iVar3);

    }

    else {

      local_328 = local_328 * 0x1dc5 + 1 & 0x7fff;

      iVar7 = iVar2;

      iVar8 = iVar3;

      iVar11 = iVar3;

      local_330 = iVar2;

      if (local_328 % 3 == 0) {

        local_33c = *(int *)(param_3 + *(int *)(unaff_EDI + iVar3 * 4) * 4);

      }

      else {

        if (local_328 % 3 == 1) {

          iVar6 = *(int *)(unaff_EDI + (iVar2 + iVar3 >> 1) * 4);

        }

        else {

          iVar6 = *(int *)(unaff_EDI + iVar2 * 4);

        }

        local_33c = *(int *)(param_3 + iVar6 * 4);

      }

LAB_00487a80:

      for (; iVar8 <= iVar7; iVar8 = iVar8 + 1) {

        while( true ) {

          iVar6 = *(int *)(unaff_EDI + iVar8 * 4);

          iVar4 = *(int *)(param_3 + iVar6 * 4);

          if (iVar4 != local_33c) break;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar8 * 4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar11 * 4);

          *(int *)(unaff_EDI + iVar11 * 4) = iVar6;

          iVar8 = iVar8 + 1;

          iVar11 = iVar11 + 1;

          if (iVar7 < iVar8) goto LAB_00487ac2;

        }

        if (iVar4 != local_33c && -1 < iVar4 - local_33c) {

          if (iVar8 <= iVar7) {

            do {

              iVar6 = *(int *)(unaff_EDI + iVar7 * 4);

              iVar4 = *(int *)(param_3 + iVar6 * 4);

              if (iVar4 == local_33c) {

                *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar7 * 4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + local_330 * 4);

                *(int *)(unaff_EDI + local_330 * 4) = iVar6;

                local_330 = local_330 + -1;

              }

              else if (iVar4 - local_33c < 0) goto LAB_00487be9;

              iVar7 = iVar7 + -1;

              if (iVar7 < iVar8) break;

            } while( true );

          }

          break;

        }

      }

LAB_00487ac2:

      if (iVar11 <= local_330) {

        local_324[0] = iVar8 - iVar11;

        local_33c = iVar11 - iVar3;

        if (local_324[0] <= iVar11 - iVar3) {

          local_33c = local_324[0];

        }

        if (0 < local_33c) {

          puVar9 = (uint32_t /* width from decompiler */ *)(unaff_EDI + iVar3 * 4);

          puVar10 = (uint32_t /* width from decompiler */ *)(unaff_EDI + (iVar8 - local_33c) * 4);

          do {

            uVar5 = *puVar9;

            *puVar9 = *puVar10;

            *puVar10 = uVar5;

            puVar9 = puVar9 + 1;

            puVar10 = puVar10 + 1;

            local_33c = local_33c + -1;

          } while (local_33c != 0);

        }

        local_33c = local_330 - iVar7;

        if (iVar2 - local_330 < local_330 - iVar7) {

          local_33c = iVar2 - local_330;

        }

        if (0 < local_33c) {

          puVar9 = (uint32_t /* width from decompiler */ *)(unaff_EDI + iVar8 * 4);

          puVar10 = (uint32_t /* width from decompiler */ *)(unaff_EDI + 4 + (iVar2 - local_33c) * 4);

          do {

            uVar5 = *puVar9;

            *puVar9 = *puVar10;

            *puVar10 = uVar5;

            puVar9 = puVar9 + 1;

            puVar10 = puVar10 + 1;

            local_33c = local_33c + -1;

          } while (local_33c != 0);

        }

        iVar1 = local_324[0] + -1 + iVar3;

        iVar7 = (iVar7 - local_330) + 1 + iVar2;

        if (iVar2 - iVar7 < iVar1 - iVar3) {

          aiStack_194[local_334] = iVar1;

          local_324[local_334 + 1] = iVar7;

          aiStack_194[local_334 + 1] = iVar2;

          iVar1 = local_334 + 1;

        }

        else {

          local_324[local_334] = iVar7;

          local_324[local_334 + 1] = iVar3;

          aiStack_194[local_334 + 1] = iVar1;

          iVar1 = local_334 + 1;

        }

      }

    }

    local_334 = iVar1;

    if (local_334 < 1) {

      return;

    }

  } while( true );

LAB_00487be9:

  if (iVar7 < iVar8) goto LAB_00487ac2;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar8 * 4);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar8 * 4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar7 * 4);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + iVar7 * 4) = uVar5;

  iVar7 = iVar7 + -1;

  iVar8 = iVar8 + 1;

  goto LAB_00487a80;

}
