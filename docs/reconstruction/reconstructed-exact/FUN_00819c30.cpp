// =============================================================================
// FUN_00819c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00819c30
// Address:   0x00819c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00819c30 @ 0x00819c30
// Stable ID: aa_00819c30
// Embedded strings (evidence for future rename):
//   - "%dx%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify×2, FUN_00418000×2, sprintf×2, FUN_00410420, FUN_00418060, FUN_00794090, FUN_00819c30.
//  - Strings: "%dx%d".
//  - Return sites: 1.

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

void FUN_00819c30(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ in_stack_fffffed8;

  uint32_t /* width from decompiler */ in_stack_fffffedc;

  uint32_t /* width from decompiler */ uStack_110;

  int iStack_10c;

  int iStack_108;

  char acStack_104 [260];

  

  if (unaff_EDI != (int *)0x0) {

    (**(code **)(*unaff_EDI + 0x74))(0x9c46);

    if (unaff_EDI[0x24c] != 0) {

      FUN_00794090();

    }

    FUN_00418060(in_stack_fffffed8,in_stack_fffffedc);

    FUN_00410420(0,0);

    sprintf(acStack_104,"%dx%d",DAT_00d1b258,DAT_00d1b25c);

    iStack_10c = DAT_00d1b258;

    iStack_108 = DAT_00d1b25c;

    FUN_00418000();

    (**(code **)(*unaff_EDI + 0x448))(acStack_104);

    CVOGReaction_FailMissionNotify(&stack0xfffffee8);

    iVar1 = *(int *)(DAT_00d1f058 + 0x24);

    if (-1 < iVar1) {

      iVar4 = *(int *)(DAT_00d1f058 + 0x14);

      if (iVar4 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(DAT_00d1f058 + 0x18) - iVar4 >> 2;

      }

      if (((iVar1 < iVar3) && (iVar1 = *(int *)(iVar4 + iVar1 * 4), iVar1 != 0)) &&

         (iVar4 = *(int *)(iVar1 + 0x710), iVar4 != *(int *)(iVar1 + 0x714))) {

        do {

          iVar3 = *(int *)(iVar4 + 4);

          if (((799 < iVar3) && (iVar2 = *(int *)(iVar4 + 8), 599 < iVar2)) &&

             ((iVar3 != DAT_00d1b258 || (iVar2 != DAT_00d1b25c)))) {

            sprintf((char *)&iStack_108,"%dx%d",iVar3,iVar2);

            FUN_00418000();

            uStack_110 = (**(code **)(*unaff_EDI + 0x448))(&iStack_108);

            CVOGReaction_FailMissionNotify(&uStack_110);

          }

          iVar4 = iVar4 + 0x24;

        } while (iVar4 != *(int *)(iVar1 + 0x714));

      }

    }

  }

  return;

}
