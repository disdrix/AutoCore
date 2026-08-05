// =============================================================================
// Input_TryFirePrimaryWeapons_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00922270
// Address:   0x00922270  (autoassault.exe, image base 0x400000)
// System:    combat / skills-abilities (client input fire)
// Generated: 2026-07-29 dual A/B pass (from Ghidra decompile + asm)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Client primary fire entry (sibling of Input_TryFireSecondaryWeapons @ 0x0091A550).
//   1) Walk hardpoint skill vector at local char+0x550 (end +0x554, stride 0xC).
//      First enabled skill with clear block flags and category-1 CD remaining == 0
//      → Client_CastSkillFromQuickBarSlot(skillId @ skill+0x5FC), then UI tail only.
//   2) Else gun path: same outer gates as secondary (player, flags+0xB8 & 0xD2,
//      sector net vtbl+8, vehicle char+0x250). Tip 0x12, then primary heat probe
//      FUN_004f5290 (vtbl+0x38 group, existential heat-OK), fire FUN_004f50d0,
//      optional chrome FUN_0089ff80 when +0x6B8/+0x6B9 and host vtbl+0x3D8.
//
// CALLERS:
//   Client_QuickBar_ActivateSlot (slot0 off-foot) @ 0x00943754
//   Client_Input_DriveControlTick (held fire)     @ 0x009233DA
//
// NOTES:
//   - Primary heat quantifier is EXISTS (any primary heat-OK); secondary is FORALL.
//   - No heat-fail log string (secondary logs explicitly).
//   - Skill path does not call gun heat/fire in the same invocation.
//   - Vehicle thiscall: ECX = *(char+0x250) for FUN_004f5290 / FUN_004f50d0 (asm).
// =============================================================================

void Input_TryFirePrimaryWeapons_Inferred(void)
{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_EDI; /* decompiler noise; category arg is literal 1 */
  float10 extraout_ST0;

  uVar3 = 0;
  iVar4 = 0;
  iVar5 = DAT_00d1b6d8;
  do {
    /* skill vector empty or index past end → gun path */
    if ((*(int *)(iVar5 + 0x550) == 0) ||
       ((uint)((*(int *)(iVar5 + 0x554) - *(int *)(iVar5 + 0x550)) / 0xc) <= uVar3)) {
      if (((iVar5 != 0) &&
          ((*(byte *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xb8 + iVar5) & 0xd2) == 0)) &&
         ((g_pSectorNetConnection_INFERRED != (void *)0x0 &&
          ((cVar2 = (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 8))(), cVar2 != '\0' &&
           (*(int *)(DAT_00d1b6d8 + 0x250) != 0)))))) {
        Client_MaybeShowFirstTimeTip(0x12);
        /* ECX = vehicle @ char+0x250 (asm); primary group vtbl+0x38 */
        cVar2 = FUN_004f5290();
        if (cVar2 != '\0') {
          FUN_004f50d0();
LAB_00922371:
          if ((((*(char *)(DAT_00d1b6d8 + 0x6b8) != '\0') ||
               (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) && (DAT_00d1b8f0 != (int *)0x0)) &&
             (cVar2 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar2 != '\0')) {
            FUN_0089ff80();
          }
        }
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar5 + 0x550) + iVar4);
    if ((*(char *)(*(int *)(iVar5 + 0x550) + iVar4 + 8) != '\0') &&
       ((((*(byte *)(iVar1 + 0x615) & 1) == 0 && (*(char *)(iVar1 + 0x628) == '\0')) &&
        (Skill_GetCategoryCooldownRemaining(*(float10 **)(iVar1 + 0x5e8),1,(char)unaff_EDI),
        iVar5 = DAT_00d1b6d8, (float10)g_flZero == extraout_ST0)))) {
      Client_CastSkillFromQuickBarSlot(*(undefined4 *)(iVar1 + 0x5fc));
      goto LAB_00922371; /* UI only — no gun heat/fire */
    }
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 0xc;
  } while( true );
}
