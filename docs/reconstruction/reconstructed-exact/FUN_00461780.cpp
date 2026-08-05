// =============================================================================
// FUN_00461780  — twin of StdDestroyRange_RcElem28
// -----------------------------------------------------------------------------
// Stable ID: aa_00461780
// Address:   0x00461780  (autoassault.exe, image base 0x400000)
// Body:      0x00461780 – 0x00461797 exclusive (23 B / 0x17)
// Wave:      W35-O OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcElem28 {
  uint32_t dw0;
  uint32_t dw1;
  uint32_t dw2;
  uint32_t dw3;
  void* shared;
  uint8_t b14;
  uint8_t b15;
  uint8_t b16;
  uint32_t dw18;
};

extern "C" void StdDestroyRange_RcElem28(RcElem28* begin, RcElem28* end);

// Ghidra decompiler shows void FUN_00461780(void) with in_EAX / unaff_EDI.
// Sealed retail ABI: EAX=begin, EDI=end, stride 0x1c, RET 0.
// Port via StdDestroyRange_RcElem28; this twin keeps the Ghidra symbol.
extern "C" void FUN_00461780(RcElem28* begin /*EAX*/, RcElem28* end /*EDI*/)
{
  StdDestroyRange_RcElem28(begin, end);
}
