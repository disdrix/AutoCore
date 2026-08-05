// =============================================================================
// UI_MissionJournal_MSelectEntry_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ec0
// Address:   0x00829ec0  (autoassault.exe, image base 0x400000)
// Body:      0x00829ec0–0x00829f3b (123 B / 0x7B); ret 4; pad CC
// System:    client UI / mission journal
// Generated: 2026-08-04 WQ7R-E dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00829ec0
// =============================================================================
//
// PURPOSE:
//   Construct a mission-journal multi-select **entry** widget (size 0x510 at
//   callers). Chains NDUIContainerPanel base ctor, installs subclass vtbl
//   PTR_FUN_00a74484, clears mselect tail fields (+0x4FC..+0x50C), sets
//   selection sentinel +0x500 = -1, then reloads root skin
//   "i_d_npc_2d_btn_mselect.xml".
//
// ABI: stack this (MSVC ctor form); returns this; ret 4
// CALLEES: FUN_00792d20 (NDUIContainerPanel_Ctor_Inferred),
//          NDUIWindow_ReloadInterface
// CALLERS: Client_UpdateMissionJournal (4 sites; operator_new(0x510))
// PEERS:   UI_MissionJournal_BuildMSelectChrome_Inferred (0x00829ce0)
// =============================================================================

#include <cstdint>

extern "C" void* FUN_00792d20(void* self); // NDUIContainerPanel_Ctor_Inferred
extern "C" void NDUIWindow_ReloadInterface(const char* xmlPath);
// ExceptionList / SEH omitted (framing only)

// Vtbl at 0x00a74484 (image)
extern "C" void* PTR_FUN_00a74484[];

struct MissionJournalMSelectEntry {
  void** vtbl; // +0x00
  // ... NDUIContainerPanel base through ~0x4FB ...
  // uint8_t categoryMode;   // +0x4FC
  // uint8_t completeFlag;   // +0x4FD
  // uint32_t selectionKey;  // +0x500  (-1 unbound)
  // void* missionButton;    // +0x504
  // void* titleWidget;      // +0x508
  // void* statusWidget;     // +0x50C
  // size 0x510
};

extern "C" MissionJournalMSelectEntry* UI_MissionJournal_MSelectEntry_Ctor_Inferred(
    MissionJournalMSelectEntry* self)
{
  // SEH: LAB_009b432e framing (elided)
  FUN_00792d20(self);

  self->vtbl = PTR_FUN_00a74484;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x4FD) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x4FC) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x500) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x504) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x508) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x50C) = 0;

  NDUIWindow_ReloadInterface("i_d_npc_2d_btn_mselect.xml");
  return self; // ret 4
}

// Scaffold alias
extern "C" MissionJournalMSelectEntry* FUN_00829ec0(MissionJournalMSelectEntry* self)
{
  return UI_MissionJournal_MSelectEntry_Ctor_Inferred(self);
}
