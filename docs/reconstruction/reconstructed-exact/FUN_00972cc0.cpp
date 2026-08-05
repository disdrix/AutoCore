// =============================================================================
// FUN_00972cc0  (twin of Xform_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00972cc0
// Address:   0x00972cc0–0x00972d6a  (autoassault.exe, image base 0x400000)
// Dual:      W37-D 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern float g_flOne;
extern uint32_t DAT_00afdf70[16];

// Prefer Xform_Ctor_Inferred.cpp for named surface.
// Returns this in EAX (bytes); decompiler displays void.

uint32_t* __fastcall FUN_00972cc0(uint32_t* param_1 /*ECX*/)
{
  float fVar1 = g_flOne;
  uint32_t* puVar3;
  uint32_t* puVar4;
  int iVar2;

  puVar3 = DAT_00afdf70;
  puVar4 = param_1;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }

  puVar3 = DAT_00afdf70;
  puVar4 = param_1 + 0x10;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }

  // +0x80..+0x8c = (0,0,0,1)
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  *reinterpret_cast<float*>(param_1 + 0x23) = fVar1;
  // +0x90..+0x98 = 0; +0x9c..+0xb0 = 1
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  *reinterpret_cast<float*>(param_1 + 0x27) = fVar1;
  *reinterpret_cast<float*>(param_1 + 0x28) = fVar1;
  *reinterpret_cast<float*>(param_1 + 0x29) = fVar1;
  *reinterpret_cast<float*>(param_1 + 0x2a) = fVar1;
  *reinterpret_cast<float*>(param_1 + 0x2b) = fVar1;
  *reinterpret_cast<float*>(param_1 + 0x2c) = fVar1;
  // +0xb4 dword 0, +0xb8 byte 0, +0xbc dword 0
  param_1[0x2d] = 0;
  *reinterpret_cast<uint8_t*>(param_1 + 0x2e) = 0;
  param_1[0x2f] = 0;

  return param_1;
}
