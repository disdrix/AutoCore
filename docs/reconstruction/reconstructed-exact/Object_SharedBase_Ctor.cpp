// =============================================================================
// Object_SharedBase_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00518940
// Address:   0x00518940–0x00518c14  (autoassault.exe, image base 0x400000)
// System:    object core / dual-base shared fields
// Generated: 2026-07-29 W22-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Shared dual-base / virtual-base field constructor for the client
//   object core used by Creature/Vehicle/Character/Item paths (and many others).
//   Outer most-derived ctors LEA ECX to this subobject at type-dependent offsets
//   (e.g. Creature +0x500, Vehicle +0x670, intermediate +0x40 / +0xe0 / +0x110).
//
// ABI: __thiscall/__fastcall; ECX = this; returns this; no stack formals.
//
// Callees: Object_PropagateDirtyBit0x20000 (FUN_00512670), operator_new(0x2c),
//          InitializeCriticalSection.
//

#include <stdint.h>
#include <windows.h>

// Externals (image symbols)
extern "C" float g_flOne;                          // 0x00a0f2a0 = 1.0f
extern "C" uint32_t g_abTfidInvalid_9CDF88[4];     // 0x009cdf88
extern "C" uint32_t DAT_00b04370;                   // +0x90 source dword0
extern "C" uint32_t DAT_00b04374;
extern "C" uint32_t DAT_00b04378;
extern "C" uint32_t DAT_00b0437c;
extern "C" uint32_t DAT_00b04200;                   // instance counter
extern "C" uint32_t DAT_00b041f0;
extern "C" uint32_t DAT_00b041f4;
extern "C" uint32_t DAT_00b041f8;
extern "C" void *PTR_FUN_009ce07c;                  // CS helper stage vtbl
extern "C" void *PTR_FUN_009ce154;                  // CS helper final vtbl
extern "C" void __fastcall FUN_00512670(int32_t self); // Object_PropagateDirtyBit0x20000
extern "C" void *operator_new(uint32_t size);
extern "C" void *ExceptionList;
extern "C" void *LAB_009a35e8;                      // SEH handler label

// MSVC SEH frame locals omitted as structured control; order of stores preserved.

