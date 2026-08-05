// =============================================================================
// BasicString_FillAssignRange_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_00431450
// Address:   0x00431450  (autoassault.exe, image base 0x400000)
// Body:      0x00431450–0x00431477 exclusive (39 B)
// System:    MSVC basic_string<char> range fill via operator=
// Generated: 2026-07-29 W33-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE: Assign one source basic_string into every live slot in [first, last).
// Element stride 0x1c. Used by StdVector_InsertN_BasicString in-place insert arms.
// Not uninitialized fill (ctor); not count-N API.

#include <cstdint>

struct BasicString_0x1c {
  // MSVC basic_string<char> layout; size 0x1C. Opaque here.
  std::uint8_t raw[0x1C];
};

// IAT: [0x009c63c4] → basic_string::operator=
extern void __thiscall BasicString_Assign(BasicString_0x1c* self, const BasicString_0x1c* other);

// cdecl; plain RET; void
void BasicString_FillAssignRange_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    const BasicString_0x1c* value)
{
  for (; first != last; first = reinterpret_cast<BasicString_0x1c*>(
           reinterpret_cast<char*>(first) + 0x1C)) {
    BasicString_Assign(first, value);
  }
}
