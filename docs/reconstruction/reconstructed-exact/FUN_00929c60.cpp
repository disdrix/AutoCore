// =============================================================================
// FUN_00929c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00929c60
// Address:   0x00929c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00929c60 @ 0x00929c60
// Stable ID: aa_00929c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CVOGCharacter_WeaponAllowsKillXpBonus, FUN_00929c60.
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

uint32_t /* width from decompiler */ FUN_00929c60(uint32_t /* width from decompiler */ param_1,float param_2)



{

  char cVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  if ((((unaff_ESI != 0) && (-1 < unaff_EDI)) && (unaff_EDI < 0xc)) &&

     (*(char *)(unaff_ESI + 0x1aa + unaff_EDI) == '\0')) {

    if (DAT_00aaa880 <= param_2) {

      return 1;

    }

    cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus();

    if (cVar1 != '\0') {

      if (*(float *)(unaff_ESI + 0x84) == DAT_00aaa668) {

        *(uint8_t *)(unaff_ESI + 0x1aa + unaff_EDI) = 1;

      }

    }

  }

  return 0;

}
