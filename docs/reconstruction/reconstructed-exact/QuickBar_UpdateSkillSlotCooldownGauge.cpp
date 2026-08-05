// =============================================================================
// QuickBar_UpdateSkillSlotCooldownGauge
// -----------------------------------------------------------------------------
// Stable ID: aa_00825520
// Address:   0x00825520  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 human-refined from raw capture
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Updates quickbar skill button cooldown gauge. Prefers charge/CD fields on skill when skill+0x628 set; else Skill_GetCategoryCooldownRemaining(skill+0x5e8). Drives i_d_qb_2d_btn_quickbar_cooldown.xml.
 *
 * Notes:
 * - Early-out if global DAT_00d1b6d8 null or both +0x6b8/+0x6b9 clear.
 * - Requires button+0x550 skill binding non-null.
 * - Charge path uses skill+0x178 / +0x14 / +0x10 floats for gauge fill.
 * - Category path calls Skill_GetCategoryCooldownRemaining.
 * - Verified against cast-again state machine (raw plate).
 */

void __fastcall QuickBar_UpdateSkillSlotCooldownGauge(void *pButton)
{
    (void)pButton;
    /* gauge fill from charge fields or category remaining; see raw */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* QuickBar_UpdateSkillSlotCooldownGauge(pButton)

   

   Parameters:

     pButton - quickbar skill button widget

   

   Algorithm:

     if skill+0x628: charge then CD from skill+0x178/+0x14/+0x10

     else: Skill_GetCategoryCooldownRemaining(skill+0x5e8)

     drives i_d_qb_2d_btn_quickbar_cooldown.xml gauge

   

   VERIFIED against cast-again state machine. */



void __fastcall QuickBar_UpdateSkillSlotCooldownGauge(void *pButton)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* decomp width */ unaff_EDI;

  int iVar5;

  long double /* x87 */ fVar6;

  long double /* x87 */ extraout_ST0;

  long double /* x87 */ extraout_ST0_00;

  float fVar7;

  char *pcVar8;

  uint32_t /* decomp width */ uVar9;

  float fVar10;

  uint32_t /* decomp width */ uVar11;

  char bAsSeconds;

  float fStack_14;

  float fStack_10;

  float local_c;

  float fStack_8;

  float local_4;

  

  bAsSeconds = (char)unaff_EDI;

  uVar3 = 0;

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if ((*(char *)(DAT_00d1b6d8 + 0x6b8) == '\0') && (*(char *)(DAT_00d1b6d8 + 0x6b9) == '\0')) {

    return;

  }

  if (*(int *)((int)pButton + 0x550) == 0) {

    return;

  }

  iVar5 = 0;

  if ((*(char *)(DAT_00d1b6d8 + 0x6b9) == '\0') ||

     (piVar2 = *(int **)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8),

     piVar2 == (int *)0x0)) {

    local_c = 0.0;

    for (; (*(int *)(DAT_00d1b6d8 + 0x550) != 0 &&

           (uVar3 < (uint)((*(int *)(DAT_00d1b6d8 + 0x554) - *(int *)(DAT_00d1b6d8 + 0x550)) / 0xc))

           ); uVar3 = uVar3 + 1) {

      piVar2 = (int *)((int)local_c + *(int *)(DAT_00d1b6d8 + 0x550));

      iVar1 = *piVar2;

      if ((iVar1 != 0) &&

         ((((*(byte *)(iVar1 + 0x615) & 1) == 0 && (*(int *)((int)pButton + 0x500) == 0)) &&

          ((char)piVar2[2] != '\0')))) {

        iVar5 = iVar1;

      }

      local_c = (float)((int)local_c + 0xc);

    }

  }

  else {

    iVar1 = (**(code **)(*piVar2 + 0x1d8))();

    if (iVar1 == 0) goto LAB_00825a0d;

    iVar4 = 0;

    local_c = 0.0;

    FUN_00402c40();

    iVar5 = FUN_00411900(&local_c);

    bAsSeconds = (char)unaff_EDI;

    while (iVar5 != 0) {

      bAsSeconds = (char)unaff_EDI;

      if ((*(byte *)(iVar5 + 0x615) & 1) == 0) {

        if (iVar4 == *(int *)((int)pButton + 0x500)) break;

        iVar4 = iVar4 + 1;

      }

      iVar5 = FUN_00411900(&local_c);

      bAsSeconds = (char)unaff_EDI;

    }

    *(uint8_t *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x74 + iVar1) + 0x1d) = 0;

  }

  if (iVar5 != 0) {

    if (*(char *)(iVar5 + 0x628) != '\0') {

      iVar1 = g_dwClientTickMs - *(int *)(iVar5 + 0x178);

      fStack_8 = (float)iVar1;

      if (iVar1 < 0) {

        fStack_8 = fStack_8 + _DAT_00aaa5dc;

      }

      fStack_8 = fStack_8 * g_flMsToSeconds_Inferred;

      local_c = (float)(int)*(short *)(iVar5 + 0x14) * g_flMsToSeconds_Inferred;

      local_4 = (float)*(int *)(iVar5 + 0x10) * g_flMsToSeconds_Inferred;

      if (*(char *)((int)pButton + 0x4fe) == '\0') {

        piVar2 = *(int **)((int)pButton + 0x550);

        if (local_c <= fStack_8) {

          if (local_4 == g_flZero) {

            (**(code **)(*piVar2 + 0x3b0))(0x3f800000);

          }

          else {

            (**(code **)(*piVar2 + 0x3b0))(g_flOne - (fStack_8 - local_c) / local_4);

          }

        }

        else {

          if (local_c == g_flZero) {

            (**(code **)(*piVar2 + 0x3b0))(0);

          }

          else {

            (**(code **)(*piVar2 + 0x3b0))(fStack_8 / local_c);

          }

          if (0 < *(short *)(iVar5 + 0x14)) {

            fVar7 = local_c - fStack_8;

            uVar11 = 0;

            fStack_14 = 0.0;

            fStack_10 = -2.5521178e+38;

            pcVar8 = "...Activating Skill...";

            iVar1 = iVar5 + 0x184;

            uVar9 = DAT_00afdf08;

            fVar10 = fStack_10;

            fVar6 = (long double /* x87 */)(**(code **)(**(int **)((int)pButton + 0x550) + 0x3c4))

                                       (fVar7,iVar1,"...Activating Skill...",DAT_00afdf08,0xff400000

                                        ,0,0);

            FUN_007fb690((float)fVar6,fVar7,iVar1,pcVar8,uVar9,fVar10,fStack_14,uVar11);

          }

        }

        fVar10 = g_flOne;

        *(uint8_t *)((int)pButton + 0x4fe) = 1;

        *(float *)((int)pButton + 0x508) = fVar10;

        if (*(int **)((int)pButton + 0x54c) != (int *)0x0) {

          (**(code **)(**(int **)((int)pButton + 0x54c) + 4))(0);

        }

      }

      fStack_8 = (float)(g_dwClientTickMs - *(int *)(iVar5 + 0x178));

      fVar10 = (float)(int)fStack_8;

      if ((int)fStack_8 < 0) {

        fVar10 = fVar10 + _DAT_00aaa5dc;

      }

      if (local_c <= fVar10 * g_flMsToSeconds_Inferred) {

        (**(code **)(**(int **)((int)pButton + 0x550) + 0x3ac))(0);

        iVar5 = g_dwClientTickMs - *(int *)(iVar5 + 0x178);

        local_c = (float)iVar5;

        if (iVar5 < 0) {

          local_c = local_c + _DAT_00aaa5dc;

        }

        local_c = local_c * g_flMsToSeconds_Inferred;

        fVar6 = (long double /* x87 */)(**(code **)(**(int **)((int)pButton + 0x550) + 0x3c0))();

        (**(code **)(**(int **)((int)pButton + 0x550) + 0x3b4))

                  ((float)(fVar6 / (((long double /* x87 */)fStack_8 + (long double /* x87 */)fStack_10) - (long double /* x87 */)local_c)));

        return;

      }

      (**(code **)(**(int **)((int)pButton + 0x550) + 0x3ac))(0x3f800000);

      fStack_8 = (float)(g_dwClientTickMs - *(int *)(iVar5 + 0x178));

      local_c = (float)(int)fStack_8;

      if ((int)fStack_8 < 0) {

        local_c = local_c + _DAT_00aaa5dc;

      }

      local_c = local_c * g_flMsToSeconds_Inferred;

      fVar6 = (long double /* x87 */)(**(code **)(**(int **)((int)pButton + 0x550) + 0x3c0))();

      (**(code **)(**(int **)((int)pButton + 0x550) + 0x3b4))

                ((float)(fVar6 / ((long double /* x87 */)fStack_10 - (long double /* x87 */)local_c)));

      return;

    }

    Skill_GetCategoryCooldownRemaining(*(long double /* x87 */ **)(iVar5 + 0x5e8),0,bAsSeconds);

    fStack_8 = (float)extraout_ST0;

    if (DAT_00aaa664 < fStack_8) {

      Skill_GetCategoryCooldownRemaining(*(long double /* x87 */ **)(iVar5 + 0x5e8),1,bAsSeconds);

      fVar10 = g_flOne;

      local_c = (float)extraout_ST0_00;

      if (*(char *)((int)pButton + 0x4fe) == '\0') {

        *(uint8_t *)((int)pButton + 0x4fe) = 1;

        *(float *)((int)pButton + 0x508) = fVar10;

        if (*(int **)((int)pButton + 0x54c) != (int *)0x0) {

          (**(code **)(**(int **)((int)pButton + 0x54c) + 4))(0);

        }

      }

      (**(code **)(**(int **)((int)pButton + 0x550) + 0x3b0))(fStack_8);

      (**(code **)(**(int **)((int)pButton + 0x550) + 0x3ac))(0);

      if (fStack_14 == g_flZero) {

        (**(code **)(**(int **)((int)pButton + 0x550) + 0x3b4))(0);

        return;

      }

      iVar5 = **(int **)((int)pButton + 0x550);

      fVar6 = (long double /* x87 */)(**(code **)(iVar5 + 0x3c0))();

      (**(code **)(iVar5 + 0x3b4))((float)(fVar6 / (long double /* x87 */)fStack_14));

      return;

    }

  }

LAB_00825a0d:

  *(uint32_t /* decomp width */ *)((int)pButton + 0x508) = *(uint32_t /* decomp width */ *)((int)pButton + 0x504);

  *(uint8_t *)((int)pButton + 0x4fe) = 0;

  (**(code **)(**(int **)((int)pButton + 0x550) + 0x3b0))(0);

  if (*(int **)((int)pButton + 0x54c) != (int *)0x0) {

    (**(code **)(**(int **)((int)pButton + 0x54c) + 0xfc))(1,0x3e800000);

    (**(code **)(**(int **)((int)pButton + 0x54c) + 0x34c))();

  }

  return;

}
