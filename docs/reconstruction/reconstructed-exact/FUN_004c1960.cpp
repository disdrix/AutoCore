// =============================================================================
// FUN_004c1960 — twin of ParticleFluidPhase_CreateLiquidChild_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1960
// Address:   0x004c1960
// Wave:      W34-O OWN-ONLY dual
// =============================================================================

#include <cstdint>

extern "C" void __fastcall ParticleFluidPhase_CreateLiquidChild_Inferred(void *phase);

extern "C" void __fastcall FUN_004c1960(void *phase /*ECX*/)
{
  ParticleFluidPhase_CreateLiquidChild_Inferred(phase);
}
