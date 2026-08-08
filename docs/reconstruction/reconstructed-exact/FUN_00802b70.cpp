// =============================================================================
// FUN_00802b70  (scaffold twin of Client_SkillHB_OnEndUiCleanup_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00802b70
// Address:   0x00802b70 – 0x00802c7b exclusive (0x10B / 267 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 MEGA-020 (ABI-corrected twin; prefer named clean)
// Exactness: Behavior-preserving. Not bit-exact certified.
// =============================================================================

#include <cstdint>

extern "C" void* DAT_00d1d8e0;
extern "C" void* DAT_00d1b6d8;
extern "C" int*  DAT_00d1b8b8;
extern "C" void* DAT_00d1b8ec;

extern "C" void FUN_007fc970(void);
extern "C" void* __fastcall FUN_00578270(void* host /*ECX*/);
extern "C" void FUN_008027e0(void* owner);
extern "C" void FUN_0087d810(void* sheet);
extern "C" void FUN_0083bf40(void* uiList, void* skillHb);

// Ghidra shows one arg + void; assembly seals stdcall RET 8 (two stack args).
using VFn0 = int(__thiscall*)(void* self);
using VFnBool = char(__thiscall*)(void* self);

void __stdcall FUN_00802b70(int param_1, int /*param_2_unused*/)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int* piVar4;

  if (param_1 != 0) {
    if ((DAT_00d1d8e0 != 0)
        && (*(int*)((char*)DAT_00d1d8e0 + 0x514) == param_1)) {
      // ESI = 0x00d1a840 before call (assembly; decompiler omits)
      FUN_007fc970();
    }
    if ((DAT_00d1b6d8 != 0)
        && (*(int**)(param_1 + 0x18) != (int*)0x0)) {
      void* owner = *(void**)(param_1 + 0x18);
      void** ov = *reinterpret_cast<void***>(owner);
      iVar2 = reinterpret_cast<VFn0>(ov[0x1dc / 4])(owner);
      if ((iVar2 == (int)(intptr_t)DAT_00d1b6d8)
          || (iVar2 = *(int*)((char*)DAT_00d1b6d8 + 0x250),
              iVar3 = reinterpret_cast<VFn0>(ov[0x1d4 / 4])(owner),
              iVar3 == iVar2)) {
        if ((DAT_00d1b8b8 != (int*)0x0)
            && (cVar1 = reinterpret_cast<VFnBool>(
                    (*reinterpret_cast<void***>(DAT_00d1b8b8))[0x3d8 / 4])(
                    DAT_00d1b8b8),
                cVar1 != '\0')) {
          FUN_0087d810(DAT_00d1b8b8);
        }
      } else {
        if (*(char*)(param_1 + 0xfe) == '\0') {
          return;
        }
        iVar2 = (int)(intptr_t)FUN_00578270((void*)(intptr_t)param_1);
        if (iVar2 == 0) {
          return;
        }
        piVar4 = (int*)FUN_00578270((void*)(intptr_t)param_1);
        iVar2 = reinterpret_cast<VFn0>(
            (*reinterpret_cast<void***>(piVar4))[0x1dc / 4])(piVar4);
        if (iVar2 != (int)(intptr_t)DAT_00d1b6d8) {
          piVar4 = (int*)FUN_00578270((void*)(intptr_t)param_1);
          iVar2 = *(int*)((char*)DAT_00d1b6d8 + 0x250);
          iVar3 = reinterpret_cast<VFn0>(
              (*reinterpret_cast<void***>(piVar4))[0x1d4 / 4])(piVar4);
          if (iVar3 != iVar2) {
            return;
          }
        }
        FUN_008027e0(*(void**)(param_1 + 0x18));
      }
      if ((DAT_00d1b8ec != 0)
          && (*(int*)((char*)DAT_00d1b8ec + 0x590) != 0)) {
        FUN_0083bf40(*(void**)((char*)DAT_00d1b8ec + 0x590),
                     (void*)(intptr_t)param_1);
      }
    }
  }
  return;
}
