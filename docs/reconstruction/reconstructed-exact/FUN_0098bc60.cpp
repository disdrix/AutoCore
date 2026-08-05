// =============================================================================
// FUN_0098bc60
// -----------------------------------------------------------------------------
// Stable ID: aa_0098bc60
// Address:   0x0098bc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098bc60 @ 0x0098bc60
// Stable ID: aa_0098bc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0077a9d0, FUN_0077dcb0, FUN_0077f960, FUN_0077fb80, FUN_0098bc60.
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

bool FUN_0098bc60(int param_1)



{

  int unaff_ESI;

  int unaff_EDI;

  int local_134;

  uint8_t local_130 [32];

  uint8_t local_110 [272];

  

  FUN_0077dcb0(local_110);

  FUN_0077fb80(local_110,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10));

  FUN_0077f960(local_110,local_130);

  FUN_0077a9d0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),local_130,0x20,&local_134,

               *(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  return local_134 != 0;

}
