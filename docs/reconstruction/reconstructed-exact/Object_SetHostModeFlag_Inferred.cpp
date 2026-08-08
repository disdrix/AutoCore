// =============================================================================
// Object_SetHostModeFlag_Inferred  (FUN_0051f880)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f880
// Address:   0x0051f880-0x0051f88c  (autoassault.exe, image base 0x400000)
// System:    object / character status (skills-abilities writer)
// Generated: 2026-08-04 WQ9F-I dual seal (from raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Store the host-mode flag byte at object+0x6b8.
//   Skill_HB_FireTail sets 1 on the resolved target char (vtbl+0x210 path);
//   Skill_HB_OnEnd clears with 0. Readers gate hardpoint cast / quick-bar
//   vehicle remaps on non-zero (+0x6b9 is the enhanced/on-foot twin).
//
// ABI (image-sealed):
//   __thiscall  ECX = this (character / object host)
//   stack: uint8_t fHostMode
//   ret 4
//   void
//
// Body hex: 8A 44 24 04  88 81 B8 06 00 00  C2 04 00
// Twin leaf: Object_SetEnhancedStateFlag_Inferred @ 0x0051f890 (+0x6b9)
//
// Dual reviews:
//   reviews/A_aa_0051f880_Object_SetHostModeFlag_Inferred.md
//   reviews/B_aa_0051f880_Object_SetHostModeFlag_Inferred.md
// =============================================================================

#include <stdint.h>

void __thiscall Object_SetHostModeFlag_Inferred(void *self, uint8_t fHostMode)
{
  *(uint8_t *)((char *)self + 0x6b8) = fHostMode;
}
