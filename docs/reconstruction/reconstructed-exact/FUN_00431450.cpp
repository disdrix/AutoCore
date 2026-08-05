// =============================================================================
// FUN_00431450  (scaffold twin of BasicString_FillAssignRange_0x1c)
// -----------------------------------------------------------------------------
// Stable ID: aa_00431450
// Address:   0x00431450  (autoassault.exe, image base 0x400000)
// Prefer:    BasicString_FillAssignRange_0x1c.cpp
// Generated: 2026-07-29 W33-I dual seal
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

extern void __thiscall BasicString_Assign(BasicString_0x1c* self, const BasicString_0x1c* other);

void FUN_00431450(
    BasicString_0x1c* param_1,
    BasicString_0x1c* param_2,
    const BasicString_0x1c* param_3)
{
  for (; param_1 != param_2;
       param_1 = reinterpret_cast<BasicString_0x1c*>(
           reinterpret_cast<char*>(param_1) + 0x1C)) {
    BasicString_Assign(param_1, param_3);
  }
}
