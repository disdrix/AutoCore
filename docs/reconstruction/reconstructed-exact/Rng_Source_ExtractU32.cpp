// =============================================================================
// Rng_Source_ExtractU32
// -----------------------------------------------------------------------------
// Purpose:  Thin thiscall wrapper on an RNG source object: load Mt19937State*
//           from this+0x14 into EAX and tail-jump to Rng_Mt19937_Extract.
//           Returns one tempered uint32 in EAX.
//
// Address:  0x007a41f0  (autoassault.exe, image base 0x400000)
// Body:     0x007a41f0–0x007a41f7 (7 bytes)
// Stable:   aa_007a41f0
// System:   RNG / MT19937
// Ghidra:   FUN_007a41f0
//
// ABI:      __thiscall source; no stack formals; tail-jmp (no local ret)
//           ECX = source*; *(source+0x14) = Mt19937State*
//           Extract callee: EAX = state* (sealed aa_00424830)
//
// Bytes:    8B 41 14  E9 38 06 C8 FF   → jmp 0x00424830
//
// Exactness: CF mirrors read_memory bytes; decompiler omits +0x14 load.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W21-L seal).
// =============================================================================

/* Rng_Source_ExtractU32 — source-object next-u32 via embedded MT state.

   Algorithm:
     1. EAX = *(uint32_t*)(this + 0x14)
     2. jmp Rng_Mt19937_Extract  (tempered u32 in EAX)

   Callers: LootCatalog_RollCandidateId (0x005e1030),
            LootCatalog_RollFilteredCandidateId (0x005e1150).
   Sibling: FUN_007a4200 fills 0x80000-entry table from same +0x14 state. */

#include <stdint.h>

/* Sealed: aa_00424830 — EAX = Mt19937State*; returns tempered u32 in EAX. */
extern uint32_t Rng_Mt19937_Extract(void /* EAX state */);

uint32_t __thiscall Rng_Source_ExtractU32(void *source)
{
  /* mov eax, [ecx+0x14] */
  void *mt_state = *(void **)((uint8_t *)source + 0x14);

  /* jmp 0x00424830 — presented as direct call for readability; retail tails. */
  return Rng_Mt19937_Extract(/* EAX = */ mt_state);
}
