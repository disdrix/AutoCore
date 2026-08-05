// =============================================================================
// Object_SetEnhancedStateFlag_Inferred  (FUN_0051f890)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f890
// Address:   0x0051f890–0x0051f89c  (autoassault.exe, image base 0x400000)
// System:    object / character status
// Generated: 2026-07-29 W28-G dual seal (from raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Store the enhanced-state flag byte at object+0x6b9.
//   ActivatePlayer path sets 1 after TFID rebind; a second code site clears with 0.
//   Readers (drive/camera/skill/UI) treat non-zero as "in enhanced state."

// ABI (image-sealed):
//   __thiscall  ECX = this (character / object host)
//   stack: uint8_t fEnhanced
//   ret 4
//   void

// Body hex: 8A 44 24 04  88 81 B9 06 00 00  C2 04 00

#include <stdint.h>

void __thiscall Object_SetEnhancedStateFlag_Inferred(void *self, uint8_t fEnhanced)
{
  *(uint8_t *)((char *)self + 0x6b9) = fEnhanced;
}
