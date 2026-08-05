// =============================================================================
// FUN_0077daf0  (scaffold alias → BitStream_readString)
// -----------------------------------------------------------------------------
// Stable ID: aa_0077daf0
// Address:   0x0077daf0  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream string
// Dual:      W20-K 2026-07-29
// Note:      Prefer BitStream_readString.cpp as the named clean unit.
// =============================================================================

#include <cstdint>

// Forward to named reconstruction — keep Ghidra symbol as thin alias surface.
std::uint32_t BitStream_readString(int param_1);

std::uint32_t FUN_0077daf0(int param_1)
{
  return BitStream_readString(param_1);
}
