// =============================================================================
// FUN_0045f360 — Ghidra-name twin of StdUninitCopy_Pod28
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f360
// Address:   0x0045f360–0x0045f3AC exclusive (76 B)
// Wave:      W35-K OWN-ONLY 2026-07-29
// See:       StdUninitCopy_Pod28.cpp for full sealed reconstruction.
// =============================================================================

#include <cstdint>

struct Pod28 {
  uint32_t w[7];
};

extern "C" Pod28* StdUninitCopy_Pod28(Pod28* dst, const Pod28* src_begin, const Pod28* src_end);

extern "C" Pod28* FUN_0045f360(Pod28* dst, const Pod28* src_begin, const Pod28* src_end)
{
  return StdUninitCopy_Pod28(dst, src_begin, src_end);
}
