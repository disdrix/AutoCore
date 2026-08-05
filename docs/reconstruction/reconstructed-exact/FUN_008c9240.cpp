// =============================================================================
// FUN_008c9240
// -----------------------------------------------------------------------------
// Stable ID: aa_008c9240
// Address:   0x008c9240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c9240 @ 0x008c9240
// Stable ID: aa_008c9240
// Embedded strings (evidence for future rename):
//   - "You need to input a password!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_008c9240.
//  - Strings: "You need to input a password!".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_008c9240(void)



{

  int iVar1;

  char *pcVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if (*(int *)(unaff_ESI + 0x594) != 0) {

    if (DAT_00d1a8e6 != '\0') {

      return 1;

    }

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x1dc))();

    if ((iVar1 != 0) &&

       (pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x594) + 0x1dc))(), *pcVar2 != '\0')) {

      return 1;

    }

    uVar6 = 0;

    uVar5 = 1;

    uVar4 = 0xffffffff;

    uVar3 = 0xffffffff;

    pcVar2 = "You need to input a password!";

    FUN_007a69d0("You need to input a password!",0xffffffff,0xffffffff,1,0);

    uVar3 = FUN_007a6de0(pcVar2,uVar3);

    FUN_007fdfb0(&DAT_00d1a840,uVar3,uVar4,uVar5,uVar6);

  }

  return 0;

}
