// =============================================================================
// FUN_006295f0  (clean twin of Phys_IslandHost_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_006295f0
// Address:   0x006295f0–0x006296a2 (178 B / 0xB2); ret 4
// Module:    autoassault.exe (image base 0x400000)
// Dual:      2026-07-29 W30-J OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler + machine-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_009e331c;
extern "C" void *PTR_LAB_009e3310;
extern "C" void *PTR_LAB_009d2794;

void __thiscall FUN_006295f0(uint32_t *param_1, uint32_t param_2)
{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = (uint32_t)&PTR_LAB_009d2794;
  param_1[8] = param_2;
  *param_1 = (uint32_t)&PTR_FUN_009e331c;
  param_1[7] = (uint32_t)&PTR_LAB_009e3310;
  *(uint8_t *)(param_1 + 10) = 0;
  *(uint8_t *)((uint8_t *)param_1 + 0x29) = 1;
  *(uint8_t *)(param_1 + 0xb) = 0;
  *(uint8_t *)(param_1 + 0xc) = 1;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0x80000001;
  param_1[0xf] = (uint32_t)(param_1 + 0x12);
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0x80000000;
  param_1[0x17] = 0;
  param_1[0x18] = 0x80000001;
  param_1[0x16] = (uint32_t)(param_1 + 0x19);
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0x80000000;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0x80000000;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0x80000000;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0x80000000;
  return;
}
