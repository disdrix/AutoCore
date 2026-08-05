// =============================================================================
// StdUninitCopy_BasicString  (aa_0046a2c0)
// -----------------------------------------------------------------------------
// Address:   0x0046a2c0  (autoassault.exe, image base 0x400000)
// Body:      0x0046a2c0 – 0x0046a34c exclusive (140 B / 0x8C); pad CC
// Wave:      W33-G OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<char> retail footprint in this binary: 0x1C bytes.
struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

// IAT basic_string copy-ctor / dtor (catch path); _CxxThrowException @ 0x006A3D60.
extern "C" void __thiscall basic_string_copy_ctor(BasicString_0x1c* self,
                                                    const BasicString_0x1c* other);
extern "C" void __thiscall basic_string_dtor(BasicString_0x1c* self);
extern "C" void __stdcall CxxThrowException(void* exc, void* throwInfo);

// cdecl (first, last, dest) -> dest_end; bare RET.
// Optional trailing allocator args from wrappers are unused by this body.
extern "C" BasicString_0x1c* StdUninitCopy_BasicString(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest)
{
  // SEH: LAB_009bcce1; EH state byte transitions 0/1 around each construction.
  BasicString_0x1c* dest_cur = dest;

  for (; first != last;
       first = reinterpret_cast<BasicString_0x1c*>(
           reinterpret_cast<char*>(first) + kElemSize)) {
    // state = constructing
    if (dest_cur != nullptr) {
      basic_string_copy_ctor(dest_cur, first);
    }
    dest_cur = reinterpret_cast<BasicString_0x1c*>(
        reinterpret_cast<char*>(dest_cur) + kElemSize);
    // state = idle
  }

  // Success path jumps over the catch residual to epilogue; EAX = dest_cur.
  return dest_cur;

  // EH catch residual @ 0x0046A318 (not normal CF):
  // for (p = dest_start; p != dest_cur; p += 0x1c) basic_string_dtor(p);
  // CxxThrowException(nullptr, nullptr);
}
