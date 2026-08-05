// =============================================================================
// StdVector_AssignFrom_BasicString  (aa_00469d10)
// -----------------------------------------------------------------------------
// Address:   0x00469d10  (autoassault.exe, image base 0x400000)
// Body:      0x00469d10 – 0x00469d96 exclusive (134 B / 0x86)
// Wave:      W34-S OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + RET 4.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<char> retail footprint in this binary: 0x1C bytes.
struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

struct VectorBasicString {
  void* _unused0;           // +0
  BasicString_0x1c* begin;  // +4
  BasicString_0x1c* end;    // +8
  BasicString_0x1c* capEnd; // +0xC
};

static constexpr uint32_t kElemSize = 0x1c;

// Nested (not dual-owned):
// FUN_00431b30(dest, n): zeros dest triad (no free!); if n!=0 buys n*0x1c,
//   begin=end=buf, capEnd=buf+n*0x1c; returns 1; n==0 returns 0.
extern "C" char __thiscall FUN_00431b30(VectorBasicString* dest, uint32_t n);
// W33-G: StdUninitCopy_BasicString — cdecl (first, last, dest) → dest_end
extern "C" BasicString_0x1c* FUN_0046a2c0(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest,
    ...);

// ECX = src vector*; stack dest*; RET 4; returns dest*.
// Blank-buy dest capacity for src size, then uninit_copy strings into dest.
// WARNING: buy path zeros dest triad without operator_delete — callers must
// ensure dest is empty/default, else prior buffer leaks.
extern "C" VectorBasicString* __thiscall StdVector_AssignFrom_BasicString(
    VectorBasicString* src,
    VectorBasicString* dest)
{
  // SEH LAB_009bdc60
  uint32_t n = 0;
  if (src->begin != nullptr) {
    n = static_cast<uint32_t>(
        (reinterpret_cast<char*>(src->end) - reinterpret_cast<char*>(src->begin)) /
        kElemSize);
  }

  // Bytes: MOV ECX, EDI (dest) before call
  char ready = FUN_00431b30(dest, n);
  if (ready != 0) {
    BasicString_0x1c* newEnd = FUN_0046a2c0(
        src->begin, src->end, dest->begin, dest);
    dest->end = newEnd;
  }
  return dest;
}
