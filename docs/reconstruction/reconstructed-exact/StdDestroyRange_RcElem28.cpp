// =============================================================================
// StdDestroyRange_RcElem28  (aa_00461780)
// -----------------------------------------------------------------------------
// Address:   0x00461780  (autoassault.exe, image base 0x400000)
// Body:      0x00461780 – 0x00461797 exclusive (23 B / 0x17)
// Wave:      W35-O OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcElem28 {
  uint32_t dw0;       // +0x00
  uint32_t dw1;       // +0x04
  uint32_t dw2;       // +0x08
  uint32_t dw3;       // +0x0C
  void* shared;       // +0x10; Release via FUN_00460d70
  uint8_t b14;        // +0x14
  uint8_t b15;        // +0x15
  uint8_t b16;        // +0x16
  uint32_t dw18;      // +0x18
};

static_assert(sizeof(RcElem28) == 0x1c, "RcElem28 stride");

// Nested leaf (not dual-owned): Releases shared resource at elem+0x10.
// Retail ABI: EAX = element*.
extern "C" void FUN_00460d70(/* EAX = RcElem28* elem */);

// MSVC-style destroy range for non-trivial T size 0x1c.
// Retail ABI: EAX=begin*, EDI=end* (exclusive); RET 0.
// Clean formals document the sealed register contract.
extern "C" void StdDestroyRange_RcElem28(RcElem28* begin, RcElem28* end)
{
  for (RcElem28* cur = begin; cur != end;
       cur = reinterpret_cast<RcElem28*>(
           reinterpret_cast<char*>(cur) + sizeof(RcElem28))) {
    // retail: mov eax, cur; call FUN_00460d70
    // FUN_00460d70: shared = *(cur+0x10); if shared: --refcount; if 0: vtbl+8
    (void)cur;
    FUN_00460d70();
  }
}
