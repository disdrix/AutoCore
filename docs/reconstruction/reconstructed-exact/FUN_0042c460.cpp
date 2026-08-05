// =============================================================================
// FUN_0042c460
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c460
// Address:   0x0042c460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c460 @ 0x0042c460
// Stable ID: aa_0042c460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0077fb80×3, FUN_0042c460, FUN_0077dcb0, FUN_0077f960.
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

uint32_t /* width from decompiler */ FUN_0042c460(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ local_130 [8];

  uint8_t local_110 [272];

  

  FUN_0077dcb0(local_110);

  FUN_0077fb80(local_110,param_2,0x14);

  FUN_0077fb80(local_110,param_3,8);

  FUN_0077fb80(local_110,param_1 + 0x84,0xc);

  FUN_0077f960(local_110,local_130);

  return local_130[0];

}
