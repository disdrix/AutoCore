// =============================================================================
// FUN_00423910
// -----------------------------------------------------------------------------
// Stable ID: aa_00423910
// Address:   0x00423910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423910 @ 0x00423910
// Stable ID: aa_00423910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, goto×1.
//  - Notable callees: FUN_00423910.
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

uint32_t /* width from decompiler */ FUN_00423910(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (*(int *)(param_1 + 4) == 0) {

    return 1;

  }

  if (param_3 == 0) {

    return 0;

  }

  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))();

  iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x30))();

  if (iVar1 < iVar2 + param_3) {

    param_3 = iVar1 - iVar2;

  }

  uVar3 = 0;

  if (0 < param_3) {

    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x14))(param_2,param_3);

    if (-1 < iVar1) goto LAB_0042396f;

  }

  uVar3 = 1;

LAB_0042396f:

  if (param_4 != (int *)0x0) {

    *param_4 = param_3;

  }

  return uVar3;

}
