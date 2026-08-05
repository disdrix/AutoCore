// =============================================================================
// FUN_00804e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00804e00
// Address:   0x00804e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804e00 @ 0x00804e00
// Stable ID: aa_00804e00
// Embedded strings (evidence for future rename):
//   - "Button 0x%x released\n"
//   - "Button 0x%x pressed\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007a4480×2, FUN_00804e00.
//  - Strings: "Button 0x%x released\n"; "Button 0x%x pressed\n".
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

void FUN_00804e00(void)



{

  uint unaff_EBX;

  int *unaff_ESI;

  uint unaff_EDI;

  

  if ((unaff_ESI[0x26] & unaff_EDI) != 0) {

    if ((unaff_EDI & unaff_EBX) == 0) {

      FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"Button 0x%x released\n");

      (**(code **)(*unaff_ESI + 0x78))();

    }

    if ((unaff_ESI[0x26] & unaff_EDI) != 0) {

      return;

    }

  }

  if ((unaff_EDI & unaff_EBX) != 0) {

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"Button 0x%x pressed\n");

    (**(code **)(*unaff_ESI + 0x74))();

  }

  return;

}
