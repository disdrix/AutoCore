// =============================================================================
// FUN_006f2290
// -----------------------------------------------------------------------------
// Stable ID: aa_006f2290
// Address:   0x006f2290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f2290 @ 0x006f2290
// Stable ID: aa_006f2290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_006f1c80, FUN_006f2180, FUN_006f2210, FUN_006f2290.
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

int * __thiscall FUN_006f2290(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  

  piVar2 = param_2;

  piVar3 = param_1;

  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {

    *piVar3 = *piVar2;

    piVar2 = piVar2 + 1;

    piVar3 = piVar3 + 1;

  }

  FUN_006f1c80(param_3);

  FUN_006f2180(param_3,param_4);

  *param_1 = *param_2 + 1;

  *(uint8_t *)(param_1 + 1) = 0;

  FUN_006f2210();

  return param_1;

}
