// =============================================================================
// StdUninitFillN_RcElem28  (aa_00461c90)
// -----------------------------------------------------------------------------
// Address:   0x00461c90  (autoassault.exe, image base 0x400000)
// Body:      0x00461c90 – 0x00461d74 exclusive (228 B / 0xE4)
// Wave:      W35-O OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Element size 0x1c with shared resource at +0x10 (refcounted).
// Layout sealed with parent StdVector_InsertN_RcElem28 (W34-P).
struct RcShared28 {
  void** vtbl;       // +0x00; [vtbl+4]=AddRef/on-first, [vtbl+8]=Release
  int32_t refcount;  // +0x04
};

struct RcElem28 {
  uint32_t dw0;       // +0x00
  uint32_t dw1;       // +0x04
  uint32_t dw2;       // +0x08
  uint32_t dw3;       // +0x0C
  RcShared28* shared; // +0x10
  uint8_t b14;        // +0x14
  uint8_t b15;        // +0x15
  uint8_t b16;        // +0x16
  // pad +0x17
  uint32_t dw18;      // +0x18
};

static_assert(sizeof(RcElem28) == 0x1c, "RcElem28 stride");

// MSVC-style _Uninit_fill_n for non-trivial T size 0x1c.
// ABI: ECX=value*, EDX=count, stack dest*; RET 0.
// Callers may push an extra unused dword and clean 8 bytes.
// SEH around each construction; unwind Releases constructed range (not modeled here).
extern "C" void __fastcall StdUninitFillN_RcElem28(
    const RcElem28* value,
    int count,
    RcElem28* dest)
{
  for (; count != 0; --count) {
    if (dest != nullptr) {
      dest->dw0 = value->dw0;
      dest->dw1 = value->dw1;
      dest->dw2 = value->dw2;
      dest->dw3 = value->dw3;

      RcShared28* r = value->shared;
      if (r != nullptr) {
        r->refcount += 1;
        if (r->refcount == 1) {
          // retail: call [r->vtbl + 4]
          using Fn = void(__fastcall*)(RcShared28*);
          reinterpret_cast<Fn>(r->vtbl[1])(r);
        }
      }
      dest->shared = value->shared;
      dest->b14 = value->b14;
      dest->b15 = value->b15;
      dest->b16 = value->b16;
      dest->dw18 = value->dw18;
    }
    dest = reinterpret_cast<RcElem28*>(
        reinterpret_cast<char*>(dest) + sizeof(RcElem28));
  }
}

// Ghidra twin name
extern "C" void __fastcall FUN_00461c90(
    const RcElem28* value,
    int count,
    RcElem28* dest)
{
  StdUninitFillN_RcElem28(value, count, dest);
}
