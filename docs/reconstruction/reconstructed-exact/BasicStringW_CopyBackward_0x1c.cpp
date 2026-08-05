// =============================================================================
// BasicStringW_CopyBackward_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_004a68d0
// Address:   0x004a68d0–0x004a6902  (autoassault.exe, image base 0x400000)
// Body:      51 B / 0x33
// System:    MSVC basic_string<wchar_t> copy_backward free helper
// Generated: dual A/B seal 2026-07-29 (W36-T); Ghidra FUN_004a68d0
// Exactness: Behavior-preserving rewrite of decompiler + read_memory control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

/*
 * Behavioral notes:
 * - Free std::copy_backward-shaped assign loop on live basic_string<wchar_t> slots.
 * - Element stride 0x1c; reverse walk last/dest_end; operator= per element.
 * - cdecl 3 stack args; plain RET; returns final dest pointer in EAX.
 * - Sole parent: StdVector_InsertN_BasicStringW (0x004a7ad0) mid-insert shift.
 * - Char twin: BasicString_CopyBackward_0x1c (0x00431790).
 * - Name is structural Inferred (closes W34-R nested helper residual).
 */

#include <cstdint>

struct BasicStringW_0x1c {
  // MSVC basic_string<wchar_t> layout; size 0x1C. Opaque here.
  std::uint8_t raw[0x1C];
};

// Retail: IAT [0x009c63bc] → 0x006ec314 basic_string<wchar_t>::operator=
extern BasicStringW_0x1c& BasicStringW_Assign(BasicStringW_0x1c* dst,
                                              const BasicStringW_0x1c* src);

// cdecl; returns final dest after reverse walk
BasicStringW_0x1c* BasicStringW_CopyBackward_0x1c(
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
