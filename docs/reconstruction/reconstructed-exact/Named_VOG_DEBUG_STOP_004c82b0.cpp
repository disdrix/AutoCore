// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×14, do×1, goto×1, while×1, return×1.
//  - Notable callees: CONCAT22, CVOGCreature_PostCreateFromPacket, CVOGReaction_ResolveObjectTarget, FUN_004c82b0, FUN_004cf320, FUN_004d4040, FUN_004e3260, FUN_005138e0.
//  - Strings: "%S %s"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_004c82b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c82b0
// Address:   0x004c82b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall

Named_VOG_DEBUG_STOP_004c82b0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  DWORD DVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int iVar8;

  void *this;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar9;

  byte bVar10;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint uVar11;

  char acStack_104 [260];

  

  FUN_005c9120(param_2,param_3,param_4,param_5,param_6,param_7,param_8);

  if ((param_2 != 0) && (param_4 != 0)) {

    DVar3 = GetTickCount();

    *(DWORD *)(param_1 + -0x4ec) = DVar3;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0053e0b0();

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 100);

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x68);

    puVar4[2] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c);

    *puVar4 = uVar1;

    puVar4[1] = uVar6;

    puVar4[3] = 0;

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x3d8);

    FUN_004cf320(uVar6);

    iVar5 = FUN_00568640(uVar6);

    if ((iVar5 != 0) && (99 < *(short *)(iVar5 + 0x12))) {

      uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                          0x15c))();

      sprintf(acStack_104,"%S %s",iVar5 + 0x16,uVar6);

      FUN_00516720(acStack_104);

    }

    *(uint8_t *)(param_1 + -0x294) = *(uint8_t *)(param_2 + 0x127);

    iVar5 = *(int *)(param_2 + 0x108);

    if (iVar5 != -1) {

      piVar7 = (int *)CVOGReaction_ResolveObjectTarget(0,iVar5,iVar5 >> 0x1f);

      if (piVar7 == (int *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (**(code **)(*piVar7 + 0x1ec))();

      }

      *(int *)(param_1 + -0x2a8) = iVar5;

      if (iVar5 == 0) {

        piVar7 = (int *)FUN_004e3260(*(int *)(param_2 + 0x108),*(int *)(param_2 + 0x108) >> 0x1f);

        if (piVar7 == (int *)0x0) {

          uVar6 = 0;

        }

        else {

          uVar6 = (**(code **)(*piVar7 + 0x1ec))();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x2a8) = uVar6;

      }

      if (*(int *)(param_1 + -0x2a8) != 0) {

        FUN_00563a70(param_1 + -0x500);

        if (param_1 == 0x500) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1;

        }

        iVar8 = *(int *)(param_1 + -0x2a8);

        if (iVar8 != 0) {

          iVar8 = *(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8;

        }

        FUN_005138e0(iVar8,iVar5);

      }

    }

    iVar5 = *(int *)(param_2 + 0x128);

    if (iVar5 != -1) {

      FUN_004d4040(param_1 + -0x500,*(int *)(param_2 + 300),*(int *)(param_2 + 300) >> 0x1f,iVar5,

                   iVar5 >> 0x1f);

    }

    cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                        0x198))();

    if ((cVar2 == '\0') && (bVar10 = 0, *(char *)(param_2 + 0x10c) != '\0')) {

      do {

        uVar11 = (uint)bVar10;

        this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc +

                                            param_1) + 0x234))

                                 (*(uint32_t /* width from decompiler */ *)(param_2 + 0x138 + uVar11 * 8));

        uVar9 = extraout_var;

        if (this == (void *)0x0) {

          Skill_EnsureLoadedInTree

                    ((void *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1),

                     *(int *)(param_2 + 0x138 + uVar11 * 8),0);

          this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc +

                                              param_1) + 0x234))

                                   (*(uint32_t /* width from decompiler */ *)(param_2 + 0x138 + uVar11 * 8));

          uVar9 = extraout_var_00;

          if (this != (void *)0x0) goto LAB_004c8583;

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        else {

LAB_004c8583:

          Skill_SetRankAndReevaluate

                    (this,(void *)CONCAT22(uVar9,*(uint16_t *)(param_2 + 0x13c + uVar11 * 8)),

                     (short)unaff_EBP);

        }

        bVar10 = bVar10 + 1;

      } while (bVar10 < *(byte *)(param_2 + 0x10c));

    }

    if (((char)param_7 == '\0') ||

       ((*(uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x380 + param_1) >> 6 & 1) == 0)) {

      CVOGCreature_PostCreateFromPacket(param_2,param_3,param_5,param_6,param_7,0);

    }

  }

  return;

}
