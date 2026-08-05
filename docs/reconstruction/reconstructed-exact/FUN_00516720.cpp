// =============================================================================
// FUN_00516720
// -----------------------------------------------------------------------------
// Stable ID: aa_00516720
// Address:   0x00516720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00516720 @ 0x00516720
// Stable ID: aa_00516720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×7, do×5, while×5, return×3, goto×1.
//  - Notable callees: FUN_00403450, FUN_004ce940, FUN_004eb240, FUN_005146a0, FUN_00516720, FUN_007a6880, FUN_007a69d0, free.
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

void __thiscall FUN_00516720(int *param_1,char *param_2)



{

  char cVar1;

  bool bVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uStack_84;

  char acStack_80 [128];

  

  if (param_2 == (char *)0x0) {

    return;

  }

  if ((void *)param_1[0x56] != (void *)0x0) {

    operator_delete__((void *)param_1[0x56]);

  }

  param_1[0x56] = 0;

  pcVar3 = param_2;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  iVar4 = (**(code **)(*param_1 + 0x60))();

  if (((iVar4 != 0) && (param_1[0x29] != 0)) && (iVar4 = FUN_004ce940(), iVar4 != 0)) {

    puVar8 = &uStack_84;

    uVar7 = 0x5a;

    FUN_007a69d0(0x5a,puVar8);

    uVar5 = FUN_007a6880();

    FUN_005146a0(param_2,uVar5,uVar7,puVar8);

    pcVar3 = (char *)&uStack_84;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar6 = operator_new__((uint)(pcVar3 + (1 - ((int)&uStack_84 + 1))));

    param_1[0x56] = (int)pcVar6;

    pcVar3 = (char *)&uStack_84;

    do {

      cVar1 = *pcVar3;

      *pcVar6 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    return;

  }

  uVar5 = FUN_004eb240();

  uStack_84 = acStack_80;

  uVar7 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(uVar5,uVar7);

  iVar4 = strncmp(param_2,uStack_84,0x41);

  if (iVar4 != 0) {

    pcVar6 = param_2;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    if (1 < (uint)((int)pcVar6 - (int)(param_2 + 1))) {

      bVar2 = true;

      goto LAB_00516846;

    }

  }

  bVar2 = false;

LAB_00516846:

  if (uStack_84 != acStack_80) {

    free(uStack_84);

  }

  if (bVar2) {

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(param_2 + 1))));

    param_1[0x56] = (int)pcVar3;

    do {

      cVar1 = *param_2;

      *pcVar3 = cVar1;

      param_2 = param_2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
