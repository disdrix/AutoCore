// =============================================================================
// FUN_004190b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004190b0
// Address:   0x004190b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004190b0 @ 0x004190b0
// Stable ID: aa_004190b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004190b0, memmove.
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

void * FUN_004190b0(void *param_1,int param_2,void *param_3)



{

  size_t _Size;

  void *pvVar1;

  

  _Size = (param_2 - (int)param_1 >> 3) * 8;

  pvVar1 = memmove(param_3,param_1,_Size);

  return (void *)((int)pvVar1 + _Size);

}
