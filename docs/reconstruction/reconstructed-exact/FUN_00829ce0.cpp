// =============================================================================
// FUN_00829ce0  (scaffold twin → named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ce0
// Address:   0x00829ce0  (autoassault.exe, image base 0x400000)
// Named:     UI_MissionJournal_BuildMSelectChrome_Inferred
// See:       UI_MissionJournal_BuildMSelectChrome_Inferred.cpp
// Dual A/B:  accept-with-gaps (W26-R 2026-07-29)
// =============================================================================

// This twin tracks Ghidra symbol FUN_00829ce0. Prefer the named clean plate for
// AutoCore port notes. Control flow is sealed against live decompile + body bytes.

#include <cstdint>

extern "C" void __fastcall FUN_00792600(void* panel);
extern "C" void* operator_new(uint32_t size);
extern "C" int __fastcall FUN_0079c860(void* self);
extern "C" int __thiscall FUN_007b5dd0(void* self, int arg0);
extern "C" void FUN_00829ac0(void);

void __fastcall FUN_00829ce0(int* param_1)
{
  void* pvVar1;
  int iVar2;
  void* pvVar3;
  char* pcVar4;

  // SEH frame omitted (LAB_009b430a)
  FUN_00792600(param_1);

  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(param_1) + 0x4FC) == '\0') {
    pvVar1 = operator_new(0x4CC);
    iVar2 = 0;
    if (pvVar1 != nullptr) {
      iVar2 = FUN_0079c860(pvVar1);
    }
    param_1[0x141] = iVar2; // +0x504
    reinterpret_cast<void(__thiscall*)(int*, int)>(
        *reinterpret_cast<void***>(param_1)[0xa8 / 4])(param_1, iVar2);
    pcVar4 = const_cast<char*>("i_d_npc_2d_btn_mselect_btn_mission.xml");
    reinterpret_cast<void(__thiscall*)(int, char*)>(
        *reinterpret_cast<void***>(param_1[0x141])[0x28 / 4])(param_1[0x141], pcVar4);
    reinterpret_cast<void(__thiscall*)(int, int)>(
        *reinterpret_cast<void***>(param_1[0x141])[0x74 / 4])(param_1[0x141], 60000);

    pvVar1 = operator_new(0x488);
    int status = 0;
    if (pvVar1 != nullptr) {
      status = FUN_007b5dd0(pvVar1, 0);
    }
    param_1[0x143] = status; // +0x50C
    reinterpret_cast<void(__thiscall*)(int*, int)>(
        *reinterpret_cast<void***>(param_1)[0xa8 / 4])(param_1, status);
    reinterpret_cast<void(__thiscall*)(int, const char*)>(
        *reinterpret_cast<void***>(param_1[0x143])[0x28 / 4])(
        param_1[0x143], "i_d_npc_2d_btn_mselect_wnd_status.xml");

    // AL = [this+0x4FD]; ESI = this
    FUN_00829ac0();

    pvVar3 = operator_new(0x488);
    iVar2 = 0;
    if (pvVar3 != nullptr) {
      iVar2 = FUN_007b5dd0(pvVar3, 0);
    }
    param_1[0x142] = iVar2; // +0x508
    reinterpret_cast<void(__thiscall*)(int*, int)>(
        *reinterpret_cast<void***>(param_1)[0xa8 / 4])(param_1, iVar2);
    pcVar4 = const_cast<char*>("i_d_npc_2d_btn_mselect_wnd_title.xml");
  } else {
    pvVar1 = operator_new(0x488);
    iVar2 = 0;
    if (pvVar1 != nullptr) {
      iVar2 = FUN_007b5dd0(pvVar1, 0);
    }
    param_1[0x142] = iVar2;
    reinterpret_cast<void(__thiscall*)(int*, int)>(
        *reinterpret_cast<void***>(param_1)[0xa8 / 4])(param_1, iVar2);
    pcVar4 = const_cast<char*>("i_d_npc_2d_btn_mselect_wnd_title_cat.xml");
  }

  reinterpret_cast<void(__thiscall*)(int, char*)>(
      *reinterpret_cast<void***>(param_1[0x142])[0x28 / 4])(param_1[0x142], pcVar4);
  reinterpret_cast<void(__thiscall*)(int*)>(
      *reinterpret_cast<void***>(param_1)[0x34c / 4])(param_1);
}
