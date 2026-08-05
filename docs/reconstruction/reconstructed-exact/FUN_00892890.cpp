// =============================================================================
// FUN_00892890
// -----------------------------------------------------------------------------
// Stable ID: aa_00892890
// Address:   0x00892890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00892890 @ 0x00892890
// Stable ID: aa_00892890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×21, goto×3, do×2, while×2, return×1.
//  - Notable callees: SUB41×2, FUN_00892890, SUB42, Skill_GetCategoryCooldownRemaining, Skill_SetRankAndReevaluate, Vehicle_GetSkillCooldownModifier.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00892890(void)



{

  float fVar1;

  int *piVar2;

  float fVar3;

  int in_EAX;

  void *pSkill;

  int iVar4;

  uint uVar5;

  float unaff_EBX;

  char *pcVar6;

  char *pcVar7;

  int *piVar8;

  float unaff_EDI;

  void *this;

  float10 extraout_ST0;

  float10 fVar9;

  float10 fVar10;

  float10 extraout_ST0_00;

  float fVar11;

  uint32_t /* width from decompiler */ uVar12;

  

  if (DAT_00d1b6d8 != (void *)0x0) {

    pcVar6 = (char *)(in_EAX + 0x528);

    piVar8 = (int *)(in_EAX + 0x548);

    do {

      pcVar7 = pcVar6 + (-0x528 - in_EAX);

      if (((int)pcVar7 < 0) || (2 < (int)pcVar7)) {

        uVar5 = 0xffffffff;

      }

      else {

        uVar5 = *(uint *)((0x810 - in_EAX) + (int)piVar8 + (int)DAT_00d1b6d8);

      }

      iVar4 = *(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x74 + (int)DAT_00d1b6d8);

      iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x10) + (*(uint *)(iVar4 + 8) & uVar5) * 4) + 4);

      if (iVar4 == 0) {

LAB_00892924:

        this = (void *)0x0;

      }

      else {

        do {

          if (uVar5 == *(uint *)(iVar4 + 0x10)) {

            if (iVar4 == 0) goto LAB_00892924;

            this = *(void **)(iVar4 + 8);

            goto LAB_0089292b;

          }

          iVar4 = *(int *)(iVar4 + 0xc);

        } while (iVar4 != 0);

        this = (void *)0x0;

      }

LAB_0089292b:

      if ((this == (void *)0x0) || (*(char **)((int)DAT_00d1b6d8 + 0xd64) == pcVar7)) {

        *pcVar6 = '\0';

        if ((int *)*piVar8 != (int *)0x0) {

          (**(code **)(*(int *)*piVar8 + 0x3b0))(0);

        }

      }

      else {

        pSkill = (void *)(**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +

                                              (int)DAT_00d1b6d8) + 0x27c))();

        Skill_SetRankAndReevaluate(this,pSkill,SUB42(unaff_EDI,0));

        if (*(char *)((int)this + 0x628) == '\0') {

          Skill_GetCategoryCooldownRemaining(*(float10 **)((int)this + 0x5e8),0,SUB41(unaff_EDI,0));

          if ((float)extraout_ST0_00 <= DAT_00aaa664) {

            *pcVar6 = '\0';

            if ((int *)*piVar8 != (int *)0x0) {

              (**(code **)(*(int *)*piVar8 + 0x3b0))(0);

            }

          }

          else {

            Skill_GetCategoryCooldownRemaining

                      (*(float10 **)((int)this + 0x5e8),1,SUB41(unaff_EDI,0));

            *pcVar6 = '\x01';

            if ((int *)*piVar8 != (int *)0x0) {

              (**(code **)(*(int *)*piVar8 + 0x3b0))((float)extraout_ST0_00);

              (**(code **)(*(int *)*piVar8 + 0x3ac))(0);

              if (unaff_EBX == g_flZero) {

                (**(code **)(*(int *)*piVar8 + 0x3b4))(0);

              }

              else {

                iVar4 = *(int *)*piVar8;

                fVar9 = (float10)(**(code **)(iVar4 + 0x3c0))();

                (**(code **)(iVar4 + 0x3b4))((float)(fVar9 / (float10)unaff_EBX));

              }

            }

          }

        }

        else {

          iVar4 = g_dwClientTickMs - *(int *)((int)this + 0x178);

          fVar3 = (float)iVar4;

          if (iVar4 < 0) {

            fVar3 = fVar3 + _DAT_00aaa5dc;

          }

          fVar3 = fVar3 * g_flMsToSeconds_Inferred;

          iVar4 = *(int *)((int)this + 0x10);

          fVar11 = (float)(int)*(short *)((int)this + 0x14) * g_flMsToSeconds_Inferred;

          Vehicle_GetSkillCooldownModifier(DAT_00d1b6d8,*(float10 **)((int)this + 0x5ec),unaff_EDI);

          fVar1 = (float)((float10)iVar4 * (float10)g_flMsToSeconds_Inferred * extraout_ST0);

          if (*pcVar6 == '\0') {

            piVar2 = (int *)*piVar8;

            if (piVar2 != (int *)0x0) {

              if (fVar11 <= fVar3) {

                if (fVar1 == g_flZero) {

                  uVar12 = 0x3f800000;

                  goto LAB_00892a4d;

                }

                (**(code **)(*piVar2 + 0x3b0))(g_flOne - (fVar3 - fVar11) / fVar1);

              }

              else if (fVar11 == g_flZero) {

                uVar12 = 0;

LAB_00892a4d:

                (**(code **)(*piVar2 + 0x3b0))(uVar12);

              }

              else {

                (**(code **)(*piVar2 + 0x3b0))(fVar3 / fVar11);

              }

            }

            *pcVar6 = '\x01';

          }

          if ((int *)*piVar8 != (int *)0x0) {

            iVar4 = g_dwClientTickMs - *(int *)((int)this + 0x178);

            fVar1 = (float)iVar4;

            if (iVar4 < 0) {

              fVar1 = fVar1 + _DAT_00aaa5dc;

            }

            iVar4 = *(int *)*piVar8;

            if (fVar11 <= fVar1 * g_flMsToSeconds_Inferred) {

              (**(code **)(iVar4 + 0x3ac))(0);

              fVar9 = (float10)(**(code **)(*(int *)*piVar8 + 0x3c0))();

              fVar10 = (float10)fVar3 + (float10)unaff_EBX;

            }

            else {

              (**(code **)(iVar4 + 0x3ac))(0x3f800000);

              fVar9 = (float10)(**(code **)(*(int *)*piVar8 + 0x3c0))();

              fVar10 = (float10)unaff_EBX;

            }

            (**(code **)(*(int *)*piVar8 + 0x3b4))((float)(fVar9 / (fVar10 - (float10)fVar11)));

          }

        }

      }

      pcVar6 = pcVar6 + 1;

      piVar8 = piVar8 + 1;

    } while ((int)(pcVar6 + (-0x528 - in_EAX)) < 3);

  }

  return;

}
