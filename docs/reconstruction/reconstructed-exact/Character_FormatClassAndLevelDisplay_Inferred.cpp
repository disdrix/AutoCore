// =============================================================================
// Character_FormatClassAndLevelDisplay_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00521970
// Address:   0x00521970  (autoassault.exe, image base 0x400000)
// Body:      0x00521970–0x00521a62 exclusive (242 B / 0xF2); pad CC
// System:    skills-abilities / character display
// Generated: 2026-08-05 R10-034 dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      A/B accept-with-gaps — class leaf dualed; callers + product English open.
// =============================================================================

// PURPOSE
//  Format a character class (± level) display label into a caller-owned buffer.
//
//  level = this->vcall(+0x27c)()
//  className = ring( LookupClassDisplayName_Inferred(class@+0x531, race@+0x532) )
//  if (level >= 0):
//      sprintf(out, "%s, %s %i", className, ring("Level"), level)
//      // e.g. "Commando, Level 12"
//  else:
//      sprintf(out, "%s", className)
//
// ABI
//  __thiscall / ECX = character-like this; stack0 = char* out; RET 4; void.
//
// KEY OFFSETS
//  Nested blob path identical to Character_GetClassDisplayName_Inferred (aa_00521900).
//  Class: blob+0x531 (uint8); Race: blob+0x532 (uint8)
//  Level: vtbl slot +0x27c (same as mission [$level])
//
// CALLEES
//  LookupClassDisplayName_Inferred / FUN_0051f940 — cdecl 2-arg class×race leaf
//  FUN_007a69d0 / FUN_007a6de0 — TLS ring copy-out
//  sprintf — IAT
//
// DECOMPILER PITFALLS
//  1. Do not pass a third 0xffffffff to FUN_0051f940; that -1 is FUN_007a6de0 length.
//  2. First FUN_007a69d0() result is kept (EBX) as ECX for "Level" localization.
//  3. RET 4 — one stack arg (out buffer); not a plain cdecl ret.

#include <cstdio>
#include <cstdint>

extern "C" const char* FUN_0051f940(unsigned classId, unsigned raceId);
extern "C" void* FUN_007a69d0(void);
extern "C" char* __thiscall FUN_007a6de0(void* tls_table, const char* src, int len);

// Nested character blob used by race/class display helpers.
static inline int Character_GetNestedBlob(int this_char)
{
  int vft = *(int*)(this_char + 4);
  int mid = *(int*)(vft + 4);
  int slot = *(int*)(mid + 0xac + this_char);
  return *(int*)(slot + 0x3c);
}

// Virtual level getter at vtbl +0x27c (mission [$level] slot).
static inline int Character_GetLevel_Vcall027c(int this_char)
{
  int vft = *(int*)(this_char + 4);
  int mid = *(int*)(vft + 4);
  int obj = mid + 4 + this_char;
  auto** vtbl = *(void***)(obj);
  using LevelFn = int(__thiscall*)(void*);
  return ((LevelFn)vtbl[0x27c / 4])((void*)obj);
}

void __fastcall Character_FormatClassAndLevelDisplay_Inferred(int this_char, int /*edx*/, char* out)
{
  void* tls_for_level_word = FUN_007a69d0();
  int level = Character_GetLevel_Vcall027c(this_char);

  int blob = Character_GetNestedBlob(this_char);
  unsigned char classId = *(unsigned char*)(blob + 0x531);
  unsigned char raceId  = *(unsigned char*)(blob + 0x532);

  // cdecl 2-arg leaf (bytes: push race, push class, call, add esp,8)
  const char* raw_class = FUN_0051f940(classId, raceId);
  char* class_name = FUN_007a6de0(FUN_007a69d0(), raw_class, /*len=*/-1);

  if (level >= 0) {
    level = Character_GetLevel_Vcall027c(this_char); // re-fetch (matches retail)
    char* level_word = FUN_007a6de0(tls_for_level_word, "Level", /*len=*/-1);
    std::sprintf(out, "%s, %s %i", class_name, level_word, level);
    return;
  }

  std::sprintf(out, "%s", class_name);
}
