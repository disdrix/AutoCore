// =============================================================================
// FUN_00427980
// -----------------------------------------------------------------------------
// Stable ID: aa_00427980
// Address:   0x00427980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00427980 @ 0x00427980
// Stable ID: aa_00427980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00426f80, FUN_00427980.
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

int __fastcall FUN_00427980(int param_1)



{

  int in_EAX;

  int unaff_EBX;

  

  for (; in_EAX != unaff_EBX; in_EAX = in_EAX + 0x60) {

    FUN_00426f80();

    param_1 = param_1 + 0x60;

  }

  return param_1;

}
