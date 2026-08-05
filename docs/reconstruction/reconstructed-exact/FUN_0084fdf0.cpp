// =============================================================================
// FUN_0084fdf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fdf0
// Address:   0x0084fdf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084fdf0 @ 0x0084fdf0
// Stable ID: aa_0084fdf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, goto×1.
//  - Notable callees: FUN_0084f810, FUN_0084fdf0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0084fdf0(int *param_1,int param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (40000 < param_3) {

    if ((param_2 != 5) && (param_2 != 6)) {

      if (param_2 != 8) goto LAB_0084fe23;

      FUN_0084f810();

    }

    return 1;

  }

LAB_0084fe23:

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar2;

  }

  return 0;

}
