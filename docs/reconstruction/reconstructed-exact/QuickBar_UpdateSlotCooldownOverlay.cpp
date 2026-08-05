// =============================================================================
// QuickBar_UpdateSlotCooldownOverlay
// -----------------------------------------------------------------------------
// Stable ID: aa_00827ab0
// Address:   0x00827ab0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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
/* QuickBar_UpdateSlotCooldownOverlay
   
   Variant for skill(type=1) vs item(type=2) quickbar buttons.
   Same charge/category-cooldown split as QuickBar_UpdateSkillSlotCooldownGauge;
   item path uses inventory cooldown lookup. */

void __fastcall QuickBar_UpdateSlotCooldownOverlay(void *pButton)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float unaff_ESI;
  float unaff_EDI;
  float10 extraout_ST0;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST0_00;
  float fVar8;
  float fVar9;
  uint32_t /* width from decompiler */ uVar10;
  
  if (*(int *)((int)pButton + 0x570) == 0) {
    return;
  }
  if (*(int *)((int)pButton + 0x548) == 2) {
    if ((((DAT_00d1b6d8 == (void *)0x0) || (*(int *)((int)DAT_00d1b6d8 + 0x250) == 0)) ||
        (*(int *)(*(int *)((int)DAT_00d1b6d8 + 0x250) + 0x2b0) == 0)) ||
       ((piVar3 = (int *)FUN_005710c0(*(uint32_t /* width from decompiler */ *)((int)pButton + 0x550),0,0),
        piVar3 == (int *)0x0 &&
        (piVar3 = (int *)FUN_005710c0(*(uint32_t /* width from decompiler */ *)((int)pButton + 0x550),0,0),
        piVar3 == (int *)0x0)))) goto LAB_00827e44;
    iVar4 = (**(code **)(*piVar3 + 0x234))(*(uint32_t /* width from decompiler */ *)(*(int *)(piVar3[0x2a] + 0x3c) + 0x3bc));
  }
  else {
    if ((*(int *)((int)pButton + 0x548) != 1) || (DAT_00d1b6d8 == (void *)0x0)) goto LAB_00827e44;
    iVar4 = *(int *)((int)pButton + 0x558);
  }
  if (iVar4 == 0) {
LAB_00827e44:
    *(uint32_t /* width from decompiler */ *)((int)pButton + 0x50c) = *(uint32_t /* width from decompiler */ *)((int)pButton + 0x508);
    *(uint8_t *)((int)pButton + 0x4fe) = 0;
    (**(code **)(**(int **)((int)pButton + 0x570) + 0x3b0))(0);
    FUN_008279b0(1);
    if ((*(int **)((int)pButton + 0x57c) != (int *)0x0) &&
       (cVar2 = (**(code **)(**(int **)((int)pButton + 0x57c) + 0xd0))(), cVar2 == '\0')) {
      (**(code **)(**(int **)((int)pButton + 0x57c) + 0xfc))(1,0x3e800000);
                    /* WARNING: Could not recover jumptable at 0x00827eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)((int)pButton + 0x57c) + 0x34c))();
      return;
    }
    return;
  }
  if (*(char *)(iVar4 + 0x628) == '\0') {
    if (DAT_00d1b6d8 != (void *)0x0) {
      Skill_GetCategoryCooldownRemaining(*(float10 **)(iVar4 + 0x5e8),0,SUB41(unaff_EDI,0));
      if (DAT_00aaa664 < (float)extraout_ST0_00) {
        Skill_GetCategoryCooldownRemaining(*(float10 **)(iVar4 + 0x5e8),1,SUB41(unaff_EDI,0));
        fVar1 = g_flOne;
        if (*(char *)((int)pButton + 0x4fe) == '\0') {
          *(uint8_t *)((int)pButton + 0x4fe) = 1;
          *(float *)((int)pButton + 0x50c) = fVar1;
          FUN_008279b0(0);
          if (*(int **)((int)pButton + 0x57c) != (int *)0x0) {
            (**(code **)(**(int **)((int)pButton + 0x57c) + 4))(0);
          }
        }
        (**(code **)(**(int **)((int)pButton + 0x570) + 0x3b0))((float)extraout_ST0_00);
        (**(code **)(**(int **)((int)pButton + 0x570) + 0x3ac))(0);
        if (unaff_ESI != g_flZero) {
          iVar4 = **(int **)((int)pButton + 0x570);
          fVar6 = (float10)(**(code **)(iVar4 + 0x3c0))();
          (**(code **)(iVar4 + 0x3b4))((float)(fVar6 / (float10)unaff_ESI));
          return;
        }
        (**(code **)(**(int **)((int)pButton + 0x570) + 0x3b4))(0);
        return;
      }
    }
    goto LAB_00827e44;
  }
  iVar5 = g_dwClientTickMs - *(int *)(iVar4 + 0x178);
  fVar1 = (float)iVar5;
  if (iVar5 < 0) {
    fVar1 = fVar1 + _DAT_00aaa5dc;
  }
  fVar1 = fVar1 * g_flMsToSeconds_Inferred;
  fVar8 = (float)(int)*(short *)(iVar4 + 0x14) * g_flMsToSeconds_Inferred;
  fVar9 = (float)*(int *)(iVar4 + 0x10) * g_flMsToSeconds_Inferred;
  if (DAT_00d1b6d8 != (void *)0x0) {
    Vehicle_GetSkillCooldownModifier(DAT_00d1b6d8,*(float10 **)(iVar4 + 0x5ec),unaff_EDI);
    fVar9 = (float)(extraout_ST0 * (float10)fVar9);
  }
  if (*(char *)((int)pButton + 0x4fe) != '\0') goto LAB_00827cae;
  piVar3 = *(int **)((int)pButton + 0x570);
  if (fVar8 <= fVar1) {
    if (fVar9 == g_flZero) {
      uVar10 = 0x3f800000;
      goto LAB_00827c75;
    }
    (**(code **)(*piVar3 + 0x3b0))(g_flOne - (fVar1 - fVar8) / fVar9);
  }
  else if (fVar8 == g_flZero) {
    uVar10 = 0;
LAB_00827c75:
    (**(code **)(*piVar3 + 0x3b0))(uVar10);
  }
  else {
    (**(code **)(*piVar3 + 0x3b0))(fVar1 / fVar8);
  }
  fVar1 = g_flOne;
  *(uint8_t *)((int)pButton + 0x4fe) = 1;
  *(float *)((int)pButton + 0x50c) = fVar1;
  FUN_008279b0(0);
  if (*(int **)((int)pButton + 0x57c) != (int *)0x0) {
    (**(code **)(**(int **)((int)pButton + 0x57c) + 4))(0);
  }
LAB_00827cae:
  iVar4 = g_dwClientTickMs - *(int *)(iVar4 + 0x178);
  fVar1 = (float)iVar4;
  if (iVar4 < 0) {
    fVar1 = fVar1 + _DAT_00aaa5dc;
  }
  if (fVar8 <= fVar1 * g_flMsToSeconds_Inferred) {
    (**(code **)(**(int **)((int)pButton + 0x570) + 0x3ac))(0);
    fVar6 = (float10)(**(code **)(**(int **)((int)pButton + 0x570) + 0x3c0))();
    fVar7 = (float10)unaff_ESI + (float10)fVar9;
  }
  else {
    (**(code **)(**(int **)((int)pButton + 0x570) + 0x3ac))(0x3f800000);
    fVar6 = (float10)(**(code **)(**(int **)((int)pButton + 0x570) + 0x3c0))();
    fVar7 = (float10)fVar9;
  }
  (**(code **)(**(int **)((int)pButton + 0x570) + 0x3b4))((float)(fVar6 / (fVar7 - (float10)fVar8)))
  ;
  return;
}
