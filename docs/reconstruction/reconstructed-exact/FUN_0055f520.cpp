// =============================================================================
// FUN_0055f520  — twin of LocalWorklist16_Init_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f520
// Address:   0x0055f520 – 0x0055f588  (autoassault.exe, image base 0x400000)
// Dual:      W28-R 2026-07-29
// See:       LocalWorklist16_Init_Inferred.cpp
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;

extern int *__thiscall LocalWorklist16_Init_Inferred(int *param_1, unsigned param_2);

int *__thiscall FUN_0055f520(int *param_1, unsigned param_2)
{
  return LocalWorklist16_Init_Inferred(param_1, param_2);
}
