// =============================================================================
// FUN_00442dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00442dd0
// Address:   0x00442dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442dd0 @ 0x00442dd0
// Stable ID: aa_00442dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00442dd0, FUN_0075a300.
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

uint32_t /* width from decompiler */ __thiscall FUN_00442dd0(int param_1,int *param_2)



{

  int iVar1;

  

  if ((int *)param_2[0x25] != (int *)0x0) {

    iVar1 = (**(code **)(*(int *)param_2[0x25] + 8))();

    if (iVar1 == 0x4c445344) {

      FUN_0075a300(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x30));

    }

  }

  (**(code **)(*param_2 + 0x3c))(*(uint32_t /* width from decompiler */ *)(param_1 + 4));

  return 0;

}
