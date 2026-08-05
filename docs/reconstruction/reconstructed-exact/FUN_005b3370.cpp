// =============================================================================
// FUN_005b3370
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3370
// Address:   0x005b3370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b3370 @ 0x005b3370
// Stable ID: aa_005b3370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b3370, FUN_006380a0.
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

void FUN_005b3370(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  

  iVar2 = param_1[1] * 2;

  if (param_1[1] == 0) {

    iVar2 = 1;

  }

  uVar1 = (**(code **)(*DAT_00b05060 + 0x10))(iVar2 * param_2,0x12);

  FUN_006380a0(uVar1,*param_1,param_1[1] * param_2);

  if (-1 < (int)param_1[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,(param_1[2] & 0x7fffffff) * param_2,0x12);

  }

  *param_1 = uVar1;

  param_1[2] = iVar2;

  return;

}
