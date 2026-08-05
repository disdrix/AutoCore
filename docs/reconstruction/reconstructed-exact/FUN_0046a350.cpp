// =============================================================================
// FUN_0046a350  — twin of StdUninitCopy_Elem28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a350
// Address:   0x0046a350–0x0046a372 exclusive (34 B)
// Wave:      W36-P OWN-ONLY 2026-07-29
// =============================================================================

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

extern "C" Elem28* StdUninitCopy_Elem28_Inferred(
    Elem28* dst,
    const Elem28* src_begin,
    const Elem28* src_end);

// Retail: EAX=dst, EDX=src_begin, EBX=src_end; bare RET; EAX=dst_end out
extern "C" Elem28* FUN_0046a350(
    Elem28* dst,
    const Elem28* src_begin,
    const Elem28* src_end)
{
  return StdUninitCopy_Elem28_Inferred(dst, src_begin, src_end);
}
