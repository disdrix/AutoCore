// =============================================================================
// WaterPhase_RegisterToken_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00576860
// Address:   0x00576860–0x00576889 exclusive (41 B)  (autoassault.exe, base 0x400000)
// System:    client / VOGEnvironmentSector water phase
// Generated: 2026-07-29 W32-S dual (from raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: After water object vcall(+0x20), allocate a 4-byte phase token
// (vtbl PTR_FUN_009d3ac4 via FUN_00576c40) and find-or-append it in the global
// registry host DAT_00d1f620 via FUN_00746400.
// Returns -1 on OOM; 1 if already present; 0 if newly appended.
// Parent treats only hr < 0 as "Water phase initialization failed".

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
// micro-ctor: *token = PTR_FUN_009d3ac4; return token
extern "C" void *__thiscall FUN_00576c40(void *token);
// registry: thiscall host; find token in [+4,+8); hit→1; miss→append→0
extern "C" int32_t __thiscall FUN_00746400(void *host, void *token);
extern "C" void *DAT_00d1f620; // registry host pointer (global)

extern "C" int32_t WaterPhase_RegisterToken_Inferred(void)
{
  void *token = operator_new(4);
  if (token != nullptr) {
    void *obj = FUN_00576c40(token);
    if (obj != nullptr) {
      return FUN_00746400(DAT_00d1f620, obj);
    }
  }
  return -1;
}

extern "C" int32_t FUN_00576860(void)
{
  return WaterPhase_RegisterToken_Inferred();
}
