// =============================================================================
// FUN_00404e00  —  alias plate; prefer CVOGPhysics_WriteNotFullyReadyOut_Inferred.cpp
// -----------------------------------------------------------------------------
// Stable ID: aa_00404e00
// Address:   0x00404e00–0x00404e22 (35 B)
// See:       reconstructed-exact/CVOGPhysics_WriteNotFullyReadyOut_Inferred.cpp
// Dual A/B:  reviews/A_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md
//            reviews/B_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md
// Generated: 2026-08-05 MEGA-049 dual A/B (scaffold superseded)
// =============================================================================

// PURPOSE: CVOGPhysics write-not-fully-ready out-byte. Leaf.
//   *out = 0 if (byte@+0x40 && dword@+0x08); else *out = 1. RET 4.

#include <stdint.h>

uint8_t *__thiscall FUN_00404e00(int param_1, uint8_t *param_2)
{
  if ((*(char *)(param_1 + 0x40) != '\0') && (*(int *)(param_1 + 8) != 0)) {
    *param_2 = 0;
    return param_2;
  }
  *param_2 = 1;
  return param_2;
}
