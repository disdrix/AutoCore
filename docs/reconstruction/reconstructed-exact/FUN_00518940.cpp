// =============================================================================
// FUN_00518940 (scaffold alias of Object_SharedBase_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00518940
// Address:   0x00518940–0x00518c14  (autoassault.exe, image base 0x400000)
// System:    object core / dual-base shared fields
// Generated: 2026-07-29 W22-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Named clean: Object_SharedBase_Ctor.cpp
// Role: Shared dual-base object-core field constructor.

#include <stdint.h>
#include <windows.h>

extern "C" float g_flOne;
extern "C" uint32_t g_abTfidInvalid_9CDF88[4];
extern "C" uint32_t DAT_00b04370;
extern "C" uint32_t DAT_00b04374;
extern "C" uint32_t DAT_00b04378;
extern "C" uint32_t DAT_00b0437c;
extern "C" uint32_t DAT_00b04200;
extern "C" uint32_t DAT_00b041f0;
extern "C" uint32_t DAT_00b041f4;
extern "C" uint32_t DAT_00b041f8;
extern "C" void *PTR_FUN_009ce07c;
extern "C" void *PTR_FUN_009ce154;
extern "C" void __fastcall FUN_00512670(int32_t self);
extern "C" void *operator_new(uint32_t size);

