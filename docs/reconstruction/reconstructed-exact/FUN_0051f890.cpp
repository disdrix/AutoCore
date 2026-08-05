// =============================================================================
// FUN_0051f890  (alias → Object_SetEnhancedStateFlag_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f890
// Address:   0x0051f890–0x0051f89c  (autoassault.exe, image base 0x400000)
// System:    object / character status
// Generated: 2026-07-29 W28-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See: Object_SetEnhancedStateFlag_Inferred.cpp (named clean twin).
// Alias keeps FUN_* path for scaffold tooling.

#include <stdint.h>

void __thiscall FUN_0051f890(void *param_1, uint8_t param_2)
{
  *(uint8_t *)((char *)param_1 + 0x6b9) = param_2;
}
