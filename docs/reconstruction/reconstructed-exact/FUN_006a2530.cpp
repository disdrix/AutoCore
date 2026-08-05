// =============================================================================
// FUN_006a2530
// -----------------------------------------------------------------------------
// Stable ID: aa_006a2530
// Address:   0x006a2530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a2530 @ 0x006a2530
// Stable ID: aa_006a2530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006a2530, block.
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

/* WARNING: Removing unreachable block (ram,0x006a2563) */



void __thiscall FUN_006a2530(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  

  fVar1 = (float)*(byte *)(param_1 + 0x16) * DAT_00aaa7a8;

  fVar2 = (float)*(byte *)(param_1 + 0x15) * DAT_00aaa7a8;

  *param_2 = (float)(*(uint *)(param_1 + 0x14) & 0xff) * DAT_00aaa7a8;

  param_2[1] = fVar2;

  param_2[2] = fVar1;

  return;

}
