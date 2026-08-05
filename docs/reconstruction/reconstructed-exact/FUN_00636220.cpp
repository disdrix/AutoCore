// =============================================================================
// FUN_00636220
// -----------------------------------------------------------------------------
// Stable ID: aa_00636220
// Address:   0x00636220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636220 @ 0x00636220
// Stable ID: aa_00636220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00507290, FUN_00636220, FUN_00651fa0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00636220(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int iVar1;

  

  FUN_00651fa0(param_2);

  *param_1 = &PTR_FUN_009e39f4;

  param_1[2] = &PTR_LAB_009e5e78;

  iVar1 = *(int *)(param_2 + 4);

  param_1[6] = iVar1;

  if (iVar1 != 0) {

    FUN_00507290(param_1);

    *(short *)(param_1[6] + 6) = *(short *)(param_1[6] + 6) + 1;

  }

  return param_1;

}
