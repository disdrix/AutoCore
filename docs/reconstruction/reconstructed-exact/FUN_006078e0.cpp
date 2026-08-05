// =============================================================================
// FUN_006078e0  — scaffold alias of Outpost_UpdateBeaconShareRatio
// -----------------------------------------------------------------------------
// Stable ID: aa_006078e0
// Address:   0x006078e0  (autoassault.exe, image base 0x400000)
// Prefer:    Outpost_UpdateBeaconShareRatio.cpp
// Dual A/B:  2026-07-29 W19-O  accept-with-gaps
// =============================================================================

void __thiscall FUN_006078e0(int param_1)
{
  float local_c;
  float local_8;
  float local_4;

  local_c = g_flOne;
  local_8 = 0.0;
  local_4 = *(float *)(param_1 + 0x24c);
  CVOGMap_LookupVariable(*(undefined4 *)(param_1 + 0x1d0), &local_c, 0);
  CVOGMap_LookupVariable(
      *(undefined4 *)(param_1 + 0xf0 + *(int *)(param_1 + 0x234) * 0x48),
      &local_8,
      0);
  if (local_c <= g_flZero) {
    FUN_007a4480(0, "Total beacons was %f on map %s", (double)local_c,
                 *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xb4);
  }
  else {
    *(float *)(param_1 + 0x24c) = local_8 / local_c;
    if (local_4 != local_8 / local_c) {
      FUN_00606ff0(*(undefined4 *)(param_1 + 0x234));
      Outpost_CastSkillsForBeaconShare(*(undefined4 *)(param_1 + 0x234));
      return;
    }
  }
  return;
}
