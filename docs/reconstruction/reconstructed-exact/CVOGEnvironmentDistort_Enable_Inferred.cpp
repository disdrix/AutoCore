// =============================================================================
// CVOGEnvironmentDistort_Enable_Inferred  (was FUN_0055cc50)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055cc50
// Address:   0x0055cc50  (autoassault.exe, image base 0x400000)
// Body:      0x0055cc50–0x0055cc6a exclusive (26 bytes / 0x1A)
// System:    client / VOGEnvironmentSector / owned Distort phase
// Generated: 2026-07-29 W33-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Host RTTI Confirmed: ctor FUN_0055c8c0 vtbl PTR_FUN_009d26ac
//   COL@0x00aae6cc → type_info@0x00af2d0c ".?AVCVOGEnvironmentDistort@@"
// Dual: reviews/A|B_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md
// =============================================================================

#include <cstdint>

// Host-base ensure aux ptrs (+4/+8); dualed W32-Q as HostBase_EnsureAuxPtrs_Inferred.
extern std::uint32_t __thiscall HostBase_EnsureAuxPtrs_Inferred(
    void* self, std::uint32_t flag);

// Particle-distort child bring-up (alloc 0x198 @ +0x90; Particle_Distort.dds /
// NDParticleDistortBlendNormal.fx). Product name residual.
extern void __fastcall FUN_0055ca90(void* self);

// Owned env phase post-ctor enable. Sole factory:
//   PalantirEnv_InitPhases → new(0xA0) + FUN_0055c8c0(parent) → env+0xC8
//   → CVOGEnvironmentDistort_Enable_Inferred(env+0xC8, 1).
std::uint32_t __thiscall CVOGEnvironmentDistort_Enable_Inferred(
    void* self,
    std::uint32_t flag)
{
  HostBase_EnsureAuxPtrs_Inferred(self, flag);
  FUN_0055ca90(self);
  return 0;
}
