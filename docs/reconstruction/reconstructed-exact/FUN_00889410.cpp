// =============================================================================
// FUN_00889410  →  UI_TabsC_SetActiveTab_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00889410
// Address:   0x00889410–0x008896f3  (autoassault.exe, image base 0x400000)
// Body:      740 B (0x2E4); RET 8; pad CC
// System:    inventory-transfer
// Generated: 2026-08-05 R11-032 dual (live Ghidra; supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving. Named clean:
//            reconstructed-exact/UI_TabsC_SetActiveTab_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// ABI: EAX=tabIndex; stack dialog*, force; RET 8; void.
// Decompiler shows `in_EAX` phantom + incomplete FUN_00822cb0 targets.
//
// PURPOSE: i_d_tabs_c dialog tab switch (char=0 / achievements=1 / locker=2).
// =============================================================================

#include <cstdint>

typedef void (*code)(void);

extern "C" void FUN_00822cb0(char force);
extern "C" uint32_t FUN_00756c90(void);

// Ghidra-shaped surface (stack args only). Real image also requires tabIndex in EAX.
extern "C" void FUN_00889410(int *param_1, uint32_t param_2 /* force */,
                             int in_EAX /* tabIndex @EAX */) {
  char cVar1;

  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') &&
      (((char)param_2 != '\0' || (in_EAX != param_1[0x14c])))) {
    param_1[0x14c] = in_EAX;
    if (in_EAX == 0) {
      // Char: show [0x143], hide [0x144]/[0x145];
      // select [0x146], deselect [0x147]/[0x148]  (ESI/EDI on 00822cb0/00756c90)
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
      cVar1 = (**(code **)(*(int *)param_1[0x145] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x145] + 4))(0);
        (**(code **)(*(int *)param_1[0x145] + 0x440))();
      }
      // ESI=[0x146], BL=1
      FUN_00822cb0((char)param_2);
      (**(code **)(*(int *)param_1[0x146] + 0x94))();
      // ESI=[0x147], BL=0; EDI=[0x147]
      FUN_00822cb0((char)param_2);
      FUN_00756c90();
      // ESI=[0x148], BL=0; EDI=[0x148]  (shared tail in image)
      FUN_00822cb0((char)param_2);
      FUN_00756c90();
    } else {
      if (in_EAX == 1) {
        // Achievements: show [0x145]; hide [0x143]/[0x144];
        // deselect [0x146]/[0x147]; select [0x148]; early RET
        cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();
        if (cVar1 != '\0') {
          (**(code **)(*(int *)param_1[0x143] + 4))(0);
          (**(code **)(*(int *)param_1[0x143] + 0x440))();
        }
        cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();
        if (cVar1 != '\0') {
          (**(code **)(*(int *)param_1[0x144] + 4))(0);
          (**(code **)(*(int *)param_1[0x144] + 0x440))();
        }
        cVar1 = (**(code **)(*(int *)param_1[0x145] + 0x3d8))();
        if (cVar1 == '\0') {
          (**(code **)(*(int *)param_1[0x145] + 0x43c))();
          (**(code **)(*(int *)param_1[0x145] + 4))(1);
        }
        FUN_00822cb0((char)param_2); // ESI=[0x146], BL=0
        FUN_00756c90();              // EDI=[0x146]
        FUN_00822cb0((char)param_2); // ESI=[0x147], BL=0
        FUN_00756c90();              // EDI=[0x147]
        FUN_00822cb0((char)param_2); // ESI=[0x148], BL=1
        (**(code **)(*(int *)param_1[0x148] + 0x94))();
        return;
      }
      if (in_EAX != 2) {
        return;
      }
      // Locker: show [0x144]; hide [0x143]/[0x145];
      // deselect [0x146]; select [0x147]; deselect [0x148]
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
      cVar1 = (**(code **)(*(int *)param_1[0x145] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x145] + 4))(0);
        (**(code **)(*(int *)param_1[0x145] + 0x440))();
      }
      FUN_00822cb0((char)param_2); // ESI=[0x146], BL=0
      FUN_00756c90();              // EDI=[0x146]
      FUN_00822cb0((char)param_2); // ESI=[0x147], BL=1
      (**(code **)(*(int *)param_1[0x147] + 0x94))();
      FUN_00822cb0((char)param_2); // ESI=[0x148], BL=0
      FUN_00756c90();              // EDI=[0x148]
    }
  }
  return;
}
