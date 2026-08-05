// READABILITY (auto CF):
//  - Body size: ~169 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, goto×2, return×1.
//  - Notable callees: FUN_00767160×6, FUN_0043b500×4, CONCAT31×2, FUN_00439810×2, vog_LogMessage×2, FUN_0075a590, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
//  - Strings: "

                   ,0xcd,3,"; "

                   ,0xfa,3,".
//  - Return sites: 1.

// =============================================================================
// Named_gfxLODHandler_SimpleDistance_0075a590
// -----------------------------------------------------------------------------
// Stable ID: aa_0075a590
// Address:   0x0075a590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLODHandler_SimpleDistance"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_gfxLODHandler_SimpleDistance_0075a590(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint8_t *puVar1;

  uint8_t *puVar2;

  int *piVar3;

  uint uVar4;

  int *piVar5;

  uint uVar6;

  uint uVar7;

  uint unaff_EBP;

  int iVar8;

  int *piVar9;

  uint8_t *puVar10;

  uint local_24;

  uint32_t /* width from decompiler */ uStack_1c;

  int local_18;

  int *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adaab;

  pvStack_c = ExceptionList;

  local_10 = param_2;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x4c445344,1);

  local_4 = 0;

  local_24 = FUN_00439810();

  iVar8 = *(int *)(param_1 + 4);

  piVar9 = *(int **)(param_1 + 0xc);

  local_14 = *(int **)(param_1 + 0x10);

  if (piVar9 != local_14) {

    do {

      piVar5 = *(int **)(iVar8 + 0xc0);

      piVar3 = *(int **)(iVar8 + 0xc4);

      if (piVar5 != piVar3) {

        do {

          if (*piVar5 == *piVar9) {

            if (param_2[7] == 0) {

              uStack_1c = 0;

              uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&uStack_1c,4);

              param_2[1] = param_2[1] | uVar4;

            }

            else {

              uVar4 = FUN_00767160(&DAT_00a37c64,0);

              param_2[1] = param_2[1] | uVar4;

              uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

              param_2[8] = 0;

              param_2[1] = uVar4 | param_2[1];

            }

            unaff_EBP = unaff_EBP | param_2[1];

            if (param_2[7] == 0) {

              local_4 = CONCAT31(local_4._1_3_,(char)piVar9[1]);

              uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&local_4,1);

              param_2[1] = param_2[1] | uVar4;

            }

            else {

              uVar4 = FUN_00767160(&DAT_00a9d718,(char)piVar9[1]);

              param_2[1] = param_2[1] | uVar4;

              uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

              param_2[8] = 0;

              param_2[1] = uVar4 | param_2[1];

            }

            uVar4 = param_2[1];

            uVar6 = FUN_0043b500(piVar9 + 2);

            uVar7 = FUN_0043b500(piVar9 + 3);

            local_24 = local_24 | uVar6 | uVar4 | uVar7;

            goto LAB_0075a762;

          }

          piVar3 = piVar3 + 1;

        } while (piVar5 != piVar3);

      }

      if (param_2[7] == 0) {

        local_18 = -1;

        uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&local_18,4);

        param_2[1] = param_2[1] | uVar4;

      }

      else {

        uVar4 = FUN_00767160(&DAT_00a37c64,0xffffffff);

        param_2[1] = param_2[1] | uVar4;

        uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

        param_2[8] = 0;

        param_2[1] = uVar4 | param_2[1];

      }

      local_24 = local_24 | param_2[1];

LAB_0075a762:

      piVar9 = piVar9 + 4;

    } while (piVar9 != local_14);

  }

  if ((int)local_24 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_SimpleDistance.cpp"

                   ,0xcd,3,"Error serializing pieces in gfxLODHandler_SimpleDistance!");

  }

  uVar4 = FUN_00439810();

  puVar2 = *(uint8_t **)(param_1 + 0x20);

  local_24 = local_24 | uVar4;

  iVar8 = *(int *)(param_1 + 4) + 0xcc;

  local_18 = iVar8;

  if (*(uint8_t **)(param_1 + 0x1c) != puVar2) {

    puVar10 = *(uint8_t **)(param_1 + 0x1c) + 4;

    do {

      piVar9 = *(int **)(iVar8 + 4);

      piVar5 = *(int **)(iVar8 + 8);

      if (piVar9 != piVar5) {

        do {

          if (*piVar9 == *(int *)(puVar10 + -4)) {

            if (param_2[7] == 0) {

              local_14 = (int *)0x0;

              uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&local_14,4);

              param_2[1] = param_2[1] | uVar4;

            }

            else {

              uVar4 = FUN_00767160(&DAT_00a37c64,0);

              param_2[1] = param_2[1] | uVar4;

              uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

              param_2[8] = 0;

              param_2[1] = uVar4 | param_2[1];

            }

            uVar4 = param_2[1];

            if (param_2[7] == 0) {

              local_4 = CONCAT31(local_4._1_3_,*puVar10);

              uVar6 = (**(code **)(*(int *)*param_2 + 0x18))(&local_4,1);

              param_2[1] = param_2[1] | uVar6;

            }

            else {

              uVar6 = FUN_00767160(&DAT_00a9d718,*puVar10);

              param_2[1] = param_2[1] | uVar6;

              uVar6 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

              param_2[8] = 0;

              param_2[1] = uVar6 | param_2[1];

            }

            uVar6 = param_2[1];

            uVar7 = FUN_0043b500(puVar10 + 4);

            local_24 = FUN_0043b500(puVar10 + 8);

            local_24 = unaff_EBP | uVar4 | uVar7 | uVar6 | local_24;

            iVar8 = local_18;

            goto LAB_0075a91e;

          }

          piVar5 = piVar5 + 1;

        } while (piVar9 != piVar5);

      }

      if (param_2[7] == 0) {

        uStack_1c = 0xffffffff;

        uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&uStack_1c,4);

        param_2[1] = param_2[1] | uVar4;

      }

      else {

        uVar4 = FUN_00767160(&DAT_00a37c64,0xffffffff);

        param_2[1] = param_2[1] | uVar4;

        uVar4 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

        param_2[8] = 0;

        param_2[1] = uVar4 | param_2[1];

      }

      local_24 = local_24 | param_2[1];

LAB_0075a91e:

      puVar1 = puVar10 + 0xc;

      puVar10 = puVar10 + 0x10;

    } while (puVar1 != puVar2);

  }

  if ((int)local_24 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_SimpleDistance.cpp"

                   ,0xfa,3,"Error serializing shadows in gfxLODHandler_SimpleDistance!");

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = pvStack_c;

  return local_24;

}
