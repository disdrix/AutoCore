// =============================================================================
// FUN_007a41f0  (scaffold twin of Rng_Source_ExtractU32)
// -----------------------------------------------------------------------------
// Stable ID: aa_007a41f0
// Address:   0x007a41f0  (autoassault.exe, image base 0x400000)
// System:    RNG / MT19937
// Dual A/B:  accept (2026-07-29 W21-L)
// Canonical: Rng_Source_ExtractU32.cpp
// Exactness: Bytes authoritative (decompiler drops [ecx+0x14] load).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern uint32_t FUN_00424830(void /* EAX = Mt19937State* */);

/* Decompiler: void FUN_007a41f0(void) { FUN_00424830(); return; }
   Sealed: thiscall; load state from this+0x14; tail to extract; u32 in EAX. */
uint32_t __thiscall FUN_007a41f0(void *param_1)
{
  void *in_EAX_state = *(void **)((uint8_t *)param_1 + 0x14);
  /* retail: mov eax, [ecx+0x14]; jmp FUN_00424830 */
  return FUN_00424830(/* EAX = */ in_EAX_state);
}
