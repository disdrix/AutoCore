// =============================================================================
// FUN_005eb210  (twin of VOGPhysics_QueryObject_BaseCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb210
// Address:   0x005eb210  (autoassault.exe, image base 0x400000)
// Range:     0x005eb210–0x005eb2ac inclusive (157 B / 0x9D); pad CC after
// System:    interaction-activation
// Generated: 2026-08-05 R11-008 dual seal
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// Canonical named twin: VOGPhysics_QueryObject_BaseCtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern void __thiscall FUN_00581190(uint32_t *self /* ECX */,
                                    uint32_t obj_from_params1,
                                    uint32_t mode);
extern void __thiscall FUN_005eb040(uint32_t *dest /* ECX */,
                                    const uint32_t *src /* stack */);
extern uint32_t PTR_FUN_009dcde0;
extern float DAT_009dcddc;

uint32_t * __thiscall FUN_005eb210(uint32_t *self /* ECX */,
                                   uint32_t *params /* stack */)
{
  uint32_t uVar1;
  float *float_block;

  FUN_00581190(self, params[1], 2);

  self[0x0F] = 0;
  self[0x10] = 0;
  self[0x11] = 0x80000000u;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0x80000000u;

  self[0x0B] = (uint32_t)(uintptr_t)self;
  *self = (uint32_t)(uintptr_t)&PTR_FUN_009dcde0;

  float_block = reinterpret_cast<float *>(self + 0x18);
  float_block[0] = 0.0f;
  float_block[1] = 0.0f;
  float_block[2] = 0.0f;
  float_block[3] = 0.0f;
  float_block[4] = 0.0f;
  float_block[5] = 0.0f;
  float_block[6] = 0.0f;
  float_block[7] = 0.0f;
  float_block[3] = DAT_009dcddc;
  float_block[7] = DAT_009dcddc;

  self[0x0A] = params[0];
  self[0x05] = (uint32_t)(uintptr_t)(self + 0x18);

  {
    uint32_t *obj = reinterpret_cast<uint32_t *>(self[3]);
    uint32_t *vtbl = reinterpret_cast<uint32_t *>(obj[0]);
    using vfn_t = uint32_t(__thiscall *)(uint32_t *);
    uVar1 = reinterpret_cast<vfn_t>(vtbl[5])(obj);
  }
  self[0x15] = uVar1;

  FUN_005eb040(self + 0x20, params + 8);

  return self;
}