int32_t __fastcall FUN_00518940(int32_t param_1)
{
  uint32_t uVar1;
  float fVar2;
  uint32_t *puVar3;

  *(uint32_t *)(param_1 + 0x60) = 0;
  *(uint32_t *)(param_1 + 0x10) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x14) = 0;
  *(uint32_t *)(param_1 + 0x18) = 0;
  *(uint32_t *)(param_1 + 0x1c) = 0;
  *(uint8_t *)(param_1 + 0x20) = 0;
  *(uint8_t *)(param_1 + 0x21) = 0;
  *(uint8_t *)(param_1 + 0x22) = 0;
  *(uint8_t *)(param_1 + 0x23) = 0;
  *(uint8_t *)(param_1 + 0x24) = 0;
  *(uint8_t *)(param_1 + 0x25) = 0;
  *(uint8_t *)(param_1 + 0x26) = 0;
  *(uint32_t *)(param_1 + 0x64) = 0;
  *(uint32_t *)(param_1 + 0x68) = 0;
  *(uint32_t *)(param_1 + 0x6c) = 0;
  *(uint32_t *)(param_1 + 0x70) = 0;
  *(uint32_t *)(param_1 + 0x90) = DAT_00b04370;
  *(uint32_t *)(param_1 + 0x94) = DAT_00b04374;
  *(uint32_t *)(param_1 + 0x98) = DAT_00b04378;
  *(uint32_t *)(param_1 + 0x9c) = DAT_00b0437c;
  fVar2 = g_flOne;
  *(uint32_t *)(param_1 + 0xa4) = 0;
  *(uint32_t *)(param_1 + 0xa8) = 0;
  *(uint32_t *)(param_1 + 0xac) = 0;
  *(uint32_t *)(param_1 + 0xb4) = 0;
  *(float *)(param_1 + 0xb8) = fVar2;
  *(uint32_t *)(param_1 + 0xc0) = 0;
  *(uint32_t *)(param_1 + 0xc4) = 0;
  *(uint32_t *)(param_1 + 0xc8) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0xcc) = 0;
  *(uint32_t *)(param_1 + 0xd0) = 0;
  *(uint32_t *)(param_1 + 0xd4) = 0;
  *(uint32_t *)(param_1 + 0xd8) = 0;
  *(uint32_t *)(param_1 + 0xdc) = 0;
  *(uint32_t *)(param_1 + 0xe0) = 0;
  *(uint32_t *)(param_1 + 0xe4) = 0;
  *(uint16_t *)(param_1 + 0xe8) = 0;
  *(uint16_t *)(param_1 + 0xea) = 0xffffu;
  *(uint32_t *)(param_1 + 0xf8) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0xfc) = 0xffffffffu;
  *(uint8_t *)(param_1 + 0x100) = 0;
  *(uint32_t *)(param_1 + 0x114) = 0;
  *(uint32_t *)(param_1 + 0x118) = 0;
  *(uint32_t *)(param_1 + 0x11c) = 0;
  *(uint32_t *)(param_1 + 0x124) = 0;
  *(uint32_t *)(param_1 + 0x128) = 0;
  *(uint32_t *)(param_1 + 0x12c) = 0;
  *(uint32_t *)(param_1 + 0x130) = 0;
  *(uint32_t *)(param_1 + 0x138) = 0;
  *(uint32_t *)(param_1 + 0x13c) = 0;
  *(uint32_t *)(param_1 + 0x140) = 0;
  *(uint32_t *)(param_1 + 0x148) = 0;
  *(uint32_t *)(param_1 + 0x14c) = 0;
  *(uint32_t *)(param_1 + 0x150) = 0;
  *(uint32_t *)(param_1 + 0x154) = 0;
  *(uint32_t *)(param_1 + 0x158) = 0;
  *(uint32_t *)(param_1 + 0x15c) = 0;
  *(uint32_t *)(param_1 + 0x160) = g_abTfidInvalid_9CDF88[0];
  *(uint32_t *)(param_1 + 0x164) = g_abTfidInvalid_9CDF88[1];
  *(uint32_t *)(param_1 + 0x168) = g_abTfidInvalid_9CDF88[2];
  uVar1 = g_abTfidInvalid_9CDF88[3];
  *(uint32_t *)(param_1 + 0x184) = *(uint32_t *)(param_1 + 0x184) & 0xfffffff0u;
  *(uint32_t *)(param_1 + 0x16c) = uVar1;
  *(uint32_t *)(param_1 + 0x170) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x174) = 0xffffffffu;
  *(uint8_t *)(param_1 + 0x178) = 0;
  *(uint16_t *)(param_1 + 0x180) = 0;
  *(uint8_t *)(param_1 + 0x101) = 0;
  *(uint32_t *)(param_1 + 0x17c) =
      (*(uint32_t *)(param_1 + 0x17c) & 0xffe22210u) | 0x22210u;
  *(uint32_t *)(param_1 + 0x80) = 0;
  *(uint32_t *)(param_1 + 0x84) = 0;
  *(uint32_t *)(param_1 + 0x88) = 0;
  *(uint32_t *)(param_1 + 0x8c) = 0;
  FUN_00512670(param_1);
  *(uint32_t *)(param_1 + 0x28) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x2c) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x30) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x34) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x38) = 0xffffffffu;
  *(uint32_t *)(param_1 + 0x3c) = 0xffffffffu;
  puVar3 = (uint32_t *)operator_new(0x2c);
  if (puVar3 == 0) {
    puVar3 = 0;
  } else {
    *puVar3 = (uint32_t)&PTR_FUN_009ce07c;
    puVar3[8] = 0;
    puVar3[7] = 0;
    puVar3[9] = 0;
    *(uint8_t *)(puVar3 + 10) = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));
    *puVar3 = (uint32_t)&PTR_FUN_009ce154;
  }
  *(uint32_t **)(param_1 + 0xb0) = puVar3;
  *(uint32_t *)(param_1 + 0xbc) = 0;
  *(uint32_t *)(param_1 + 0xa0) = 0;
  *(uint32_t *)(param_1 + 0x40) = g_abTfidInvalid_9CDF88[0];
  *(uint32_t *)(param_1 + 0x44) = g_abTfidInvalid_9CDF88[1];
  *(uint32_t *)(param_1 + 0x48) = g_abTfidInvalid_9CDF88[2];
  *(uint32_t *)(param_1 + 0x4c) = g_abTfidInvalid_9CDF88[3];
  DAT_00b04200 = DAT_00b04200 + 1;
  if (DAT_00b04200 == 1) {
    DAT_00b041f0 = 0;
    DAT_00b041f4 = 0;
    DAT_00b041f8 = 0;
  }
  return param_1;
}
