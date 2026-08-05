// =============================================================================
// FUN_00513e30  — scaffold alias → Item_SetCustomized
// -----------------------------------------------------------------------------
// Stable ID: aa_00513e30
// Address:   0x00513e30  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual A/B:  2026-07-29 W19-H — see Item_SetCustomized.cpp (authoritative clean)
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00512670(int item);

void __thiscall Item_SetCustomized(int *item, std::uint32_t desiredCustomized);

// Scaffold / Ghidra name — body mirrors Item_SetCustomized
void __thiscall FUN_00513e30(int *param_1, std::uint32_t param_2)
{
  Item_SetCustomized(param_1, param_2);
}

// Inline plate (same CF as dual seal; keep if callers include this TU only)
void __thiscall FUN_00513e30_body(int *param_1, std::uint32_t param_2)
{
  int *self = param_1;
  const std::uint32_t desired_byte = param_2 & 0xff;

  if ((((std::uint32_t)self[0x5f] >> 0x14) & 1u) != desired_byte) {
    FUN_00512670((int)self);
    self = param_1;
  }

  self[0x5f] = (int)((std::uint32_t)self[0x5f] ^
                     (((desired_byte << 0x14) ^ (std::uint32_t)self[0x5f]) & 0x100000u));
}
