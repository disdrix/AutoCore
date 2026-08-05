// =============================================================================
// FUN_00907dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00907dc0
// Address:   0x00907dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907dc0 @ 0x00907dc0
// Stable ID: aa_00907dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00907dc0.
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

char FUN_00907dc0(void)



{

  char cVar1;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if ((((cVar1 != '\0') && (unaff_ESI[0x1b1] != 0)) && (unaff_ESI[0x1b0] != 0)) &&

     (unaff_ESI[0x1af] != 0)) {

    cVar1 = (**(code **)(*(int *)unaff_ESI[0x1b1] + 0x3bc))();

    if (cVar1 != '\0') {

      return '\x02';

    }

    cVar1 = (**(code **)(*(int *)unaff_ESI[0x1b0] + 0x3bc))();

    if (cVar1 == '\0') {

      cVar1 = (**(code **)(*(int *)unaff_ESI[0x1af] + 0x3bc))();

      return (-(cVar1 != '\0') & 8U) + 4;

    }

  }

  return '\x04';

}
