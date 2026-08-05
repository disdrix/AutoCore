// =============================================================================
// FUN_00996f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00996f40
// Address:   0x00996f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00996f40 @ 0x00996f40
// Stable ID: aa_00996f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: BitStream_writeBits×2, FUN_00996f40.
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

void FUN_00996f40(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int *piVar1;

  

  piVar1 = param_2;

  param_2 = *(int **)(*param_2 + 0x10);

  BitStream_writeBits(10,&param_2);

  BitStream_writeBits(*(int *)(*piVar1 + 0x10) * 8,*(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc));

  return;

}
