// =============================================================================
// BasicString_CopyBackward_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_00431790
// Address:   0x00431790–0x004317c2  (autoassault.exe, image base 0x400000)
// Body:      51 B / 0x33
// System:    MSVC basic_string<char> copy_backward free helper
// Generated: dual A/B seal 2026-07-29 (W34-L); Ghidra FUN_00431790
// Exactness: Behavior-preserving rewrite of decompiler + read_memory control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

/*
 * Behavioral notes:
 * - Free std::copy_backward-shaped assign loop on live basic_string slots.
 * - Element stride 0x1c; reverse walk last/dest_end; operator= per element.
 * - cdecl 3 stack args; plain RET; returns final dest pointer in EAX.
 * - Sole parent trampoline: BasicString_CopyBackward_Thunk_0x1c (0x00431480).
 * - Name is structural Inferred (W33-I nested residual closed here).
 */

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

// Retail: IAT [0x009c63c4] → 0x006ec244 basic_string::operator=
extern BasicString_0x1c& BasicString_Assign(BasicString_0x1c* dst,
                                            const BasicString_0x1c* src);

// cdecl; returns final dest after reverse walk
BasicString_0x1c* BasicString_CopyBackward_0x1c(
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
