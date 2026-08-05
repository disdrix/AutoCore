// =============================================================================
// FUN_004c4070  /  Object_GetTargetAccuracyBase_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4070
// Address:   0x004c4070  (autoassault.exe, image base 0x400000)
// Body:      0x004c4070–0x004c413d
// System:    combat / accuracy stats
// Generated: 2026-07-23 scaffold; 2026-07-29 W17-O dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + thr bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept — clamp + vehicle thr seal.
// Prefer: reconstructed-exact/Object_GetTargetAccuracyBase_Inferred.cpp
// =============================================================================

/*
 * score = min(min(*(i16*)(this+0x13e),200) + *(i16*)(this+0x146), 250)
 * thr   = (MI vtbl+0x1DC() != 0) ? 1 : -100
 * return (thr < score) ? score : thr
 *
 * Used as TargetAccuracy base by Client_DebugDumpEntityCombatStats (level
 * formula applied outside this unit).
 */

int __fastcall FUN_004c4070(int param_1)
{
  short sVar1;
  int iVar2;
  short sVar3;
  int iVar4;

  sVar1 = *(short *)(param_1 + 0x13e);
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  if ((int)sVar3 + (int)*(short *)(param_1 + 0x146) < 0xfa) {
    if (199 < sVar1) {
      sVar1 = 200;
    }
    iVar4 = (int)sVar1 + (int)*(short *)(param_1 + 0x146);
  }
  else {
    iVar4 = 0xfa;
  }
  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();
  if ((int)((-(uint)(iVar2 != 0) & 0x65) - 100) < iVar4) {
    sVar1 = *(short *)(param_1 + 0x13e);
    sVar3 = sVar1;
    if (199 < sVar1) {
      sVar3 = 200;
    }
    if ((int)sVar3 + (int)*(short *)(param_1 + 0x146) < 0xfa) {
      if (199 < sVar1) {
        sVar1 = 200;
      }
      return (int)sVar1 + (int)*(short *)(param_1 + 0x146);
    }
    return 0xfa;
  }
  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();
  return (-(uint)(iVar4 != 0) & 0x65) - 100;
}
