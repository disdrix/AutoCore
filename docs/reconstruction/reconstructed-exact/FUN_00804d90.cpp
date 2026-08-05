// =============================================================================
// FUN_00804d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00804d90
// Address:   0x00804d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804d90 @ 0x00804d90
// Stable ID: aa_00804d90
// Embedded strings (evidence for future rename):
//   - "lgLcdAPI returned with other error (0x%08x) closing device and connection\n"
//   - "lgLcdAPI returned with ERROR_DEVICE_NOT_CONNECTED, closing device\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a4480×2, FUN_00804d90, error.
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

void FUN_00804d90(void)



{

  int in_EAX;

  int *unaff_ESI;

  

  if (in_EAX != 0) {

    if (in_EAX != 0x48f) {

      FUN_007a4480(0xffffffff,&DAT_00a2c2a4,

                   "lgLcdAPI returned with other error (0x%08x) closing device and connection\n");

      (**(code **)(*unaff_ESI + 0x84))(unaff_ESI[0x22]);

      (**(code **)(*unaff_ESI + 0x88))(unaff_ESI[0x21]);

      return;

    }

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,

                 "lgLcdAPI returned with ERROR_DEVICE_NOT_CONNECTED, closing device\n");

    (**(code **)(*unaff_ESI + 0x84))(unaff_ESI[0x22]);

  }

  return;

}
