// =============================================================================
// FUN_007776f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007776f0
// Address:   0x007776f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007776f0 @ 0x007776f0
// Stable ID: aa_007776f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00770440, FUN_007707a0, FUN_007707d0, FUN_007772e0, FUN_007776f0.
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

int FUN_007776f0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int *unaff_EDI;

  

  *param_1 = 0;

  if ((unaff_EDI[2] != 1) && ((1 < *unaff_EDI || (1 < *(uint *)unaff_EDI[3])))) {

    iVar1 = FUN_00770440();

    if (iVar1 == 0) {

      iVar1 = FUN_007772e0();

      if (iVar1 == 0) {

        iVar1 = FUN_007707a0();

        if (iVar1 == 0) {

          *param_1 = 1;

        }

        iVar1 = 0;

      }

      FUN_007707d0();

    }

    return iVar1;

  }

  return -3;

}
