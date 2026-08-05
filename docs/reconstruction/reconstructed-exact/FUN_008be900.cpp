// =============================================================================
// FUN_008be900 — scaffold alias
// -----------------------------------------------------------------------------
// Stable ID: aa_008be900
// Address:   0x008be900–0x008beb13  (autoassault.exe, image base 0x400000)
// Canonical: UI_InventoryPanel_MessageHandler_Inferred
// See:       reconstructed-exact/UI_InventoryPanel_MessageHandler_Inferred.cpp
// Generated: 2026-07-29 W20-F OWN dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>
#include <cmath>

extern "C" {
uint32_t __thiscall FUN_0087b500(void *self, int msg, int controlId);
char FUN_00941d50(int mode); // Client_UseInventoryItem_Inferred
void Client_SendUseObject_IfInteractable(void);
void FUN_007fd420(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3);
void FUN_007fca10(void);
int FUN_004024b0(void);
void FUN_008bda60(void);
}

extern int *DAT_00d1d8dc;
extern uint8_t DAT_00d1d8f4;
extern uint8_t DAT_00d1d8f5;
extern float _DAT_00aaa5dc;

uint32_t __thiscall FUN_008be900(int param_1, int param_2, int param_3)
{
  float fVar1;
  char cVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  int iVar5;
  uint32_t uVar6;
  long double fVar7;
  uint8_t local_10[16];

  if ((0x9c42 < param_3) && (param_3 < 0x9c47)) {
    iVar5 = param_3 + -0x9c43;
    if (param_2 == 5) {
      if (*(int *)(param_1 + 0x55c + iVar5 * 4) != 0) {
        puVar3 = (uint32_t *)(
            (**(code **)(**(int **)(param_1 + 0x55c + iVar5 * 4) + 0x140))(local_10, 1));
        puVar4 = (uint32_t *)(
            (**(code **)(**(int **)(param_1 + 0x55c + iVar5 * 4) + 0x120))(local_10, 1, 1));
        FUN_007fd420(*puVar4, puVar4[1], *puVar3, puVar3[1]);
      }
      return 1;
    }
    if (param_2 == 6) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (DAT_00d1d8dc != (int *)0x0) {
        (**(code **)(*DAT_00d1d8dc + 4))(0);
      }
      return 1;
    }
    if (param_2 == 0xe) {
      cVar2 = FUN_00941d50(1);
      if (cVar2 == '\0') {
        Client_SendUseObject_IfInteractable();
      }
      return 1;
    }
  }
  if (param_3 == 40000) {
    if (param_2 == 8) {
      FUN_007fca10();
    }
  }
  else if (param_3 == 0x9c41) {
    if (param_2 == 8) {
      return 1;
    }
  }
  else if ((param_3 == 0x9c42) && (param_2 == 0x1a)) {
    if (((*(int **)(param_1 + 0x544) != (int *)0x0) && (*(int *)(param_1 + 0x550) != 0)) &&
        (4 < (uint32_t)(*(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2))) {
      fVar7 = (long double)((**(code **)(**(int **)(param_1 + 0x544) + 0x458))());
      iVar5 = FUN_004024b0();
      fVar1 = (float)(iVar5 + -4);
      if (iVar5 + -4 < 0) {
        fVar1 = fVar1 + _DAT_00aaa5dc;
      }
      if (*(int *)(param_1 + 0x548) != (int)std::lround(fVar1 * (float)fVar7)) {
        *(int *)(param_1 + 0x548) = (int)std::lround(fVar1 * (float)fVar7);
        FUN_008bda60();
      }
    }
    return 1;
  }
  uVar6 = FUN_0087b500(reinterpret_cast<void *>(param_1), param_2, param_3);
  return uVar6;
}
