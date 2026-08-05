// =============================================================================
// VehiclePhys_Mode2Helper_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f400
// Address:   0x0063f400  (autoassault.exe, image base 0x400000)
// System:    input-drive-control / vehicle phys mode
// Generated: 2026-07-29 W25-K dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct the heap mode-2 vehicle physics helper COM (0x60 bytes).
//   Sole caller: VehiclePhys_SetModeHelper (FUN_005d4050) when mode==2.
//   Installs vtable PTR_FUN_009e3ec0, refcount=1, FLT_MAX / 1.0 defaults,
//   and four blend floats; then FUN_0063f330(this, *(host+0xc)).
//
// ABI (bytes):
//   __thiscall RET 4
//   ECX = Mode2Helper* this (factory-allocated 0x60)
//   stack0 = PhysHost* host
//   EAX = this
//
// CALLER: FUN_005d4050 @ 0x005d4094 (mode-2 only)
// CALLEE: FUN_0063f330
// SIZE:   199 bytes (0x0063f400–0x0063f4c6)
// =============================================================================

#include <cstdint>

extern float g_flOne;                    // 0x00a0f2a0 = 1.0f
extern float g_flHardKillInterpolate;    // 0x00aaa6a4 ≈ 0.005f
extern float g_flMultiKillCountBlend;    // 0x00a0f730 = 0.1f
extern float DAT_00a0f718;               // ≈ 0.01f
extern float DAT_00a0f70c;               // = 0.2f
extern float DAT_009e3ebc;               // FLT_MAX bits 0x7F7FFFFF
extern void* PTR_FUN_009e3ec0;           // mode-2 helper vtable

// Nested: seeds helper+8 from host entity/rb at host+0xc (dual residual).
extern float FUN_0063f330(void* self, void* hostField0c);

struct Mode2Helper {
  void* vtbl;            // +0x00
  uint16_t size_tag;     // +0x04 (set by factory to 0x60 before ctor)
  uint16_t refcount;     // +0x06
  // ... through +0x5c
};

void* __thiscall VehiclePhys_Mode2Helper_Ctor(void* self_raw, void* host)
{
  auto* self = (uint32_t*)self_raw;
  float one = g_flOne;
  float flMax = DAT_009e3ebc;

  self[0x14] = *(uint32_t*)&DAT_00a0f718;            // +0x50
  self[0x15] = *(uint32_t*)&g_flHardKillInterpolate; // +0x54
  self[0x16] = *(uint32_t*)&g_flMultiKillCountBlend; // +0x58
  self[0x17] = *(uint32_t*)&DAT_00a0f70c;            // +0x5c

  *(uint16_t*)((uint8_t*)self + 6) = 1;
  self[0] = (uint32_t)&PTR_FUN_009e3ec0;

  self[4] = self[5] = self[6] = self[7] = *(uint32_t*)&flMax;       // +0x10
  self[0xc] = self[0xd] = self[0xe] = self[0xf] = *(uint32_t*)&flMax; // +0x30

  self[0xb] = 0;
  self[0xa] = 0;
  self[9] = 0;
  self[8] = 0;
  self[0xb] = *(uint32_t*)&one; // +0x2c = 1.0f

  self[0x13] = 0;
  self[0x12] = 0;
  self[0x11] = 0;
  self[0x10] = 0;
  self[0x13] = *(uint32_t*)&one; // +0x4c = 1.0f

  FUN_0063f330(self_raw, *(void**)((uint8_t*)host + 0xc));
  return self_raw;
}

// Ghidra twin symbol
void* __thiscall FUN_0063f400(void* param_1, void* param_2)
{
  return VehiclePhys_Mode2Helper_Ctor(param_1, param_2);
}
