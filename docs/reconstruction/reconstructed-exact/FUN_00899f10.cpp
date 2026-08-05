// =============================================================================
// FUN_00899f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00899f10
// Address:   0x00899f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00899f10 @ 0x00899f10
// Stable ID: aa_00899f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×19, goto×10, return×4.
//  - Notable callees: FUN_00899f10.
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

uint32_t /* width from decompiler */ __thiscall FUN_00899f10(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  uint8_t auStack_8 [8];

  

  if (param_1[0x15c] == 0) {

LAB_00899f57:

    bVar2 = false;

  }

  else {

    cVar3 = (**(code **)(*(int *)param_1[0x15c] + 0xd8))();

    if (cVar3 == '\0') goto LAB_00899f57;

    cVar3 = (**(code **)(*(int *)param_1[0x15c] + 0xd0))();

    bVar2 = true;

    if (cVar3 == '\0') goto LAB_00899f57;

  }

  if (param_1[0x15d] == 0) {

LAB_00899f8d:

    bVar1 = false;

  }

  else {

    cVar3 = (**(code **)(*(int *)param_1[0x15d] + 0xd8))();

    if (cVar3 == '\0') goto LAB_00899f8d;

    cVar3 = (**(code **)(*(int *)param_1[0x15d] + 0xd0))();

    if (cVar3 == '\0') goto LAB_00899f8d;

    bVar1 = true;

  }

  if (bVar2) {

    if (bVar1) {

      if (param_1[0x158] != 0) {

        iVar4 = (**(code **)(*(int *)param_1[0x158] + 0x120))(auStack_8,1,1);

        if (DAT_00d1d870 < *(int *)(iVar4 + 4)) goto LAB_00899fc5;

      }

      goto LAB_00899fcd;

    }

LAB_00899fc5:

    piVar6 = (int *)param_1[0x15c];

  }

  else {

LAB_00899fcd:

    if (bVar1) {

      if (bVar2) {

        if (param_1[0x158] != 0) {

          iVar4 = (**(code **)(*(int *)param_1[0x158] + 0x120))(auStack_8,1,1);

          if (*(int *)(iVar4 + 4) <= DAT_00d1d870) goto LAB_0089a016;

        }

        goto LAB_0089a003;

      }

    }

    else {

LAB_0089a003:

      if (bVar2) {

        piVar6 = (int *)param_1[0x15c];

        goto LAB_0089a01c;

      }

      if (!bVar1) goto LAB_0089a056;

    }

LAB_0089a016:

    piVar6 = (int *)param_1[0x15d];

  }

LAB_0089a01c:

  if (piVar6 != (int *)0x0) {

    if (0 < (short)((uint)param_2 >> 0x10)) {

      (**(code **)(*piVar6 + 0x45c))(0xbf800000);

      return 1;

    }

    (**(code **)(*piVar6 + 0x45c))(0x3f800000);

    return 1;

  }

LAB_0089a056:

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar3 != '\0') && (param_1[0x12e] != 0)) {

    uVar5 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))(param_2,param_3);

    return uVar5;

  }

  return 0;

}
