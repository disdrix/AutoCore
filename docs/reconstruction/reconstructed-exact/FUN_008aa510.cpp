// =============================================================================
// FUN_008aa510  (twin of MissionDialog_StampResponseSlot_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa510
// Address:   0x008aa510  (autoassault.exe, image base 0x400000)
// System:    missions-progression / mission dialog chrome
// Wave:      MEGA-046 (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// Canonical named clean: MissionDialog_StampResponseSlot_Inferred.cpp
// =============================================================================
//
// PURPOSE: see MissionDialog_StampResponseSlot_Inferred.cpp
// ABI: EDI=dialog, ESI=slot, EDX=caption, stack tfidLo/tfidHi, RET 8
// Body: 75 B / 0x4B @ 0x008aa510–0x008aa55b exclusive
// =============================================================================

#include <cstdint>

// Decompiler-shaped twin (unaff_ESI / unaff_EDI are image register formals).

void __fastcall FUN_008aa510(
    uint32_t /*param_1 unused*/,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4)
{
  int *piVar1;
  int unaff_ESI;
  int unaff_EDI;

  if ((-1 < unaff_ESI) && (unaff_ESI < *(int *)(unaff_EDI + 0x510))) {
    piVar1 = *(int **)(unaff_EDI + 0x708 + unaff_ESI * 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1d8))(param_2, 1, 1);
      (**(code **)(**(int **)(unaff_EDI + 0x708 + unaff_ESI * 4) + 0x34c))();
    }
    *(uint32_t *)(unaff_EDI + 0x518 + unaff_ESI * 8) = param_3;
    *(uint32_t *)(unaff_EDI + 0x51c + unaff_ESI * 8) = param_4;
  }
  return;
}
