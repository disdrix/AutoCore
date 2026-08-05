// =============================================================================
// FUN_008b5680
// -----------------------------------------------------------------------------
// Stable ID: aa_008b5680
// Address:   0x008b5680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b5680 @ 0x008b5680
// Stable ID: aa_008b5680
// Embedded strings (evidence for future rename):
//   - "Item still loading, please wait a moment and try again."
//   - "Item does not fit in your cargo.  Clear more room and try again."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_005714e0, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_008b5680, FUN_00980510.
//  - Strings: "Item still loading, please wait a moment and try again.".
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

uint32_t /* width from decompiler */ FUN_008b5680(void)



{

  uint uVar1;

  uint uVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_ESI;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ extraout_var;

  

  uVar1 = *(uint *)(unaff_ESI + 0x510);

  uVar2 = *(uint *)(unaff_ESI + 0x514);

  if (((((uVar1 & uVar2) != 0xffffffff) || (0 < *(int *)(unaff_ESI + 0x524))) ||

      ((-1 < *(int *)(unaff_ESI + 0x524) && (*(int *)(unaff_ESI + 0x520) != 0)))) &&

     (((DAT_00d1b6d8 != 0 && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

      (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0)))) {

    if ((uVar1 & uVar2) == 0xffffffff) {

LAB_008b5762:

      FUN_00980510(DAT_00d1ad2c,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x518),

                   *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x51c));

      return 1;

    }

    iVar4 = CVOGReaction_ResolveObjectTarget(1,uVar1,uVar2);

    uVar5 = extraout_var;

    if (iVar4 == 0) {

      pcVar6 = "Item still loading, please wait a moment and try again.";

    }

    else {

      cVar3 = FUN_005714e0(iVar4,&stack0xffffffff,&stack0xfffffffe,1,0xffffffff);

      if (cVar3 != '\0') goto LAB_008b5762;

      pcVar6 = "Item does not fit in your cargo.  Clear more room and try again.";

    }

    uVar10 = 0;

    uVar9 = 1;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    FUN_007a69d0(pcVar6,0xffffffff,0xffffffff,1,0,uVar5);

    uVar5 = FUN_007a6de0(pcVar6,uVar7);

    FUN_007fdfb0(&DAT_00d1a840,uVar5,uVar8,uVar9,uVar10);

  }

  return 0;

}
