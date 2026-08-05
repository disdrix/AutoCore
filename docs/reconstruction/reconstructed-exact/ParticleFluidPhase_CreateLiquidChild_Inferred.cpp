// =============================================================================
// ParticleFluidPhase_CreateLiquidChild_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1960
// Address:   0x004c1960  (autoassault.exe, image base 0x400000)
// System:    client / particle fluid phase (child @ phase+0xc4)
// Generated: 2026-07-29 W34-O dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Allocate/construct a 0x40 liquid-environment child, install it at
// phase+0xc4, run liquid filter/RT init (FUN_004c0fe0 / VOGEnvironmentLiquid
// chain), and mark active (child+0x10=1) via FUN_0075bf40 + FUN_007567b0 on
// child+0x38 when not already active.
//
// Callers:
//   - ParticleFluidPhase_Init_Inferred (0x004c2080, W33-S) — final step
//   - FUN_004c1a10 (Gfx_NDParticleFluidBlendNormal_004c1a10) — after delete of prior +0xc4

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_004c1800(void *self, void *parent_phase);
extern "C" void __fastcall FUN_004c0fe0(void *liquid_child /*ECX*/);
extern "C" void FUN_0075bf40(int arg0);
extern "C" void FUN_007567b0(void *obj, int arg1);

// Retail: mov esi,ecx; new(0x40); ctor; [esi+0xc4]=child; FUN_004c0fe0(ecx=child); activate
extern "C" void __fastcall ParticleFluidPhase_CreateLiquidChild_Inferred(void *phase /*ECX*/)
{
  void *raw = operator_new(0x40);
  void *child = nullptr;
  if (raw != nullptr) {
    child = FUN_004c1800(raw, phase);
  }
  *reinterpret_cast<void **>(reinterpret_cast<char *>(phase) + 0xc4) = child;

  FUN_004c0fe0(child);

  auto *c = reinterpret_cast<char *>(child);
  if (c[0x10] != 1) {
    FUN_0075bf40(0);
    FUN_007567b0(*reinterpret_cast<void **>(c + 0x38), 0);
    c[0x10] = 1;
  }
}

extern "C" void __fastcall FUN_004c1960(void *phase /*ECX*/)
{
  ParticleFluidPhase_CreateLiquidChild_Inferred(phase);
}
