// =============================================================================
// FUN_0053dbb0  (alias of CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053dbb0
// Address:   0x0053dbb0  (autoassault.exe, image base 0x400000)
// System:    object lifecycle / AI mode apply
// Generated: 2026-07-29 W26-E dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

// Twin named clean: CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.cpp

#include <cstdint>

extern void *DAT_00b04610;
extern void __thiscall FUN_00560e90(int worldObj, int flag);
extern char *__fastcall FUN_005070b0(void *slot);
extern void FUN_005070d0(void);
extern void __thiscall FUN_005d4440(int *self, int aiCode);

void __thiscall FUN_0053dbb0(int *param_1, char param_2)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint32_t uVar4;
  char *pcVar5;
  uint32_t uVar6;

  cVar2 = param_2;
  if (param_1[2] != 0) {
    if (param_2 == '\0') {
      (**(void (**)())(*param_1 + 0x10))();
    } else {
      (**(void (**)())(*param_1 + 0xc))();
      *(uint32_t *)(param_1[2] + 0x28) = 0x10;
      if (param_1[3] != 0) {
        uVar6 = 0;
        iVar3 = (**(int (**)())(*(int *)param_1[3] + 0x4c))();
        if (iVar3 != 0) {
          do {
            iVar3 = (**(int (**)())(*(int *)param_1[3] + 0x50))();
            (**(void (**)(int))(**(int **)(iVar3 + uVar6 * 4) + 8))(4);
            uVar6 = uVar6 + 1;
            uVar4 = (**(uint32_t(**)())(*(int *)param_1[3] + 0x4c))();
          } while (uVar6 < uVar4);
        }
      }
    }
    FUN_00560e90(param_1[2], 1);
    iVar3 = param_1[2];
    pcVar5 = FUN_005070b0(&param_2);
    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {
      FUN_005070d0();
    }
    (**(void (**)(void *))(**(int **)(iVar3 + 0x3c) + 0x50))(&DAT_00b04610);
    iVar3 = param_1[2];
    pcVar5 = FUN_005070b0(nullptr);
    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {
      FUN_005070d0();
    }
    (**(void (**)(void *))(**(int **)(iVar3 + 0x3c) + 0x54))(&DAT_00b04610);
    iVar3 = param_1[2];
    if (iVar3 != 0) {
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
            FUN_005d4440(param_1, 1);
            return;
          }
          FUN_005d4440(param_1, 6);
          return;
        }
      }
    }
  }
}
