// =============================================================================
// StdVector_BuyN_BasicString  (aa_00431b30)
// -----------------------------------------------------------------------------
// Address:   0x00431b30  (autoassault.exe, image base 0x400000)
// Body:      0x00431b30 – 0x00431b82 exclusive (82 B / 0x52)
// Wave:      W37-E OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + RET 4 + full hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<char> retail footprint in this binary: 0x1C bytes.
struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

struct VectorBasicString {
  void* _unused0;           // +0  (allocator / proxy; not touched here)
  BasicString_0x1c* begin;  // +4
  BasicString_0x1c* end;    // +8
  BasicString_0x1c* capEnd; // +0xC
};

static constexpr uint32_t kElemSize = 0x1c;
// Max n such that n*0x1c fits in size_t-1: 0xFFFFFFFF / 0x1c floored.
static constexpr uint32_t kMaxElems = 0x09249249;

// Nested (not dual-owned): throws length_error "vector<T> too long" — noreturn.
extern "C" void __thiscall FUN_004540b0(VectorBasicString* /*this_unused_or_ctx*/);
extern "C" void* __cdecl operator_new(uint32_t nbytes);

// ECX = dest vector*; stack n; RET 4.
// Zeros begin/end/capEnd WITHOUT freeing prior buffer.
// n==0 → return 0 (empty triad).
// n>0  → allocate n*0x1c, begin=end=buf (size 0), capEnd=buf+nbytes, return 1.
// WARNING: callers must pass empty/default dest or prior buffer leaks.
extern "C" uint8_t __thiscall StdVector_BuyN_BasicString(
    VectorBasicString* self,
    uint32_t n)
{
  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;

  if (n == 0) {
    return 0;
  }

  if (n > kMaxElems) {
    FUN_004540b0(self);  // noreturn — "vector<T> too long"
  }

  uint32_t nbytes = n * kElemSize;
  void* buf = operator_new(nbytes);
  self->begin = static_cast<BasicString_0x1c*>(buf);
  self->end = static_cast<BasicString_0x1c*>(buf);
  self->capEnd = reinterpret_cast<BasicString_0x1c*>(
      reinterpret_cast<char*>(buf) + nbytes);
  return 1;
}
