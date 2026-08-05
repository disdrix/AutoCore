// =============================================================================
// FUN_00716580
// -----------------------------------------------------------------------------
// Stable ID: aa_00716580
// Address:   0x00716580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716580 @ 0x00716580
// Stable ID: aa_00716580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00716580.
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

void FUN_00716580(uint *param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  

  uVar1 = ((int)*param_1 >> 0x10) * 0x41a7;

  uVar3 = (*param_1 & 0xffff) * 0x41a7 + (uVar1 & 0x7fff) * 0x10000;

  iVar2 = ((uVar1 >> 0xf) - ((int)uVar3 >> 0x1f)) + (uVar3 & 0x7fffffff);

  *param_1 = iVar2 - (iVar2 >> 0x1f) & 0x7fffffff;

  return;

}
