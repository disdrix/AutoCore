// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_004cd220
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd220
// Canonical: CVOGMap_SampleHeightfieldY (Probable)
// Address:   0x004cd220  (autoassault.exe, image base 0x400000)
// System:    world-terrain (also DriveControlTick camera ground consumer)
// Generated: 2026-07-23 parent-seed name; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite. Not modernization.
// Note:      Parent-seed alias only — function has ~34 named callers, not DCT-only.
// Dual:      reviews/A_aa_004cd220_CVOGMap_SampleHeightfieldY.md
//            reviews/B_aa_004cd220_CVOGMap_SampleHeightfieldY.md
// Prefer:    CVOGMap_SampleHeightfieldY.cpp
// =============================================================================

// PURPOSE:
//   Shared map heightfield Y sample. DriveControlTick calls after PushDriveAxes
//   (~0x009236d2) with world (X,Z) for look-projection ground Y.
//   Gate map+0xe4e0 → FUN_005a58c0(hf,x,z) or 0.0f.

extern "C" long double __thiscall FUN_005a58c0(void* heightfield, float x, float z);
extern "C" float g_flZero;  // 0x00a0f518

long double __thiscall Named_CalleeOf_Client_Input_DriveControlTick_004cd220(
    void* map, float worldX, float worldZ)
{
  void* heightfield = *(void**)((char*)map + 0xe4e0);

  if (heightfield != 0) {
    return FUN_005a58c0(heightfield, worldX, worldZ);
  }

  return (long double)g_flZero;
}
