// =============================================================================
// FUN_00431790  (clean twin of BasicString_CopyBackward_0x1c)
// -----------------------------------------------------------------------------
// Stable ID: aa_00431790
// Address:   0x00431790–0x004317c2  (autoassault.exe, image base 0x400000)
// Generated: dual A/B seal 2026-07-29 (W34-L)
// Exactness: Behavior-preserving rewrite; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

extern BasicString_0x1c& BasicString_Assign(BasicString_0x1c* dst,
                                            const BasicString_0x1c* src);

// Ghidra name retained as twin entry; see BasicString_CopyBackward_0x1c.cpp
BasicString_0x1c* FUN_00431790(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end)
{
  if (first == last) {
    return dest_end;
  }
  do {
    last = reinterpret_cast<BasicString_0x1c*>(
        reinterpret_cast<std::uint8_t*>(last) - 0x1C);
    dest_end = reinterpret_cast<BasicString_0x1c*>(
        reinterpret_cast<std::uint8_t*>(dest_end) - 0x1C);
    BasicString_Assign(dest_end, last);
  } while (last != first);
  return dest_end;
}
