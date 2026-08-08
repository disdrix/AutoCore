// =============================================================================
// FUN_00402c40 — twin of CNDHash_TraversalLock_Set_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402c40
// Address:   0x00402c40  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/CNDHash_TraversalLock_Set_Inferred.cpp
// MEGA-110:  2026-08-05 dual seal; scaffold body retired in favor of named clean.
// =============================================================================

#include <cstdint>

extern void FUN_007a4480(int level, const char *fmt);

// Machine ABI: ECX = hash*; bare RET; void.
void __fastcall FUN_00402c40(int param_1)
{
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(uint8_t *)(param_1 + 0x1d) = 1;
  return;
}
