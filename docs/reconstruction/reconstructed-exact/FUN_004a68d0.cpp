// =============================================================================
// FUN_004a68d0 / BasicStringW_CopyBackward_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_004a68d0
// Address:   0x004a68d0  (autoassault.exe, image base 0x400000)
// System:    MSVC basic_string<wchar_t> copy_backward free helper
// Generated: dual A/B seal 2026-07-29 (W36-T)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Twin of named clean: BasicStringW_CopyBackward_0x1c.cpp

#include <cstdint>

struct BasicStringW_0x1c {
  std::uint8_t raw[0x1C];
};

extern BasicStringW_0x1c& BasicStringW_Assign(BasicStringW_0x1c* dst,
                                              const BasicStringW_0x1c* src);

BasicStringW_0x1c* FUN_004a68d0(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest_end)
{
  if (first == last) {
    return dest_end;
  }
  do {
    last = reinterpret_cast<BasicStringW_0x1c*>(
        reinterpret_cast<std::uint8_t*>(last) - 0x1C);
    dest_end = reinterpret_cast<BasicStringW_0x1c*>(
        reinterpret_cast<std::uint8_t*>(dest_end) - 0x1C);
    BasicStringW_Assign(dest_end, last);
  } while (last != first);
  return dest_end;
}
