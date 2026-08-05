// =============================================================================
// BasicStringW_FillAssignRange_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_004a68a0
// Address:   0x004a68a0–0x004a68c6  (autoassault.exe, image base 0x400000)
// Body:      39 B / 0x27
// System:    MSVC basic_string<wchar_t> range fill via operator=
// Generated: dual A/B seal 2026-07-29 (W36-T); Ghidra FUN_004a68a0
// Exactness: Behavior-preserving rewrite of decompiler + read_memory control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

/*
 * Behavioral notes:
 * - Free std::fill-shaped assign loop on live basic_string<wchar_t> slots.
 * - Element stride 0x1c; forward walk; operator= per element from fixed value*.
 * - cdecl 3 stack args; plain RET; void.
 * - Sole parent: StdVector_InsertN_BasicStringW (0x004a7ad0) in-place hole fill.
 * - Char twin: BasicString_FillAssignRange_0x1c (0x00431450).
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

// cdecl; plain RET; void
void BasicStringW_FillAssignRange_0x1c(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    const BasicStringW_0x1c* value)
{
  for (; first != last; first = reinterpret_cast<BasicStringW_0x1c*>(
           reinterpret_cast<std::uint8_t*>(first) + 0x1C)) {
    BasicStringW_Assign(first, value);
  }
}
