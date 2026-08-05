// =============================================================================
// Outpost_UpdateBeaconShareRatio  (was FUN_006078e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006078e0
// Address:   0x006078e0  (autoassault.exe, image base 0x400000)
// Body:      0x006078e0–0x006079e2
// System:    skills-abilities / outpost
// Dual A/B:  2026-07-29 W19-O  accept-with-gaps
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Recompute outpost beacon-share ratio:
//     ratio = factionBeacons / totalBeacons  →  this+0x24c
//   When totalBeacons <= 0: log and leave ratio unchanged.
//   When ratio changes: FUN_00606ff0(faction) then Outpost_CastSkillsForBeaconShare(faction).
//
// SIGNATURE
//   void __thiscall Outpost_UpdateBeaconShareRatio(void* thisOutpost);
//   // ECX = outpost; no stack args; RET
//
// KEY OFFSETS
//   this+0x1d0                 u32 map-var id → total beacons
//   this+0x234                 int current faction index
//   this+0xf0 + faction*0x48   u32 map-var id → faction beacons
//   this+0x24c                 float share ratio (written here)
//
// STRINGS
//   "Total beacons was %f on map %s"
//
// CALLERS
//   FUN_006082e0 (CaptureOutpost path) after faction store
//   MI thunk 0x006079f0: add ecx,-0x260; call this; ret 4
//
// SIBLINGS
//   Outpost_CastSkillsForBeaconShare @ 0x006070e0  (consumer of +0x24c)
//   FUN_00606ff0 @ 0x00606ff0                     (pre-recast bank walk)
// =============================================================================

void __thiscall Outpost_UpdateBeaconShareRatio(int thisOutpost)
{
  float totalBeacons;
  float factionBeacons;
  float oldRatio;

  totalBeacons = g_flOne;
  factionBeacons = 0.0f;
  oldRatio = *(float *)(thisOutpost + 0x24c);

  CVOGMap_LookupVariable(*(undefined4 *)(thisOutpost + 0x1d0), &totalBeacons, 0);
  CVOGMap_LookupVariable(
      *(undefined4 *)(thisOutpost + 0xf0 + *(int *)(thisOutpost + 0x234) * 0x48),
      &factionBeacons,
      0);

  if (totalBeacons <= g_flZero) {
    FUN_007a4480(
        0,
        "Total beacons was %f on map %s",
        (double)totalBeacons,
        *(int *)(*(int *)(*(int *)(thisOutpost + 4) + 4) + 0xa8 + thisOutpost) + 0xb4);
    return;
  }

  *(float *)(thisOutpost + 0x24c) = factionBeacons / totalBeacons;

  if (oldRatio != factionBeacons / totalBeacons) {
    FUN_00606ff0(*(undefined4 *)(thisOutpost + 0x234));
    Outpost_CastSkillsForBeaconShare(*(undefined4 *)(thisOutpost + 0x234));
    return;
  }
  return;
}
