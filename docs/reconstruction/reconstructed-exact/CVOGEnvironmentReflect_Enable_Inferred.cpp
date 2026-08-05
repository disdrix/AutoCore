// =============================================================================
// CVOGEnvironmentReflect_Enable_Inferred  (was FUN_005b39a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b39a0
// Address:   0x005b39a0  (autoassault.exe, image base 0x400000)
// Body:      0x005b39a0–0x005b39c1 exclusive (33 bytes / 0x21)
// System:    client / VOGEnvironmentSector / owned Reflect phase
// Generated: 2026-07-29 W33-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Host RTTI Confirmed (W32-T): vtbl PTR_FUN_009d95a0
//   COL@0x00aafff8 → type_info@0x00af3eb0 ".?AVCVOGEnvironmentReflect@@"
// Dual: reviews/A|B_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md
// =============================================================================

#include <cstdint>

// Host-base ensure aux ptrs (+4/+8); dualed W32-Q as HostBase_EnsureAuxPtrs_Inferred.
extern std::uint32_t __thiscall HostBase_EnsureAuxPtrs_Inferred(
    void* self, std::uint32_t flag);

// Resolve nested fog/light slots into +0x150/+0x154 when empty. Product residual.
extern void __fastcall FUN_005b3520(void* self);

// Alloc/bind fog child host @ +0x158 (new 0x198 + FUN_00968a50). Product residual.
extern void __fastcall FUN_005b3420(void* self);

// Owned env phase post-ctor enable. Sole factory:
//   PalantirEnv_InitPhases → new(0x170) + CVOGEnvironmentReflect_ctor(parent@+0xB8)
//   → env+0xC4; CVOGEnvironmentReflect_Enable_Inferred(env+0xC4, 1).
std::uint32_t __thiscall CVOGEnvironmentReflect_Enable_Inferred(
    void* self,
    std::uint32_t flag)
{
  HostBase_EnsureAuxPtrs_Inferred(self, flag);
  FUN_005b3520(self);
  FUN_005b3420(self);
  return 0;
}
