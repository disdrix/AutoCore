// =============================================================================
// FUN_0075ed60
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ed60
// Address:   0x0075ed60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075ed60 @ 0x0075ed60
// Stable ID: aa_0075ed60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0073ba70, FUN_0073daa0, FUN_0075ed60, FUN_00966fe0, FUN_0096e670, FUN_00985460, FUN_00985fe0, FUN_009863c0.
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

void FUN_0075ed60(void)



{

  int unaff_ESI;

  

  FUN_00985fe0();

  FUN_00966fe0();

  FUN_0073daa0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x764));

  FUN_009863c0();

  FUN_00985460();

  FUN_0073ba70();

  FUN_0096e670();

  return;

}
