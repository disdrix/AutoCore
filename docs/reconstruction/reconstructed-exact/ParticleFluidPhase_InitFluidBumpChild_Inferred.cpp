// =============================================================================
// ParticleFluidPhase_InitFluidBumpChild_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0a90
// Address:   0x004c0a90  (autoassault.exe, image base 0x400000)
// System:    client / particle fluid phase (env+0xCC host from FUN_004c0640)
// Generated: 2026-07-29 W34-N dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Install fluid-bump / blend-normal render child on the fluid phase:
//   new(0x198)+FUN_00968a50 → phase+0x9c; parent link; SetNear(0.2)/far(500);
//   color 0x808080; dirty flags; device vtbl+0x18; cache phase+0x94=child+0x44;
//   load Particle_Fluid_bump.dds + NDParticleFluidBlendNormal.fx; NormalMapTexture.
// Sole caller: ParticleFluidPhase_Init_Inferred (0x004c2080).

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__fastcall FUN_00968a50(void *self);
extern "C" void  __thiscall GfxView_SetNear_Inferred(void *view, uint32_t near_bits);
extern "C" void  __thiscall FUN_0075b390(void *view, uint32_t far_bits);
extern "C" void  __thiscall FUN_0075bf40(void *view, uint32_t color);
extern "C" void  __thiscall FUN_0075b450(void *view);
extern "C" void  FUN_0096ef70(void);
extern "C" void  FUN_00989e00(void *dst, const char *cstr);
extern "C" void  FUN_0096f3e0(void *name, int flag);
extern "C" void  FUN_009701d0(void *fx_name);
extern "C" void  FUN_00970140(const char *param, uint32_t value);
extern "C" void  FUN_0096efd0(void);

// Also linked as FUN_0075b3b0
extern "C" void  __thiscall FUN_0075b3b0(void *view, uint32_t near_bits);

extern "C" void __fastcall ParticleFluidPhase_InitFluidBumpChild_Inferred(void *phase)
{
  // Retail: SEH; load device pair from *(DAT_00d1f058+0x2c)+0x80/0x84
  void *raw = operator_new(0x198);
  void *child = raw ? FUN_00968a50(raw) : 0;
  *reinterpret_cast<void **>(reinterpret_cast<char *>(phase) + 0x9c) = child;

  // Unchecked on OOM (retail)
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(child) + 0x195) |= 0x40;
  *reinterpret_cast<void **>(reinterpret_cast<char *>(child) + 4) = phase;

  GfxView_SetNear_Inferred(child, 0x3e4ccccdu); // 0.2f
  FUN_0075b390(child, 0x43fa0000u);             // 500.0f
  FUN_0075bf40(child, 0x808080u);
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(child) + 0x180) = 0;
  FUN_0075b450(child);

  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(child) + 0xec) = 0;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(child) + 0x48) = 1;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(child) + 0xcc) = 1;

  // child->vtbl[+0x18](&device_pair) — residual callee
  // *(child+0x108)=0; *(child+0x190)=1

  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(phase) + 0x94) =
      *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(child) + 0x44);

  FUN_0096ef70();
  // FUN_00989e00(..., "Particle_Fluid_bump.dds"); FUN_0096f3e0(..., 0);
  // FUN_00989e00(..., "NDParticleFluidBlendNormal.fx"); FUN_009701d0(...);
  // FUN_00970140("NormalMapTexture", 0x808080);
  FUN_0096efd0();
}

extern "C" void __fastcall FUN_004c0a90(void *phase)
{
  ParticleFluidPhase_InitFluidBumpChild_Inferred(phase);
}
