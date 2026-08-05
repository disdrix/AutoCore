// =============================================================================
// FUN_006f8070
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8070
// Address:   0x006f8070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8070 @ 0x006f8070
// Stable ID: aa_006f8070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_006f8070.
//  - Return sites: 2.

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

void FUN_006f8070(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,float *param_3,float *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*param_3 <= *param_4) {

    uVar1 = *param_1;

  }

  else {

    uVar1 = *param_2;

  }

  *param_1 = uVar1;

  if (param_3[1] <= *param_4) {

    uVar1 = param_1[1];

  }

  else {

    uVar1 = *param_2;

  }

  param_1[1] = uVar1;

  if (*param_4 < param_3[2]) {

    param_1[2] = *param_2;

    return;

  }

  param_1[2] = param_1[2];

  return;

}
