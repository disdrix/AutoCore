// =============================================================================
// FUN_0078e980
// -----------------------------------------------------------------------------
// Stable ID: aa_0078e980
// Address:   0x0078e980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078e980 @ 0x0078e980
// Stable ID: aa_0078e980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, goto×1.
//  - Notable callees: FUN_0078e980.
//  - Return sites: 4.

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

void __fastcall FUN_0078e980(int *param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uStack_2c;

  int *local_18 [4];

  uint8_t local_8 [8];

  

  piVar2 = (int *)param_1[0x252];

  if ((piVar2 == (int *)0x0) || (param_1[0x253] == 0)) {

    param_1[0x142] = 0;

  }

  else {

    uStack_2c = 1;

    if (*(char *)((int)param_1 + 0x4fd) == '\0') {

      piVar3 = (int *)param_1[0x253];

      param_1[0x142] = 0;

      local_18[0] = piVar3;

      iVar6 = (**(code **)(*piVar2 + 0x140))(local_8);

      iVar6 = *(int *)(iVar6 + 4);

      iVar1 = param_1[0x14b];

      iVar7 = (**(code **)(*piVar3 + 0x120))(local_18,1,0);

      iVar7 = *(int *)(iVar7 + 4);

      iVar5 = (**(code **)(*piVar3 + 0x140))(&uStack_2c,1);

      param_1[0x143] = (iVar6 / 2 - iVar1) + iVar7 + *(int *)(iVar5 + 4);

      goto LAB_0078ea73;

    }

    piVar2 = (int *)(**(code **)(*piVar2 + 0x140))(local_18);

    piVar3 = (int *)(**(code **)(*(int *)param_1[0x253] + 0x120))(local_18,1,0);

    piVar4 = (int *)(**(code **)(*(int *)param_1[0x253] + 0x140))(&stack0xffffffe4,1);

    param_1[0x142] = (*piVar2 / 2 - param_1[0x14a]) + *piVar4 + *piVar3;

  }

  param_1[0x143] = 0;

LAB_0078ea73:

  piVar2 = (int *)param_1[0x252];

  if ((piVar2 != (int *)0x0) && (param_1[0x254] != 0)) {

    uStack_2c = 1;

    if (*(char *)((int)param_1 + 0x4fd) != '\0') {

      piVar2 = (int *)(**(code **)(*piVar2 + 0x140))(local_8);

      piVar3 = (int *)(**(code **)(*(int *)param_1[0x254] + 0x120))(local_18,1,0);

      iVar6 = *piVar2;

      iVar1 = *piVar3;

      param_1[0x145] = 0;

      param_1[0x144] = (param_1[0x14a] - iVar6 / 2) + iVar1;

      return;

    }

    piVar3 = (int *)param_1[0x254];

    param_1[0x144] = 0;

    iVar6 = (**(code **)(*piVar2 + 0x140))(local_8);

    iVar6 = *(int *)(iVar6 + 4);

    iVar1 = param_1[0x14b];

    iVar7 = (**(code **)(*piVar3 + 0x120))(local_18,1,0);

    param_1[0x145] = (iVar1 - iVar6 / 2) + *(int *)(iVar7 + 4);

    return;

  }

  uStack_2c = 1;

  if (*(char *)((int)param_1 + 0x4fd) != '\0') {

    piVar2 = (int *)(**(code **)(*param_1 + 0x140))();

    iVar6 = *piVar2;

    param_1[0x145] = 0;

    param_1[0x144] = iVar6;

    return;

  }

  param_1[0x144] = 0;

  iVar6 = (**(code **)(*param_1 + 0x140))(local_8);

  param_1[0x145] = *(int *)(iVar6 + 4);

  return;

}
