// =============================================================================
// MemZero_DestSize_ReturnOne_Inferred  (aa_00788db0)
// -----------------------------------------------------------------------------
// Address:   0x00788db0  (autoassault.exe, image base 0x400000)
// Wave:      W37-O OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Decompiler dword/byte loops ≡ REP STOSD / REP STOSB.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// cdecl zero-fill: dest @ [ESP+4], size @ [ESP+8]; bare RET; always returns 1.
// Not CRT memset (which returns dest). Signed size; size<=0 is no-op success.
extern "C" uint32_t __cdecl MemZero_DestSize_ReturnOne_Inferred(void* dest, int size)
{
  auto* p = static_cast<uint32_t*>(dest);
  auto n = size;

  if (n > 4) {
    // bulk dword count = floor((n-1)/4)  ==  ((n-5)>>2)+1
    int bulk = ((n - 5) >> 2) + 1;
    for (int i = bulk; i != 0; --i) {
      *p++ = 0;
    }
    n -= bulk * 4;
  }

  if (n > 0) {
    for (unsigned dwords = static_cast<unsigned>(n) >> 2; dwords != 0; --dwords) {
      *p++ = 0;
    }
    auto* b = reinterpret_cast<uint8_t*>(p);
    for (unsigned rem = static_cast<unsigned>(n) & 3u; rem != 0; --rem) {
      *b++ = 0;
    }
  }

  return 1u;
}

// Scaffold twin symbol
extern "C" uint32_t __cdecl FUN_00788db0(void* dest, int size)
{
  return MemZero_DestSize_ReturnOne_Inferred(dest, size);
}
