// =============================================================================
// FUN_0040aff0  (scaffold alias — prefer Object_CopyTfid16At228_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040aff0
// Address:   0x0040aff0
// Dual:      2026-08-04 WQ9R-B — named clean is authoritative
// =============================================================================

#include <cstdint>

void __thiscall FUN_0040aff0(int param_1, std::uint32_t *param_2)
{
  *param_2 = *reinterpret_cast<std::uint32_t *>(param_1 + 0x228);
  param_2[1] = *reinterpret_cast<std::uint32_t *>(param_1 + 0x22c);
  param_2[2] = *reinterpret_cast<std::uint32_t *>(param_1 + 0x230);
  param_2[3] = *reinterpret_cast<std::uint32_t *>(param_1 + 0x234);
}
