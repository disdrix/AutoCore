// =============================================================================
// FUN_0075ec90
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ec90
// Address:   0x0075ec90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075ec90 @ 0x0075ec90
// Stable ID: aa_0075ec90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0075ec90, FUN_00966d50.
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

byte FUN_0075ec90(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (DAT_00d1f614 != 0) {

    FUN_00966d50();

  }

  iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x44))((int *)*unaff_ESI,0,0,0,0);

  unaff_ESI[0x1eb] = unaff_ESI[0x1eb] + 1;

  if (iVar1 != -0x7789f798) {

    return (iVar1 != -0x7789f797) - 1U & 2;

  }

  return 1;

}
