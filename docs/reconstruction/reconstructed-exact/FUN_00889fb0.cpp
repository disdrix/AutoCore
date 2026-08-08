// =============================================================================
// FUN_00889fb0  (scaffold twin of UI_CarTabs_ApplyPanelMode_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00889fb0
// Address:   0x00889fb0–0x0088a12e  (autoassault.exe, image base 0x400000)
// Canonical: UI_CarTabs_ApplyPanelMode_Inferred
// System:    inventory-transfer
// Generated: 2026-08-05 R11-033 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Prefer named clean sibling for new work.
// =============================================================================

#include <cstdint>

extern "C" void FUN_00822cb0(char force);
extern "C" uint32_t FUN_00756c90(void);

// ABI: EAX = mode; stack (host*, force); RET 8; void
void FUN_00889fb0(int *param_1, uint32_t param_2)
{
  char cVar1;
  int in_EAX; // panel mode from EAX

  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (((char)param_2 != '\0' || (in_EAX != param_1[0x14a])))) {
    param_1[0x14a] = in_EAX;
    if (in_EAX == 0) {
      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();
      if (cVar1 == '\0') {
        (**(code **)(*(int *)param_1[0x143] + 0x43c))();
        (**(code **)(*(int *)param_1[0x143] + 4))(1);
      }
      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x144] + 4))(0);
        (**(code **)(*(int *)param_1[0x144] + 0x440))();
      }
      FUN_00822cb0((char)param_2); // ESI=param_1[0x145], BL=1
      (**(code **)(*(int *)param_1[0x145] + 0x94))();
      FUN_00822cb0((char)param_2); // ESI=param_1[0x146], BL=0
      FUN_00756c90();              // EDI=param_1[0x146]
    }
    else if (in_EAX == 1) {
      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x143] + 4))(0);
        (**(code **)(*(int *)param_1[0x143] + 0x440))();
      }
      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();
      if (cVar1 == '\0') {
        (**(code **)(*(int *)param_1[0x144] + 0x43c))();
        (**(code **)(*(int *)param_1[0x144] + 4))(1);
      }
      FUN_00822cb0((char)param_2); // ESI=param_1[0x145], BL=0
      FUN_00756c90();              // EDI=param_1[0x145]
      FUN_00822cb0((char)param_2); // ESI=param_1[0x146], BL=1
      (**(code **)(*(int *)param_1[0x146] + 0x94))();
      return;
    }
  }
  return;
}
