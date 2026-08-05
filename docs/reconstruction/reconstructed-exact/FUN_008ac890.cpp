// =============================================================================
// FUN_008ac890
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac890
// Address:   0x008ac890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ac890 @ 0x008ac890
// Stable ID: aa_008ac890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008ac110, FUN_008ac890.
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

void __fastcall FUN_008ac890(int param_1)



{

  int in_EAX;

  

  *(int *)(param_1 + 0x510) = in_EAX;

  if (8 < in_EAX) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 8;

  }

  FUN_008ac110();

  return;

}
