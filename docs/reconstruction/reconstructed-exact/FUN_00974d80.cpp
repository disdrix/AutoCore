// =============================================================================
// FUN_00974d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00974d80
// Address:   0x00974d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974d80 @ 0x00974d80
// Stable ID: aa_00974d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, goto×2.
//  - Notable callees: FUN_0077fe70, FUN_00974d80.
//  - Return sites: 5.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall FUN_00974d80(int *param_1,int *param_2)



{

  int *piVar1;

  uint uVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  

  iVar4 = (**(code **)(*param_1 + 0x50))();

  iVar5 = (**(code **)*param_2)();

  uVar2 = *(uint *)(iVar5 + 0x10 + iVar4 * 4);

  if (((uint)param_1[0x7e] <= uVar2) && (param_1[0x6e] == 7)) {

    return uVar2 & 0xffffff00;

  }

  (**(code **)(*param_2 + 0x18))(param_1);

  piVar6 = DAT_00afdc78;

  _DAT_00afdc70 = _DAT_00afdc70 + 1;

  if (DAT_00afdc78 == (int *)0x0) {

    piVar6 = (int *)FUN_0077fe70();

    piVar3 = DAT_00afdc78;

    if (piVar6 != (int *)0x0) {

      *piVar6 = 0;

      goto LAB_00974e00;

    }

  }

  else {

    piVar3 = (int *)*DAT_00afdc78;

    if (DAT_00afdc78 != (int *)0x0) {

      *DAT_00afdc78 = 0;

      DAT_00afdc78 = piVar3;

      goto LAB_00974e00;

    }

  }

  DAT_00afdc78 = piVar3;

  piVar6 = (int *)0x0;

LAB_00974e00:

  piVar3 = (int *)*piVar6;

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  *piVar6 = (int)param_2;

  param_2[2] = param_2[2] + 1;

  piVar6[2] = 0;

  if (*(int *)(*piVar6 + 0x10) == 0) {

    piVar6[1] = param_1[0x7a];

    param_1[0x7a] = param_1[0x7a] + 1;

    if (param_1[0x74] == 0) {

      param_1[0x81] = param_1[0x81] + 1;

      param_1[0x74] = (int)piVar6;

      param_1[0x75] = (int)piVar6;

      return 1;

    }

    *(int **)(param_1[0x75] + 8) = piVar6;

    param_1[0x81] = param_1[0x81] + 1;

    param_1[0x75] = (int)piVar6;

    return 1;

  }

  piVar6[1] = -1;

  if (param_1[0x76] == 0) {

    param_1[0x81] = param_1[0x81] + 1;

    param_1[0x76] = (int)piVar6;

    param_1[0x77] = (int)piVar6;

    return 1;

  }

  *(int **)(param_1[0x77] + 8) = piVar6;

  param_1[0x81] = param_1[0x81] + 1;

  param_1[0x77] = (int)piVar6;

  return 1;

}
