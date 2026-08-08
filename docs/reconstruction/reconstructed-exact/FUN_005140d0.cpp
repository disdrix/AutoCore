// =============================================================================
// FUN_005140d0  (machine twin of UI_ItemRarity_WriteBgraFromIndex_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005140d0
// Address:   0x005140d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R12-016 dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// cdecl; bare RET; EAX = param_1 on exit.
// param_1 = BGRA out[4]; param_2 = signed rarity index (word).
uint8_t* FUN_005140d0(uint8_t* param_1, int16_t param_2)
{
  switch (param_2) {
  case 0:
    param_1[2] = 0x91;
    param_1[1] = 0x91;
    *param_1 = 0x91;
    param_1[3] = 0xFF;
    return param_1;
  case 1:
    param_1[2] = 0xFF;
    param_1[1] = 0xFF;
    *param_1 = 0xFF;
    param_1[3] = 0xFF;
    return param_1;
  case 2:
    param_1[2] = 0x28;
    param_1[1] = 0x28;
    *param_1 = 0xFF;
    param_1[3] = 0xFF;
    return param_1;
  case 3:
    param_1[1] = 0x14;
    *param_1 = 0xF0;
    param_1[2] = 0xF0;
    param_1[3] = 0xFF;
    return param_1;
  case 4:
    param_1[2] = 0xFF;
    param_1[1] = 0x0A;
    *param_1 = 0x23;
    param_1[3] = 0xFF;
    return param_1;
  case 5:
    param_1[2] = 0xFF;
    param_1[1] = 0x8A;
    *param_1 = 0x0A;
    param_1[3] = 0xFF;
    return param_1;
  default:
    param_1[1] = 0xE4;
    *param_1 = 0x3C;
    param_1[2] = 0xF0;
    param_1[3] = 0xFF;
    return param_1;
  }
}
