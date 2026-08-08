// =============================================================================
// FUN_00521970  (twin of Character_FormatClassAndLevelDisplay_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00521970
// Address:   0x00521970  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / character display
// Generated: 2026-08-05 R10-034 dual
// Exactness: Ghidra-name twin; prefer Character_FormatClassAndLevelDisplay_Inferred.cpp
// =============================================================================

// See Character_FormatClassAndLevelDisplay_Inferred.cpp for full plate + notes.

#include <cstdio>
#include <cstdint>

extern "C" const char* FUN_0051f940(unsigned classId, unsigned raceId);
extern "C" void* FUN_007a69d0(void);
extern "C" char* __thiscall FUN_007a6de0(void* tls_table, const char* src, int len);

void __thiscall FUN_00521970(int param_1, char* param_2)
{
  void* tls = FUN_007a69d0();

  int vft = *(int*)(param_1 + 4);
  int mid = *(int*)(vft + 4);
  int obj = mid + 4 + param_1;
  auto** vtbl = *(void***)(obj);
  using LevelFn = int(__thiscall*)(void*);
  int level = ((LevelFn)vtbl[0x27c / 4])((void*)obj);

  int slot = *(int*)(mid + 0xac + param_1);
  int blob = *(int*)(slot + 0x3c);
  unsigned char classId = *(unsigned char*)(blob + 0x531);
  unsigned char raceId  = *(unsigned char*)(blob + 0x532);

  // Bytes: cdecl 2-arg; decompiler phantom third 0xffffffff is 007a6de0 length.
  const char* raw = FUN_0051f940(classId, raceId);
  char* className = FUN_007a6de0(FUN_007a69d0(), raw, /*len=*/-1);

  if (level >= 0) {
    level = ((LevelFn)vtbl[0x27c / 4])((void*)obj);
    char* levelWord = FUN_007a6de0(tls, "Level", /*len=*/-1);
    std::sprintf(param_2, "%s, %s %i", className, levelWord, level);
    return;
  }

  std::sprintf(param_2, "%s", className);
}
