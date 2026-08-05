// =============================================================================
// FUN_005cb190
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb190
// Address:   0x005cb190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb190 @ 0x005cb190
// Stable ID: aa_005cb190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005c9800, FUN_005c9870, FUN_005cad30, FUN_005cadd0, FUN_005cb190.
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

void __fastcall FUN_005cb190(int param_1)



{

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = 0;

  local_4 = 0;

  FUN_005c9800(&local_8);

  FUN_005c9870(&local_4);

  FUN_005cad30(local_8,1);

  FUN_005cadd0(local_4,1);

  *(uint8_t *)(param_1 + -0x1b) = 0;

  return;

}
