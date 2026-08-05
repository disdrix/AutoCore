// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00487c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00487c80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00487c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "        bucket sorting ...\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "        bucket sorting ...\n"
//   - "        depth %6d has "
//   - "        reconstructing block ...\n"
//   - "

                  ,0x3ed,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~209 non-empty decompiler lines.
//  - Control keywords: if×20, while×17, do×9, for×3, return×2.
//  - Notable callees: fprintf×5, FUN_004879a0, FUN_00487c80, author, exit.
//  - Strings: "        bucket sorting ...\n"; "        depth %6d has "; "%6d unresolved strings\n"; "        reconstructing block ...\n".
//  - Return sites: 2.

                  ,0x3ed,"
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00487c80(int param_1,int param_2,int param_3,int param_4)



{

  uint uVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  int *piVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int local_820;

  int local_81c;

  int local_818 [517];

  

  if (3 < param_4) {

    fprintf((FILE *)(_iob_exref + 0x40),"        bucket sorting ...\n");

  }

  piVar9 = local_818 + 2;

  for (iVar5 = 0x101; iVar5 != 0; iVar5 = iVar5 + -1) {

    *piVar9 = 0;

    piVar9 = piVar9 + 1;

  }

  iVar5 = 0;

  if (0 < param_3) {

    do {

      local_818[*(byte *)(iVar5 + param_2) + 2] = local_818[*(byte *)(iVar5 + param_2) + 2] + 1;

      iVar5 = iVar5 + 1;

    } while (iVar5 < param_3);

  }

  piVar9 = local_818 + 2;

  piVar10 = local_818 + 0x104;

  for (iVar5 = 0x100; iVar5 != 0; iVar5 = iVar5 + -1) {

    *piVar10 = *piVar9;

    piVar9 = piVar9 + 1;

    piVar10 = piVar10 + 1;

  }

  iVar5 = 1;

  do {

    local_818[iVar5 + 2] = local_818[iVar5 + 2] + local_818[iVar5 + 1];

    local_818[iVar5 + 3] = local_818[iVar5 + 3] + local_818[iVar5 + 2];

    local_818[iVar5 + 4] = local_818[iVar5 + 4] + local_818[iVar5 + 3];

    local_818[iVar5 + 5] = local_818[iVar5 + 5] + local_818[iVar5 + 4];

    iVar5 = iVar5 + 4;

  } while (iVar5 < 0x101);

  iVar5 = 0;

  if (0 < param_3) {

    do {

      iVar6 = local_818[*(byte *)(iVar5 + param_2) + 2] + -1;

      local_818[*(byte *)(iVar5 + param_2) + 2] = iVar6;

      *(int *)(param_1 + iVar6 * 4) = iVar5;

      iVar5 = iVar5 + 1;

    } while (iVar5 < param_3);

  }

  iVar5 = ((int)(param_3 + (param_3 >> 0x1f & 0x1fU)) >> 5) + 2;

  puVar11 = in_EAX;

  if (0 < iVar5) {

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar11 = 0;

      puVar11 = puVar11 + 1;

    }

  }

  iVar5 = 0;

  do {

    iVar6 = local_818[iVar5 + 3];

    iVar3 = iVar5 + 4;

    in_EAX[local_818[iVar5 + 2] >> 5] =

         in_EAX[local_818[iVar5 + 2] >> 5] | 1 << ((byte)local_818[iVar5 + 2] & 0x1f);

    iVar7 = local_818[iVar3];

    in_EAX[iVar6 >> 5] = in_EAX[iVar6 >> 5] | 1 << ((byte)iVar6 & 0x1f);

    iVar5 = local_818[iVar5 + 5];

    in_EAX[iVar7 >> 5] = in_EAX[iVar7 >> 5] | 1 << ((byte)iVar7 & 0x1f);

    in_EAX[iVar5 >> 5] = in_EAX[iVar5 >> 5] | 1 << ((byte)iVar5 & 0x1f);

    iVar5 = iVar3;

  } while (iVar3 < 0x100);

  local_820 = 0x20;

  iVar5 = param_3;

  do {

    iVar7 = iVar5 >> 5;

    bVar2 = (byte)iVar5;

    iVar6 = iVar5 + 1;

    iVar5 = iVar5 + 2;

    in_EAX[iVar7] = in_EAX[iVar7] | 1 << (bVar2 & 0x1f);

    in_EAX[iVar6 >> 5] = in_EAX[iVar6 >> 5] & ~(1 << ((byte)iVar6 & 0x1f));

    local_820 = local_820 + -1;

  } while (local_820 != 0);

  local_820 = 1;

  do {

    if (3 < param_4) {

      fprintf((FILE *)(_iob_exref + 0x40),"        depth %6d has ",local_820);

    }

    iVar5 = 0;

    iVar6 = 0;

    if (0 < param_3) {

      do {

        if ((in_EAX[iVar6 >> 5] & 1 << ((byte)iVar6 & 0x1f)) != 0) {

          iVar5 = iVar6;

        }

        iVar7 = *(int *)(param_1 + iVar6 * 4) - local_820;

        if (iVar7 < 0) {

          iVar7 = iVar7 + param_3;

        }

        iVar6 = iVar6 + 1;

        *(int *)(param_2 + iVar7 * 4) = iVar5;

      } while (iVar6 < param_3);

    }

    local_81c = 0;

    iVar5 = -1;

    while( true ) {

      uVar4 = iVar5 + 1;

      uVar8 = uVar4 & 0x1f;

      uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << (sbyte)uVar8;

      while ((uVar1 != 0 && (uVar8 != 0))) {

        uVar4 = uVar4 + 1;

        uVar8 = uVar4 & 0x1f;

        uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << (sbyte)uVar8;

      }

      uVar1 = in_EAX[(int)uVar4 >> 5];

      if ((uVar1 & 1 << ((byte)uVar4 & 0x1f)) != 0) {

        while (uVar1 == 0xffffffff) {

          uVar4 = uVar4 + 0x20;

          uVar1 = in_EAX[(int)uVar4 >> 5];

        }

        uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << ((byte)uVar4 & 0x1f);

        while (uVar1 != 0) {

          uVar4 = uVar4 + 1;

          uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << ((byte)uVar4 & 0x1f);

        }

      }

      local_818[0] = uVar4 - 1;

      if (param_3 <= local_818[0]) break;

      uVar8 = uVar4 & 0x1f;

      uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << (sbyte)uVar8;

      while ((uVar1 == 0 && (uVar8 != 0))) {

        uVar4 = uVar4 + 1;

        uVar8 = uVar4 & 0x1f;

        uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << (sbyte)uVar8;

      }

      uVar1 = in_EAX[(int)uVar4 >> 5];

      if ((uVar1 & 1 << ((byte)uVar4 & 0x1f)) == 0) {

        while (uVar1 == 0) {

          uVar4 = uVar4 + 0x20;

          uVar1 = in_EAX[(int)uVar4 >> 5];

        }

        uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << ((byte)uVar4 & 0x1f);

        while (uVar1 == 0) {

          uVar4 = uVar4 + 1;

          uVar1 = in_EAX[(int)uVar4 >> 5] & 1 << ((byte)uVar4 & 0x1f);

        }

      }

      iVar5 = uVar4 - 1;

      local_818[1] = iVar5;

      if (param_3 <= iVar5) break;

      if (local_818[0] < iVar5) {

        local_81c = local_81c + 1 + (iVar5 - local_818[0]);

        FUN_004879a0(param_2);

        iVar6 = -1;

        if (local_818[0] <= iVar5) {

          do {

            iVar7 = *(int *)(param_2 + *(int *)(param_1 + local_818[0] * 4) * 4);

            if (iVar6 != iVar7) {

              in_EAX[local_818[0] >> 5] =

                   in_EAX[local_818[0] >> 5] | 1 << ((byte)local_818[0] & 0x1f);

              iVar6 = iVar7;

              iVar5 = local_818[1];

            }

            local_818[0] = local_818[0] + 1;

          } while (local_818[0] <= iVar5);

        }

      }

    }

    if (3 < param_4) {

      fprintf((FILE *)(_iob_exref + 0x40),"%6d unresolved strings\n",local_81c);

    }

    local_820 = local_820 * 2;

    if ((param_3 < local_820) || (local_81c == 0)) {

      if (3 < param_4) {

        fprintf((FILE *)(_iob_exref + 0x40),"        reconstructing block ...\n");

      }

      iVar5 = 0;

      iVar6 = 0;

      if (0 < param_3) {

        piVar9 = local_818 + 0x104;

        do {

          iVar7 = *piVar9;

          while (iVar7 == 0) {

            iVar7 = local_818[iVar5 + 0x105];

            iVar5 = iVar5 + 1;

          }

          iVar7 = *(int *)(param_1 + iVar6 * 4);

          local_818[iVar5 + 0x104] = local_818[iVar5 + 0x104] + -1;

          piVar9 = local_818 + iVar5 + 0x104;

          iVar6 = iVar6 + 1;

          *(char *)(param_2 + iVar7) = (char)iVar5;

        } while (iVar6 < param_3);

        if (0xff < iVar5) {

          fprintf((FILE *)(_iob_exref + 0x40),

                  "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"

                  ,0x3ed,"1.0.2, 30-Dec-2001");

                    /* WARNING: Subroutine does not return */

          exit(3);

        }

      }

      return;

    }

  } while( true );

}
