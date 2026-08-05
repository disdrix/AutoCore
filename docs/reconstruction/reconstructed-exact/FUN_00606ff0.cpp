// =============================================================================
// FUN_00606ff0  (scaffold alias → Outpost_PreRecastBankWalk)
// -----------------------------------------------------------------------------
// Stable ID: aa_00606ff0
// Address:   0x00606ff0  (autoassault.exe, image base 0x400000)
// Canonical: Outpost_PreRecastBankWalk
// Dual A/B:  2026-07-29 W20-C accept-with-gaps
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer: reconstructed-exact/Outpost_PreRecastBankWalk.cpp

void __thiscall FUN_00606ff0(int param_1, unsigned int param_2)
{
  unsigned int *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  unsigned int uVar5;
  int local_4;

  if ((-1 < (int)param_2) && ((int)param_2 < 4)) {
    param_1 = param_1 + param_2 * 0x48;
    local_4 = 0;
    for (param_2 = 0;
        (iVar2 = *(int *)(param_1 + 0xd4), iVar2 != 0 &&
        (param_2 < (unsigned int)(*(int *)(param_1 + 0xd8) - iVar2 >> 4))); param_2 = param_2 + 1) {
      if (*(char *)((unsigned int *)(iVar2 + local_4) + 3) == '\0') {
        for (uVar5 = 0;
            (iVar4 = *(int *)(param_1 + 0xb4), iVar4 != 0 &&
            (uVar5 < (unsigned int)(*(int *)(param_1 + 0xb8) - iVar4 >> 3))); uVar5 = uVar5 + 1) {
          puVar1 = (unsigned int *)(iVar4 + uVar5 * 8);
          piVar3 = (int *)CVOGReaction_ResolveObjectTarget(0, *puVar1, puVar1[1]);
          if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x1ec))(), iVar4 != 0)) {
            (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x220))
                      (*(unsigned int *)(iVar2 + local_4), 1);
          }
        }
      }
      local_4 = local_4 + 0x10;
    }
  }
  return;
}
