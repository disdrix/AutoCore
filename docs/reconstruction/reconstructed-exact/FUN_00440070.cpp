// =============================================================================
// FUN_00440070
// -----------------------------------------------------------------------------
// Stable ID: aa_00440070
// Address:   0x00440070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00440070 @ 0x00440070
// Stable ID: aa_00440070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00440070, ROUND, floor.
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

int FUN_00440070(float param_1)



{

  uint uVar1;

  uint uVar2;

  double dVar3;

  

  dVar3 = floor((double)param_1);

  uVar2 = -((uint)(float)dVar3 >> 0x17 & 0xff);

  uVar1 = -(uint)(0xffffff69 < uVar2);

  return (int)ROUND((float)((uint)(float)dVar3 & (uVar1 << ((char)uVar2 + 0x96U & 0x1f) | ~uVar1)));

}
