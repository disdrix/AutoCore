// =============================================================================
// FUN_00829ec0 — scaffold twin of UI_MissionJournal_MSelectEntry_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ec0
// Address:   0x00829ec0  (autoassault.exe, image base 0x400000)
// Prefer named clean: UI_MissionJournal_MSelectEntry_Ctor_Inferred.cpp
// WQ7R-E dual seal 2026-08-04.
// =============================================================================

#include <cstdint>

extern "C" void* FUN_00792d20(void* self);
extern "C" void NDUIWindow_ReloadInterface(const char* xmlPath);
extern "C" void* PTR_FUN_00a74484[];
extern void* ExceptionList;
extern "C" char LAB_009b432e;

extern "C" uint32_t* FUN_00829ec0(uint32_t* param_1)
{
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = reinterpret_cast<uint8_t*>(&LAB_009b432e);
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00792d20(param_1);
  local_4 = 0;
  *param_1 = reinterpret_cast<uint32_t>(&PTR_FUN_00a74484);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_1) + 0x4fd) = 0;
  *reinterpret_cast<uint8_t*>(param_1 + 0x13f) = 0;
  param_1[0x140] = 0xffffffffu;
  param_1[0x141] = 0;
  param_1[0x142] = 0;
  param_1[0x143] = 0;
  NDUIWindow_ReloadInterface("i_d_npc_2d_btn_mselect.xml");
  ExceptionList = local_c;
  return param_1;
}
