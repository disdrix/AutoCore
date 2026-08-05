// =============================================================================
// FUN_004c1cb0  (twin of ParticleFluidPhase_CreateFluidParticles_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1cb0
// Address:   0x004c1cb0  (autoassault.exe, image base 0x400000)
// System:    client / particle fluid phase
// Generated: 2026-07-29 W34-N dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: CreateFluidParticles(capacity) — product log stem.
// Strings: Invalid arg to CreateFluidParticles; NDParticleFluid.fx; Particles.dds;
//          ParticleTexture; NormalMapTexture; ReflectionSurface; vert/index/lock errors.
// Sole caller: FUN_004c2080 with capacity 0x7FFF.

#include <cstdint>

extern "C" void __thiscall ParticleFluidPhase_CreateFluidParticles_Inferred(
    void *phase, int capacity);

extern "C" void __thiscall FUN_004c1cb0(void *phase, int capacity)
{
  ParticleFluidPhase_CreateFluidParticles_Inferred(phase, capacity);
}
