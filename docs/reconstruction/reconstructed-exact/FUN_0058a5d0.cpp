// =============================================================================
// FUN_0058a5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058a5d0
// Address:   0x0058a5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058a5d0 @ 0x0058a5d0
// Stable ID: aa_0058a5d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0058a5d0.
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

uint32_t /* width from decompiler */ FUN_0058a5d0(int *param_1,float param_2,float param_3,float param_4)



{

  int *piVar1;

  float unaff_ESI;

  float unaff_retaddr;

  

  if (param_1 == (int *)0x0) {

    return 0;

  }

  piVar1 = (int *)(**(code **)(*param_1 + 0x214))();

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0xa4))

              ((int)((float)(int)*(short *)((int)param_2 + 0xd8) * param_3 * param_4));

    (**(code **)(*piVar1 + 0xa0))

              ((int)((float)(int)*(short *)((int)param_2 + 0xd4) * param_2 * param_3));

    (**(code **)(*piVar1 + 0x94))

              ((int)((float)(int)*(short *)((int)param_2 + 0xd6) * (float)param_1 * param_2));

    (**(code **)(*piVar1 + 0x98))

              ((int)((float)(int)*(short *)((int)param_2 + 0xd0) * unaff_retaddr * (float)param_1));

    (**(code **)(*piVar1 + 0x9c))

              ((int)((float)(int)*(short *)((int)param_2 + 0xd2) * unaff_ESI * unaff_retaddr));

    return 1;

  }

  return 0;

}
