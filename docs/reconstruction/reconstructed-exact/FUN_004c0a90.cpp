// =============================================================================
// FUN_004c0a90  (twin of ParticleFluidPhase_InitFluidBumpChild_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0a90
// Address:   0x004c0a90  (autoassault.exe, image base 0x400000)
// System:    client / particle fluid phase
// Generated: 2026-07-29 W34-N dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Fluid-bump render child install for ParticleFluidPhase (phase+0x9c).
// Strings: Particle_Fluid_bump.dds; NDParticleFluidBlendNormal.fx; NormalMapTexture.
// Sole caller: FUN_004c2080 (ParticleFluidPhase_Init_Inferred).

#include <cstdint>

extern "C" void __fastcall ParticleFluidPhase_InitFluidBumpChild_Inferred(void *phase);

extern "C" void __fastcall FUN_004c0a90(void *phase)
{
  ParticleFluidPhase_InitFluidBumpChild_Inferred(phase);
}
