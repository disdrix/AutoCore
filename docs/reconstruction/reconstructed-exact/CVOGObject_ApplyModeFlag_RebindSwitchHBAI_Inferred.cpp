// =============================================================================
// CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0053dbb0
// Address:   0x0053dbb0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0053dbb0
// System:    object lifecycle / AI mode apply
// Generated: 2026-07-29 W26-E dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE: Virtual mode-flag apply on CVOGObject.
// Branches self vfuncs on modeFlag, rebinds world object via WorldObj_RebindActivate,
// notifies AI host under lock, and may SwitchHBAIByCode(1 or 6).

#include <cstdint>

extern "C" void *DAT_00b04610;

extern "C" void __thiscall FUN_00560e90(int worldObj /*stack*/, int flag /*staged*/);
extern "C" char *__fastcall FUN_005070b0(void *slot /*ECX?*/);
extern "C" void FUN_005070d0(void);
extern "C" void __thiscall FUN_005d4440(int *self /*ECX*/, int aiCode /*stack*/);

// thiscall; ret 4; virtual
void __thiscall CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred(
    int *self /*ECX*/, char modeFlag /*stack*/)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint32_t uVar4;
  char *pcVar5;
  uint32_t uVar6;

  cVar2 = modeFlag;
  if (self[2] != 0) {
    if (modeFlag == '\0') {
      (**(void (**)())(*self + 0x10))();
    } else {
      (**(void (**)())(*self + 0xc))();
      *(uint32_t *)(self[2] + 0x28) = 0x10;
      if (self[3] != 0) {
        uVar6 = 0;
        iVar3 = (**(int (**)())(*(int *)self[3] + 0x4c))();
        if (iVar3 != 0) {
          do {
            iVar3 = (**(int (**)())(*(int *)self[3] + 0x50))();
            (**(void (**)(int))(**(int **)(iVar3 + uVar6 * 4) + 8))(4);
            uVar6 = uVar6 + 1;
            uVar4 = (**(uint32_t(**)())(*(int *)self[3] + 0x4c))();
          } while (uVar6 < uVar4);
        }
      }
    }
    FUN_00560e90(self[2], 1);
    iVar3 = self[2];
    pcVar5 = FUN_005070b0(&modeFlag);
    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {
      FUN_005070d0();
    }
    (**(void (**)(void *))(**(int **)(iVar3 + 0x3c) + 0x50))(&DAT_00b04610);
    iVar3 = self[2];
    pcVar5 = FUN_005070b0(/*stack slot*/ nullptr);
    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {
      FUN_005070d0();
    }
    (**(void (**)(void *))(**(int **)(iVar3 + 0x3c) + 0x54))(&DAT_00b04610);
    iVar3 = self[2];
    if (iVar3 != 0) {
      // needsSwitch = (obj+0x40==0) || (obj+8==0)
      if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {
        bVar1 = true;
      } else {
        bVar1 = false;
      }
      bVar1 = !bVar1;
      if (!bVar1) {
        if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          if (cVar2 == '\0') {
            FUN_005d4440(self, 1);
            return;
          }
          FUN_005d4440(self, 6);
          return;
        }
      }
    }
  }
}
