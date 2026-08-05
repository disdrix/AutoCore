// =============================================================================
// FUN_00786a00  /  Profiler_EnterNamedZone (Probable)
// -----------------------------------------------------------------------------
// Stable ID: aa_00786a00
// Address:   0x00786a00  (autoassault.exe, image base 0x400000)
// System:    client instrumentation (callee of SearchAutoMissions enter/leave pair)
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B assembly correction
// Exactness: Behavior-preserving rewrite of live assembly control flow.
//            Frozen raw decompiler mis-binds FUN_00786470 this — corrected here.
// Bit-for-bit vs retail EXE: DEFERRED
// Duals: reviews/A_aa_00786a00_Profiler_EnterNamedZone.md
//        reviews/B_aa_00786a00_Profiler_EnterNamedZone.md
// =============================================================================

// PURPOSE:
//   Enter a hierarchical named profiler zone on the global profiler object
//   (call sites: ECX = *DAT_00afa27c, stack = C-string name).
//   If enable flag *(profiler+0x175)==0, return 0.
//   Else: resolve thread slot → parent zone at slot+8 → find/create child by name →
//   start QPC timer on child → push child to slot+8 → return child*.
//
// ABI: __thiscall  ECX=profiler*, stack0=const char* name, RET 4, returns void* zone|0
//
// CALL ORDER (live):
//   1) FUN_007866e0(profiler) -> idx
//   2) parent = *( *(profiler+0x4c) + idx*0xc + 8 )
//   3) zone = FUN_00786470(this=parent, name)
//   4) FUN_00785e00 with EAX=zone (StartZoneTimer)
//   5) idx = FUN_007866e0(profiler); push zone to slot+8
//   6) return zone
//
// Notable callees: FUN_007866e0×2, FUN_00786470, FUN_00785e00
// Sibling leave (not this unit): FUN_00786990
// SearchAutoMissions string @0x009cff4c

#include <cstdint>

// Forward decls — bodies owned by their own units
int FUN_007866e0(void* profiler);
void* __thiscall FUN_00786470(void* parentZone, const char* name);
// StartZoneTimer: binary passes zone in EAX (decompiler in_EAX). Modeled as explicit arg.
void FUN_00785e00_StartZoneTimer(void* zone);

void* __thiscall FUN_00786a00(void* profiler, const char* name)
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