int32_t __fastcall Object_SharedBase_Ctor(int32_t self)
{
  uint32_t tfid_dw3;
  float one;
  uint32_t *cs_helper;

  // --- field defaults (order from decompiler) ---
  *(uint32_t *)(self + 0x60) = 0;
  *(uint32_t *)(self + 0x10) = 0xffffffffu;
  *(uint32_t *)(self + 0x14) = 0;
  *(uint32_t *)(self + 0x18) = 0;
  *(uint32_t *)(self + 0x1c) = 0;
  *(uint8_t *)(self + 0x20) = 0;
  *(uint8_t *)(self + 0x21) = 0;
  *(uint8_t *)(self + 0x22) = 0;
  *(uint8_t *)(self + 0x23) = 0;
  *(uint8_t *)(self + 0x24) = 0;
  *(uint8_t *)(self + 0x25) = 0;
  *(uint8_t *)(self + 0x26) = 0;
  *(uint32_t *)(self + 0x64) = 0;
  *(uint32_t *)(self + 0x68) = 0;
  *(uint32_t *)(self + 0x6c) = 0;
  *(uint32_t *)(self + 0x70) = 0;
  *(uint32_t *)(self + 0x90) = DAT_00b04370;
  *(uint32_t *)(self + 0x94) = DAT_00b04374;
  *(uint32_t *)(self + 0x98) = DAT_00b04378;
  *(uint32_t *)(self + 0x9c) = DAT_00b0437c;
  one = g_flOne;
  *(uint32_t *)(self + 0xa4) = 0;
  *(uint32_t *)(self + 0xa8) = 0;
  *(uint32_t *)(self + 0xac) = 0;
  *(uint32_t *)(self + 0xb4) = 0;
  *(float *)(self + 0xb8) = one;
  *(uint32_t *)(self + 0xc0) = 0;
  *(uint32_t *)(self + 0xc4) = 0;
  *(uint32_t *)(self + 0xc8) = 0xffffffffu;
  *(uint32_t *)(self + 0xcc) = 0;
  *(uint32_t *)(self + 0xd0) = 0;
  *(uint32_t *)(self + 0xd4) = 0;
  *(uint32_t *)(self + 0xd8) = 0;
  *(uint32_t *)(self + 0xdc) = 0;
  *(uint32_t *)(self + 0xe0) = 0;
  *(uint32_t *)(self + 0xe4) = 0;
  *(uint16_t *)(self + 0xe8) = 0;
  *(uint16_t *)(self + 0xea) = 0xffffu;
  *(uint32_t *)(self + 0xf8) = 0xffffffffu;
  *(uint32_t *)(self + 0xfc) = 0xffffffffu;
  *(uint8_t *)(self + 0x100) = 0;
  *(uint32_t *)(self + 0x114) = 0;
  *(uint32_t *)(self + 0x118) = 0;
  *(uint32_t *)(self + 0x11c) = 0;
  *(uint32_t *)(self + 0x124) = 0;
  *(uint32_t *)(self + 0x128) = 0;
  *(uint32_t *)(self + 0x12c) = 0;
  *(uint32_t *)(self + 0x130) = 0;
  *(uint32_t *)(self + 0x138) = 0;
  *(uint32_t *)(self + 0x13c) = 0;
  *(uint32_t *)(self + 0x140) = 0;
  *(uint32_t *)(self + 0x148) = 0;
  *(uint32_t *)(self + 0x14c) = 0;
  *(uint32_t *)(self + 0x150) = 0;
  *(uint32_t *)(self + 0x154) = 0;
  *(uint32_t *)(self + 0x158) = 0;
  *(uint32_t *)(self + 0x15c) = 0;
  *(uint32_t *)(self + 0x160) = g_abTfidInvalid_9CDF88[0];
  *(uint32_t *)(self + 0x164) = g_abTfidInvalid_9CDF88[1];
  *(uint32_t *)(self + 0x168) = g_abTfidInvalid_9CDF88[2];
  tfid_dw3 = g_abTfidInvalid_9CDF88[3];
  *(uint32_t *)(self + 0x184) = *(uint32_t *)(self + 0x184) & 0xfffffff0u;
  *(uint32_t *)(self + 0x16c) = tfid_dw3;
  *(uint32_t *)(self + 0x170) = 0xffffffffu;
  *(uint32_t *)(self + 0x174) = 0xffffffffu;
  *(uint8_t *)(self + 0x178) = 0;
  *(uint16_t *)(self + 0x180) = 0;
  *(uint8_t *)(self + 0x101) = 0;
  *(uint32_t *)(self + 0x17c) =
      (*(uint32_t *)(self + 0x17c) & 0xffe22210u) | 0x22210u;
  *(uint32_t *)(self + 0x80) = 0;
  *(uint32_t *)(self + 0x84) = 0;
  *(uint32_t *)(self + 0x88) = 0;
  *(uint32_t *)(self + 0x8c) = 0;

  // Dirty-bit OR 0x20000 on self (+ parent chain via +0xac; empty here)
  FUN_00512670(self);

  *(uint32_t *)(self + 0x28) = 0xffffffffu;
  *(uint32_t *)(self + 0x2c) = 0xffffffffu;
  *(uint32_t *)(self + 0x30) = 0xffffffffu;
  *(uint32_t *)(self + 0x34) = 0xffffffffu;
  *(uint32_t *)(self + 0x38) = 0xffffffffu;
  *(uint32_t *)(self + 0x3c) = 0xffffffffu;

  cs_helper = (uint32_t *)operator_new(0x2c);
  if (cs_helper == 0) {
    cs_helper = 0;
  } else {
    *cs_helper = (uint32_t)&PTR_FUN_009ce07c;   // stage vtbl
    cs_helper[8] = 0;
    cs_helper[7] = 0;
    cs_helper[9] = 0;
    *(uint8_t *)(cs_helper + 10) = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(cs_helper + 1));
    *cs_helper = (uint32_t)&PTR_FUN_009ce154;   // final vtbl
  }
  *(uint32_t **)(self + 0xb0) = cs_helper;
  *(uint32_t *)(self + 0xbc) = 0;
  *(uint32_t *)(self + 0xa0) = 0;
  *(uint32_t *)(self + 0x40) = g_abTfidInvalid_9CDF88[0];
  *(uint32_t *)(self + 0x44) = g_abTfidInvalid_9CDF88[1];
  *(uint32_t *)(self + 0x48) = g_abTfidInvalid_9CDF88[2];
  *(uint32_t *)(self + 0x4c) = g_abTfidInvalid_9CDF88[3];

  DAT_00b04200 = DAT_00b04200 + 1;
  if (DAT_00b04200 == 1) {
    DAT_00b041f0 = 0;
    DAT_00b041f4 = 0;
    DAT_00b041f8 = 0;
  }
  return self;
}
