// =============================================================================
// FUN_0061db60
// -----------------------------------------------------------------------------
// Stable ID: aa_0061db60
// Address:   0x0061db60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061db60 @ 0x0061db60
// Stable ID: aa_0061db60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0040aff0×2, FUN_00512150×2, CONCAT22, FUN_004d0e90, FUN_00578270, FUN_0061db60, TFID_NotEquals.
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

void __thiscall FUN_0061db60(int *param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *pA;

  uint16_t extraout_var;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint8_t *puVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint8_t auStack_24 [32];

  

  if (((*(char *)(param_1[0x1a2] + 0x7e) != '\0') &&

      (((iVar2 = (**(code **)(*(int *)param_1[6] + 0x1d8))(), iVar2 == 0 ||

        (iVar2 = (**(code **)(*(int *)param_1[6] + 0x1d8))(), *(char *)(iVar2 + 0x307) == '\0')) &&

       ((char)param_1[0x1b0] != '\0')))) &&

     ((cVar1 = (**(code **)(*(int *)param_1[6] + 0x298))(param_2), cVar1 != '\0' &&

      (((*(int *)(param_2[0x2a] + 0x38) == 0xe || (*(int *)(param_2[0x2a] + 0x38) == 0x12)) &&

       (((uint)param_2[0x5f] >> 10 & 1) == 0)))))) {

    puVar3 = CVOGReaction_ResolveSkillTargets

                       ((void *)param_1[0x5d],

                        CONCAT22(extraout_var,(short)param_1[0x40]) & 0xffff00ff);

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[6] + 0x1a0))();

    uStack_34 = *puVar4;

    uVar13 = 0;

    uVar11 = 0;

    uVar10 = 0xffffffff;

    uVar9 = 0;

    puVar14 = &uStack_34;

    uStack_30 = puVar4[1];

    uVar8 = 0;

    uStack_2c = puVar4[2];

    uVar7 = 0;

    uStack_28 = puVar4[3];

    piVar6 = param_2;

    uVar5 = FUN_00578270(param_2,0,0,puVar14,0,0xffffffff,0,0);

    CVOGReaction_CastSkillOnTarget

              (puVar3,uVar5,piVar6,uVar7,uVar8,puVar14,uVar9,uVar10,uVar11,uVar13);

    if ((char)param_1[0x1b2] != '\0') {

      param_1[0x1b1] = param_1[0x1b1] + -1;

      if (param_1[0x1b1] < 1) {

        if ((float)param_1[0x62] == g_flZero) {

          *(uint32_t /* width from decompiler */ *)(param_1[6] + 0xcc) = 2;

          uVar7 = DAT_009e2a54;

          uVar5 = DAT_009e2a50;

          uStack_38 = DAT_009e2a5c;

          uStack_3c = DAT_009e2a58;

          iVar2 = (**(code **)(*param_2 + 0x214))();

          if (iVar2 != 0) {

            iVar2 = (**(code **)(*param_2 + 0x214))();

            puVar14 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);

            uVar5 = *puVar14;

            uVar7 = puVar14[1];

            uStack_3c = puVar14[2];

            uStack_38 = puVar14[3];

            puVar14 = &DAT_009e2a50;

            puVar12 = auStack_24;

            (**(code **)(*param_2 + 0x214))(puVar12);

            pA = (void *)FUN_0040aff0(puVar12);

            iVar2 = TFID_NotEquals(pA,puVar14);

            if ((char)iVar2 != '\0') {

              puVar12 = auStack_24;

              (**(code **)(*param_2 + 0x214))(puVar12);

              puVar14 = (uint32_t /* width from decompiler */ *)FUN_0040aff0(puVar12);

              uStack_3c = puVar14[2];

              uVar5 = *puVar14;

              uVar7 = puVar14[1];

              uStack_38 = puVar14[3];

            }

          }

          (**(code **)(*(int *)param_1[6] + 600))(uVar5,uVar7,uStack_3c,uStack_38);

          FUN_004d0e90(param_1[6]);

        }

        else {

          FUN_00512150(6,0,param_1[0x188],1);

          (**(code **)(*param_1 + 0x18))(1,1);

        }

      }

      else {

        FUN_00512150(5,(float)param_1[0x1b1],param_1[0x188],1);

      }

      *(uint8_t *)(param_1 + 0x1b0) = 0;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar3);

  }

  return;

}
