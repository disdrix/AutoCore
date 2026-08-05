// =============================================================================
// FUN_00906dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00906dd0
// Address:   0x00906dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00906dd0 @ 0x00906dd0
// Stable ID: aa_00906dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×11, if×2, do×1, switch×1, while×1.
//  - Notable callees: FUN_00906dd0.
//  - Return sites: 11.

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

uint32_t /* width from decompiler */ FUN_00906dd0(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x7dc) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x7dc) + 0x464))();

    iVar2 = 0;

    piVar3 = (int *)(unaff_ESI + 0x720);

    do {

      if (iVar1 == *piVar3) {

        switch(iVar2) {

        case 0:

          return 0xc;

        case 1:

          return 0x1c;

        case 2:

          return 0x10;

        case 3:

          return 6;

        case 4:

          return 8;

        case 5:

          return 10;

        case 6:

          return 0xe;

        case 7:

          return 0x1a;

        case 8:

          return 0x32;

        default:

          return 0xff;

        }

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < 10);

  }

  return 0xff;

}
