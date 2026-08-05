// =============================================================================
// FUN_004c41c0  — alias plate for Creature_GetPerception
// -----------------------------------------------------------------------------
// Stable ID: aa_004c41c0
// Address:   0x004c41c0–0x004c428e  (autoassault.exe, image base 0x400000)
// Canonical: Creature_GetPerception
// Generated: 2026-07-29 W18-H dual A/B seal
// See:       reconstructed-exact/Creature_GetPerception.cpp
// Dual:      reviews/A|B_aa_004c41c0_Creature_GetPerception.md
// =============================================================================

int __fastcall FUN_004c41c0(int param_1)
{
  short sVar1;
  int iVar2;
  short sVar3;
  int iVar4;

  sVar1 = *(short *)(param_1 + 0x142);
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  if ((int)sVar3 + (int)*(short *)(param_1 + 0x14a) < 0xfa) {
    if (199 < sVar1) {
      sVar1 = 200;
    }
    iVar4 = (int)sVar1 + (int)*(short *)(param_1 + 0x14a);
  } else {
    iVar4 = 0xfa;
  }
  iVar2 = (**(int (**)())(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();
  if ((int)((-(unsigned int)(iVar2 != 0) & 0x65) - 100) < iVar4) {
    sVar1 = *(short *)(param_1 + 0x142);
    sVar3 = sVar1;
    if (199 < sVar1) {
      sVar3 = 200;
    }
    if ((int)sVar3 + (int)*(short *)(param_1 + 0x14a) < 0xfa) {
      if (199 < sVar1) {
        sVar1 = 200;
      }
      return (int)sVar1 + (int)*(short *)(param_1 + 0x14a);
    }
    return 0xfa;
  }
  iVar4 = (**(int (**)())(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();
  return (-(unsigned int)(iVar4 != 0) & 0x65) - 100;
}
