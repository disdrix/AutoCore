// =============================================================================
// FUN_00892560
// -----------------------------------------------------------------------------
// Stable ID: aa_00892560
// Address:   0x00892560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00892560 @ 0x00892560
// Stable ID: aa_00892560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008908c0, FUN_00891b60, FUN_00892430, FUN_00892560.
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

void FUN_00892560(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  char cVar1;

  int *unaff_ESI;

  

  FUN_00892430(unaff_ESI,param_1,param_2,1);

  FUN_00891b60(param_1,param_2,param_3,param_4,param_5,param_6,param_7);

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_008908c0(unaff_ESI);

  }

  return;

}
