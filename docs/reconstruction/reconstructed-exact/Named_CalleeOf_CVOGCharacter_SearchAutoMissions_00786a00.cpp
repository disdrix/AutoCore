// =============================================================================
// Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00786a00
// Alias of FUN_00786a00 / Profiler_EnterNamedZone (Probable)
// -----------------------------------------------------------------------------
// Stable ID: aa_00786a00
// Callee of CVOGCharacter_SearchAutoMissions (profile enter)
// Address:   0x00786a00  (autoassault.exe, image base 0x400000)
// System:    client instrumentation
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B assembly correction
// Exactness: Same body as FUN_00786a00.cpp — keep in sync.
// Duals: reviews/A_aa_00786a00_Profiler_EnterNamedZone.md
//        reviews/B_aa_00786a00_Profiler_EnterNamedZone.md
// =============================================================================

// PURPOSE:
//   SearchAutoMissions call site:
//     ECX = *[DAT_00afa27c]; PUSH "CVOGCharacter::SearchAutoMissions"; CALL 0x00786a00
//   Instrumentation enter only — does not grant missions.
//   Paired leave: FUN_00786990 on same profiler this.

#include <cstdint>

int FUN_007866e0(void* profiler);
void* __thiscall FUN_00786470(void* parentZone, const char* name);
void FUN_00785e00_StartZoneTimer(void* zone);

void* __thiscall Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00786a00(
    void* profiler, const char* name)
{
  if (*(std::uint8_t*)((char*)profiler + 0x175) == 0) {
    return 0;
  }

  int idx = FUN_007866e0(profiler);
  char* slots = *(char**)((char*)profiler + 0x4c);
  void* parent = *(void**)(slots + idx * 0xc + 8);

  void* zone = FUN_00786470(parent, name);
  FUN_00785e00_StartZoneTimer(zone);

  idx = FUN_007866e0(profiler);
  slots = *(char**)((char*)profiler + 0x4c);
  *(void**)(slots + idx * 0xc + 8) = zone;

  return zone;
}
