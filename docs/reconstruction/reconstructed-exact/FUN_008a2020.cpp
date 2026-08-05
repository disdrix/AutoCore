// =============================================================================
// FUN_008a2020  (canonical clean plate → Client_IsLocalMissionJournalReady)
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2020
// Address:   0x008a2020  (autoassault.exe, image base 0x400000)
// System:    missions-progression / journal UI
// Generated: 2026-07-29 W21-F (updates 2026-07-23 scaffold)
// Exactness: Behavior-preserving. Prefer named plate Client_IsLocalMissionJournalReady.cpp
// =============================================================================

#include <cstdint>

extern void* DAT_00d1b6d8;
extern "C" uint8_t __thiscall FUN_0052b3b0(void* self, void* mission);

// Ghidra decompile returns uint and uses "in_EAX & 0xffffff00" for AL-clear;
// image is xor al,al / ret. Clean uses explicit bool byte.

extern "C" uint8_t __cdecl FUN_008a2020(uint32_t param_1)
{
  if (DAT_00d1b6d8 == nullptr) {
    return 0;
  }
  return FUN_0052b3b0(DAT_00d1b6d8, reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)));
}
