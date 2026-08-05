// =============================================================================
// FUN_00834ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00834ad0
// Address:   0x00834ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00834ad0 @ 0x00834ad0
// Stable ID: aa_00834ad0
// Embedded strings (evidence for future rename):
//   - "%s 00:00:00"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a5160, FUN_00834ad0, sprintf.
//  - Strings: "%s 00:00:00".
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

void FUN_00834ad0(void)



{

  int *unaff_ESI;

  char local_100 [256];

  

  sprintf(local_100,"%s 00:00:00",unaff_ESI[0x125] + 0x1d);

  (**(code **)(*unaff_ESI + 0x1d8))(local_100,1,1);

  (**(code **)(*unaff_ESI + 0xfc))(0,0x40a00000);

  if (unaff_ESI[0x125] != 0) {

    FUN_005a5160();

  }

  *(uint8_t *)(unaff_ESI + 0x124) = 1;

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
