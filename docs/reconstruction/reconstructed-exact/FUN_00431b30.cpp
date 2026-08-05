// =============================================================================
// FUN_00431b30  — twin of StdVector_BuyN_BasicString
// -----------------------------------------------------------------------------
// Address:   0x00431b30  (autoassault.exe, image base 0x400000)
// Body:      0x00431b30 – 0x00431b82 exclusive (82 B / 0x52)
// Wave:      W37-E OWN-ONLY dual 2026-08-04
// Canonical: StdVector_BuyN_BasicString
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

struct VectorBasicString {
  void* _unused0;
  BasicString_0x1c* begin;
  BasicString_0x1c* end;
  BasicString_0x1c* capEnd;
};

static constexpr uint32_t kElemSize = 0x1c;
static constexpr uint32_t kMaxElems = 0x09249249;

extern "C" void __thiscall FUN_004540b0(VectorBasicString* self);
extern "C" void* __cdecl operator_new(uint32_t nbytes);

// ECX=vector*; stack n; RET 4; return 0 if n==0 else 1 after buy.
// Zeros triad without free; size left 0 (begin==end).
extern "C" uint8_t __thiscall FUN_00431b30(VectorBasicString* self, uint32_t n)
{
  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;
  if (n == 0) {
    return 0;
  }
  if (n > kMaxElems) {
    FUN_004540b0(self);  // noreturn
  }
  uint32_t nbytes = n * kElemSize;
  void* buf = operator_new(nbytes);
  self->begin = static_cast<BasicString_0x1c*>(buf);
  self->end = static_cast<BasicString_0x1c*>(buf);
  self->capEnd = reinterpret_cast<BasicString_0x1c*>(
      reinterpret_cast<char*>(buf) + nbytes);
  return 1;
}
