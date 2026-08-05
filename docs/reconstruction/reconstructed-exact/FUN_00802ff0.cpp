// =============================================================================
// FUN_00802ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00802ff0
// Address:   0x00802ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00802ff0 @ 0x00802ff0
// Stable ID: aa_00802ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00802ff0, FUN_008908c0, FUN_00891e80, FUN_00892430.
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

void FUN_00802ff0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  

  piVar1 = *(int **)(in_EAX + 0x10ec);

  if (piVar1 != (int *)0x0) {

    FUN_00892430(piVar1,param_1,param_2,1);

    FUN_00891e80(param_1,param_2,param_3,param_5);

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      FUN_008908c0(piVar1);

    }

    (**(code **)(*piVar1 + 0x94))();

  }

  return;

}
