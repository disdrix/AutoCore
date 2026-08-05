// =============================================================================
// FUN_004c2080 / ParticleFluidPhase_Init_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2080
// Address:   0x004c2080  (autoassault.exe, image base 0x400000)
// System:    client / particle fluid phase (env+0xCC host from FUN_004c0640)
// Generated: 2026-07-29 W33-S dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Phase enable — EnsureAuxPtrs → fluid-bump child → CreateFluidParticles(0x7FFF)
// → secondary child. thiscall ECX=phase; stack flags; RET 4; returns 0.
// Decompiler omits ECX; bytes seal mov esi,ecx.

#include <cstdint>

extern "C" uint32_t __thiscall FUN_00756320(void *host, uint32_t flags);
extern "C" void __fastcall FUN_004c0a90(void *phase);
extern "C" void __thiscall FUN_004c1cb0(void *phase, int capacity);
extern "C" void __fastcall FUN_004c1960(void *phase);

extern "C" uint32_t __thiscall FUN_004c2080(void *phase, uint32_t flags)
{
  (void)FUN_00756320(phase, flags);
  FUN_004c0a90(phase);
  FUN_004c1cb0(phase, 0x7fff);
  FUN_004c1960(phase);
  return 0;
}
