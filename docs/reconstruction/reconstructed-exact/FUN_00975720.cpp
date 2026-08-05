// =============================================================================
// FUN_00975720
// -----------------------------------------------------------------------------
// Stable ID: aa_00975720
// Address:   0x00975720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00975720 @ 0x00975720
// Stable ID: aa_00975720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: BitStream_writeBits, FUN_00426a90, FUN_00975720.
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

void __thiscall FUN_00975720(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  FUN_00426a90(param_2);

  iVar1 = (**(code **)(*param_1 + 0x50))();

  param_2 = *(uint32_t /* width from decompiler */ *)(&DAT_00d1ea20 + iVar1 * 0x24);

  BitStream_writeBits(0x20,&param_2);

  return;

}
