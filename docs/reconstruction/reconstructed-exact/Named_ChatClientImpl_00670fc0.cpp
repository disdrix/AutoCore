// READABILITY (auto CF):
//  - Body size: ~171 non-empty decompiler lines.
//  - Control keywords: if×16, return×7, do×5, while×5, for×1, goto×1.
//  - Notable callees: FUN_00680c50×5, FUN_0067b110×3, FUN_0076cec0×3, vog_LogMessage×3, CONCAT31×2, FUN_0067b070×2, FUN_0067b860×2, FUN_0066ff20.
//  - Strings: "ProcessPeers failed."; "Socket send for peer failed"; "Peer msg from invalid IP: %d".
//  - Return sites: 7.

// =============================================================================
// Named_ChatClientImpl_00670fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00670fc0
// Address:   0x00670fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_ChatClientImpl_00670fc0(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  uint uVar8;

  float10 fVar9;

  int local_60;

  uint32_t /* width from decompiler */ *local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint8_t local_54 [4];

  uint32_t /* width from decompiler */ *local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint8_t local_48 [16];

  uint8_t local_38 [4];

  int local_34;

  uint8_t local_28 [4];

  int local_24;

  uint32_t /* width from decompiler */ local_1c;

  int local_18;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a910f;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x20c) == 0) {

    return (uint)ExceptionList & 0xffffff00;

  }

  ExceptionList = &local_c;

  FUN_0067b070();

  local_4 = 0;

  do {

    iVar3 = FUN_0067b680(&DAT_00d04a88,0x2000,&local_60,local_38,0);

    if (iVar3 < 0) {

      uVar5 = FUN_0076cec0(&local_5c,"ProcessPeers failed.");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                     ,0x2ea,2,uVar5);

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x20c));

    }

    if (local_60 == 0) {

LAB_00671121:

      piVar7 = (int *)**(int **)(param_1 + 0x214);

      if (piVar7 != *(int **)(param_1 + 0x214)) {

        do {

          FUN_00680f60(piVar7 + 2);

          uVar4 = 0;

          local_4._0_1_ = 2;

          if (*(char *)(param_1 + 0x14) != '\0') {

            do {

              FUN_0067b070();

              local_4._0_1_ = 3;

              if ((uVar4 != *(byte *)(param_1 + 0xc)) &&

                 (iVar3 = *(int *)(*(int *)(param_1 + 0x208) + uVar4 * 4), iVar3 != 0)) {

                FUN_0067b180(iVar3,0x2289);

                iVar3 = FUN_0067b860(local_18 + local_24,local_1c,local_48);

                if (iVar3 < 0) {

                  uVar5 = FUN_0076cec0(&local_58,"Socket send for peer failed");

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                                 ,0x302,2,uVar5);

                    /* WARNING: Subroutine does not return */

                  operator_delete(*(void **)(param_1 + 0x20c));

                }

              }

              local_4._0_1_ = 2;

              FUN_0067b110();

              uVar4 = uVar4 + 1;

            } while (uVar4 != *(byte *)(param_1 + 0x14));

          }

          local_4 = (uint)local_4._1_3_ << 8;

          FUN_00680c50();

          piVar7 = (int *)*piVar7;

        } while (piVar7 != (int *)*(int *)(param_1 + 0x214));

      }

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x214);

      pvVar1 = (void *)*puVar6;

      *puVar6 = puVar6;

      *(int *)(*(int *)(param_1 + 0x214) + 4) = *(int *)(param_1 + 0x214);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x218) = 0;

      if (pvVar1 != *(void **)(param_1 + 0x214)) {

        FUN_00680c50();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar6 = (uint32_t /* width from decompiler */ *)FUN_00671610();

      local_4c = 0;

      local_4 = CONCAT31(local_4._1_3_,4);

      local_50 = puVar6;

      fVar9 = (float10)FUN_0076c330();

      local_5c = (uint32_t /* width from decompiler */ *)(float)fVar9;

      piVar7 = (int *)**(int **)(param_1 + 0x220);

      if (piVar7 != *(int **)(param_1 + 0x220)) {

        do {

          if ((float)local_5c < (float)piVar7[2]) {

            iVar3 = FUN_00671760(puVar6,puVar6[1],piVar7 + 2);

            FUN_006717f0(1);

            puVar6[1] = iVar3;

            **(int **)(iVar3 + 4) = iVar3;

            puVar6 = local_50;

          }

          else {

            FUN_0067b860(piVar7[0xb] + piVar7[8],piVar7[10],piVar7 + 3);

          }

          piVar7 = (int *)*piVar7;

        } while (piVar7 != (int *)*(int *)(param_1 + 0x220));

      }

      if ((uint8_t *)(param_1 + 0x21c) != local_54) {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x220);

        pvVar1 = (void *)*puVar2;

        uVar5 = *puVar6;

        *puVar2 = puVar2;

        *(int *)(*(int *)(param_1 + 0x220) + 4) = *(int *)(param_1 + 0x220);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x224) = 0;

        if (pvVar1 != *(void **)(param_1 + 0x220)) {

          local_5c = (uint32_t /* width from decompiler */ *)((int)pvVar1 + 8);

          local_4._0_1_ = 5;

          FUN_00680c50();

          local_4 = CONCAT31(local_4._1_3_,4);

          FUN_0067b110();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        FUN_00671990(**(uint32_t /* width from decompiler */ **)(param_1 + 0x220),uVar5,puVar6,local_58);

      }

      puVar2 = (uint32_t /* width from decompiler */ *)*puVar6;

      *puVar6 = puVar6;

      puVar6[1] = puVar6;

      if (puVar2 == puVar6) {

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar6);

      }

      local_5c = puVar2 + 2;

      local_4._0_1_ = 6;

      FUN_00680c50();

      local_4 = (uint)local_4._1_3_ << 8;

      FUN_0067b110();

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

    uVar8 = 0xff;

    uVar4 = 0;

    if (*(byte *)(param_1 + 0x14) != 0) {

      piVar7 = *(int **)(param_1 + 0x208);

      do {

        if (*piVar7 == local_34) {

          uVar8 = uVar4 & 0xff;

          break;

        }

        uVar4 = uVar4 + 1;

        piVar7 = piVar7 + 1;

      } while (uVar4 != *(byte *)(param_1 + 0x14));

    }

    if ((uVar8 == 0xffffffff) || (local_34 == 0)) {

      uVar5 = FUN_0076cec0(&local_5c,"Peer msg from invalid IP: %d",local_34);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                     ,0x2db,2,uVar5);

      goto LAB_00671121;

    }

    FUN_00680c30();

    local_4._0_1_ = 1;

    FUN_006810a0(&DAT_00d04a88,local_60);

    FUN_0066ff20(local_28,0,1);

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00680c50();

  } while( true );

}
