// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×10, return×6, switch×1, goto×1.
//  - Notable callees: FUN_007a6de0×4, Experience_GetCumulativeThreshold×2, FUN_00803a20×2, FUN_00806170×2, sprintf×2, FUN_00402d50, FUN_004eb240, FUN_0051fc80.
//  - Strings: "Level"; "%s - %s %d"; "Money"; "%s: %s".
//  - Return sites: 6.

// =============================================================================
// Mission_Objective_Display_008066f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008066f0
// Address:   0x008066f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Objective Display"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_Objective_Display_008066f0(int param_1)



{

  int *piVar1;

  ushort wLevel;

  short sVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint8_t *puVar12;

  uint8_t *local_290;

  uint8_t auStack_28c [120];

  char acStack_214 [8];

  char acStack_20c [248];

  uint8_t auStack_114 [264];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac471;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007a69d0();

  switch(*(uint8_t *)(param_1 + 0xd1c)) {

  case 1:

    piVar1 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);

    uVar10 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                         0x27c))();

    uVar3 = FUN_007a6de0("Level",0xffffffff);

    uVar10 = (**(code **)(*piVar1 + 0x160))(uVar3,uVar10);

    sprintf(acStack_20c,"%s - %s %d",uVar10);

    (**(code **)(*(int *)(param_1 + 0x70) + 0x80))(acStack_20c);

    wLevel = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                         0x27c))();

    uVar4 = Experience_GetCumulativeThreshold(wLevel);

    sVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x27c))();

    uVar5 = Experience_GetCumulativeThreshold(sVar2 - 1);

    iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x27c))();

    if (iVar9 == 1) {

      uVar5 = 0;

    }

    (**(code **)(*(int *)(param_1 + 0xbb0) + 0x78))

              (((float)(int)(*(int *)(DAT_00d1b6d8 + 0x730) - uVar5) / (float)(int)(uVar4 - uVar5))

               * DAT_00a0f520);

    FUN_0051fc80(*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728),

                 (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                 (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),

                 auStack_114,1);

    puVar12 = auStack_114;

    uVar10 = FUN_007a6de0("Money",0xffffffff);

    sprintf(acStack_214,"%s: %s",uVar10,puVar12);

    (**(code **)(*(int *)(param_1 + 0x350) + 0x80))(acStack_214);

    break;

  case 2:

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x19c))();

    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x19c))();

    iVar9 = *(int *)(param_1 + 0xb64);

    iVar8 = *(int *)(*(int *)(iVar7 + 4) + 4);

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x23c))();

    iVar8 = (**(code **)(*(int *)(iVar8 + 4 + iVar7) + 0x244))();

    (**(code **)(iVar9 + 0x78))(((float)iVar6 / (float)iVar8) * DAT_00aaa7ac);

    (**(code **)(*(int *)(param_1 + 0xbb0) + 0x78))

              (((float)(int)*(short *)(DAT_00d1b6d8 + 300) /

               (float)(int)*(short *)(DAT_00d1b6d8 + 0x12e)) * DAT_00aaa7ac);

    iVar9 = (**(code **)(*(int *)(param_1 + 0xbfc) + 0x30))();

    if ((iVar9 != 0) && (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x148) == 0)) {

      FUN_00806170();

    }

    if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x148) != 0) {

      iVar9 = (**(code **)(*(int *)(param_1 + 0xbfc) + 0x30))();

      if (iVar9 == 0) {

        FUN_00806170();

      }

      (**(code **)(*(int *)(param_1 + 0xbfc) + 0x78))

                (((float)*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x144) /

                 (float)*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x148)) * DAT_00aaa7ac);

    }

    break;

  case 3:

    if (DAT_00d1b8c8 != 0) {

      if (*(int *)(DAT_00d1b8c8 + 0x688) != 0) {

        (**(code **)(**(int **)(DAT_00d1b8c8 + 0x688) + 0x1dc))();

      }

      FUN_00803a20();

      if (*(int *)(DAT_00d1b8c8 + 0x694) != 0) {

        uVar10 = (**(code **)(**(int **)(DAT_00d1b8c8 + 0x694) + 0x1dc))();

        (**(code **)(*(int *)(param_1 + 0x1e0) + 0x80))(uVar10);

        ExceptionList = local_c;

        return;

      }

      (**(code **)(*(int *)(param_1 + 0x1e0) + 0x80))(0);

      ExceptionList = local_c;

      return;

    }

    FUN_007a6de0("Objective Display",0xffffffff);

    FUN_00803a20();

    goto LAB_00806aab;

  case 4:

    if (DAT_00d1b8d8 != 0) {

      iVar9 = FUN_008beb40(0xffff);

      if (iVar9 == 0) {

        (**(code **)(*(int *)(param_1 + 0x1e0) + 0x80))(&DAT_00a1419b);

        ExceptionList = local_c;

        return;

      }

      uVar10 = FUN_004eb240();

      puVar11 = (uint32_t /* width from decompiler */ *)FUN_00402d50(uVar10);

      local_4 = 0;

      iVar9 = *(int *)(param_1 + 0x1e0);

      uVar10 = FUN_007a6de0(*puVar11,0xffffffff);

      (**(code **)(iVar9 + 0x80))(uVar10);

      local_4 = 0xffffffff;

      if (local_290 == auStack_28c) {

        ExceptionList = local_c;

        return;

      }

      free(local_290);

      ExceptionList = local_c;

      return;

    }

LAB_00806aab:

    (**(code **)(*(int *)(param_1 + 0x1e0) + 0x80))(&DAT_00a1419b);

  }

  ExceptionList = local_c;

  return;

}
