// =============================================================================
// FUN_00431480  (scaffold twin of BasicString_CopyBackward_Thunk_0x1c)
// -----------------------------------------------------------------------------
// Stable ID: aa_00431480
// Address:   0x00431480  (autoassault.exe, image base 0x400000)
// Prefer:    BasicString_CopyBackward_Thunk_0x1c.cpp
// Generated: 2026-07-29 W33-I dual seal
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

extern BasicString_0x1c* FUN_00431790(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end);

// Effective call-site: three stack args (first, last, dest_end).
// Body also PUSH ECX and reorders; ECX unused by sole parent.
void FUN_00431480(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end)
{
  FUN_00431790(first, last, dest_end);
}
