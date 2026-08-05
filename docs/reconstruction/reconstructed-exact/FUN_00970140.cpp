// =============================================================================
// FUN_00970140
// -----------------------------------------------------------------------------
// Stable ID: aa_00970140
// Address:   0x00970140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00970140 @ 0x00970140
// Stable ID: aa_00970140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00752370, FUN_00970060, FUN_00970140.
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

uint32_t /* width from decompiler */ __thiscall FUN_00970140(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*param_1 == 0) {

    param_2 = -1;

    piVar1 = &param_2;

  }

  else {

    piVar1 = (int *)FUN_00752370(&param_2,param_2);

  }

  if (-1 < *piVar1) {

    uVar2 = FUN_00970060(*piVar1,param_3);

    return uVar2;

  }

  return 0xffffffff;

}
