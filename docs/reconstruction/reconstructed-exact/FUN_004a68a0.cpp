// =============================================================================
// FUN_004a68a0 / BasicStringW_FillAssignRange_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_004a68a0
// Address:   0x004a68a0  (autoassault.exe, image base 0x400000)
// System:    MSVC basic_string<wchar_t> range fill via operator=
// Generated: dual A/B seal 2026-07-29 (W36-T)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Twin of named clean: BasicStringW_FillAssignRange_0x1c.cpp

#include <cstdint>

struct BasicStringW_0x1c {
  std::uint8_t raw[0x1C];
};

extern BasicStringW_0x1c& BasicStringW_Assign(BasicStringW_0x1c* dst,
                                              const BasicStringW_0x1c* src);

void FUN_004a68a0(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    const BasicStringW_0x1c* value)
{
  for (; first != last; first = reinterpret_cast<BasicStringW_0x1c*>(
           reinterpret_cast<std::uint8_t*>(first) + 0x1C)) {
    BasicStringW_Assign(first, value);
  }
}
