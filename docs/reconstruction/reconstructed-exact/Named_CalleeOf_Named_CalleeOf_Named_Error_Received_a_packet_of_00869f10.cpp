// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00869f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00869f10
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x00869f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×8, while×8, do×7, return×3, for×3, goto×1.
//  - Notable callees: strtok×4, FUN_007a6de0×2, sprintf×2, FUN_00418700, FUN_00418790, FUN_007a69d0, FUN_007fbd30, FUN_00869ae0.
//  - Strings: "%s (%d)"; "%s %s ".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00869f10(int *param_1,int *param_2)



{

  char *pcVar1;

  int *piVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  int *piVar11;

  int iVar12;

  char *pcVar13;

  time_t *ptVar14;

  time_t *local_290;

  int local_28c;

  int local_288;

  uint32_t /* width from decompiler */ uStack_284;

  char acStack_280 [64];

  char acStack_240 [64];

  char acStack_200 [255];

  char cStack_101;

  char acStack_100 [256];

  

  if (param_2 == (int *)0x0) {

    return;

  }

  param_2[0xba] = param_2[0xba] + DAT_00b04590;

  local_290 = (time_t *)(param_2 + 0xba);

  local_28c = *param_2;

  local_288 = local_28c >> 0x1f;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 == '\0') {

    return;

  }

  cVar3 = FUN_00869ae0();

  puVar4 = &DAT_00afdf0c;

  if (cVar3 == '\0') {

    puVar4 = &DAT_00afdf08;

  }

  uStack_284 = *puVar4;

  iVar12 = local_28c;

  if (param_1[0x16d] != 0) {

    sprintf(acStack_200,"%s (%d)",param_2 + 2,param_2[0xa6]);

    iVar9 = local_288;

    iVar12 = local_28c;

    (**(code **)(*(int *)param_1[0x16d] + 0x45c))(acStack_200,local_28c,local_288,1);

    (**(code **)(*(int *)param_1[0x16d] + 0x464))(iVar12,iVar9,1,&stack0xfffffd6c);

  }

  if (param_1[0x16e] != 0) {

    FUN_007a69d0();

    pcVar5 = ctime(local_290);

    pcVar13 = acStack_200;

    do {

      cVar3 = *pcVar5;

      *pcVar13 = cVar3;

      pcVar5 = pcVar5 + 1;

      pcVar13 = pcVar13 + 1;

    } while (cVar3 != '\0');

    pcVar5 = strtok(acStack_200," ");

    pcVar13 = acStack_240;

    do {

      cVar3 = *pcVar5;

      *pcVar13 = cVar3;

      pcVar5 = pcVar5 + 1;

      pcVar13 = pcVar13 + 1;

    } while (cVar3 != '\0');

    pcVar5 = strtok((char *)0x0," ");

    pcVar13 = acStack_280;

    do {

      cVar3 = *pcVar5;

      *pcVar13 = cVar3;

      pcVar5 = pcVar5 + 1;

      pcVar13 = pcVar13 + 1;

    } while (cVar3 != '\0');

    uVar6 = FUN_007a6de0(acStack_280,0xffffffff);

    uVar7 = FUN_007a6de0(acStack_240,0xffffffff);

    sprintf(acStack_100,"%s %s ",uVar7,uVar6);

    pcVar13 = strtok((char *)0x0," ");

    iVar9 = local_288;

    while (pcVar5 = pcVar13, local_288 = iVar9, pcVar13 != (char *)0x0) {

      do {

        cVar3 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar3 != '\0');

      uVar8 = (int)pcVar5 - (int)pcVar13;

      pcVar5 = &cStack_101;

      do {

        pcVar1 = pcVar5 + 1;

        pcVar5 = pcVar5 + 1;

      } while (*pcVar1 != '\0');

      for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar13;

        pcVar13 = pcVar13 + 4;

        pcVar5 = pcVar5 + 4;

      }

      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

        *pcVar5 = *pcVar13;

        pcVar13 = pcVar13 + 1;

        pcVar5 = pcVar5 + 1;

      }

      pcVar13 = &cStack_101;

      do {

        pcVar5 = pcVar13 + 1;

        pcVar13 = pcVar13 + 1;

      } while (*pcVar5 != '\0');

      *(uint16_t *)pcVar13 = DAT_00a2a000;

      pcVar13 = strtok((char *)0x0," ");

      iVar12 = local_28c;

      iVar9 = local_288;

    }

    pcVar13 = acStack_100;

    (**(code **)(*(int *)param_1[0x16e] + 0x45c))(pcVar13,iVar12,iVar9,1);

    (**(code **)(*(int *)param_1[0x16e] + 0x464))(iVar12,iVar9,1,&stack0xfffffd6c);

    (**(code **)(*(int *)param_1[0x16e] + 0x460))(iVar12,iVar9,0,*(uint32_t /* width from decompiler */ *)pcVar13);

  }

  piVar2 = (int *)param_1[0x159];

  piVar11 = (int *)*piVar2;

  ptVar14 = (time_t *)0x0;

  if (piVar11 != piVar2) {

    do {

      iVar12 = (int)*(time_t *)piVar11[2];

      if ((iVar12 == local_28c) && (iVar12 >> 0x1f == local_288)) {

        ptVar14 = (time_t *)piVar11[2];

      }

      piVar11 = (int *)*piVar11;

    } while (piVar11 != piVar2);

    if (ptVar14 != (time_t *)0x0) goto LAB_0086a1e1;

  }

  ptVar14 = operator_new(0x338);

  iVar12 = param_1[0x159];

  local_290 = ptVar14;

  iVar9 = FUN_00418700(iVar12,*(uint32_t /* width from decompiler */ *)(iVar12 + 4),&local_290);

  FUN_00418790();

  *(int *)(iVar12 + 4) = iVar9;

  **(int **)(iVar9 + 4) = iVar9;

LAB_0086a1e1:

  for (iVar12 = 0xce; iVar12 != 0; iVar12 = iVar12 + -1) {

    *(int *)ptVar14 = *param_2;

    param_2 = param_2 + 1;

    ptVar14 = (time_t *)((int)ptVar14 + 4);

  }

  FUN_007fbd30();

  return;

}
