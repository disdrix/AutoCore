// =============================================================================
// FUN_004220c0  (scaffold alias of SkillRow_UninitializedFillN_0x934)
// -----------------------------------------------------------------------------
// Stable ID: aa_004220c0
// Address:   0x004220c0  (autoassault.exe, image base 0x400000)
// Body:      0x004220c0–0x004220e3 (36 bytes)
// Named:     SkillRow_UninitializedFillN_0x934.cpp (authoritative clean)
// System:    skills-abilities / vector helpers
// Generated: 2026-07-29 W22-M — live decompile ≡ raw; ABI from bytes+callers
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

/* Scaffold retains decompiler shape. Named clean documents full register ABI.
   Machine: ECX=count (param_1), EAX=dst (in_EAX), EBX=src (unaff_EBX). */

void __fastcall FUN_004220c0(int param_1)
{
  uint32_t *in_EAX;     /* dst — register input */
  int iVar1;
  uint32_t *unaff_EBX;  /* src prototype — register input */
  uint32_t *puVar2;
  uint32_t *puVar3;

  for (; param_1 != 0; param_1 = param_1 + -1) {
    if (in_EAX != (uint32_t *)0) {
      puVar2 = unaff_EBX;
      puVar3 = in_EAX;
      for (iVar1 = 0x24d; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    in_EAX = in_EAX + 0x24d;
  }
  return;
}
