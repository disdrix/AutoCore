// =============================================================================
// FUN_0047cc90
// -----------------------------------------------------------------------------
// Stable ID: aa_0047cc90
// Address:   0x0047cc90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047cc90 @ 0x0047cc90
// Stable ID: aa_0047cc90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00476e50, FUN_0047cc90.
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

void __fastcall FUN_0047cc90(byte *param_1)



{

  byte bVar1;

  

  bVar1 = *param_1;

  if (((((((0x40 < bVar1) && (bVar1 < 0x7b)) && ((bVar1 < 0x5b || (0x60 < bVar1)))) &&

        ((bVar1 = param_1[1], 0x40 < bVar1 && (bVar1 < 0x7b)))) &&

       ((bVar1 < 0x5b || (0x60 < bVar1)))) &&

      ((((bVar1 = param_1[2], 0x40 < bVar1 && (bVar1 < 0x7b)) && ((bVar1 < 0x5b || (0x60 < bVar1))))

       && ((bVar1 = param_1[3], 0x40 < bVar1 && (bVar1 < 0x7b)))))) &&

     ((bVar1 < 0x5b || (0x60 < bVar1)))) {

    return;

  }

  FUN_00476e50();

  return;

}
