// =============================================================================
// FUN_008bb180
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb180
// Address:   0x008bb180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bb180 @ 0x008bb180
// Stable ID: aa_008bb180
// Embedded strings (evidence for future rename):
//   - "Loading information from satellite..."
//   - "Fetching details..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_008bb180.
//  - Strings: "Loading information from satellite..."; "Fetching details...".
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

void FUN_008bb180(void)



{

  int *unaff_ESI;

  

  if (unaff_ESI[0x15e] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x15e] + 0x1d8))("Loading information from satellite...",1,1);

  }

  if (unaff_ESI[0x15f] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x15f] + 0x1d8))("Fetching details...",1,1);

  }

  if (unaff_ESI[0x160] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x160] + 0x1d8))("Fetching details...",1,1);

  }

  if (unaff_ESI[0x161] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x161] + 0x1d8))("Fetching details...",1,1);

  }

  if (unaff_ESI[0x164] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x164] + 0x3ac))(0);

  }

                    /* WARNING: Could not recover jumptable at 0x008bb21d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
