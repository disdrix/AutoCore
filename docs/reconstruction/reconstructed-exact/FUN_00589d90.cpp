// =============================================================================
// FUN_00589d90  (scaffold twin of Skill_HB_ApplyShieldPool_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00589d90
// Address:   0x00589d90  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; refreshed 2026-08-05 MEGA-007
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named clean: Skill_HB_ApplyShieldPool_Inferred.cpp
// =============================================================================

extern "C" float DAT_00aaa668; // -1.0f
extern "C" float g_flOne;      //  1.0f

int FUN_00589d90(int *param_1, int *param_2, float param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;

  if (param_2 != (int *)0x0) {
    iVar3 = (**(code **)(*param_2 + 0x19c))();
    if ((iVar3 != 0) &&
       (piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3),
        piVar5 != (int *)0x0))
      goto LAB_00589de7;
    param_1 = (int *)param_2[0x2b];
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*param_1 + 0x19c))();
  if (iVar3 == 0) {
    return 0;
  }
  piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
LAB_00589de7:
  iVar3 = (**(code **)(*piVar5 + 0x1d4))();
  if (iVar3 != 0) {
    iVar4 = (int)param_3;
    if ((DAT_00aaa668 <= param_3) && (param_3 <= g_flOne)) {
      iVar4 = (int)((float)*(int *)(iVar3 + 0x148) * param_3);
    }
    iVar1 = *(int *)(iVar3 + 0x144);
    iVar2 = *(int *)(iVar3 + 0x148);
    iVar4 = iVar4 + iVar1;
    iVar6 = iVar4;
    if (iVar2 <= iVar4) {
      iVar6 = iVar2;
    }
    if (iVar6 < 1) {
      iVar4 = 0;
    }
    else if (iVar2 <= iVar4) {
      iVar4 = iVar2;
    }
    *(int *)(iVar3 + 0x144) = iVar4;
    if (iVar1 != iVar4) {
      return iVar4 - iVar1;
    }
  }
  return 0;
}
