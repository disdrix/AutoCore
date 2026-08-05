// =============================================================================
// FUN_00952bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00952bc0
// Address:   0x00952bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00952bc0 @ 0x00952bc0
// Stable ID: aa_00952bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, for×1, while×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×4, FUN_005715d0×3, Client_SendSectorPacket×2, FUN_00424830×2, FUN_004248c0×2, FUN_00571620×2, Client_RefreshOpenMissionUiWindows, FUN_00404060.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __fastcall FUN_00952bc0(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  uint uVar4;

  uint8_t uVar5;

  uint8_t uVar6;

  char cVar7;

  uint uVar8;

  uint uVar9;

  int iVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint uVar13;

  int iStack_74;

  int *local_70;

  uint uStack_6c;

  int iStack_60;

  int *local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50 [2];

  int iStack_48;

  int iStack_44;

  uint8_t uStack_40;

  uint8_t uStack_38;

  uint8_t uStack_37;

  uint8_t uStack_36;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ auStack_30 [2];

  int iStack_28;

  int iStack_24;

  uint8_t uStack_20;

  uint8_t uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7eaf;

  local_c = ExceptionList;

  if (((*(int *)(param_1 + 0xe98) != 0) &&

      (iVar10 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250), iVar10 != 0)) &&

     (*(int *)(iVar10 + 0x2b0) != 0)) {

    piVar1 = *(int **)(iVar10 + 0x2b0);

    ExceptionList = &local_c;

    local_54 = FUN_0040fb90();

    local_50[0] = 0;

    local_4 = 0;

    (**(code **)(*piVar1 + 0xc))(&local_58);

    local_70 = (int *)*local_58;

    if (local_70 != local_58) {

      do {

        piVar2 = (int *)local_70[2];

        if (piVar2 != (int *)0x0) {

          uVar5 = (**(code **)(*piVar2 + 0x250))();

          uVar6 = (**(code **)(*piVar2 + 0x254))();

          CVOGReaction_RandomUnitScalar();

          uVar3 = piVar1[6];

          uVar8 = FUN_00424830();

          uVar13 = uVar8 % uVar3 & 0xff;

          CVOGReaction_RandomUnitScalar();

          uVar4 = piVar1[7];

          uVar9 = FUN_00424830();

          uStack_6c = uVar9 % uVar4 & 0xff;

          cVar7 = FUN_005715d0(piVar2,uVar13,uStack_6c,0);

          for (; (cVar7 == '\0' && (iStack_74 < 0x3d)); iStack_74 = iStack_74 + 1) {

            iVar10 = CVOGReaction_RandomUnitScalar();

            iVar10 = *(int *)(iVar10 + 0x14);

            if (*(int *)(iVar10 + 0x9c4) == 0) {

              FUN_004248c0();

            }

            *(int *)(iVar10 + 0x9c4) = *(int *)(iVar10 + 0x9c4) + -1;

            *(int *)(iVar10 + 0x9c0) = *(int *)(iVar10 + 0x9c0) + 4;

            iVar10 = CVOGReaction_RandomUnitScalar();

            iVar10 = *(int *)(iVar10 + 0x14);

            if (*(int *)(iVar10 + 0x9c4) == 0) {

              FUN_004248c0();

            }

            *(int *)(iVar10 + 0x9c4) = *(int *)(iVar10 + 0x9c4) + -1;

            *(int *)(iVar10 + 0x9c0) = *(int *)(iVar10 + 0x9c0) + 4;

            cVar7 = FUN_005715d0(piVar2,uVar13,uStack_6c,0);

          }

          cVar7 = FUN_005715d0(piVar2,uVar13,uStack_6c,0);

          if (cVar7 != '\0') {

            uVar12 = 0;

            uVar11 = (**(code **)(*piVar2 + 0x25c))(0);

            iVar10 = FUN_00571b80(piVar2,uVar11,uVar12);

            if (iVar10 != 0) {

              uVar11 = (**(code **)(*piVar2 + 0x25c))();

              cVar7 = FUN_00571620(piVar2,uVar13,uStack_6c,uVar11);

              if (cVar7 == '\0') {

                uVar11 = (**(code **)(*piVar2 + 0x25c))();

                FUN_00571620(piVar2,uVar5,uVar6,uVar11);

              }

              else {

                uStack_20 = (uint8_t)piVar2[0x5a];

                iStack_28 = piVar2[0x58];

                iStack_24 = piVar2[0x59];

                auStack_30[0] = 0x2038;

                uStack_18 = 1;

                uStack_14 = (**(code **)(*piVar2 + 0x25c))();

                Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_30);

                uStack_40 = (uint8_t)piVar2[0x5a];

                iStack_48 = piVar2[0x58];

                iStack_44 = piVar2[0x59];

                local_50[0] = 0x203a;

                uStack_36 = 1;

                uStack_38 = (char)(uVar8 % uVar3);

                uStack_37 = (char)(uVar9 % uVar4);

                uStack_34 = (**(code **)(*piVar2 + 0x25c))();

                Client_SendSectorPacket(&DAT_00d1a840,0x20,local_50);

              }

            }

          }

        }

        local_70 = (int *)*local_70;

        param_1 = iStack_60;

      } while (local_70 != local_58);

    }

    Client_RefreshOpenMissionUiWindows(param_1);

    FUN_0092ce90();

    puStack_8 = (uint8_t *)0xffffffff;

    FUN_00404060();

                    /* WARNING: Subroutine does not return */

    operator_delete(local_58);

  }

  return 1;

}
