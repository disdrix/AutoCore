// =============================================================================
// FUN_004a7aa0  — scaffold twin of StdVector_DestroyRange_BasicStringW
// -----------------------------------------------------------------------------
// Address:   0x004a7aa0  (autoassault.exe, image base 0x400000)
// Wave:      W36-S OWN-ONLY dual 2026-07-29
// Canonical: StdVector_DestroyRange_BasicStringW
// =============================================================================

#include <cstdint>

struct BasicStringW_0x1c {
  uint8_t bytes[0x1c];
};

extern "C" void __thiscall basic_string_wchar_dtor(BasicStringW_0x1c* self);

extern "C" void FUN_004a7aa0(BasicStringW_0x1c* first, BasicStringW_0x1c* last)
{
  for (; first != last; first = reinterpret_cast<BasicStringW_0x1c*>(
           reinterpret_cast<uint8_t*>(first) + 0x1c)) {
    basic_string_wchar_dtor(first);
  }
}
