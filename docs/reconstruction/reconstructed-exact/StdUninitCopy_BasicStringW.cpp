// =============================================================================
// StdUninitCopy_BasicStringW  (aa_004a6b50)
// -----------------------------------------------------------------------------
// Address:   0x004a6b50  (autoassault.exe, image base 0x400000)
// Body:      0x004a6b50 – 0x004a6bdc exclusive (140 B / 0x8C); pad CC
// Wave:      W36-R OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<wchar_t> retail footprint in this binary: 0x1C bytes.
struct BasicStringW_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

// IAT basic_string<wchar_t> copy-ctor / dtor (catch path); _CxxThrowException @ 0x006A3D60.
extern "C" void __thiscall basic_string_w_copy_ctor(BasicStringW_0x1c* self,
                                                    const BasicStringW_0x1c* other);
extern "C" void __thiscall basic_string_w_dtor(BasicStringW_0x1c* self);
extern "C" void __stdcall CxxThrowException(void* exc, void* throwInfo);

// cdecl (first, last, dest) -> dest_end; bare RET.
// Sole parent: StdVector_InsertN_BasicStringW (0x004a7ad0) grow/hole relocate arms.
extern "C" BasicStringW_0x1c* StdUninitCopy_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest)
{
  // SEH: LAB_009a1181; EH state byte transitions 0/1 around each construction.
  BasicStringW_0x1c* dest_cur = dest;

  for (; first != last;
       first = reinterpret_cast<BasicStringW_0x1c*>(
           reinterpret_cast<char*>(first) + kElemSize)) {
    // state = constructing
    if (dest_cur != nullptr) {
      basic_string_w_copy_ctor(dest_cur, first);
    }
    dest_cur = reinterpret_cast<BasicStringW_0x1c*>(
        reinterpret_cast<char*>(dest_cur) + kElemSize);
    // state = idle
  }

  // Success path jumps over the catch residual to epilogue; EAX = dest_cur.
  return dest_cur;

  // EH catch residual @ 0x004a6ba7 (not normal CF):
  // for (p = dest_start; p != dest_cur; p += 0x1c) basic_string_w_dtor(p);
  // CxxThrowException(nullptr, nullptr);  // call site 0x004a6bc4 → 0x006A3D60
}
