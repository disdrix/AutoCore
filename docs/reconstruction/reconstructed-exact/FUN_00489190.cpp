// =============================================================================
// FUN_00489190
// -----------------------------------------------------------------------------
// Stable ID: aa_00489190
// Address:   0x00489190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00489190 @ 0x00489190
// Stable ID: aa_00489190
// Embedded strings (evidence for future rename):
//   - "      %d work, %d block, ratio %5.2f\n"
//   - "    too repetitive; using fallback sorting algorithm\n"
//   - "

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, goto×1, do×1, while×1.
//  - Notable callees: fprintf×3, CONCAT44, FUN_00487c80, FUN_00488a40, FUN_00489190, author, exit.
//  - Strings: "      %d work, %d block, ratio %5.2f\n"; "    too repetitive; using fallback sorting algorithm\n"; "

          ,0x3eb,".
//  - Return sites: 2.

          ,0x3eb,"
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

void FUN_00489190(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar7;

  int local_10;

  

  iVar1 = *(int *)(unaff_ESI + 0x20);

  iVar5 = *(int *)(unaff_ESI + 0x268);

  iVar2 = *(int *)(unaff_ESI + 0x44);

  iVar4 = *(int *)(unaff_ESI + 0x30);

  if (iVar2 < 10000) {

    uVar3 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14);

    uVar7 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

  }

  else {

    uVar6 = iVar2 + 0x22;

    if ((uVar6 & 1) != 0) {

      uVar6 = iVar2 + 0x23;

    }

    if (iVar4 < 1) {

      iVar4 = 1;

    }

    else if (100 < iVar4) {

      iVar4 = 100;

    }

    FUN_00488a40(iVar1,*(int *)(unaff_ESI + 0x24),uVar6 + *(int *)(unaff_ESI + 0x24),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),iVar2,iVar5);

    if (2 < iVar5) {

      local_10 = 1;

      if (iVar2 != 0) {

        local_10 = iVar2;

      }

      fprintf((FILE *)(_iob_exref + 0x40),"      %d work, %d block, ratio %5.2f\n",0,iVar2,

              0.0 / (double)local_10);

    }

    if (-1 < ((iVar4 + -1) / 3) * iVar2) goto LAB_004892ac;

    if (1 < iVar5) {

      fprintf((FILE *)(_iob_exref + 0x40),"    too repetitive; using fallback sorting algorithm\n");

    }

    uVar3 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14);

    uVar7 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

  }

  FUN_00487c80(uVar7,CONCAT44(iVar2,uVar3),iVar5);

LAB_004892ac:

  iVar5 = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0xffffffff;

  if (0 < *(int *)(unaff_ESI + 0x44)) {

    do {

      if (*(int *)(iVar1 + iVar5 * 4) == 0) {

        *(int *)(unaff_ESI + 0x1c) = iVar5;

        break;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(unaff_ESI + 0x44));

  }

  if (*(int *)(unaff_ESI + 0x1c) != -1) {

    return;

  }

  fprintf((FILE *)(_iob_exref + 0x40),

          "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"

          ,0x3eb,"1.0.2, 30-Dec-2001");

                    /* WARNING: Subroutine does not return */

  exit(3);

}
