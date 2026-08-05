// =============================================================================
// FUN_00513580  — scaffold alias → Item_SumEquippedComponentValues
// -----------------------------------------------------------------------------
// Stable ID: aa_00513580
// Address:   0x00513580  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (vendor / item value)
// Dual A/B:  2026-07-29 W19-H — see Item_SumEquippedComponentValues.cpp
// =============================================================================

#include <cstdint>

int __thiscall Item_SumEquippedComponentValues(int *item);

// Scaffold / Ghidra name
int __thiscall FUN_00513580(int *param_1)
{
  return Item_SumEquippedComponentValues(param_1);
}
