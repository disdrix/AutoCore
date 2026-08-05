// =============================================================================
// CVOGEnvironmentDistort_BringUpParticleDistort_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ca90
// Address:   0x0055ca90–0x0055cc42  (0x1B2 / 434 bytes; autoassault.exe @ 0x400000)
// System:    client / VOGEnvironmentSector / CVOGEnvironmentDistort
// Dual A/B:  2026-08-04 W37-J
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// Ghidra:    FUN_0055ca90
// =============================================================================
// PURPOSE
//   Post-ctor particle-distort child bring-up for CVOGEnvironmentDistort:
//     - new(0x198) + FUN_00968a50 → host+0x90; parent backlink; flags |0x40
//     - particle floats 0.2f / 500.0f, color 0xff808000, dirty flags
//     - vcall child[+0x18] with render-context snapshot
//     - bind Particle_Distort.dds + NDParticleDistortBlendNormal.fx
//       + NormalMapTexture(0xff808000)
//     - mirror child+0x44 → host+0x8C
//
// ABI
//   __thiscall  plain ret  void  (SEH frame LAB_009a4975)
//
// Callers
//   CVOGEnvironmentDistort_Enable_Inferred (FUN_0055cc50) @ 0x0055cc5f — sole
//
// Product strings
//   "Particle_Distort.dds"
//   "NDParticleDistortBlendNormal.fx"
//   "NormalMapTexture"
//
// Related
//   Enable wrapper: 0x0055cc50 (W33-T)
//   Host RTTI: .?AVCVOGEnvironmentDistort@@ (Confirmed via ctor COL)
//   Peer child: FUN_005b3420 (Reflect, slot +0x158; no Particle_Distort path)
//   Particle ctor: FUN_00968a50 (W37-I)
//
// Rejected aliases
//   Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0055ca90
//   Gfx_NDParticleDistortBlendNormal (incomplete — misses host/dds path)
// =============================================================================

#include <cstdint>

// Global graphics hub (Ghidra DAT_00d1f058)
extern uint8_t *DAT_00d1f058;

struct CVOGEnvironmentDistort {
  // size 0xA0 (ctor FUN_0055c8c0)
  // +0x8C = mirror of child+0x44
  // +0x90 = particle child*
  uint8_t raw[0xA0];
};

struct ParticleChild_0x198 {
  void **vtbl;   // +0x00
  void *parent;  // +0x04
  uint8_t raw[0x198];
};

extern void *__cdecl operator_new(uint32_t size);
extern ParticleChild_0x198 *__fastcall FUN_00968a50(void *mem);
extern void __thiscall FUN_0075b3b0(void *self, uint32_t f32bits);
extern void __thiscall FUN_0075b390(void *self, uint32_t f32bits);
extern void __thiscall FUN_0075bf40(void *self, uint32_t argb);
extern void __fastcall FUN_0075b450(void *self);
extern void __fastcall FUN_0096ef70(void *binder);
extern void FUN_00989e00(void *dst, const char *cstr);
extern void __thiscall FUN_0096f3e0(void *binder, void *name, int flags);
extern void __thiscall FUN_009701d0(void *binder, void *name);
extern void __thiscall FUN_00970140(void *binder, const char *param, uint32_t color);
extern void __fastcall FUN_0096efd0(void *binder);

void __thiscall CVOGEnvironmentDistort_BringUpParticleDistort_Inferred(
    CVOGEnvironmentDistort *host)
{
  auto *h = reinterpret_cast<uint8_t *>(host);

  // Snapshot from DAT_00d1f058 → +0x2c → +0x80 / +0x84
  uint8_t *mid = *reinterpret_cast<uint8_t **>(DAT_00d1f058 + 0x2c);
  uint32_t snapshot[2];
  snapshot[0] = *reinterpret_cast<uint32_t *>(mid + 0x80);
  snapshot[1] = *reinterpret_cast<uint32_t *>(mid + 0x84);

  void *mem = operator_new(0x198);
  ParticleChild_0x198 *child = mem ? FUN_00968a50(mem) : nullptr;

  *reinterpret_cast<ParticleChild_0x198 **>(h + 0x90) = child;
  auto *c = reinterpret_cast<uint8_t *>(child);

  c[0x195] = static_cast<uint8_t>(c[0x195] | 0x40);
  *reinterpret_cast<void **>(c + 0x04) = host;

  FUN_0075b3b0(child, 0x3e4ccccd); // 0.2f  → child+0xF0
  FUN_0075b390(child, 0x43fa0000); // 500.f → child+0xF4
  FUN_0075bf40(child, 0xff808000); // ARGB  → child+0x148 path
  *reinterpret_cast<uint32_t *>(c + 0x180) = 0;
  FUN_0075b450(child);
  *reinterpret_cast<uint32_t *>(c + 0xec) = 0;
  c[0x48] = 1;
  c[0xcc] = 1;

  using V18 = void(__thiscall *)(void *self, void *snapshotPair);
  auto **vtbl = *reinterpret_cast<void ***>(child);
  reinterpret_cast<V18>(vtbl[0x18 / 4])(child, snapshot);

  *reinterpret_cast<uint32_t *>(c + 0x108) = 0;
  c[0x190] = 1; // +400 decimal
  *reinterpret_cast<uint32_t *>(h + 0x8c) =
      *reinterpret_cast<uint32_t *>(c + 0x44);

  // Material binder thiscall target is stack/host plumbing (ESI path in body).
  // Call order sealed; binder identity residual.
  uint8_t binder[0x20]{};
  FUN_0096ef70(binder);

  uint8_t texName[0x20]{};
  uint8_t fxName[0x28]{};
  FUN_00989e00(texName, "Particle_Distort.dds");
  FUN_0096f3e0(binder, texName, 0);
  FUN_00989e00(fxName, "NDParticleDistortBlendNormal.fx");
  FUN_009701d0(binder, fxName);
  FUN_00970140(binder, "NormalMapTexture", 0xff808000);
  FUN_0096efd0(binder);
}
