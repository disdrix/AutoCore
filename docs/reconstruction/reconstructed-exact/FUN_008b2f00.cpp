// =============================================================================
// FUN_008b2f00
// -----------------------------------------------------------------------------
// Stable ID: aa_008b2f00
// Address:   0x008b2f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b2f00 @ 0x008b2f00
// Stable ID: aa_008b2f00
// Embedded strings (evidence for future rename):
//   - "You do not have anything memorized!"
//   - "The following items are memorized"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, return×2, while×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00522000, FUN_008b2f00.
//  - Strings: "You do not have anything memorized!"; "The following items are memorized".
//  - Return sites: 2.

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

void FUN_008b2f00(void)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int unaff_ESI;

  

  uVar6 = 0;

  if (*(int *)(unaff_ESI + 0x560) != 0) {

    *(uint16_t *)(unaff_ESI + 0x6b0) = 0;

    if ((((DAT_00d1b6d8 != 0) && (iVar3 = FUN_00522000(), DAT_00d1b6d8 != 0)) &&

        (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) != 0)) &&

       (iVar5 = DAT_00d1b6d8, 0 < iVar3)) {

      do {

        uVar1 = *(uint *)(iVar5 + 0x5a0 + (uVar6 & 0xff) * 8);

        uVar2 = *(uint *)(iVar5 + 0x5a4 + (uVar6 & 0xff) * 8);

        if (((uVar1 & uVar2) != 0xffffffff) &&

           (iVar4 = CVOGReaction_ResolveObjectTarget(1,uVar1,uVar2), iVar5 = DAT_00d1b6d8,

           iVar4 != 0)) {

          *(short *)(unaff_ESI + 0x6b0) = *(short *)(unaff_ESI + 0x6b0) + 1;

          iVar5 = DAT_00d1b6d8;

        }

        uVar6 = uVar6 + 1;

      } while ((int)uVar6 < iVar3);

    }

    if (*(short *)(unaff_ESI + 0x6b0) == 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x1d8))

                ("You do not have anything memorized!",1,1);

    }

    else {

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x1d8))("The following items are memorized");

    }

    (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x34c))();

    if (*(int **)(unaff_ESI + 0x6b4) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6b4) + 0xcc))(1);

      (**(code **)(**(int **)(unaff_ESI + 0x6b4) + 0xd4))(1);

      (**(code **)(**(int **)(unaff_ESI + 0x6b4) + 0x460))(0x3eaaaaab);

      (**(code **)(**(int **)(unaff_ESI + 0x6b4) + 0x454))

                ((float)*(int *)(unaff_ESI + 0x6ac) * g_flDisplayRateScaleOneThird,0);

                    /* WARNING: Could not recover jumptable at 0x008b3039. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x6b4) + 0x34c))();

      return;

    }

  }

  return;

}
