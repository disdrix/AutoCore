// =============================================================================
// Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008a2020
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2020
// Address:   0x008a2020
// NOTE: Prior xref-seed name. Prefer Client_IsLocalMissionJournalReady (W21-F).
// Redirect plate — body matches named clean.
// =============================================================================

#include <cstdint>

extern void* DAT_00d1b6d8;
extern "C" uint8_t __thiscall FUN_0052b3b0(void* self, void* mission);

extern "C" uint8_t __cdecl Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008a2020(
    uint32_t param_1)
{
  if (DAT_00d1b6d8 == nullptr) {
    return 0;
  }
  return FUN_0052b3b0(DAT_00d1b6d8, reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)));
}
