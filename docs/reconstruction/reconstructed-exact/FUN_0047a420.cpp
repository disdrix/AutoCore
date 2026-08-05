// =============================================================================
// FUN_0047a420
// -----------------------------------------------------------------------------
// Stable ID: aa_0047a420
// Address:   0x0047a420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047a420 @ 0x0047a420
// Stable ID: aa_0047a420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, goto×1.
//  - Notable callees: FUN_0046d130, FUN_00476cc0, FUN_0047a420.
//  - Return sites: 4.

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

void FUN_0047a420(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  if (*(code **)(unaff_ESI + 0x50) == (code *)0x0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  (**(code **)(unaff_ESI + 0x50))();

  if ((*(byte *)(unaff_ESI + 0x11c) & 0x20) == 0) {

    if ((*(byte *)(unaff_ESI + 0x6d) & 8) == 0) goto LAB_0047a44e;

  }

  else if ((*(uint *)(unaff_ESI + 0x6c) & 0x300) != 0x300) {

LAB_0047a44e:

    if (unaff_EDI == 0) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x110) = 0;

      return;

    }

    uVar1 = FUN_0046d130();

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x110) = uVar1;

    return;

  }

  return;

}
