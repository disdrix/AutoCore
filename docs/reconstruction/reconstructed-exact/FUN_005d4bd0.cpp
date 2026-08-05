// =============================================================================
// FUN_005d4bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4bd0
// Address:   0x005d4bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4bd0 @ 0x005d4bd0
// Stable ID: aa_005d4bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31, FUN_005d4bd0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_005d4bd0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + -0xd8);

  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x40) != '\0')) {

    return CONCAT31((int3)((uint)iVar1 >> 8),1);

  }

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c);

  if (((*(byte *)(iVar1 + 0x3f2) >> 1 & 1) == 0) && (*(float *)(iVar1 + 0x3e4) != g_flZero)) {

    return 0;

  }

  return 1;

}
