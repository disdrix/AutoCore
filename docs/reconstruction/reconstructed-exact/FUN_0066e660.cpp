// =============================================================================
// FUN_0066e660
// -----------------------------------------------------------------------------
// Stable ID: aa_0066e660
// Address:   0x0066e660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066e660 @ 0x0066e660
// Stable ID: aa_0066e660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00507290×2, FUN_00651fa0, FUN_0066e660.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0066e660(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  short *psVar1;

  int iVar2;

  

  FUN_00651fa0(param_2);

  *param_1 = &PTR_FUN_009e7b8c;

  param_1[2] = &PTR_LAB_009e7a18;

  iVar2 = *(int *)(param_2 + 4);

  param_1[6] = iVar2;

  param_1[7] = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  if (iVar2 != 0) {

    *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 1;

    FUN_00507290(param_1);

  }

  if (param_1[7] != 0) {

    psVar1 = (short *)(param_1[7] + 6);

    *psVar1 = *psVar1 + 1;

    FUN_00507290(param_1);

  }

  return param_1;

}
