// =============================================================================
// FUN_004bbfb0  (scaffold twin → COList_Constructor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbfb0
// Address:   0x004bbfb0–0x004bc17f  (464 B, autoassault.exe base 0x400000)
// System:    client / COList
// Generated: 2026-07-29 W27-L dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: docs/reconstruction/reconstructed-exact/COList_Constructor.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* operator_new(uint32_t size);
extern "C" uint32_t* __thiscall FUN_004bcf90(uint32_t* self, uint8_t bit_size);
extern "C" uint32_t* __thiscall FUN_004bce90(uint32_t* self, uint8_t bit_size);

extern void* PTR_FUN_009cb448;
extern void* PTR_FUN_009cb334;
extern void* PTR_FUN_009cb378;
extern void* ExceptionList;
extern void* LAB_009a1742;

// __thiscall; ECX=this; stack (capA, capB); ret 8; returns this*
extern "C" uint32_t* __thiscall FUN_004bbfb0(uint32_t* param_1, int param_2, int param_3)
{
  void* pvVar1;
  uint32_t uVar2;
  uint32_t* puVar3;
  void* local_c;
  uint8_t* puStack_8;
  uint8_t local_4;
  uint8_t uStack_3[3];

  puStack_8 = reinterpret_cast<uint8_t*>(&LAB_009a1742);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  *param_1 = reinterpret_cast<uint32_t>(&PTR_FUN_009cb448);
  param_1[0x0B] = 0;
  param_1[0x0C] = 0;
  param_1[0x0D] = 0;
  param_1[0x0F] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;

  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }

  local_4 = 2;
  uStack_3[0] = 0;
  uStack_3[1] = 0;
  uStack_3[2] = 0;
  param_1[4] = static_cast<uint32_t>(param_2);
  param_1[5] = static_cast<uint32_t>(param_3);
  *reinterpret_cast<uint8_t*>(param_1 + 3) = static_cast<uint8_t>(param_2 != 0);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x0D) =
      static_cast<uint8_t>(param_3 != 0);

  if (param_2 != 0) {
    pvVar1 = operator_new(0x34);
    local_4 = 3;
    if (pvVar1 == nullptr) {
      uVar2 = 0;
    } else {
      uVar2 = reinterpret_cast<uint32_t>(
          FUN_004bcf90(static_cast<uint32_t*>(pvVar1), static_cast<uint8_t>(param_2)));
    }
  } else {
    uVar2 = 0;
  }
  local_4 = 2;
  param_1[1] = uVar2;

  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x0D) == 0) {
    uVar2 = 0;
  } else {
    pvVar1 = operator_new(0x34);
    local_4 = 4;
    if (pvVar1 == nullptr) {
      uVar2 = 0;
    } else {
      uVar2 = reinterpret_cast<uint32_t>(
          FUN_004bcf90(static_cast<uint32_t*>(pvVar1), static_cast<uint8_t>(param_3)));
    }
  }
  local_4 = 2;
  param_1[2] = uVar2;

  pvVar1 = operator_new(0x34);
  local_4 = 5;
  if (pvVar1 == nullptr) {
    uVar2 = 0;
  } else {
    uVar2 = reinterpret_cast<uint32_t>(FUN_004bce90(static_cast<uint32_t*>(pvVar1), 5));
  }
  local_4 = 2;
  param_1[6] = uVar2;

  // Three identical 0x2C CS-list constructions (final vtbl 009cb378).
  for (int slot = 7; slot <= 9; ++slot) {
    puVar3 = static_cast<uint32_t*>(operator_new(0x2C));
    if (puVar3 == nullptr) {
      puVar3 = nullptr;
    } else {
      *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_009cb334);
      puVar3[8] = 0;
      puVar3[7] = 0;
      puVar3[9] = 0;
      *reinterpret_cast<uint8_t*>(puVar3 + 10) = 0;
      InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(puVar3 + 1));
      *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_009cb378);
    }
    param_1[slot] = reinterpret_cast<uint32_t>(puVar3);
  }

  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x0E) = 0;
  ExceptionList = local_c;
  return param_1;
}
