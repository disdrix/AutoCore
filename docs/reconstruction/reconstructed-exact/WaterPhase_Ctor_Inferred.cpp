// =============================================================================
// WaterPhase_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005769c0
// Address:   0x005769c0–0x00576a07 exclusive (71 B)  (autoassault.exe, base 0x400000)
// System:    client / VOGEnvironmentSector water phase
// Generated: 2026-07-29 W32-S dual (from raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Complete ctor for 0x20 water-phase process singleton.
// Installs vtbl PTR_FUN_009d3b04, stores view* at +0x04, zeros +0x0C..+0x1C.
// Does NOT write +0x08. Called from PalantirEnv_InitPhases_Inferred when
// DAT_00b04808 == 0 (new(0x20) + this).

#include <cstdint>

extern "C" uint32_t PTR_FUN_009d3b04; // vtbl base (rdata)

// __thiscall; ECX=self; stack view*; RET 4; returns self (EAX)
extern "C" void *__thiscall WaterPhase_Ctor_Inferred(void *self, void *view)
{
  auto *p = reinterpret_cast<uint32_t *>(self);

  p[1] = reinterpret_cast<uint32_t>(view); // +0x04
  p[0] = reinterpret_cast<uint32_t>(&PTR_FUN_009d3b04);
  p[3] = 0; // +0x0C
  p[4] = 0;
  p[5] = 0;
  p[6] = 0;
  p[7] = 0; // +0x1C
  // p[2] (+0x08) intentionally not written (matches retail)

  return self;
}

// Scaffold alias
extern "C" void *__thiscall FUN_005769c0(void *self, void *view)
{
  return WaterPhase_Ctor_Inferred(self, view);
}
