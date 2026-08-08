// =============================================================================
// FUN_0051f880  (scaffold alias of Object_SetHostModeFlag_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f880
// Address:   0x0051f880  (autoassault.exe, image base 0x400000)
// System:    object / character status
// Generated: 2026-08-04 WQ9F-I (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: Object_SetHostModeFlag_Inferred
// =============================================================================

#include <stdint.h>

void __thiscall FUN_0051f880(void *param_1, uint8_t param_2)
{
  *(uint8_t *)((char *)param_1 + 0x6b8) = param_2;
}
