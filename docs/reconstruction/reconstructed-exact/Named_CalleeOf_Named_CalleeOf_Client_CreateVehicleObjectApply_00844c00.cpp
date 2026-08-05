// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_CreateVehicleObjectApply_00844c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00844c00
// Callee of Named_CalleeOf_Client_CreateVehicleObjectApply (+1 other named callers)
// Address:   0x00844c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_CreateVehicleObjectApply: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_CreateVehicleObjectApply (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×13, goto×3, return×1.
//  - Notable callees: CONCAT13, FUN_00844c00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_CreateVehicleObjectApply (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Client_CreateVehicleObjectApply_00844c00(int param_1,int param_2,int param_3,int param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  uint8_t *puVar4;

  uint8_t *puVar5;

  int unaff_EBX;

  int iVar6;

  int *unaff_ESI;

  int unaff_EDI;

  int iVar7;

  uint8_t *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint8_t *puVar10;

  uint uVar11;

  int iStack_40;

  int iStack_3c;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  uint8_t auStack_28 [8];

  uint8_t local_20 [28];

  

  uVar11 = 1;

  puVar4 = local_20;

  piVar2 = (int *)(**(code **)(*unaff_ESI + 0x140))();

  iVar6 = *piVar2;

  iStack_2c = param_4 / 2 + (unaff_ESI[0x144] - piVar2[1] / 2) + param_2;

  iStack_30 = 0;

  puVar10 = (uint8_t *)0x1;

  puVar5 = auStack_28;

  piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(puVar5);

  if (*piVar2 < param_3 + param_1 + iVar6) {

    uVar11 = CONCAT13(1,(int3)uVar11);

    iStack_38 = (param_1 - unaff_ESI[0x143]) - iVar6;

  }

  else {

    iStack_38 = unaff_ESI[0x143] + param_3 + param_1;

    uVar11 = uVar11 & 0xffffff;

  }

  if (iStack_38 < 0) {

    iStack_38 = 0;

  }

  else {

    piVar2 = (int *)(**(code **)(*unaff_ESI + 0x140))(&iStack_30,1);

    iVar6 = *piVar2 + iStack_40;

    piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0xffffffb8,1);

    if (*piVar2 < iVar6) {

      piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&iStack_30,1);

      piVar3 = (int *)(**(code **)(*unaff_ESI + 0x140))(&stack0xffffffb8,1);

      iStack_38 = *piVar2 - *piVar3;

    }

  }

  if (iStack_34 < 0) {

    iStack_34 = 0;

  }

  else {

    iVar6 = (**(code **)(*unaff_ESI + 0x140))(&iStack_30,1);

    iVar6 = *(int *)(iVar6 + 4);

    iVar7 = (**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0xffffffb8,1);

    if (*(int *)(iVar7 + 4) < iVar6 + iStack_3c) {

      piVar2 = (int *)*DAT_00d1b780;

      puVar4 = (uint8_t *)(**(code **)(*unaff_ESI + 0x140))(&iStack_30,1);

      iVar6 = (**(code **)(*piVar2 + 0x140))(&stack0xffffffb8,1);

      iStack_34 = *(int *)(iVar6 + 4) - *(int *)(unaff_EDI + 4);

    }

  }

  cVar1 = (**(code **)(*(int *)unaff_ESI[0x159] + 0xd0))();

  if (cVar1 == '\0') goto LAB_00844f80;

  iStack_40 = param_1 - iStack_38;

  iStack_30 = unaff_ESI[0x15a];

  iStack_2c = unaff_ESI[0x15b];

  iVar7 = param_2 - iStack_34;

  uVar9 = 1;

  puVar8 = &stack0xffffffb8;

  piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x159] + 0x140))(puVar8,1);

  iVar6 = *piVar2 + unaff_ESI[0x15a];

  if ((char)((uint)puVar10 >> 0x18) == '\0') {

    piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&iStack_30,1);

    puVar5 = (uint8_t *)(*piVar2 - unaff_EDI);

    piVar2 = (int *)(**(code **)(*unaff_ESI + 0x140))(&iStack_30,1);

    if (iVar6 <= (int)puVar4 - *piVar2) goto LAB_00844df4;

LAB_00844eec:

    iStack_38 = -(unaff_ESI[0x15a] + iVar6);

  }

  else {

    if (iVar6 < iStack_40) goto LAB_00844eec;

LAB_00844df4:

    piVar2 = (int *)(**(code **)(*unaff_ESI + 0x140))(auStack_28,1,puVar8,uVar9,puVar5);

    iStack_38 = *piVar2 + unaff_ESI[0x15a];

  }

  iVar6 = (**(code **)(*(int *)unaff_ESI[0x159] + 0x140))(auStack_28,1);

  puVar5 = *(uint8_t **)(iVar6 + 4);

  piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x159] + 0x140))(&iStack_30,1);

  if ((((unaff_EDI < (int)(puVar5 + param_3)) && ((int)puVar5 < *piVar2 + unaff_EDI)) &&

      (puVar5 = (uint8_t *)(param_4 + iVar7), unaff_EBX < (int)puVar5)) &&

     (iVar7 < piVar2[1] + unaff_EBX)) {

    if ((int)puVar8 < param_2) {

      if (param_2 - (int)puVar8 < (int)uVar11) {

        uVar11 = param_2 - (int)puVar8;

      }

    }

    else {

      iVar6 = (**(code **)(*unaff_ESI + 0x140))(&iStack_38,1);

      if ((int)(*(int *)(iVar6 + 4) + uVar11) < (int)(puVar8 + param_2 + param_4)) {

        iVar6 = (**(code **)(*unaff_ESI + 0x140))(&iStack_38,1);

        puVar10 = puVar8 + param_2 + (param_4 - *(int *)(iVar6 + 4));

        (**(code **)(*unaff_ESI + 0x140))(&iStack_40,1);

      }

    }

  }

  (**(code **)(*(int *)unaff_ESI[0x159] + 0x11c))(&stack0xffffffb8);

LAB_00844f80:

  (**(code **)(*unaff_ESI + 0x118))(&iStack_38,puVar5,puVar10,puVar4,uVar11);

  return;

}
