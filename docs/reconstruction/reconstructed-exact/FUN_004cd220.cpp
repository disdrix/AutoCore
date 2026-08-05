// =============================================================================
// FUN_004cd220  →  CVOGMap_SampleHeightfieldY
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd220
// Address:   0x004cd220  (autoassault.exe, image base 0x400000)
// System:    world-terrain
// Generated: 2026-07-23 scaffold; refined 2026-07-29 OWN-ONLY dual A/B
// Exactness: Behavior-preserving rewrite of decompiler + body CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer:    CVOGMap_SampleHeightfieldY.cpp (same unit)
// Dual:      reviews/A_aa_004cd220_CVOGMap_SampleHeightfieldY.md
//            reviews/B_aa_004cd220_CVOGMap_SampleHeightfieldY.md
// =============================================================================

// PURPOSE:
//   CVOGMap pure heightfield Y sample at world (x, z).
//   map+0xe4e0 null → 0.0f; else FUN_005a58c0(hf, x, z) via tail.
//   ABI: __thiscall ECX=map; stack float x, float z; RET 8.

extern "C" long double __thiscall FUN_005a58c0(void* heightfield, float x, float z);
extern "C" float g_flZero;  // 0x00a0f518

long double __thiscall FUN_004cd220(void* map, float worldX, float worldZ)
{
  void* heightfield = *(void**)((char*)map + 0xe4e0);

  if (heightfield != 0) {
    return FUN_005a58c0(heightfield, worldX, worldZ);
  }

  return (long double)g_flZero;
}
