// =============================================================================
// FUN_00711e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00711e60
// Address:   0x00711e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711e60 @ 0x00711e60
// Stable ID: aa_00711e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00711e60.
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

int FUN_00711e60(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = (param_1 + -0xe) / 0xc;

  param_3 = iVar3 + param_3;

  iVar1 = ((param_3 + 0x1324) / 100) * 3;

  iVar2 = (param_3 * 0x1e7 + 0x23ab40) * 3;

  return ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) + -0x7d4b +

         param_2 + (((param_1 + iVar3 * -0xc + -2) * 0x16f) / 0xc -

                   ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2));

}
