// =============================================================================
// FUN_00469d10  — twin of StdVector_AssignFrom_BasicString
// -----------------------------------------------------------------------------
// Address:   0x00469d10  (autoassault.exe, image base 0x400000)
// Body:      0x00469d10 – 0x00469d96 exclusive (134 B / 0x86)
// Wave:      W34-S OWN-ONLY dual 2026-07-29
// Canonical: StdVector_AssignFrom_BasicString
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

extern "C" char __thiscall FUN_00431b30(VectorBasicString* dest, uint32_t n);
extern "C" BasicString_0x1c* FUN_0046a2c0(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest,
    ...);

// ECX = src*; stack dest*; RET 4; returns dest*.
extern "C" VectorBasicString* __thiscall FUN_00469d10(
    VectorBasicString* src,
    VectorBasicString* dest)
{
  uint32_t n = 0;
  if (src->begin != nullptr) {
    n = static_cast<uint32_t>(
        (reinterpret_cast<char*>(src->end) - reinterpret_cast<char*>(src->begin)) /
        kElemSize);
  }

  char ready = FUN_00431b30(dest, n);
  if (ready != 0) {
    BasicString_0x1c* newEnd = FUN_0046a2c0(
        src->begin, src->end, dest->begin, dest);
    dest->end = newEnd;
  }
  return dest;
}
