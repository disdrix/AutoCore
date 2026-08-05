// =============================================================================
// ParticleFluidPhase_Init_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2080
// Address:   0x004c2080  (autoassault.exe, image base 0x400000)
// System:    client / particle fluid phase (env+0xCC host from FUN_004c0640)
// Generated: 2026-07-29 W33-S dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Phase enable method for the 0xC8 fluid-particle host:
//   1) HostBase_EnsureAuxPtrs(flags)
//   2) FUN_004c0a90 — fluid-bump render child
//   3) FUN_004c1cb0(0x7fff) — CreateFluidParticles(32767)
//   4) FUN_004c1960 — secondary child @ +0xc4
// Returns 0. Called from PalantirEnv_InitPhases after new(0xC8)+FUN_004c0640
// with flags=1 and ECX=phase (not env).

#include <cstdint>

extern "C" uint32_t __thiscall HostBase_EnsureAuxPtrs_Inferred(void *host, uint32_t flags);
extern "C" void __fastcall FUN_004c0a90(void *phase);
extern "C" void __thiscall FUN_004c1cb0(void *phase, int capacity);
extern "C" void __fastcall FUN_004c1960(void *phase);

// Also linked as FUN_00756320
extern "C" uint32_t __thiscall FUN_00756320(void *host, uint32_t flags);

extern "C" uint32_t __thiscall ParticleFluidPhase_Init_Inferred(void *phase, uint32_t flags)
{
  // Retail: mov esi,ecx; push flags; call EnsureAuxPtrs (ECX still phase)
  (void)FUN_00756320(phase, flags);
  FUN_004c0a90(phase);
  FUN_004c1cb0(phase, 0x7fff);
  FUN_004c1960(phase);
  return 0;
}

extern "C" uint32_t __thiscall FUN_004c2080(void *phase, uint32_t flags)
{
  return ParticleFluidPhase_Init_Inferred(phase, flags);
}
