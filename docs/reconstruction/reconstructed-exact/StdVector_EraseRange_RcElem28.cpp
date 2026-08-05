// =============================================================================
// StdVector_EraseRange_RcElem28  (aa_00461720)
// -----------------------------------------------------------------------------
// Address:   0x00461720  (autoassault.exe, image base 0x400000)
// Body:      0x00461720 – 0x0046177F exclusive (95 B / 0x5F)
// Wave:      W36-N OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcElem28 {
  uint32_t dw0;       // +0x00
  uint32_t dw1;       // +0x04
  uint32_t dw2;       // +0x08
  uint32_t dw3;       // +0x0C
  void* shared;       // +0x10; RC via move helper / Release leaf
  uint8_t b14;        // +0x14
  uint8_t b15;        // +0x15
  uint8_t b16;        // +0x16
  uint32_t dw18;      // +0x18
};

static_assert(sizeof(RcElem28) == 0x1c, "RcElem28 stride");

struct StdVectorRc28 {
  void* unknown0;     // +0x00
  RcElem28* begin;    // +0x04
  RcElem28* end;      // +0x08
  // capacity @ +0x0C (unused here)
};

// Nested (not dual-owned): RC move-assign [src_begin, src_end) onto dest@EAX.
// Retail: EAX=dest, stack (src_begin=last, src_end=old_end, unused/third per call site),
// cdecl ADD ESP,0xC from erase caller; returns pointer past last written elem.
extern "C" RcElem28* FUN_00461e60(RcElem28* src_begin, RcElem28* src_end, RcElem28* /*first_hint*/);

// Nested (not dual-owned): Release shared @ elem+0x10. Retail EAX=elem*.
extern "C" void FUN_00460d70(/* EAX = RcElem28* elem */);

// MSVC-style vector erase [first, last) for non-trivial T size 0x1c.
// Retail ABI: stdcall 4 stack formals; RET 0x10; returns outIt*.
extern "C" RcElem28** StdVector_EraseRange_RcElem28(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* first,
    RcElem28* last)
{
  if (first == last) {
    *outIt = first;
    return outIt;
  }

  // retail: EAX = first before call; move [last, end) down onto first
  RcElem28* new_end = FUN_00461e60(last, vec->end, first);
  RcElem28* old_end = vec->end;

  for (RcElem28* cur = new_end; cur != old_end;
       cur = reinterpret_cast<RcElem28*>(
           reinterpret_cast<char*>(cur) + sizeof(RcElem28))) {
    // retail: mov eax, cur; call FUN_00460d70
    (void)cur;
    FUN_00460d70();
  }

  vec->end = new_end;
  *outIt = first;
  return outIt;
}
