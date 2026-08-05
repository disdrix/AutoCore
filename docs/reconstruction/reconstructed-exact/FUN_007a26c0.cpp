// =============================================================================
// FUN_007a26c0  (twin of Palantir_ExtendedHost_Ctor_Inferred)
// Stable ID: aa_007a26c0  VA: 0x007a26c0  Wave: W37-R
// ABI: stack self*; RET 4; EAX=self. See named clean for full notes.
// =============================================================================

#include <cstdint>

extern "C" float g_flOne;
extern "C" float g_flMultiKillCountBlend;
extern "C" float DAT_00a0f718;
extern "C" float DAT_00a11088;
extern "C" float DAT_00aaa7a4;
extern "C" void* DAT_00d17958;
extern "C" void* ExceptionList;
extern "C" void* PTR_FUN_00a97170;
extern "C" void* PTR_LAB_00a9add0;
extern "C" void* LAB_009b0088;
extern "C" void* __cdecl operator_new(std::uint32_t size);
extern "C" std::uint32_t* __stdcall FUN_007543b0(std::uint32_t* self);
extern "C" void FUN_00424bf0(void); // EAX = self+0xD8 on entry (bytes)
extern "C" std::uint32_t FUN_004933f0(void);

extern "C" std::uint32_t* FUN_007a26c0(std::uint32_t* param_1)
{
  float fVar1;
  std::uint32_t uVar2;
  void* pvVar3;
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xFFFFFFFFu;
  puStack_8 = reinterpret_cast<std::uint8_t*>(&LAB_009b0088);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_007543b0(param_1);
  local_4 = 0;
  *param_1 = reinterpret_cast<std::uint32_t>(PTR_FUN_00a97170);
  // LEA EAX,[ESI+0xD8]; CALL FUN_00424bf0
  FUN_00424bf0();

  param_1[0x57] = *reinterpret_cast<std::uint32_t*>(&DAT_00a0f718);
  fVar1 = g_flOne;
  param_1[0x4A] = 0;
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x4B) = 0;
  param_1[0x59] = 0;
  param_1[0x5A] = 0;
  param_1[0x5B] = 0;
  param_1[0x5C] = 0;
  param_1[0x5D] = 0;
  param_1[0x5E] = 0;
  param_1[0x5F] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6A] = 0;
  param_1[0x6B] = 0;
  param_1[0x6C] = 0;
  param_1[0x6D] = 0;
  param_1[0x6E] = 0;
  param_1[0x6F] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x77) = 1;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7A] = 0;
  param_1[0x7B] = 0;
  param_1[0x7C] = 0;
  param_1[0x7D] = 0;
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x7E) = 0;
  param_1[0x99] = *reinterpret_cast<std::uint32_t*>(&fVar1);
  fVar1 = g_flMultiKillCountBlend;
  param_1[0x9A] = *reinterpret_cast<std::uint32_t*>(&g_flMultiKillCountBlend);
  param_1[0x9B] = *reinterpret_cast<std::uint32_t*>(&fVar1);
  param_1[0x9C] = *reinterpret_cast<std::uint32_t*>(&fVar1);
  param_1[0x9D] = *reinterpret_cast<std::uint32_t*>(&DAT_00a11088);
  uVar2 = *reinterpret_cast<std::uint32_t*>(&DAT_00aaa7a4);
  param_1[0x7F] = reinterpret_cast<std::uint32_t>(PTR_LAB_00a9add0);
  param_1[0x9E] = uVar2;
  local_4 = (local_4 & 0xFFFFFF00u) | 1u;
  uVar2 = FUN_004933f0();
  param_1[0xB5] = uVar2;
  param_1[0xB6] = 0;
  local_4 = (local_4 & 0xFFFFFF00u) | 2u;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0x2E1) = 1;
  param_1[0xB9] = 0;
  DAT_00d17958 = param_1;
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x38) = 0;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0xE2) = 0;
  param_1[0x41] = 800;
  param_1[0x42] = 600;
  param_1[0x43] = 800;
  param_1[0x44] = 600;
  param_1[0x3B] = 0x20;
  param_1[0x3C] = 0x18;
  param_1[0x3D] = 8;
  param_1[0x40] = 0;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0xE6) = 1;
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x3A) = 1;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0xE7) = 1;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0xEA) = 1;

  pvVar3 = operator_new(0xA8);
  if (pvVar3 == nullptr) {
    pvVar3 = nullptr;
  } else {
    auto* b = reinterpret_cast<std::uint8_t*>(pvVar3);
    b[0xE] = 0xFF; b[0xD] = 0xFF; b[0xC] = 0xFF; b[0xF] = 0xFF;
    b[0x12] = 0xFF; b[0x11] = 0xFF; b[0x10] = 0xFF; b[0x13] = 0xFF;
    b[0x16] = 0xFF; b[0x15] = 0xFF; b[0x14] = 0xFF; b[0x17] = 0xFF;
    *reinterpret_cast<std::uint32_t*>(b + 0x6C) = 0;
  }
  param_1[0xB7] = reinterpret_cast<std::uint32_t>(pvVar3);
  *reinterpret_cast<void**>(pvVar3) = pvVar3;
  *reinterpret_cast<std::uint32_t*>(param_1[0xB7] + 4) = param_1[0xB7];
  param_1[0x4F] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  ExceptionList = local_c;
  return param_1;
}
