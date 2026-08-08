// =============================================================================
// FUN_00416160 — Ghidra alias twin of XformState_AssignSelectiveByFlags_Inferred
// VA 0x00416160; see XformState_AssignSelectiveByFlags_Inferred.cpp for sealed body.
// Wave: WQ9I-G 2026-08-05
// =============================================================================

#include <cstdint>

// thiscall ECX=dest, stack src*; ret 4.
// param indices are dword slots (×4 = byte offset).
extern "C" void __thiscall FUN_00416160(uint32_t* param_1, uint32_t* param_2)
{
  uint32_t uVar1;
  int iVar2;
  uint32_t* puVar3;
  uint32_t* puVar4;

  param_1[0x20] = param_2[0x20];
  param_1[0x21] = param_2[0x21];
  param_1[0x22] = param_2[0x22];
  param_1[0x23] = param_2[0x23];
  param_1[0x24] = param_2[0x24];
  param_1[0x25] = param_2[0x25];
  param_1[0x26] = param_2[0x26];
  param_1[0x27] = param_2[0x27];
  param_1[0x28] = param_2[0x28];
  param_1[0x29] = param_2[0x29];
  *reinterpret_cast<uint8_t*>(param_1 + 0x2e) =
      *reinterpret_cast<uint8_t*>(param_2 + 0x2e);
  uVar1 = param_2[0x2f];
  param_1[0x2f] = uVar1;
  if ((uVar1 & 1) == 0) {
    puVar3 = param_2;
    puVar4 = param_1;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  if (((static_cast<uint32_t>(param_1[0x2f]) >> 1) & 1) == 0) {
    puVar3 = param_2 + 0x10;
    puVar4 = param_1 + 0x10;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  if (((static_cast<uint32_t>(param_1[0x2f]) >> 2) & 1) == 0) {
    param_1[0x2a] = param_2[0x2a];
    param_1[0x2b] = param_2[0x2b];
    param_1[0x2c] = param_2[0x2c];
  }
  param_1[0x2d] = param_1[0x2d] + 1;
}
